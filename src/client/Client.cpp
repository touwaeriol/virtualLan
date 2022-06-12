//
// Created by touwaerio on 2022/6/2.
//

#include "Client.h"
#include "TapDataHandler.h"

namespace vl::client {

    using namespace vl::core;
    using namespace std;


    Client::Client(const string &serverHost, int serverPort, int udpPort) : _grpcServerHost(serverHost),
                                                                            _grpcServerPort(serverPort),
                                                                            _udpPort(udpPort),
                                                                            _syncEvent(false, false),
                                                                            _request_id_generator(
                                                                                    RequestIdGenerator::defaultGenerator()) {}


    void Client::operator()() {
        start();
    }


    void Client::init() {
        DLOG << "创建通道";
        _channel = grpc::CreateChannel(_grpcServerHost + ":" + to_string(_grpcServerPort),
                                       grpc::InsecureChannelCredentials());
        DLOG << "创建注册 stub";
        _register_stub = make_shared<RegisterService::Stub>(_channel);
        DLOG << "初始化同步";
        _syncEvent.reset();
        DLOG << "初始化数据队列";
        _dataQueue = moodycamel::BlockingConcurrentQueue<vector<Byte>>(1024);
    }

    pair<bool, string> Client::start() {
        DLOG << "注册设备";
        RegisterRequest request;
        RegisterResponse response;
        request.set_allocated_status(newRequestCode().release());
        auto status = _register_stub->registe(&_context, request, &response);
        if (!status.ok()) {
            ELOG << "获取设备信息失败";
            return {false, "获取设备信息失败"};
        }
        DLOG << "得到设备信息";
        _device.CopyFrom(response.device());
        DLOG << "启用tap设备";
        _tap.name("vl-adapter0");
        _tap.ip(_device.ip(), static_cast<int>(_device.ipnetmask()));
        _tap.hwaddr(_device.mac());
        _tap.mtu(static_cast<int >(_device.mtu()));
        _tap.up();
        DLOG << "buf初始化";
        _buf.reserve(_device.mtu());
        _buf.resize(_device.mtu());
        DLOG << "开始转发tap设备";
        dataLoop();
        DLOG << "完成";
        return {true, ""};
    }

    void Client::wait() {
        _syncEvent.wait();
    }


    std::unique_ptr<RequestCode> Client::newRequestCode() {
        auto status = make_unique<RequestCode>();
        status->set_requestid(_request_id_generator.next());
        status->set_clientid(_device.clientid());
        return status;
    }

    void Client::dataLoop() {
        //专门的读取数据线程
        _dataReader = make_unique<Thread>([this]() -> void {
            size_t len;
            while (true) {
                len = this->_tap.read(this->_buf.data(), this->_buf.size());
                if (len == -1) {
                    auto errorCode = errno;
                    auto errorMessage = strerror(errorCode);
                    FLOG << "tap设备异常，socket发生错误 : error = " << errorCode << ", message = " << errorMessage;
                } else if (len == 0) {
                    FLOG << "tap 设备 EOF";
                } else {
                    auto data = vector<Byte>(len);
                    memcpy(data.data(), this->_buf.data(), len);
                    auto ok = _dataQueue.try_enqueue(std::move(data));
                    if (!ok) {
                        DLOG << "数据处理失败,丢失该数据 len = " << len;
                    }
                }
            }
        });
        _dataHandler = make_unique<Thread>([this]() -> void {
            while (true){
                auto data = vector<Byte>();
                _dataQueue.wait_dequeue(data);
                TapDataHandler handler(*this, move(data));
                co::go<TapDataHandler>(std::move(handler));
            }
        });
    }

    void Client::onReceiveData(vector<Byte> & data) {

    }


}




