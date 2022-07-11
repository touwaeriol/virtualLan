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
            size_t receivedUdpDataQueueCap,
            size_t waitSendUdpDataQueueCap,
            const string &tapName
    ) : _grpcServerHost(
            serverHost),
        _grpcServerPort(
                serverPort),
        _udpPort(
                udpPort),
        _request_id_generator(),
        _tapDataQueue(
                moodycamel::BlockingReaderWriterCircularBuffer<vector<Byte>>

                        (
                                dataQueueCap)),

        _receivedUdpDataQueue(
                moodycamel::BlockingReaderWriterCircularBuffer<vl::core::EtherData>(
                        receivedUdpDataQueueCap)),
        _waitSendUdpDataQueue(
                moodycamel::BlockingConcurrentQueue<vl::core::EtherData>(
                        waitSendUdpDataQueueCap)),
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
        auto serverAddress = fmt::format("{}:{}", _grpcServerHost, _grpcServerPort);
        _channel = grpc::CreateChannel(serverAddress,
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
        gpr_timespec timeOut = gpr_time_from_seconds(5, GPR_TIMESPAN);
        DLOG("等待channel 连接grp远程服务器连接");
        auto ok = _channel->WaitForConnected<gpr_timespec>(gpr_timespec(timeOut));
        if (!ok) {
            auto msg = "channel连接远程服务器失败";
            ELOG(msg);
            return {false, msg};
        }
        auto status = _register_stub->registe(&_context, request, &response);
        if (!status.ok()) {
            auto msg = fmt::format("获取设备信息失败: code = {} , message = {}", status.error_code(),
                                   status.error_message());
            ELOG(msg);
            return {false, msg};
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
        boost::system::error_code error;
        DLOG("udp 打开socket");
        _udpSock->open(boost::asio::ip::udp::v4(), error);
        if (error) {
            auto msg = fmt::format("打开socket失败:{}", error.message());
            CLOG(msg);
            return {false, msg};
        }
        DLOG("UDP绑定本地端口服务");
        _udpSock->bind(_localAddr, error);
        if (error) {
            auto msg = fmt::format("绑定本地端口失败:{}", error.message());
            CLOG(fmt::format("绑定本地端口失败:{}", error.message()));
            return {false, msg};
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
                vector<Byte> data;
                data.resize(mtu);
                len = this->_tap->read(data.data(), data.size());
                //长度与实际长度一致
                data.resize(len);
                if (len == -1) {
                    WLOG("tap设备异常，socket发生错误");
                } else if (len == 0) {
                    WLOG("tap 设备 EOF");
                } else {
                    auto ok = _tapDataQueue.try_enqueue(std::move(data));
                    if (!ok) {
                        DLOG("tap数据处理失败,丢失该数据 len = " + to_string(len));
                    }
                    DLOG(fmt::format("tap数据 len = {},已加入队列", len));
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
                async::spawn([this, data(std::move(data))]() -> void {
                    //处理数据
                    this->onReadTapData(data);
                });
            }
        });
        //发送udp数据
        _udpDataSender = make_unique<std::thread>([this]() -> void {
            boost::system::error_code error;
            EtherData data{};
            while (true) {
                if (this->_stop) {
                    break;
                }
                _waitSendUdpDataQueue.wait_dequeue(data);
                auto buf = boost::asio::buffer(data._content);
                auto len = _udpSock->send_to(buf, data._peer, 0, error);
                if (error) {
                    WLOG(fmt::format("udp 数据发送失败 ，剩余等待发送的数据：{}" , _waitSendUdpDataQueue.size_approx()));
                } else {
                    WLOG(fmt::format("udp 数据发送成功，size = {},len = {},剩余待发数据 {}", data._content.size(), len,_waitSendUdpDataQueue.size_approx()));
                }
            }
        });
        //处理接收到的udp数据，放入到队列中
        _udpDataReceiver = make_unique<std::thread>([this]() -> void {
            boost::system::error_code error;
            while (true) {
                if (this->_stop) {
                    break;
                }
                EtherData data{};
                data._content.resize(_device.mtu());
                auto buf = boost::asio::buffer(data._content);
                _udpSock->wait(boost::asio::ip::udp::socket::wait_read);
                auto len = _udpSock->receive_from(buf, data._peer, 0, error);
                data._content.resize(len);
                if (error) {
                    DLOG(string("udp数据获取失败:") + error.message());
                }
                auto ok = _receivedUdpDataQueue.try_enqueue(std::move(data));
                if (!ok) {
                    WLOG(fmt::format("udp 数据队列已满: {}", len));
                } else {
                    DLOG(fmt::format("udp 数据接收成功: {}", len));
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
                _receivedUdpDataQueue.wait_dequeue(data);
                async::spawn([this, data(std::move(data))]() -> void {
                    DLOG(fmt::format("udp数据 处理： size = {}", data._content.size()));
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
                auto ok = _waitSendUdpDataQueue.try_enqueue(EtherData{
                        ._content =  HEART_BEAT_PACKAGE,
                        ._peer = _serverAddr
                });
                if (!ok) {
                    WLOG(fmt::format("udp 等待发送的数据加入队列失败 len = {}",HEART_BEAT_PACKAGE.size()));
                }else{
                    DLOG(fmt::format("udp 等待发送的数据加入队列成功 len = {}",HEART_BEAT_PACKAGE.size()))
                }
                std::this_thread::sleep_for(5s);
            }
        });
    }


    void Client::onReadTapData(const vector<Byte> &data) {
        auto ok = _waitSendUdpDataQueue.try_enqueue(EtherData{
                ._content =  std::move(data),
                ._peer = _serverAddr
        });
        if (!ok) {
            WLOG(fmt::format("udp 等待发送的数据加入队列失败: size = {}",_waitSendUdpDataQueue.size_approx()));
        }else{
            DLOG(fmt::format("udp 等待发送的数据加入队列成功"))
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

    void Client::sendUdpToServer(const vector<Byte> &data) {
        auto asiBuf = boost::asio::buffer(data);
        boost::system::error_code error;
        _udpSock->wait(boost::asio::ip::udp::socket::wait_write, error);
        if (error) {
            CLOG(std::string("udp 等待写数据失败: message = ") + error.message());
        }
        auto len = _udpSock->send_to(asiBuf, _serverAddr, 0, error);
        if (error) {
            CLOG(fmt::format("udp 数据传输失败: message = {}", error.message()));
        } else if (len != data.size()) {
            DLOG(fmt::format("udp 数据一共 {}{}{}{}{}", data.size(), "字节", " ,发送了", len, "字节"));
        } else {
            DLOG(fmt::format("udp 转发数据完成 {}:{}", _serverAddr.address().to_string(), _serverAddr.port()));
        }
    }


}




