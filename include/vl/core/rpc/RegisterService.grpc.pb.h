// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: RegisterService.proto
#ifndef GRPC_RegisterService_2eproto__INCLUDED
#define GRPC_RegisterService_2eproto__INCLUDED

#include "RegisterService.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace vl {
    namespace core {

        class RegisterService final {
        public:
            static constexpr char const *service_full_name() {
                return "vl.core.RegisterService";
            }

            class StubInterface {
            public:
                virtual ~StubInterface() {}

                // *
                // 注册设备
                virtual ::grpc::Status
                registe(::grpc::ClientContext *context, const ::vl::core::RegisterRequest &request,
                        ::vl::core::RegisterResponse *response) = 0;

                std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::vl::core::RegisterResponse>>
                Asyncregiste(::grpc::ClientContext *context, const ::vl::core::RegisterRequest &request,
                             ::grpc::CompletionQueue *cq) {
                    return std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::vl::core::RegisterResponse>>(
                            AsyncregisteRaw(context, request, cq));
                }

                std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::vl::core::RegisterResponse>>
                PrepareAsyncregiste(::grpc::ClientContext *context, const ::vl::core::RegisterRequest &request,
                                    ::grpc::CompletionQueue *cq) {
                    return std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::vl::core::RegisterResponse>>(
                            PrepareAsyncregisteRaw(context, request, cq));
                }

                // *
                // 注销设备
                virtual ::grpc::Status cancel(::grpc::ClientContext *context, const ::vl::core::CancelRequest &request,
                                              ::vl::core::CancelResponse *response) = 0;

                std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::vl::core::CancelResponse>>
                Asynccancel(::grpc::ClientContext *context, const ::vl::core::CancelRequest &request,
                            ::grpc::CompletionQueue *cq) {
                    return std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::vl::core::CancelResponse>>(
                            AsynccancelRaw(context, request, cq));
                }

                std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::vl::core::CancelResponse>>
                PrepareAsynccancel(::grpc::ClientContext *context, const ::vl::core::CancelRequest &request,
                                   ::grpc::CompletionQueue *cq) {
                    return std::unique_ptr<::grpc::ClientAsyncResponseReaderInterface<::vl::core::CancelResponse>>(
                            PrepareAsynccancelRaw(context, request, cq));
                }

                class async_interface {
                public:
                    virtual ~async_interface() {}

                    // *
                    // 注册设备
                    virtual void registe(::grpc::ClientContext *context, const ::vl::core::RegisterRequest *request,
                                         ::vl::core::RegisterResponse *response,
                                         std::function<void(::grpc::Status)>) = 0;

                    virtual void registe(::grpc::ClientContext *context, const ::vl::core::RegisterRequest *request,
                                         ::vl::core::RegisterResponse *response,
                                         ::grpc::ClientUnaryReactor *reactor) = 0;

                    // *
                    // 注销设备
                    virtual void cancel(::grpc::ClientContext *context, const ::vl::core::CancelRequest *request,
                                        ::vl::core::CancelResponse *response, std::function<void(::grpc::Status)>) = 0;

                    virtual void cancel(::grpc::ClientContext *context, const ::vl::core::CancelRequest *request,
                                        ::vl::core::CancelResponse *response, ::grpc::ClientUnaryReactor *reactor) = 0;
                };

                typedef class async_interface experimental_async_interface;

                virtual class async_interface *async() { return nullptr; }

                class async_interface *experimental_async() { return async(); }

            private:
                virtual ::grpc::ClientAsyncResponseReaderInterface<::vl::core::RegisterResponse> *
                AsyncregisteRaw(::grpc::ClientContext *context, const ::vl::core::RegisterRequest &request,
                                ::grpc::CompletionQueue *cq) = 0;

                virtual ::grpc::ClientAsyncResponseReaderInterface<::vl::core::RegisterResponse> *
                PrepareAsyncregisteRaw(::grpc::ClientContext *context, const ::vl::core::RegisterRequest &request,
                                       ::grpc::CompletionQueue *cq) = 0;

                virtual ::grpc::ClientAsyncResponseReaderInterface<::vl::core::CancelResponse> *
                AsynccancelRaw(::grpc::ClientContext *context, const ::vl::core::CancelRequest &request,
                               ::grpc::CompletionQueue *cq) = 0;

                virtual ::grpc::ClientAsyncResponseReaderInterface<::vl::core::CancelResponse> *
                PrepareAsynccancelRaw(::grpc::ClientContext *context, const ::vl::core::CancelRequest &request,
                                      ::grpc::CompletionQueue *cq) = 0;
            };

            class Stub final : public StubInterface {
            public:
                Stub(const std::shared_ptr<::grpc::ChannelInterface> &channel,
                     const ::grpc::StubOptions &options = ::grpc::StubOptions());

                ::grpc::Status registe(::grpc::ClientContext *context, const ::vl::core::RegisterRequest &request,
                                       ::vl::core::RegisterResponse *response) override;

                std::unique_ptr<::grpc::ClientAsyncResponseReader<::vl::core::RegisterResponse>>
                Asyncregiste(::grpc::ClientContext *context, const ::vl::core::RegisterRequest &request,
                             ::grpc::CompletionQueue *cq) {
                    return std::unique_ptr<::grpc::ClientAsyncResponseReader<::vl::core::RegisterResponse>>(
                            AsyncregisteRaw(context, request, cq));
                }

                std::unique_ptr<::grpc::ClientAsyncResponseReader<::vl::core::RegisterResponse>>
                PrepareAsyncregiste(::grpc::ClientContext *context, const ::vl::core::RegisterRequest &request,
                                    ::grpc::CompletionQueue *cq) {
                    return std::unique_ptr<::grpc::ClientAsyncResponseReader<::vl::core::RegisterResponse>>(
                            PrepareAsyncregisteRaw(context, request, cq));
                }

                ::grpc::Status cancel(::grpc::ClientContext *context, const ::vl::core::CancelRequest &request,
                                      ::vl::core::CancelResponse *response) override;

                std::unique_ptr<::grpc::ClientAsyncResponseReader<::vl::core::CancelResponse>>
                Asynccancel(::grpc::ClientContext *context, const ::vl::core::CancelRequest &request,
                            ::grpc::CompletionQueue *cq) {
                    return std::unique_ptr<::grpc::ClientAsyncResponseReader<::vl::core::CancelResponse>>(
                            AsynccancelRaw(context, request, cq));
                }

                std::unique_ptr<::grpc::ClientAsyncResponseReader<::vl::core::CancelResponse>>
                PrepareAsynccancel(::grpc::ClientContext *context, const ::vl::core::CancelRequest &request,
                                   ::grpc::CompletionQueue *cq) {
                    return std::unique_ptr<::grpc::ClientAsyncResponseReader<::vl::core::CancelResponse>>(
                            PrepareAsynccancelRaw(context, request, cq));
                }

                class async final :
                        public StubInterface::async_interface {
                public:
                    void registe(::grpc::ClientContext *context, const ::vl::core::RegisterRequest *request,
                                 ::vl::core::RegisterResponse *response, std::function<void(::grpc::Status)>) override;

                    void registe(::grpc::ClientContext *context, const ::vl::core::RegisterRequest *request,
                                 ::vl::core::RegisterResponse *response, ::grpc::ClientUnaryReactor *reactor) override;

                    void cancel(::grpc::ClientContext *context, const ::vl::core::CancelRequest *request,
                                ::vl::core::CancelResponse *response, std::function<void(::grpc::Status)>) override;

                    void cancel(::grpc::ClientContext *context, const ::vl::core::CancelRequest *request,
                                ::vl::core::CancelResponse *response, ::grpc::ClientUnaryReactor *reactor) override;

                private:
                    friend class Stub;

                    explicit async(Stub *stub) : stub_(stub) {}

                    Stub *stub() { return stub_; }

                    Stub *stub_;
                };

                class async *async() override { return &async_stub_; }

            private:
                std::shared_ptr<::grpc::ChannelInterface> channel_;

                class async async_stub_{this};

                ::grpc::ClientAsyncResponseReader<::vl::core::RegisterResponse> *
                AsyncregisteRaw(::grpc::ClientContext *context, const ::vl::core::RegisterRequest &request,
                                ::grpc::CompletionQueue *cq) override;

                ::grpc::ClientAsyncResponseReader<::vl::core::RegisterResponse> *
                PrepareAsyncregisteRaw(::grpc::ClientContext *context, const ::vl::core::RegisterRequest &request,
                                       ::grpc::CompletionQueue *cq) override;

                ::grpc::ClientAsyncResponseReader<::vl::core::CancelResponse> *
                AsynccancelRaw(::grpc::ClientContext *context, const ::vl::core::CancelRequest &request,
                               ::grpc::CompletionQueue *cq) override;

                ::grpc::ClientAsyncResponseReader<::vl::core::CancelResponse> *
                PrepareAsynccancelRaw(::grpc::ClientContext *context, const ::vl::core::CancelRequest &request,
                                      ::grpc::CompletionQueue *cq) override;

                const ::grpc::internal::RpcMethod rpcmethod_registe_;
                const ::grpc::internal::RpcMethod rpcmethod_cancel_;
            };

            static std::unique_ptr<Stub> NewStub(const std::shared_ptr<::grpc::ChannelInterface> &channel,
                                                 const ::grpc::StubOptions &options = ::grpc::StubOptions());

            class Service : public ::grpc::Service {
            public:
                Service();

                virtual ~Service();

                // *
                // 注册设备
                virtual ::grpc::Status
                registe(::grpc::ServerContext *context, const ::vl::core::RegisterRequest *request,
                        ::vl::core::RegisterResponse *response);

                // *
                // 注销设备
                virtual ::grpc::Status cancel(::grpc::ServerContext *context, const ::vl::core::CancelRequest *request,
                                              ::vl::core::CancelResponse *response);
            };

            template<class BaseClass>
            class WithAsyncMethod_registe : public BaseClass {
            private:
                void BaseClassMustBeDerivedFromService(const Service *
                service
                ) {}

            public:
                WithAsyncMethod_registe() {
                    ::grpc::Service::MarkMethodAsync(0);
                }

                ~WithAsyncMethod_registe() override {
                    BaseClassMustBeDerivedFromService(this);
                }

                // disable synchronous version of this method
                ::grpc::Status
                registe(::grpc::ServerContext *
                context, const ::vl::core::RegisterRequest *
                request,
                        ::vl::core::RegisterResponse *
                        response
                ) override {
                    abort();
                    return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
                }

                void Requestregiste(::grpc::ServerContext *context, ::vl::core::RegisterRequest *request,
                                    ::grpc::ServerAsyncResponseWriter<::vl::core::RegisterResponse> *response,
                                    ::grpc::CompletionQueue *new_call_cq,
                                    ::grpc::ServerCompletionQueue *notification_cq, void *tag) {
                    ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq,
                                                       tag);
                }
            };

            template<class BaseClass>
            class WithAsyncMethod_cancel : public BaseClass {
            private:
                void BaseClassMustBeDerivedFromService(const Service *
                service
                ) {}

            public:
                WithAsyncMethod_cancel() {
                    ::grpc::Service::MarkMethodAsync(1);
                }

                ~WithAsyncMethod_cancel() override {
                    BaseClassMustBeDerivedFromService(this);
                }

                // disable synchronous version of this method
                ::grpc::Status
                cancel(::grpc::ServerContext *
                context, const ::vl::core::CancelRequest *
                request,
                       ::vl::core::CancelResponse *
                       response
                ) override {
                    abort();
                    return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
                }

                void Requestcancel(::grpc::ServerContext *context, ::vl::core::CancelRequest *request,
                                   ::grpc::ServerAsyncResponseWriter<::vl::core::CancelResponse> *response,
                                   ::grpc::CompletionQueue *new_call_cq, ::grpc::ServerCompletionQueue *notification_cq,
                                   void *tag) {
                    ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq,
                                                       tag);
                }
            };

            typedef WithAsyncMethod_registe<WithAsyncMethod_cancel<Service> > AsyncService;

            template<class BaseClass>
            class WithCallbackMethod_registe : public BaseClass {
            private:
                void BaseClassMustBeDerivedFromService(const Service *
                service
                ) {}

            public:
                WithCallbackMethod_registe() {
                    ::grpc::Service::MarkMethodCallback(0,
                                                        new ::grpc::internal::CallbackUnaryHandler<::vl::core::RegisterRequest, ::vl::core::RegisterResponse>(
                                                                [this](
                                                                        ::grpc::CallbackServerContext *context,
                                                                        const ::vl::core::RegisterRequest *request,
                                                                        ::vl::core::RegisterResponse *response) {
                                                                    return this->registe(context, request, response);
                                                                }));
                }

                void SetMessageAllocatorFor_registe(
                        ::grpc::MessageAllocator<::vl::core::RegisterRequest, ::vl::core::RegisterResponse> *allocator) {
                    ::grpc::internal::MethodHandler *const handler = ::grpc::Service::GetHandler(0);
                    static_cast<::grpc::internal::CallbackUnaryHandler<::vl::core::RegisterRequest, ::vl::core::RegisterResponse> *>(handler)
                            ->SetMessageAllocator(allocator);
                }

                ~WithCallbackMethod_registe() override {
                    BaseClassMustBeDerivedFromService(this);
                }

                // disable synchronous version of this method
                ::grpc::Status
                registe(::grpc::ServerContext *
                context, const ::vl::core::RegisterRequest *
                request,
                        ::vl::core::RegisterResponse *
                        response
                ) override {
                    abort();
                    return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
                }

                virtual ::grpc::ServerUnaryReactor *registe(
                        ::grpc::CallbackServerContext *
                        context, const ::vl::core::RegisterRequest *
                request,
                        ::vl::core::RegisterResponse *
                        response
                ) { return nullptr; }
            };

            template<class BaseClass>
            class WithCallbackMethod_cancel : public BaseClass {
            private:
                void BaseClassMustBeDerivedFromService(const Service *
                service
                ) {}

            public:
                WithCallbackMethod_cancel() {
                    ::grpc::Service::MarkMethodCallback(1,
                                                        new ::grpc::internal::CallbackUnaryHandler<::vl::core::CancelRequest, ::vl::core::CancelResponse>(
                                                                [this](
                                                                        ::grpc::CallbackServerContext *context,
                                                                        const ::vl::core::CancelRequest *request,
                                                                        ::vl::core::CancelResponse *response) {
                                                                    return this->cancel(context, request, response);
                                                                }));
                }

                void SetMessageAllocatorFor_cancel(
                        ::grpc::MessageAllocator<::vl::core::CancelRequest, ::vl::core::CancelResponse> *allocator) {
                    ::grpc::internal::MethodHandler *const handler = ::grpc::Service::GetHandler(1);
                    static_cast<::grpc::internal::CallbackUnaryHandler<::vl::core::CancelRequest, ::vl::core::CancelResponse> *>(handler)
                            ->SetMessageAllocator(allocator);
                }

                ~WithCallbackMethod_cancel() override {
                    BaseClassMustBeDerivedFromService(this);
                }

                // disable synchronous version of this method
                ::grpc::Status
                cancel(::grpc::ServerContext *
                context, const ::vl::core::CancelRequest *
                request,
                       ::vl::core::CancelResponse *
                       response
                ) override {
                    abort();
                    return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
                }

                virtual ::grpc::ServerUnaryReactor *cancel(
                        ::grpc::CallbackServerContext *
                        context, const ::vl::core::CancelRequest *
                request,
                        ::vl::core::CancelResponse *
                        response
                ) { return nullptr; }
            };

            typedef WithCallbackMethod_registe<WithCallbackMethod_cancel<Service> > CallbackService;
            typedef CallbackService ExperimentalCallbackService;

            template<class BaseClass>
            class WithGenericMethod_registe : public BaseClass {
            private:
                void BaseClassMustBeDerivedFromService(const Service *
                service
                ) {}

            public:
                WithGenericMethod_registe() {
                    ::grpc::Service::MarkMethodGeneric(0);
                }

                ~WithGenericMethod_registe() override {
                    BaseClassMustBeDerivedFromService(this);
                }

                // disable synchronous version of this method
                ::grpc::Status
                registe(::grpc::ServerContext *
                context, const ::vl::core::RegisterRequest *
                request,
                        ::vl::core::RegisterResponse *
                        response
                ) override {
                    abort();
                    return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
                }
            };

            template<class BaseClass>
            class WithGenericMethod_cancel : public BaseClass {
            private:
                void BaseClassMustBeDerivedFromService(const Service *
                service
                ) {}

            public:
                WithGenericMethod_cancel() {
                    ::grpc::Service::MarkMethodGeneric(1);
                }

                ~WithGenericMethod_cancel() override {
                    BaseClassMustBeDerivedFromService(this);
                }

                // disable synchronous version of this method
                ::grpc::Status
                cancel(::grpc::ServerContext *
                context, const ::vl::core::CancelRequest *
                request,
                       ::vl::core::CancelResponse *
                       response
                ) override {
                    abort();
                    return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
                }
            };

            template<class BaseClass>
            class WithRawMethod_registe : public BaseClass {
            private:
                void BaseClassMustBeDerivedFromService(const Service *
                service
                ) {}

            public:
                WithRawMethod_registe() {
                    ::grpc::Service::MarkMethodRaw(0);
                }

                ~WithRawMethod_registe() override {
                    BaseClassMustBeDerivedFromService(this);
                }

                // disable synchronous version of this method
                ::grpc::Status
                registe(::grpc::ServerContext *
                context, const ::vl::core::RegisterRequest *
                request,
                        ::vl::core::RegisterResponse *
                        response
                ) override {
                    abort();
                    return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
                }

                void Requestregiste(::grpc::ServerContext *context, ::grpc::ByteBuffer *request,
                                    ::grpc::ServerAsyncResponseWriter<::grpc::ByteBuffer> *response,
                                    ::grpc::CompletionQueue *new_call_cq,
                                    ::grpc::ServerCompletionQueue *notification_cq, void *tag) {
                    ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq,
                                                       tag);
                }
            };

            template<class BaseClass>
            class WithRawMethod_cancel : public BaseClass {
            private:
                void BaseClassMustBeDerivedFromService(const Service *
                service
                ) {}

            public:
                WithRawMethod_cancel() {
                    ::grpc::Service::MarkMethodRaw(1);
                }

                ~WithRawMethod_cancel() override {
                    BaseClassMustBeDerivedFromService(this);
                }

                // disable synchronous version of this method
                ::grpc::Status
                cancel(::grpc::ServerContext *
                context, const ::vl::core::CancelRequest *
                request,
                       ::vl::core::CancelResponse *
                       response
                ) override {
                    abort();
                    return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
                }

                void Requestcancel(::grpc::ServerContext *context, ::grpc::ByteBuffer *request,
                                   ::grpc::ServerAsyncResponseWriter<::grpc::ByteBuffer> *response,
                                   ::grpc::CompletionQueue *new_call_cq, ::grpc::ServerCompletionQueue *notification_cq,
                                   void *tag) {
                    ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq,
                                                       tag);
                }
            };

            template<class BaseClass>
            class WithRawCallbackMethod_registe : public BaseClass {
            private:
                void BaseClassMustBeDerivedFromService(const Service *
                service
                ) {}

            public:
                WithRawCallbackMethod_registe() {
                    ::grpc::Service::MarkMethodRawCallback(0,
                                                           new ::grpc::internal::CallbackUnaryHandler<::grpc::ByteBuffer, ::grpc::ByteBuffer>(
                                                                   [this](
                                                                           ::grpc::CallbackServerContext *context,
                                                                           const ::grpc::ByteBuffer *request,
                                                                           ::grpc::ByteBuffer *response) {
                                                                       return this->registe(context, request, response);
                                                                   }));
                }

                ~WithRawCallbackMethod_registe() override {
                    BaseClassMustBeDerivedFromService(this);
                }

                // disable synchronous version of this method
                ::grpc::Status
                registe(::grpc::ServerContext *
                context, const ::vl::core::RegisterRequest *
                request,
                        ::vl::core::RegisterResponse *
                        response
                ) override {
                    abort();
                    return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
                }

                virtual ::grpc::ServerUnaryReactor *registe(
                        ::grpc::CallbackServerContext *
                        context, const ::grpc::ByteBuffer *
                request,
                        ::grpc::ByteBuffer *
                        response
                ) { return nullptr; }
            };

            template<class BaseClass>
            class WithRawCallbackMethod_cancel : public BaseClass {
            private:
                void BaseClassMustBeDerivedFromService(const Service *
                service
                ) {}

            public:
                WithRawCallbackMethod_cancel() {
                    ::grpc::Service::MarkMethodRawCallback(1,
                                                           new ::grpc::internal::CallbackUnaryHandler<::grpc::ByteBuffer, ::grpc::ByteBuffer>(
                                                                   [this](
                                                                           ::grpc::CallbackServerContext *context,
                                                                           const ::grpc::ByteBuffer *request,
                                                                           ::grpc::ByteBuffer *response) {
                                                                       return this->cancel(context, request, response);
                                                                   }));
                }

                ~WithRawCallbackMethod_cancel() override {
                    BaseClassMustBeDerivedFromService(this);
                }

                // disable synchronous version of this method
                ::grpc::Status
                cancel(::grpc::ServerContext *
                context, const ::vl::core::CancelRequest *
                request,
                       ::vl::core::CancelResponse *
                       response
                ) override {
                    abort();
                    return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
                }

                virtual ::grpc::ServerUnaryReactor *cancel(
                        ::grpc::CallbackServerContext *
                        context, const ::grpc::ByteBuffer *
                request,
                        ::grpc::ByteBuffer *
                        response
                ) { return nullptr; }
            };

            template<class BaseClass>
            class WithStreamedUnaryMethod_registe : public BaseClass {
            private:
                void BaseClassMustBeDerivedFromService(const Service *
                service
                ) {}

            public:
                WithStreamedUnaryMethod_registe() {
                    ::grpc::Service::MarkMethodStreamed(0,
                                                        new ::grpc::internal::StreamedUnaryHandler<
                                                                ::vl::core::RegisterRequest, ::vl::core::RegisterResponse>(
                                                                [this](::grpc::ServerContext *context,
                                                                       ::grpc::ServerUnaryStreamer<
                                                                               ::vl::core::RegisterRequest, ::vl::core::RegisterResponse> *streamer) {
                                                                    return this->Streamedregiste(context,
                                                                                                 streamer);
                                                                }));
                }

                ~WithStreamedUnaryMethod_registe() override {
                    BaseClassMustBeDerivedFromService(this);
                }

                // disable regular version of this method
                ::grpc::Status
                registe(::grpc::ServerContext *
                context, const ::vl::core::RegisterRequest *
                request,
                        ::vl::core::RegisterResponse *
                        response
                ) override {
                    abort();
                    return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
                }

                // replace default version of method with streamed unary
                virtual ::grpc::Status Streamedregiste(::grpc::ServerContext *context,
                                                       ::grpc::ServerUnaryStreamer<::vl::core::RegisterRequest, ::vl::core::RegisterResponse> *server_unary_streamer) = 0;
            };

            template<class BaseClass>
            class WithStreamedUnaryMethod_cancel : public BaseClass {
            private:
                void BaseClassMustBeDerivedFromService(const Service *
                service
                ) {}

            public:
                WithStreamedUnaryMethod_cancel() {
                    ::grpc::Service::MarkMethodStreamed(1,
                                                        new ::grpc::internal::StreamedUnaryHandler<
                                                                ::vl::core::CancelRequest, ::vl::core::CancelResponse>(
                                                                [this](::grpc::ServerContext *context,
                                                                       ::grpc::ServerUnaryStreamer<
                                                                               ::vl::core::CancelRequest, ::vl::core::CancelResponse> *streamer) {
                                                                    return this->Streamedcancel(context,
                                                                                                streamer);
                                                                }));
                }

                ~WithStreamedUnaryMethod_cancel() override {
                    BaseClassMustBeDerivedFromService(this);
                }

                // disable regular version of this method
                ::grpc::Status
                cancel(::grpc::ServerContext *
                context, const ::vl::core::CancelRequest *
                request,
                       ::vl::core::CancelResponse *
                       response
                ) override {
                    abort();
                    return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
                }

                // replace default version of method with streamed unary
                virtual ::grpc::Status Streamedcancel(::grpc::ServerContext *context,
                                                      ::grpc::ServerUnaryStreamer<::vl::core::CancelRequest, ::vl::core::CancelResponse> *server_unary_streamer) = 0;
            };

            typedef WithStreamedUnaryMethod_registe<WithStreamedUnaryMethod_cancel<Service> > StreamedUnaryService;
            typedef Service SplitStreamedService;
            typedef WithStreamedUnaryMethod_registe<WithStreamedUnaryMethod_cancel<Service> > StreamedService;
        };

    }  // namespace core
}  // namespace vl


#endif  // GRPC_RegisterService_2eproto__INCLUDED