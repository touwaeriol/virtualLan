//
// Created by touwaerio on 2022/6/2.
//

#ifndef VIRTUALLAN_CLIENT_H
#define VIRTUALLAN_CLIENT_H

#include <vl/core.h>

namespace vl::client {

    class Client;
}


namespace vl::client {
    using namespace vl::core;
    using namespace grpc;
    using namespace std;


    class Client : public Uncopymovable {

    public:
        Client(const string &serverHost, int serverPort, int udpPort);

        ~Client() override = default;

        void operator()();

    public:
        void init();

        std::pair<bool,string> start();

        void wait();


    private:
        std::unique_ptr<RequestCode> newRequestCode();


    private:
        SyncEvent _syncEvent;

        int _udpPort;

        string _grpcServerHost;

        int _grpcServerPort;

        vl::core::RequestIdGenerator _request_id_generator;

        std::shared_ptr<grpc::Channel> _channel;

        grpc::ClientContext _context;

        std::shared_ptr<vl::core::RegisterService::Stub> _register_stub;

        Device _device;

        vl::core::Tap _tap;

        std::vector<Byte> _buf;
    };
}


#endif //VIRTUALLAN_CLIENT_H
