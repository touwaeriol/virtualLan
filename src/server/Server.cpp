//
// Created by touwaerio on 2022/6/6.
//

#include "Server.h"

vl::server::Server::Server(const string &listenHost, int listenPort, const pair<string, string> &ipRange, int netmask,
                           size_t dataQueueCap, int mtu)
        : _listenHost(listenHost), _listenPort(listenPort), _ipRange(ipRange), _netmask(netmask),
          _dataQueue(moodycamel::BlockingReaderWriterCircularBuffer<std::unique_ptr<vector<Byte>>>(dataQueueCap)),
          _mtu(mtu) {}


void vl::server::Server::init() {
    DLOG << "初始化服务器";
    _register = make_shared<RegisterServiceImpl>(_ipRange.first, _ipRange.second, _netmask);
    _builder.RegisterService(_register.get());
    _builder.AddListeningPort(_listenHost + ":" + to_string(_listenPort), grpc::InsecureServerCredentials(), nullptr);
    DLOG << "初始化buf";
    _buf.resize(_mtu);

    DLOG << "初始化udpsocket";
    _udpSock = co::udp_socket();
    if (_udpSock == -1) {
        FLOG << " 创建udp socket失败";
    }
    auto ok = co::init_ip_addr(&_addr, _listenHost.c_str(), _listenPort);
    if (!ok) {
        FLOG << "udp socket绑定地址失败, code = " << co::error() << " ,message = " << co::strerror(co::error());
    }
    DLOG << "初始化数据队列";
    _dataQueue = moodycamel::BlockingReaderWriterCircularBuffer<std::unique_ptr<vector<Byte>>>(1024);

}

pair<bool, string> vl::server::Server::start() {
    DLOG << "启动 grpc 服务器";
    _grpcServer = _builder.BuildAndStart();
    DLOG << "udp绑定地址";
    auto code = co::bind(_udpSock, &_addr, sizeof(sockaddr_in));
    if (code == -1) {
        FLOG << "绑定本地udp端口失败";
    }
    DLOG << "监听 udp数据";
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

void vl::server::Server::initUdpSocket() {
    _udpSock = co::udp_socket();
    if (_udpSock == -1) {
        FLOG << " 创建udp socket失败";
    }
    sockaddr_in addr{};
    auto ok = co::init_ip_addr(&addr, _listenHost.c_str(), sizeof(addr));
    if (!ok) {
        FLOG << "udp socket绑定地址失败, code = " << co::error() << " ,message = " << co::strerror(co::error());
    }
    auto code = co::bind(_udpSock, &addr, sizeof(addr));
    if (code == -1) {
        FLOG << "绑定本地udp端口失败";
    }
}

void vl::server::Server::loopUdpData() {
    //使用协程接收数据
    co::go([this]() -> void {
        std::unique_ptr<vector<Byte>> buf;
        while (true) {
            sockaddr_in peer{};
            buf = std::make_unique<vector<Byte>>();
            buf->resize(_mtu);
            int addrLen = sizeof(sockaddr_in);
            auto code = co::recvfrom(_udpSock, buf->data(), static_cast<int>(buf->size()), &peer, &addrLen);
            if (code == -1) {
                FLOG << "接收数据错误";
            } else if (code == 0) {
                FLOG << "socket已经关闭";
            } else {
                buf->resize(code);
//                DLOG << "收到来自 " << co::ip_str(&peer).c_str() << "的数据包，加入到数据队列中";
                _dataQueue.try_enqueue(std::move(buf));
            }
        }
    });
    //使用线程处理数据
    _dataHandler = std::make_unique<Thread>([this]() -> void {
        auto data = std::unique_ptr<vector<Byte>>();
        _dataQueue.wait_dequeue(data);
        co::go([this,data{move(data)}] () -> void {
            //处理数据
            this->onReceiveData(*data);
        });
    });
}

void vl::server::Server::onReceiveData(vector<Byte> &data) {

}
