//
// Created by touwaerio on 2022/6/6.
//

#include "Server.h"

#include <asio.hpp>

vl::server::Server::Server(const string &listenHost, int listenPort, const pair<string, string> &ipRange, int netmask,
                           size_t dataQueueCap, int mtu)
        : _listenHost(listenHost), _listenPort(listenPort), _ipRange(ipRange), _netmask(netmask),
          _dataQueue(moodycamel::BlockingReaderWriterCircularBuffer<std::unique_ptr<EtherData>>(dataQueueCap)),
          _mtu(mtu) {}


void vl::server::Server::init() {
    DLOG("初始化服务器");
    _register = make_shared<RegisterServiceImpl>(_ipRange.first, _ipRange.second, _netmask);
    _builder.RegisterService(_register.get());
    _builder.AddListeningPort(_listenHost + ":" + to_string(_listenPort), grpc::InsecureServerCredentials(), nullptr);
    DLOG("初始化udpsocket");
    _udpServerSock = std::make_shared<asio::ip::udp::socket>(*this->_udpContext);
    DLOG("初始化数据队列");
    _dataQueue = moodycamel::BlockingReaderWriterCircularBuffer<std::unique_ptr<EtherData>>(1024);

}

pair<bool, string> vl::server::Server::start() {
    DLOG("启动 grpc 服务器");
    _grpcServer = _builder.BuildAndStart();
    DLOG("udp绑定地址");
    auto endpoint = asio::ip::udp::endpoint(asio::ip::make_address_v4("0.0.0.0"), _listenPort);
    try {
        _udpServerSock->bind(endpoint);
    } catch (const asio::system_error &err) {
        CLOG(std::string("绑定本地udp端口失败: ") + err.what());
    }

    DLOG("监听 udp数据");
    loopUdpData();
    return {true, ""};
}

void vl::server::Server::wait() {
    _grpcServer->Wait();
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
    vl::core::co([this]() -> void {
        asio::error_code errorCode;
        while (true) {
            auto buf = std::make_unique<EtherData>();
            buf->_content.resize(_mtu);
            asio::mutable_buffer asioBuf = asio::buffer(buf->_content);
            auto len = _udpServerSock->receive_from(asioBuf, buf->_peer, 0, errorCode);
            buf->_content.resize(len);
            if (!errorCode) {
                FLOG("接收数据错误 : ") << errorCode.message();
            } else {
                _dataQueue.try_enqueue(std::move(buf));
            }
        }
    });
    //使用线程处理数据
    _dataHandler = std::make_unique<std::thread>([this]() -> void {
        auto data = std::unique_ptr<EtherData>();
        _dataQueue.wait_dequeue(data);
        vl::core::co([this, data{move(data)}]() -> void {
            //处理数据
            this->onReceiveData(*data);
        });
    });
}

void vl::server::Server::onReceiveData(const EtherData &data) {
    if (data._content.size() < 42) {
        switch (data._content.size()) {
            case MAC_LEN : {
                std::array<Byte, MAC_LEN> mac{};
                memcpy(mac.data(), data._content.data(), MAC_LEN);
                //找到了设备
                auto result = _register->_manager.setDeviceUdpPort(mac, data._peer.port());
                if (!result.first) {
                    WLOG("mac 地址 ")<< (EthernetAddressManager::macAddrToStr(mac)) << " 记录失败：" << result.second;
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
                // 如果第一个字节的最低位是1，则是多播？不然就是单播
                auto broadcast = (dest[0] & 0x01) == 0x01;
                if (broadcast) {

                } else {
                    auto destAddr = _register->_manager.getDevicePublicAddr(dest);
                    asio::error_code errorCode;
                    if (destAddr.has_value()) {
                        auto buf = asio::buffer(data._content);
                        asio::ip::udp::endpoint destEp(asio::ip::address(
                                                               asio::ip::make_address(EthernetAddressManager::ipAddrToStr(destAddr->first))),
                                                       destAddr->second);
                        this->_udpServerSock->send_to(buf, destEp, 0, errorCode);
                        if (!errorCode) {
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
