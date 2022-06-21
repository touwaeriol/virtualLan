//
// Created by touwaerio on 2022/6/2.
//

#include "Client.h"

#include <utility>


namespace vl::client {

    using namespace vl::core;
    using namespace std;


    Client::Client(const string &serverHost, int serverPort, int udpPort, size_t dataQueueCap,
                   const string &tapName) : _grpcServerHost(
            serverHost),
                                            _grpcServerPort(
                                                    serverPort),
                                            _udpPort(
                                                    udpPort),
                                            _syncEvent(false,
                                                       false),
                                            _request_id_generator(
                                                    RequestIdGenerator::defaultGenerator()),
                                            _dataQueue(
                                                    moodycamel::BlockingReaderWriterCircularBuffer<std::unique_ptr<vector<Byte>>>(
                                                            dataQueueCap)),
                                            _tapName(
                                                    tapName) {
    }

    Client::~Client() {
        co::shutdown(_sock);
    }

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
        DLOG << "初始化socket地址";
        auto ok = co::init_ip_addr(&_serverAddr, _grpcServerHost.c_str(), _grpcServerPort);
        if (!ok) {
            FLOG << "初始化服务器 udp地址 失败";
        }
        ok = co::init_ip_addr(&_localAddr, "0.0.0.0", _udpPort);
        if (!ok) {
            FLOG << "初始化本地 udp地址 失败";
        }
        DLOG << "创建sock";
        _udpSock = asio::ip::udp::socket(_udpContext);
        _localAddr = asio::ip::udp::endpoint(asio::ip::make_address("0.0.0.0"), _udpPort);
        _serverAddr = asio::ip::udp::endpoint(asio::ip::make_address(_grpcServerHost), _grpcServerPort);

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
        DLOG << "UDP绑定本地端口服务";
        asio::error_code errorCode;
        _udpSock.bind(_localAddr, errorCode);
        if (!errorCode) {
            FLOG << "绑带本地端口失败";
        }
        DLOG << "转发tap设备的流量";
        loopUdpData();
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

    void Client::loopUdpData() {
        //专门的读取数据线程
        _dataReader = make_unique<std::thread>([this]() -> void {
            size_t len;
            auto mtu = this->_device.mtu();
            while (true) {
                auto data = std::make_unique<vector<Byte>>();
                data->resize(mtu);
                len = this->_tap.read(data->data(), data->size());
                if (len == -1) {
                    auto errorCode = errno;
                    auto errorMessage = strerror(errorCode);
                    FLOG << "tap设备异常，socket发生错误 : error = " << errorCode << ", message = " << errorMessage;
                } else if (len == 0) {
                    FLOG << "tap 设备 EOF";
                } else {
                    //长度与实际长度一致
                    if (data->size() != len) {
                        data->resize(len);
                    }
                    auto ok = _dataQueue.try_enqueue(std::move(data));
                    if (!ok) {
                        DLOG << "数据处理失败,丢失该数据 len = " << len;
                    }
                    DLOG << "收到数据,已加入队列";
                }
            }
        });
        //处理数据的线程
        _dataHandler = make_unique<std::thread>([this]() -> void {
            while (true) {
                auto data = std::make_unique<vector<Byte>>();
                _dataQueue.wait_dequeue(data);
                co::go([this, data{move(data)}]() mutable -> void {
                    //处理数据
                    this->onReceiveData(*data);
                });
            }
        });
        //循环发送心跳数据包（一个字节的数据包为心跳数据包）
        vl::core::co([this]() -> void {
            while (true) {
                auto buf = asio::buffer(HEART_BEAT_PACKAGE);
                asio::error_code errorCode;
                auto len = _udpSock.send_to(buf, _serverAddr, 0, errorCode);
                if (errorCode) {
                    FLOG << "数据传输失败";
                } else if (len != HEART_BEAT_PACKAGE.size()) {
                    DLOG << "数据一共 " << HEART_BEAT_PACKAGE.size() << "字节" << " ,发送了" << len << "字节";
                }
                co::sleep(1000);
            }
        });
    }


    void Client::onReceiveData(const vector<Byte> &data) {
        auto buf = asio::buffer(data);
        asio::error_code errorCode;
        auto len = _udpSock.send_to(buf, _serverAddr, 0, errorCode);
        if (!errorCode) {
            FLOG << "数据传输失败";
        } else if (len != data.size()) {
            DLOG << "数据一共 " << data.size() << "字节" << " ,发送了" << len << "字节";
        } else {
            DLOG << "转发数据完成";
        }
    }


    void Client::setTapName(const string &tapName) {
        _tapName = tapName;
    }


}




