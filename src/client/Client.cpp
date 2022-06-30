//
// Created by touwaerio on 2022/6/2.
//

#include "Client.h"

#include <utility>


namespace vl::client {

    using namespace vl::core;
    using namespace std;


    Client::Client(
            const string &serverHost,
            int serverPort,
            int udpPort,
            size_t dataQueueCap,
            size_t udpQueueData,
            const string &tapName
    ) : _grpcServerHost(
            serverHost),
        _grpcServerPort(
                serverPort),
        _udpPort(
                udpPort),
        _request_id_generator(),
        _tapDataQueue(
                moodycamel::BlockingReaderWriterCircularBuffer<vector < Byte>>

    (
    dataQueueCap)),

    _udpDataQueue (
    moodycamel::BlockingReaderWriterCircularBuffer<vl::core::EtherData>(
            udpQueueData)),
    _tapName(
            tapName),
    _stop(false) {
    }

    Client::~Client() {
        _stop = true;
        _udpSock->close();
        wait();
    }

    void Client::operator()() {
        start();
    }


    void Client::init() {
        DLOG("创建通道");
        _channel = grpc::CreateChannel(_grpcServerHost + ":" + to_string(_grpcServerPort),
                                       grpc::InsecureChannelCredentials());
        DLOG("创建注册 stub");
        _register_stub = make_shared<RegisterService::Stub>(_channel);
        DLOG("初始化socket地址");
        _serverAddr = boost::asio::ip::udp::endpoint(boost::asio::ip::make_address(_grpcServerHost), _grpcServerPort);
        _localAddr = boost::asio::ip::udp::endpoint(boost::asio::ip::make_address("0.0.0.0"), _udpPort);
        DLOG("创建sock");
        _udpSock = std::make_unique<boost::asio::ip::udp::socket>(_udpContext);

    }

    pair<bool, string> Client::start() {
        DLOG("注册设备");
        RegisterRequest request;
        RegisterResponse response;
        request.set_allocated_status(newRequestCode().release());
        auto status = _register_stub->registe(&_context, request, &response);
        if (!status.ok()) {
            ELOG("获取设备信息失败");
            return {false, "获取设备信息失败"};
        }
        DLOG("得到设备信息");
        _device.CopyFrom(response.device());
        DLOG("启用tap设备");
        _tap = std::make_shared<Tap>();
        _tap->name(_tapName);
        _tap->ip(_device.ip(), static_cast<int>(_device.ipnetmask()));
        _tap->hwaddr(_device.mac());
        _tap->mtu(static_cast<int >(_device.mtu()));
        _tap->up();
        assert(_tap->name() == _tapName);
        DLOG("打开socket")
        _udpSock->open(boost::asio::ip::udp::v4());
        DLOG("UDP绑定本地端口服务");
        boost::system::error_code error;
        _udpSock->bind(_localAddr, error);
        if (!error) {
            CLOG("绑定本地端口失败");
        }
        _udpSock->open(boost::asio::ip::udp::v4(), error);
        if (!error) {
            CLOG("打开socket失败");
        }
        DLOG("转发tap设备的流量");
        loopUdpData();
        DLOG("完成");
        return {true, ""};
    }

    void Client::wait() {
        _tapDataReader->join();
        _tapDataHandler->join();
        _udpDataReceiver->join();
        _udpDataHandler->join();
        _beatHearthThread->join();
    }


    std::unique_ptr<RequestCode> Client::newRequestCode() {
        auto status = make_unique<RequestCode>();
        status->set_requestid(_request_id_generator.next());
        status->set_clientid(_device.clientid());
        return status;
    }

