//
// Created by touwaerio on 2022/6/2.
//

#ifndef VIRTUALLAN_CLIENT_H
#define VIRTUALLAN_CLIENT_H

#include <vl/core.h>
#include <thread>
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

        Client(
                const string &serverHost,
                int serverPort,
                int udpPort,
                size_t dataQueueCap = 1024,
                size_t receivedUdpDataQueueCap = 1024,
                size_t waitSendUdpDataQueueCap = 1024,
                const string &tapName = "vltap0"
        );

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

        void onReadTapData(const vector<Byte> &data);

        void onReceiveUdpData(const vl::core::EtherData &data);

        void sendUdpToServer(const vector<Byte> & data);


    private:

        int _udpPort;

        string _grpcServerHost;

        int _grpcServerPort;

        vl::core::RequestIdGenerator _request_id_generator;

        std::shared_ptr<grpc::Channel> _channel;

        grpc::ClientContext _context;

        std::shared_ptr<vl::core::RegisterService::Stub> _register_stub;

        Device _device;

        std::shared_ptr<vl::core::Tap> _tap;

        std::string _tapName;

        unique_ptr<std::thread> _tapDataReader;

        unique_ptr<std::thread> _tapDataHandler;

        unique_ptr<std::thread> _udpDataSender;

        unique_ptr<std::thread> _udpDataReceiver;

        unique_ptr<std::thread> _udpDataHandler;

        unique_ptr<std::thread> _beatHearthThread;

        /**
         * 收到的tap数据
         */
        moodycamel::BlockingReaderWriterCircularBuffer<vector<Byte>>
                _tapDataQueue;

        /**
         * 收到的udp数据
         */
        moodycamel::BlockingReaderWriterCircularBuffer<vl::core::EtherData> _receivedUdpDataQueue;

        /**
         * 等待发送的udp数据队列
         */
        moodycamel::BlockingConcurrentQueue<vl::core::EtherData> _waitSendUdpDataQueue;


        boost::asio::io_context _udpContext;
        std::shared_ptr<boost::asio::ip::udp::socket> _udpSock;
        boost::asio::ip::udp::endpoint _serverAddr;
        boost::asio::ip::udp::endpoint _localAddr;

        volatile bool _stop;

    };


}


#endif //VIRTUALLAN_CLIENT_H
