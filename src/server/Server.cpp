//
// Created by touwaerio on 2022/6/6.
//



#include "Server.h"


using namespace std;

vl::server::Server::Server(const string &listenHost, int listenPort, const pair<string, string> &ipRange, int netmask,
                           size_t dataQueueCap, int mtu)
        : _listenHost(listenHost), _listenPort(listenPort), _ipRange(ipRange), _netmask(netmask),
          _dataQueue(moodycamel::BlockingReaderWriterCircularBuffer<EtherData>(dataQueueCap)),
          _mtu(mtu) {}

vl::server::Server::~Server() {
    _stop = true;
    _grpcServer->Shutdown();
    _udpServerSock->close();
    wait();
}

void vl::server::Server::init() {
    DLOG("初始化服务器");
    _register = std::make_shared<RegisterServiceImpl>(_ipRange.first, _ipRange.second, _netmask);
    _builder.RegisterService(_register.get());
    _builder.AddListeningPort(_listenHost + ":" + to_string(_listenPort), grpc::InsecureServerCredentials(), nullptr);
    DLOG("初始化udpsocket");
    _udpContext = std::make_shared<boost::asio::io_context>();


    _udpServerSock = std::make_shared<boost::asio::ip::udp::socket>(*this->_udpContext);
    DLOG("初始化数据队列");
    _dataQueue = moodycamel::BlockingReaderWriterCircularBuffer<EtherData>(1024);

}

pair<bool, string> vl::server::Server::start() {
    DLOG("启动 grpc 服务器");
    _grpcServer = std::shared_ptr<grpc::Server>(_builder.BuildAndStart().release());
    DLOG("udp绑定地址");
    auto endpoint = boost::asio::ip::udp::endpoint(boost::asio::ip::make_address_v4("0.0.0.0"), _listenPort);
    boost::system::error_code error;
    _udpServerSock->bind(endpoint, error);
    if (error) {
        CLOG(std::string("绑定本地udp端口失败: ") + error.message());
        assert(error.operator bool());
    }
    DLOG("打开socket");
    _udpServerSock->open(boost::asio::ip::udp::v4());
    DLOG("监听 udp数据");
    loopUdpData();
    return {true, ""};
}

void vl::server::Server::wait() {
    _grpcServer->Wait();
    _dataHandler->join();
    _dataReceiver->join();
}


void vl::server::Server::setListenHost(const string &listenHost) {
    _listenHost = listenHost;
}

void vl::server::Server::setListenPort(int listenPort) {
    _listenPort = listenPort;
}

void vl::server::Server::setIpRange(const pair<string, string> &ipRange) {
    _ipRange = ipRange;
}

void vl::server::Server::setNetmask(int netmask) {
    _netmask = netmask;
}


void vl::server::Server::loopUdpData() {
    //使用协程接收数据
    _dataReceiver = std::make_unique<std::thread>([this]() -> void {
        boost::system::error_code error;
        while (true) {
            if (_stop) {
                break;
            }
            EtherData buf{};
            buf._content.resize(_mtu);
            boost::asio::mutable_buffer asioBuf = boost::asio::buffer(buf._content);
            _udpServerSock->wait(boost::asio::ip::udp::socket::wait_read, error);
            if (error) {
                WLOG("等待数据可以读取失败");
            }
            auto len = _udpServerSock->receive_from(asioBuf, buf._peer, 0, error);
            buf._content.resize(len);
            if (error) {
                DLOG("接收数据错误 : " + error.message());
            } else {
                DLOG(fmt::format("接收数据成功， len = {}", len));
                _dataQueue.try_enqueue(std::move(buf));
            }
        }
    });
    //使用线程处理数据
    _dataHandler = std::make_unique<std::thread>([this]() -> void {
        while (true) {
            if (_stop) {
                break;
            }
            EtherData data{};
            _dataQueue.wait_dequeue(data);
            vl::core::co([this, data(std::move(data))]() -> void {
                //处理数据
                this->onReceiveData(data);
            });
        }
    });
}

void vl::server::Server::onReceiveData(const EtherData &data) {
    if (data._content.size() < 42) {
        switch (data._content.size()) {
            //客户端心跳数据包
            case VL_HEART_BEAT_PACKAGE_SIZE : {
                auto buf = boost::asio::buffer(data._content);
                boost::system::error_code error;
                _udpServerSock->wait(boost::asio::ip::udp::socket::wait_write, error);
                if (error) {
                    WLOG(fmt::format("待数据可以发送失败: {}", error.message()));
                }
                _udpServerSock->send_to(buf, data._peer, 0, error);
                if (error) {
                    WLOG(fmt::format("发送udp数据失败: {}", error.message()));
                }
                break;
            }
                //客户端上报公网port地址
            case MAC_LEN : {
                std::array<Byte, MAC_LEN> mac{};
                memcpy(mac.data(), data._content.data(), MAC_LEN);
                //找到了设备
                auto result = _register->_manager.setDeviceUdpPort(mac, data._peer.port());
                if (!result.first) {
                    WLOG("mac 地址 " + (EthernetAddressManager::macAddrToStr(mac)) + " 记录失败：" + result.second);
                }
                break;
            }
            default : {

                break;
            }
        }
    } else {
        switch (vl::core::Frame::frameType(data._content)) {
            case core::ETHERNET_V2: {
                EthernetV2Frame frame{data._content};
                auto dest = frame.dest();
                TLOG("如果第一个字节的最低位是1，则是多播？不然就是单播");
                auto broadcast = (dest[0] & 0x01) == 0x01;
                if (broadcast) {

                } else {
                    auto destAddr = _register->_manager.getDevicePublicAddr(dest);
                    boost::system::error_code error;
                    if (destAddr.has_value()) {
                        auto buf = boost::asio::buffer(data._content);
                        boost::asio::ip::udp::endpoint destEp(boost::asio::ip::address(
                                                                      boost::asio::ip::make_address(EthernetAddressManager::ipAddrToStr(destAddr->first))),
                                                              destAddr->second);
                        _udpServerSock->wait(boost::asio::ip::udp::socket::wait_write, error);
                        if (error) {
                            WLOG("等待数据可以发送失败");
                        }
                        this->_udpServerSock->send_to(buf, destEp, 0, error);
                        if (error) {
                            DLOG("转发数据失败");
                        }
                    }
                }
                break;
            }
            default: {
                DLOG("不能识别的数据格式");
                break;
            }
        }
    }

}
