//
// Created by touwaerio on 2022/6/6.
//



#include "Server.h"


using namespace std;

vl::server::Server::Server(const string &listenHost, int listenPort, const pair<string, string> &ipRange, int netmask,
                           size_t dataQueueCap, int mtu)
        : _listenHost(listenHost), _listenPort(listenPort), _ipRange(ipRange), _netmask(netmask),
          _dataQueue(moodycamel::BlockingReaderWriterCircularBuffer<EtherData>(dataQueueCap)),
          _mtu(mtu),
          _stop(false) {}

vl::server::Server::~Server() {
    _stop = true;
    _grpcServer->Shutdown();
    _udpServerSock->close();
    wait();
}

void vl::server::Server::init() {
    DLOG("初始化服务器");
    _addressesManager = std::make_shared<EthernetAddressManager>(
            std::pair<std::string, std::string>(_ipRange.first, _ipRange.second));
    auto listen = fmt::format("{}:{}", _listenHost, _listenPort);
    DLOG(fmt::format("监听端口 : {}", listen));
    _builder.AddListeningPort(listen, grpc::InsecureServerCredentials(), nullptr);
    DLOG("注册 注册设备服务")
    auto _register = std::make_unique<RegisterServiceImpl>(_addressesManager, _netmask);
    _builder.RegisterService(_register.release());
    DLOG("初始化udpsocket");
    _udpContext = std::make_shared<boost::asio::io_context>();
    _udpServerSock = std::make_shared<boost::asio::ip::udp::socket>(*this->_udpContext);
    DLOG("初始化数据队列");
    _dataQueue = moodycamel::BlockingReaderWriterCircularBuffer<EtherData>(1024);

}

pair<bool, string> vl::server::Server::start() {
    DLOG("启动 grpc 服务器");
    auto server = _builder.BuildAndStart();
    _grpcServer = std::shared_ptr<grpc::Server>(server.release());

    boost::system::error_code error;
    DLOG("打开socket");
    _udpServerSock->open(boost::asio::ip::udp::v4(), error);
    if (error) {
        CLOG(std::string("打开socket: ") + error.message());
        assert(error.operator bool());
    }
    auto endpoint = boost::asio::ip::udp::endpoint(boost::asio::ip::make_address_v4("0.0.0.0"), _listenPort);
    DLOG(fmt::format("udp绑定地址 {}:{}", endpoint.address().to_string(), endpoint.port()));
    if (error) {
        CLOG(std::string("绑定本地udp端口失败: ") + error.message());
        assert(error.operator bool());
    }
    _udpServerSock->bind(endpoint, error);
    if (error) {
        WLOG(fmt::format("绑定本地端口失败 {}:{}", endpoint.address().to_string(), endpoint.port()));
    }
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
            auto asioBuf = boost::asio::buffer(buf._content);
            _udpServerSock->wait(boost::asio::ip::udp::socket::wait_read, error);
            if (error) {
                WLOG("等待数据可以读取失败");
            }
            buf._content.resize(_udpServerSock->receive_from(asioBuf, buf._peer, 0, error));
            if (error) {
                DLOG(fmt::format("接收数据错误 : {}", error.message()))
            } else {
                DLOG(fmt::format("接收数据成功， len = {}", buf._content.size()))
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
            async::spawn([this, data(std::move(data))]() -> void {
                //处理数据
                this->onReceiveData(data);
            });
        }
    });
}

