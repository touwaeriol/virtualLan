//
// Created by touwaerio on 2022/6/6.
//

#include "Server.h"

vl::server::Server::Server(const string &listenHost, int listenPort, const pair<string, string> &ipRange, int netmask)
        : _listenHost(listenHost), _listenPort(listenPort), _ipRange(ipRange), _netmask(netmask) {}


void vl::server::Server::init() {
    DLOG << "初始化服务器";
    _register = make_shared<RegisterServiceImpl>(_ipRange.first, _ipRange.second, _netmask);

    _builder.RegisterService(_register.get());
    _builder.AddListeningPort(_listenHost + ":" + to_string(_listenPort), grpc::InsecureServerCredentials(), nullptr);


}

pair<bool, string> vl::server::Server::start() {
    DLOG << "启动服务器";
    _grpcServer = _builder.BuildAndStart();
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

