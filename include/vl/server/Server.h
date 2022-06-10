//
// Created by touwaerio on 2022/6/6.
//

#ifndef VIRTUALLAN_SERVER_H
#define VIRTUALLAN_SERVER_H


#include <vl/core.h>
#include <utility>
#include <string>
#include <memory>

#include <vl/core/util/Uncopymovable.hpp>
#include <c++/9/bits/stl_pair.h>

#include "service/RegisterServiceImpl.h"

using namespace std;
using namespace vl::core;

namespace vl::server {
    class Server;
}

namespace vl::server {


    class Server : public core::Uncopymovable {
    public:

        Server() = default;

        Server(const string &listenHost, int listenPort, const pair<string, string> &ipRange, int netmask);


        ~Server() override = default;


    public:
        void init();

        pair<bool, string> start();

        void wait();

    public:

        void setListenHost(const string &listenHost);

        void setListenPort(int listenPort);

        void setIpRange(const pair<string, string> &ipRange);

        void setNetmask(int netmask);

    private:
        string _listenHost;

        int _listenPort;

        pair<string, string> _ipRange;

        int _netmask;

        grpc::ServerBuilder _builder;

        shared_ptr <grpc::Server> _grpcServer;

        shared_ptr <RegisterServiceImpl> _register;


    };
}


#endif //VIRTUALLAN_SERVER_H
