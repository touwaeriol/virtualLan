//
// Created by touwaerio on 2022/6/2.
//

#ifndef VIRTUALLAN_CLIENT_H
#define VIRTUALLAN_CLIENT_H

#include <vl/core.h>

#include "Client.h"



namespace vl::client {
    class Client;

}


namespace vl::client {
    using namespace vl::core;
    using namespace grpc;
    using namespace std;


    class Client : public Uncopymovable {


    public:

        Client(const string &serverHost, int serverPort, int udpPort, size_t dataQueueCap = 1024,
               const string &tapName = "vl-adapter0");

        ~Client() override;

        void operator()();

    public:
        void init();

        std::pair<bool, string> start();

        void wait();

    public:
        void setTapName(const string &tapName);

    private:
        std::unique_ptr<RequestCode> newRequestCode();

        void loopUdpData();


        void onReceiveData(const vector<Byte> &data);


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

        std::string _tapName;

        unique_ptr<Thread> _dataReader;

        unique_ptr<Thread> _dataHandler;

        moodycamel::BlockingReaderWriterCircularBuffer<std::unique_ptr<vector < Byte>>>_dataQueue;

        sock_t _sock;
        sockaddr_in _serverAddr;
        sockaddr_in _localAddr;

    };


}


#endif //VIRTUALLAN_CLIENT_H
