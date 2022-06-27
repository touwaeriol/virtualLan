//
// Created by touwaerio on 2022/6/6.
//

#ifndef VIRTUALLAN_SERVER_H
#define VIRTUALLAN_SERVER_H


#include <vl/core.h>
#include <utility>
#include <string>
#include <memory>


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

        Server(const string &listenHost, int listenPort, const pair<string, string> &ipRange, int netmask,
               size_t dataQueueCap = 1024, int mtu = VL_TAP_MAX_MTU);


        ~Server() override;


    public:
        void init();

        pair<bool, string> start();

        void wait();

    public:

        void setListenHost(const string &listenHost = "0.0.0.0");

        void setListenPort(int listenPort);

        void setIpRange(const pair<string, string> &ipRange);

        void setNetmask(int netmask);


    private:


        void loopUdpData();

    private:
        string _listenHost;

        int _listenPort;

        pair<string, string> _ipRange;

        int _netmask;

        int _mtu;

        grpc::ServerBuilder _builder;

        std::shared_ptr<grpc::Server> _grpcServer;

        shared_ptr<RegisterServiceImpl> _register;

        std::shared_ptr<boost::asio::io_context> _udpContext;

        std::shared_ptr<boost::asio::ip::udp::socket> _udpServerSock;

        /**
         * 收到的udp数据
         */
        moodycamel::BlockingReaderWriterCircularBuffer<EtherData> _dataQueue;

        std::unique_ptr<std::thread> _dataReceiver;

        std::unique_ptr<std::thread> _dataHandler;

        void onReceiveData(const EtherData &data);

        volatile bool _stop;
    };
}


#endif //VIRTUALLAN_SERVER_H
