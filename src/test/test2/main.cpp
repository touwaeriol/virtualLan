//
// Created by touwaerio on 2022/5/11.
//
#include "ping.grpc.pb.h"
#include "ping.pb.h"
#include <cstring>
#include <grpc++/grpc++.h>
#include <iostream>
#include <memory>
class PingServiceImpl final : public vl::Ping::Service {
public:
    ~PingServiceImpl() override {
    }
    ::grpc::Status ping(::grpc::ServerContext *context, const ::vl::PingRequest *request, ::vl::PingResponse *response) override {
        response->set_id("123445");

        return grpc::Status::OK;
    }
};


int main() {

    std::string listen = "0.0.0.0:50051";
    vl::Ping::Service service;
    grpc::ServerBuilder builder;
    builder.AddChannelArgument(GRPC_ARG_ALLOW_REUSEPORT, 1);
    builder.AddListeningPort("0.0.0.0:8080", grpc::InsecureServerCredentials());
    builder.RegisterService(&service);


    std::unique_ptr<grpc::Server> server = builder.BuildAndStart();



    grpc::ClientContext context;
    const std::shared_ptr<grpc::Channel> &channel= grpc::CreateChannel("localhost:8088", grpc::InsecureChannelCredentials());
    

    vl::Ping::Stub stub = vl::Ping::Stub(channel);
    vl::PingRequest request;
    vl::PingResponse response;

    const grpc::Status &status = stub.ping(&context, request, &response);
    if(!status.ok()){
        std::cout << "发送请求失败" << std::endl;
    }else{
        std::cout << "发送请求成功" << std::endl;
    }


    return 0;
}