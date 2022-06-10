//
// Created by touwaerio on 2022/5/20.
//

#ifndef VIRTUALLAN_UDPSOCKETSERVER_H
#define VIRTUALLAN_UDPSOCKETSERVER_H


#include "../SocketServer.h"


namespace vl::core {

    class UdpSocketServer : public SocketServer {

    private:

    public:

        UdpSocketServer(const std::string &ip, int port, int bufSize);

        UdpSocketServer(const sockaddr_in &bindAddress, int bufSize);

        UdpSocketServer(int port, int bufSize);

        void run() override;

        ~UdpSocketServer();


        virtual void onMessage(const sockaddr_in &peer, std::vector<char> buf, int len) override = 0;

        virtual void onConnect(const sockaddr_in &peer) {};

        virtual void onClose(const sockaddr_in &peer) {};

        virtual void onException(const sockaddr_in &peer, vl::core::VlSocketException e) override = 0;

        void shutDown(int ms = 0) override;

        void wait() override;

    private:
        sock_t serverSock;

        co::Event waiter;
    };


}


#endif //VIRTUALLAN_UDPSOCKETSERVER_H