void vl::server::Server::onReceiveData(const EtherData &data) noexcept {
    try {
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
                    auto len = _udpServerSock->send_to(buf, data._peer, 0, error);
                    if (error) {
                        WLOG(fmt::format("发送udp数据失败: {}", error.message()));
                    }
                    break;
                }
                    //客户端上报公网port地址
                case MAC_LEN : {
                    DLOG("客户端上报公网信息")
                    std::array<Byte, MAC_LEN> mac{};
                    memcpy(mac.data(), data._content.data(), MAC_LEN);
                    //找到了设备
                    auto result = _addressesManager->setDeviceUdpPort(mac, data._peer.port());
                    if (!result.first) {
                        WLOG("mac 地址 " + (EthernetAddressManager::macAddrToStr(mac)) + " 记录失败：" + result.second);
                    } else{
                        DLOG(fmt::format("mac 地址 mac={} {}:{} 记录成功" ,(EthernetAddressManager::macAddrToStr(mac))))
                    }
                    break;
                }
                default : {

                    break;
                }
            }
        } else {
            DLOG("转发以太层数据");
            switch (vl::core::Frame::frameType(data._content)) {
                case core::ETHERNET_V2: {
                    EthernetV2Frame frame{data._content};
                    auto dest = frame.dest();
                    TLOG("如果第一个字节的最低位是1，则是多播？不然就是单播");
                    auto broadcast = (dest[0] & 0x01) == 0x01;
                    if (broadcast) {
                        DLOG("广播")
                        auto allAddress = _addressesManager->getMacDeviceMap();
                        DLOG(fmt::format("广播到 {} 个客户端", allAddress.size()))
                        auto buf = boost::asio::buffer(data._content);
                        DLOG(fmt::format("buf创建完成"))
                        boost::system::error_code error;
                        for (const auto &item: allAddress) {
                            DLOG("准备转发广播数据")
                            auto device = item.second;
                            if (device == nullptr) {
                                WLOG(fmt::format("{} 对应的设备信息为空",
                                                 EthernetAddressManager::macAddrToStr(item.first)))
                                continue;
                            }
                            DLOG(fmt::format("发送数据到 mac = {} {}:{}",
                                             EthernetAddressManager::macAddrToStr(item.first), device->publicip(),
                                             device->publicudpport()));
                            auto addr = boost::asio::ip::make_address(device->publicip(), error);
                            if (error) {
                                WLOG(fmt::format("目标设备地址错误 {}:{}",
                                                 device->publicip(),
                                                 device->publicudpport()));
                                continue;
                            }
                            auto destEp = boost::asio::ip::udp::endpoint(
                                    addr, device->publicudpport());
                            _udpServerSock->wait(boost::asio::ip::udp::socket::wait_write, error);
                            if (error) {
                                WLOG(fmt::format("等待发送广播数据到 {}:{} 发生了错误", device->publicip(),
                                                 device->publicudpport()));
                                continue;
                            }
                            auto length = this->_udpServerSock->send_to(buf, destEp, 0, error);
                            if (error) {
                                DLOG(fmt::format("发送广播数据到 {}:{} 失败", device->publicip(),
                                                 device->publicudpport()));
                                continue;
                            } else {
                                DLOG(fmt::format("发送广播数据到 {}:{} 成功 len = {}", device->publicip(),
                                                 device->publicudpport(), length));
                            }
                        }
                    } else {
                        DLOG("单播")
                        auto destAddr = _addressesManager->getDevicePublicAddr(dest);
                        boost::system::error_code error;
                        if (destAddr.has_value()) {
                            auto buf = boost::asio::buffer(data._content);
                            boost::asio::ip::udp::endpoint destEp(boost::asio::ip::address(
                                                                          boost::asio::ip::make_address(
                                                                                  EthernetAddressManager::ipAddrToStr(destAddr->first))),
                                                                  destAddr->second);
                            _udpServerSock->wait(boost::asio::ip::udp::socket::wait_write, error);
                            if (error) {
                                WLOG("等待数据可以发送失败");
                            }
                            this->_udpServerSock->send_to(buf, destEp, 0, error);
                            if (error) {
                                DLOG("转发数据失败");
                            } else {
                                DLOG("转发数据成功");
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
    } catch (exception &e) {
        WLOG(fmt::format("处理转发数据发生了异常 {}", e.what()))
    }


}
