
//
// Created by touwaerio on 2022/5/18.
//

#ifndef VIRTUALLAN_TESTSERVICEIMPL_H
#define VIRTUALLAN_TESTSERVICEIMPL_H

#include "core/core.h"

namespace  vl::server{
    class TestServiceImpl final : public vl::core::TestService::Service {


    public:
        ~TestServiceImpl() override;


        grpc::Status Hello(::grpc::ServerContext *context, const ::vl::core::Test_Request *request,
                           ::vl::core::Test_Response *response) override;

    };


}



#endif //VIRTUALLAN_TESTSERVICEIMPL_H
