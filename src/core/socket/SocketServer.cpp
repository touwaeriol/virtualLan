//
// Created by touwaerio on 2022/5/20.
//

#include "socket/SocketServer.h"

#include <utility>


vl::core::SocketServer::SocketServer(const std::string &bindIp, int bindPort, int bufSize) {
    co::init_ip_addr(&this->_bindAddress, bindIp.c_str(), bindPort);
    this->_bufSize = bufSize;
}

vl::core::SocketServer::SocketServer(const sockaddr_in &bindAddress, int bufSize) : _bindAddress(bindAddress),
                                                                                    _bufSize(bufSize) {

}
