//
// Created by touwaerio on 2022/5/19.
//

#include <vl/core.h>


#include "service/RegisterServiceImpl.h"


using namespace grpc;


namespace vl::server {


    RegisterServiceImpl::RegisterServiceImpl(std::string ipStart, std::string ipEnd, int netmask) : _manager(
            std::pair<std::string, std::string>(ipStart, ipEnd)), _netmask(netmask) {

    }


    RegisterServiceImpl::~RegisterServiceImpl() {

    }

    grpc::Status
    RegisterServiceImpl::registe(::grpc::ServerContext *context, const ::vl::core::RegisterRequest *request,
                                 ::vl::core::RegisterResponse *response) {

        auto requestId = request->status().requestid();
        auto clientId = request->status().clientid();
        std::string peer = context->peer();

        auto ips = vl::core::split(peer, ":");
        auto clientHost = ips[1];
        auto clientPort = ips[2];
        auto status = std::make_unique<vl::core::ResponseCode>();
        status->set_clientid(clientId);
        status->set_requestid(requestId);
        status->set_allocated_message(new std::string("ok"));



        auto device = _manager.allocDevice();

        auto deviceCopy = make_unique<Device>();
        deviceCopy->CopyFrom(*device);
        deviceCopy->set_clientid(clientId);
        deviceCopy->set_publicip(vl::core::split(context->peer().c_str(),":")[1].c_str());
        deviceCopy->set_group("default");




        response->set_allocated_status(status.release());
        response->set_allocated_device(deviceCopy.release());

        return Status::OK;
    }



}