    void Client::loopUdpData() {
        //从tap读取数据
        _tapDataReader = make_unique<std::thread>([this]() -> void {
            size_t len;
            auto mtu = this->_device.mtu();
            while (true) {
                if (this->_stop) {
                    break;
                }
                vector <Byte> data;
                data.resize(mtu);
                len = this->_tap->read(data.data(), data.size());
                if (len == -1) {
                    CLOG("tap设备异常，socket发生错误");
                } else if (len == 0) {
                    CLOG("tap 设备 EOF");
                } else {
                    //长度与实际长度一致
                    if (data.size() != len) {
                        data.resize(len);
                    }
                    auto ok = _tapDataQueue.try_enqueue(std::move(data));
                    if (!ok) {
                        DLOG("数据处理失败,丢失该数据 len = " + to_string(len));
                    }
                    DLOG(fmt::format("数据 len = {},已加入队列", len));
                }
            }
        });
        //处理从tap读取到的数据，通过udp发送出去
        _tapDataHandler = make_unique<std::thread>([this]() -> void {
            while (true) {
                if (this->_stop) {
                    break;
                }
                auto data = vector<Byte>();
                _tapDataQueue.wait_dequeue(data);
                auto f = [this, data(std::move(data))]() -> void {
                    //处理数据
                    this->onReadTapData(data);
                };
                vl::core::co(f);
            }
        });
        //处理接收到的udp数据，写入到tap
        _udpDataReceiver = make_unique<std::thread>([this]() -> void {
            boost::system::error_code errorCode;
            while (true) {
                if (this->_stop) {
                    break;
                }
                EtherData data{};
                data._content.resize(_device.mtu());
                auto buf = boost::asio::buffer(data._content);
                _udpSock->wait(boost::asio::ip::udp::socket::wait_read);
                auto len = _udpSock->receive_from(buf, data._peer, 0, errorCode);
                if (!errorCode) {
                    DLOG(string("获取udp数据失败:") + errorCode.message());
                }
                data._content.resize(len);
                auto ok = _udpDataQueue.try_enqueue(std::move(data));
                if (!ok) {
                    WLOG("udp数据队列已满: " + to_string(len));
                } else {
                    DLOG("接收udp数据成功: " + to_string(len));
                }
            }
        });
        //专门处理收到的udp数据
        _udpDataHandler = make_unique<std::thread>([this]() -> void {
            while (true) {
                if (this->_stop) {
                    break;
                }
                EtherData data{};
                _udpDataQueue.wait_dequeue(data);
                vl::core::co([this, data(move(data))]() -> void {
                    DLOG("处理udp数据： size = " + to_string(data._content.size()));
                    this->onReceiveUdpData(data);
                });
            }
        });
        //循环发送心跳数据包（一个字节的数据包为心跳数据包）
        _beatHearthThread = make_unique<std::thread>([this]() -> void {
            while (true) {
                if (this->_stop) {
                    break;
                }
                vector <Byte> bytes{};
                bytes = HEART_BEAT_PACKAGE;
                _tapDataQueue.try_enqueue(std::move(bytes));
                std::this_thread::sleep_for(5s);
            }
        });
    }


    void Client::onReadTapData(const vector <Byte> &data) {
        auto buf = boost::asio::buffer(data);
        boost::system::error_code error;
        _udpSock->wait(boost::asio::ip::udp::socket::wait_write, error);
        if (error) {
            CLOG(std::string("等待写数据失败: message = ") + error.message());
        }
        auto len = _udpSock->send_to(buf, _serverAddr, 0, error);
        if (error) {
            CLOG(fmt::format("数据传输失败: message = {}", error.message()));
        } else if (len != data.size()) {
            DLOG(std::string("数据一共 ") + to_string(data.size()) + "字节" + " ,发送了" + to_string(len) + "字节");
        } else {
            DLOG("转发数据完成");
        }
    }


    void Client::onReceiveUdpData(const vl::core::EtherData &data) {
        if (data._content.size() < 42) {
            //不是tap数据，忽略
        } else {
            _tap->write(static_cast<void *>(const_cast<Byte * >(data._content.data())), data._content.size());
        }
    }

    void Client::setTapName(const string &tapName) {
        _tapName = tapName;
    }


}




