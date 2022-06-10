//
// Created by touwaerio on 2022/5/20.
//



#include <co/co.h>

#include "socket/udp/UdpSocketServer.h"
#include "exception/VlSocketException.h"
#include "socket/checkCode.h"


using namespace vl::core;



vl::core::UdpSocketServer::UdpSocketServer(const std::string &ip, int port, int bufSize) : SocketServer(ip, port,
                                                                                                        bufSize) {}

vl::core::UdpSocketServer::UdpSocketServer(const sockaddr_in &bindAddress, int bufSize) : SocketServer(bindAddress,
                                                                                                       bufSize) {}

vl::core::UdpSocketServer::UdpSocketServer(int port, int bufSize) : UdpSocketServer("0.0.0.0", port, bufSize) {}

vl::core::UdpSocketServer::~UdpSocketServer() {
    co::close(serverSock);
    waiter.signal();
}

void vl::core::UdpSocketServer::run() {
    co::go([this]() -> void {
        serverSock = co::udp_socket();
        CHECK_CODE(co::bind(serverSock, &this->_bindAddress, sizeof this->_bindAddress))
        while (true) {
            //申请buf空间
            std::vector<char> buf(_bufSize);
            buf.resize(_bufSize, '\0');
            //申请peer空间
            sockaddr_in peer{};
            //长度
            int len = sizeof(sockaddr_in);
            //接收数据
            int n = co::recvfrom(serverSock, buf.data(), _bufSize, &peer, &len);
            //检查code
            CHECK_CODE(n)
            //处理数据
            if (n != 0) {
                this->onMessage(peer, buf, n);
            }
        }
    });
}

void vl::core::UdpSocketServer::shutDown(int ms) {
    co::close(serverSock, ms);
    waiter.signal();
}

void UdpSocketServer::wait() {
    waiter.wait();
}





