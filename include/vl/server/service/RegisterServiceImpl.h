//
// Created by touwaerio on 2022/5/19.
//

#ifndef VIRTUALLAN_REGISTERSERVICEIMPL_H
#define VIRTUALLAN_REGISTERSERVICEIMPL_H


#include <mutex>

#include <vl/core.h>
#include "ethernet/EthernetAddressManager.h"

namespace vl::server {
    class Server;

}

namespace vl::server {


    class RegisterServiceImpl : public vl::core::RegisterService::Service {
        friend class Server;


    public:

        RegisterServiceImpl(std::string ipStart, std::string ipEnd, int netmask);

        RegisterServiceImpl(std::shared_ptr<EthernetAddressManager> _manager, int netmask);

        ~RegisterServiceImpl() override;

        grpc::Status registe(::grpc::ServerContext *context, const ::vl::core::RegisterRequest *request,
                             ::vl::core::RegisterResponse *response) override;

    private:

        std::shared_ptr<EthernetAddressManager> _manager;

        uint32_t _netmask;

        uint32_t mtu;

    };
}


#endif //VIRTUALLAN_REGISTERSERVICEIMPL_H
