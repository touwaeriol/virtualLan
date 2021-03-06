// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: RequestCode.proto

#include "RequestCode.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace vl {
namespace core {
constexpr RequestCode::RequestCode(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : requestid_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , clientid_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct RequestCodeDefaultTypeInternal {
  constexpr RequestCodeDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~RequestCodeDefaultTypeInternal() {}
  union {
    RequestCode _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT RequestCodeDefaultTypeInternal _RequestCode_default_instance_;
}  // namespace core
}  // namespace vl
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_RequestCode_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_RequestCode_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_RequestCode_2eproto = nullptr;

const uint32_t TableStruct_RequestCode_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::vl::core::RequestCode, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::vl::core::RequestCode, requestid_),
  PROTOBUF_FIELD_OFFSET(::vl::core::RequestCode, clientid_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::vl::core::RequestCode)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::vl::core::_RequestCode_default_instance_),
};

const char descriptor_table_protodef_RequestCode_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\021RequestCode.proto\022\007vl.core\"2\n\013RequestC"
  "ode\022\021\n\trequestId\030\001 \001(\t\022\020\n\010clientId\030\002 \001(\t"
  "b\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_RequestCode_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_RequestCode_2eproto = {
  false, false, 88, descriptor_table_protodef_RequestCode_2eproto, "RequestCode.proto", 
  &descriptor_table_RequestCode_2eproto_once, nullptr, 0, 1,
  schemas, file_default_instances, TableStruct_RequestCode_2eproto::offsets,
  file_level_metadata_RequestCode_2eproto, file_level_enum_descriptors_RequestCode_2eproto, file_level_service_descriptors_RequestCode_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_RequestCode_2eproto_getter() {
  return &descriptor_table_RequestCode_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_RequestCode_2eproto(&descriptor_table_RequestCode_2eproto);
namespace vl {
namespace core {

// ===================================================================

class RequestCode::_Internal {
 public:
};

RequestCode::RequestCode(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:vl.core.RequestCode)
}
RequestCode::RequestCode(const RequestCode& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  requestid_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    requestid_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_requestid().empty()) {
    requestid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_requestid(), 
      GetArenaForAllocation());
  }
  clientid_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    clientid_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_clientid().empty()) {
    clientid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_clientid(), 
      GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:vl.core.RequestCode)
}

inline void RequestCode::SharedCtor() {
requestid_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  requestid_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
clientid_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  clientid_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

RequestCode::~RequestCode() {
  // @@protoc_insertion_point(destructor:vl.core.RequestCode)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void RequestCode::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  requestid_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  clientid_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void RequestCode::ArenaDtor(void* object) {
  RequestCode* _this = reinterpret_cast< RequestCode* >(object);
  (void)_this;
}
void RequestCode::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void RequestCode::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void RequestCode::Clear() {
// @@protoc_insertion_point(message_clear_start:vl.core.RequestCode)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  requestid_.ClearToEmpty();
  clientid_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* RequestCode::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string requestId = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_requestid();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "vl.core.RequestCode.requestId"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string clientId = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_clientid();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "vl.core.RequestCode.clientId"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* RequestCode::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:vl.core.RequestCode)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string requestId = 1;
  if (!this->_internal_requestid().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_requestid().data(), static_cast<int>(this->_internal_requestid().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "vl.core.RequestCode.requestId");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_requestid(), target);
  }

  // string clientId = 2;
  if (!this->_internal_clientid().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_clientid().data(), static_cast<int>(this->_internal_clientid().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "vl.core.RequestCode.clientId");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_clientid(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:vl.core.RequestCode)
  return target;
}

size_t RequestCode::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:vl.core.RequestCode)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string requestId = 1;
  if (!this->_internal_requestid().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_requestid());
  }

  // string clientId = 2;
  if (!this->_internal_clientid().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_clientid());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData RequestCode::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    RequestCode::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*RequestCode::GetClassData() const { return &_class_data_; }

void RequestCode::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<RequestCode *>(to)->MergeFrom(
      static_cast<const RequestCode &>(from));
}


void RequestCode::MergeFrom(const RequestCode& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:vl.core.RequestCode)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_requestid().empty()) {
    _internal_set_requestid(from._internal_requestid());
  }
  if (!from._internal_clientid().empty()) {
    _internal_set_clientid(from._internal_clientid());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void RequestCode::CopyFrom(const RequestCode& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:vl.core.RequestCode)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RequestCode::IsInitialized() const {
  return true;
}

void RequestCode::InternalSwap(RequestCode* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &requestid_, lhs_arena,
      &other->requestid_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &clientid_, lhs_arena,
      &other->clientid_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata RequestCode::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_RequestCode_2eproto_getter, &descriptor_table_RequestCode_2eproto_once,
      file_level_metadata_RequestCode_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace core
}  // namespace vl
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::vl::core::RequestCode* Arena::CreateMaybeMessage< ::vl::core::RequestCode >(Arena* arena) {
  return Arena::CreateMessageInternal< ::vl::core::RequestCode >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
