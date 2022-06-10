//
// Created by touwaerio on 2022/5/19.
//

#ifndef VIRTUALLAN_REGISTERSERVICEIMPL_H
#define VIRTUALLAN_REGISTERSERVICEIMPL_H


#include <mutex>

#include <vl/core.h>
#include "ethernet/EthernetAddressManager.h"

namespace vl::server{

    class RegisterServiceImpl :public vl::core::RegisterService::Service{


    public:

        RegisterServiceImpl(std::string ipStart,std::string ipEnd,int netmask);

        ~RegisterServiceImpl() override;

        grpc::Status registe(::grpc::ServerContext *context, const ::vl::core::RegisterRequest *request,
                              ::vl::core::RegisterResponse *response) override;

    private:
        std::mutex _mutex;

        EthernetAddressManager _manager;

        uint32 _netmask;

        uint32  mtu;

    };
}



#endif //VIRTUALLAN_REGISTERSERVICEIMPL_H
