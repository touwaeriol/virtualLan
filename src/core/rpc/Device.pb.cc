// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Device.proto

#include "Device.pb.h"

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
constexpr Device::Device(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : clientid_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , mac_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , ip_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , ipv6_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , publicip_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , publicipv6_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , publicipv6udpport_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , group_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , mtu_(0u)
  , ipnetmask_(0u)
  , prefixlength_(0u)
  , publicudpport_(0u){}
struct DeviceDefaultTypeInternal {
  constexpr DeviceDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~DeviceDefaultTypeInternal() {}
  union {
    Device _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT DeviceDefaultTypeInternal _Device_default_instance_;
}  // namespace core
}  // namespace vl
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_Device_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_Device_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_Device_2eproto = nullptr;

const uint32_t TableStruct_Device_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::vl::core::Device, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::vl::core::Device, clientid_),
  PROTOBUF_FIELD_OFFSET(::vl::core::Device, mac_),
  PROTOBUF_FIELD_OFFSET(::vl::core::Device, mtu_),
  PROTOBUF_FIELD_OFFSET(::vl::core::Device, ip_),
  PROTOBUF_FIELD_OFFSET(::vl::core::Device, ipnetmask_),
  PROTOBUF_FIELD_OFFSET(::vl::core::Device, ipv6_),
  PROTOBUF_FIELD_OFFSET(::vl::core::Device, prefixlength_),
  PROTOBUF_FIELD_OFFSET(::vl::core::Device, publicip_),
  PROTOBUF_FIELD_OFFSET(::vl::core::Device, publicudpport_),
  PROTOBUF_FIELD_OFFSET(::vl::core::Device, publicipv6_),
  PROTOBUF_FIELD_OFFSET(::vl::core::Device, publicipv6udpport_),
  PROTOBUF_FIELD_OFFSET(::vl::core::Device, group_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::vl::core::Device)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::vl::core::_Device_default_instance_),
};

const char descriptor_table_protodef_Device_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\014Device.proto\022\007vl.core\"\336\001\n\006Device\022\020\n\010cl"
  "ientId\030\001 \001(\t\022\013\n\003mac\030\002 \001(\t\022\013\n\003mtu\030\003 \001(\r\022\n"
  "\n\002ip\030\004 \001(\t\022\021\n\tipNetmask\030\005 \001(\r\022\014\n\004ipv6\030\006 "
  "\001(\t\022\024\n\014prefixLength\030\007 \001(\r\022\020\n\010publicIp\030\010 "
  "\001(\t\022\025\n\rpublicUdpPort\030\t \001(\r\022\022\n\npublicIpv6"
  "\030\n \001(\t\022\031\n\021publicIpv6UdpPort\030\013 \001(\t\022\r\n\005gro"
  "up\030\014 \001(\tb\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_Device_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Device_2eproto = {
  false, false, 256, descriptor_table_protodef_Device_2eproto, "Device.proto", 
  &descriptor_table_Device_2eproto_once, nullptr, 0, 1,
  schemas, file_default_instances, TableStruct_Device_2eproto::offsets,
  file_level_metadata_Device_2eproto, file_level_enum_descriptors_Device_2eproto, file_level_service_descriptors_Device_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_Device_2eproto_getter() {
  return &descriptor_table_Device_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_Device_2eproto(&descriptor_table_Device_2eproto);
namespace vl {
namespace core {

// ===================================================================

class Device::_Internal {
 public:
};

Device::Device(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:vl.core.Device)
}
Device::Device(const Device& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  clientid_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    clientid_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_clientid().empty()) {
    clientid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_clientid(), 
      GetArenaForAllocation());
  }
  mac_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    mac_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_mac().empty()) {
    mac_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_mac(), 
      GetArenaForAllocation());
  }
  ip_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    ip_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_ip().empty()) {
    ip_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_ip(), 
      GetArenaForAllocation());
  }
  ipv6_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    ipv6_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_ipv6().empty()) {
    ipv6_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_ipv6(), 
      GetArenaForAllocation());
  }
  publicip_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    publicip_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_publicip().empty()) {
    publicip_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_publicip(), 
      GetArenaForAllocation());
  }
  publicipv6_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    publicipv6_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_publicipv6().empty()) {
    publicipv6_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_publicipv6(), 
      GetArenaForAllocation());
  }
  publicipv6udpport_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    publicipv6udpport_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_publicipv6udpport().empty()) {
    publicipv6udpport_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_publicipv6udpport(), 
      GetArenaForAllocation());
  }
  group_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    group_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_group().empty()) {
    group_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_group(), 
      GetArenaForAllocation());
  }
  ::memcpy(&mtu_, &from.mtu_,
    static_cast<size_t>(reinterpret_cast<char*>(&publicudpport_) -
    reinterpret_cast<char*>(&mtu_)) + sizeof(publicudpport_));
  // @@protoc_insertion_point(copy_constructor:vl.core.Device)
}

inline void Device::SharedCtor() {
clientid_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  clientid_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
mac_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  mac_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
ip_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  ip_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
ipv6_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  ipv6_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
publicip_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  publicip_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
publicipv6_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  publicipv6_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
publicipv6udpport_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  publicipv6udpport_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
group_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  group_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&mtu_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&publicudpport_) -
    reinterpret_cast<char*>(&mtu_)) + sizeof(publicudpport_));
}

Device::~Device() {
  // @@protoc_insertion_point(destructor:vl.core.Device)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Device::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  clientid_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  mac_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ip_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ipv6_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  publicip_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  publicipv6_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  publicipv6udpport_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  group_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Device::ArenaDtor(void* object) {
  Device* _this = reinterpret_cast< Device* >(object);
  (void)_this;
}
void Device::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Device::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Device::Clear() {
// @@protoc_insertion_point(message_clear_start:vl.core.Device)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  clientid_.ClearToEmpty();
  mac_.ClearToEmpty();
  ip_.ClearToEmpty();
  ipv6_.ClearToEmpty();
  publicip_.ClearToEmpty();
  publicipv6_.ClearToEmpty();
  publicipv6udpport_.ClearToEmpty();
  group_.ClearToEmpty();
  ::memset(&mtu_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&publicudpport_) -
      reinterpret_cast<char*>(&mtu_)) + sizeof(publicudpport_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Device::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string clientId = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_clientid();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "vl.core.Device.clientId"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string mac = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_mac();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "vl.core.Device.mac"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint32 mtu = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          mtu_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string ip = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          auto str = _internal_mutable_ip();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "vl.core.Device.ip"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint32 ipNetmask = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 40)) {
          ipnetmask_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string ipv6 = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 50)) {
          auto str = _internal_mutable_ipv6();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "vl.core.Device.ipv6"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint32 prefixLength = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 56)) {
          prefixlength_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string publicIp = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 66)) {
          auto str = _internal_mutable_publicip();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "vl.core.Device.publicIp"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint32 publicUdpPort = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 72)) {
          publicudpport_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string publicIpv6 = 10;
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 82)) {
          auto str = _internal_mutable_publicipv6();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "vl.core.Device.publicIpv6"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string publicIpv6UdpPort = 11;
      case 11:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 90)) {
          auto str = _internal_mutable_publicipv6udpport();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "vl.core.Device.publicIpv6UdpPort"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string group = 12;
      case 12:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 98)) {
          auto str = _internal_mutable_group();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "vl.core.Device.group"));
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

uint8_t* Device::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:vl.core.Device)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string clientId = 1;
  if (!this->_internal_clientid().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_clientid().data(), static_cast<int>(this->_internal_clientid().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "vl.core.Device.clientId");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_clientid(), target);
  }

  // string mac = 2;
  if (!this->_internal_mac().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_mac().data(), static_cast<int>(this->_internal_mac().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "vl.core.Device.mac");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_mac(), target);
  }

  // uint32 mtu = 3;
  if (this->_internal_mtu() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(3, this->_internal_mtu(), target);
  }

  // string ip = 4;
  if (!this->_internal_ip().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_ip().data(), static_cast<int>(this->_internal_ip().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "vl.core.Device.ip");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal_ip(), target);
  }

  // uint32 ipNetmask = 5;
  if (this->_internal_ipnetmask() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(5, this->_internal_ipnetmask(), target);
  }

  // string ipv6 = 6;
  if (!this->_internal_ipv6().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_ipv6().data(), static_cast<int>(this->_internal_ipv6().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "vl.core.Device.ipv6");
    target = stream->WriteStringMaybeAliased(
        6, this->_internal_ipv6(), target);
  }

  // uint32 prefixLength = 7;
  if (this->_internal_prefixlength() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(7, this->_internal_prefixlength(), target);
  }

  // string publicIp = 8;
  if (!this->_internal_publicip().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_publicip().data(), static_cast<int>(this->_internal_publicip().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "vl.core.Device.publicIp");
    target = stream->WriteStringMaybeAliased(
        8, this->_internal_publicip(), target);
  }

  // uint32 publicUdpPort = 9;
  if (this->_internal_publicudpport() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(9, this->_internal_publicudpport(), target);
  }

  // string publicIpv6 = 10;
  if (!this->_internal_publicipv6().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_publicipv6().data(), static_cast<int>(this->_internal_publicipv6().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "vl.core.Device.publicIpv6");
    target = stream->WriteStringMaybeAliased(
        10, this->_internal_publicipv6(), target);
  }

  // string publicIpv6UdpPort = 11;
  if (!this->_internal_publicipv6udpport().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_publicipv6udpport().data(), static_cast<int>(this->_internal_publicipv6udpport().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "vl.core.Device.publicIpv6UdpPort");
    target = stream->WriteStringMaybeAliased(
        11, this->_internal_publicipv6udpport(), target);
  }

  // string group = 12;
  if (!this->_internal_group().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_group().data(), static_cast<int>(this->_internal_group().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "vl.core.Device.group");
    target = stream->WriteStringMaybeAliased(
        12, this->_internal_group(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:vl.core.Device)
  return target;
}

size_t Device::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:vl.core.Device)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string clientId = 1;
  if (!this->_internal_clientid().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_clientid());
  }

  // string mac = 2;
  if (!this->_internal_mac().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_mac());
  }

  // string ip = 4;
  if (!this->_internal_ip().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_ip());
  }

  // string ipv6 = 6;
  if (!this->_internal_ipv6().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_ipv6());
  }

  // string publicIp = 8;
  if (!this->_internal_publicip().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_publicip());
  }

  // string publicIpv6 = 10;
  if (!this->_internal_publicipv6().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_publicipv6());
  }

  // string publicIpv6UdpPort = 11;
  if (!this->_internal_publicipv6udpport().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_publicipv6udpport());
  }

  // string group = 12;
  if (!this->_internal_group().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_group());
  }

  // uint32 mtu = 3;
  if (this->_internal_mtu() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32SizePlusOne(this->_internal_mtu());
  }

  // uint32 ipNetmask = 5;
  if (this->_internal_ipnetmask() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32SizePlusOne(this->_internal_ipnetmask());
  }

  // uint32 prefixLength = 7;
  if (this->_internal_prefixlength() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32SizePlusOne(this->_internal_prefixlength());
  }

  // uint32 publicUdpPort = 9;
  if (this->_internal_publicudpport() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32SizePlusOne(this->_internal_publicudpport());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Device::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Device::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Device::GetClassData() const { return &_class_data_; }

void Device::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Device *>(to)->MergeFrom(
      static_cast<const Device &>(from));
}


void Device::MergeFrom(const Device& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:vl.core.Device)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_clientid().empty()) {
    _internal_set_clientid(from._internal_clientid());
  }
  if (!from._internal_mac().empty()) {
    _internal_set_mac(from._internal_mac());
  }
  if (!from._internal_ip().empty()) {
    _internal_set_ip(from._internal_ip());
  }
  if (!from._internal_ipv6().empty()) {
    _internal_set_ipv6(from._internal_ipv6());
  }
  if (!from._internal_publicip().empty()) {
    _internal_set_publicip(from._internal_publicip());
  }
  if (!from._internal_publicipv6().empty()) {
    _internal_set_publicipv6(from._internal_publicipv6());
  }
  if (!from._internal_publicipv6udpport().empty()) {
    _internal_set_publicipv6udpport(from._internal_publicipv6udpport());
  }
  if (!from._internal_group().empty()) {
    _internal_set_group(from._internal_group());
  }
  if (from._internal_mtu() != 0) {
    _internal_set_mtu(from._internal_mtu());
  }
  if (from._internal_ipnetmask() != 0) {
    _internal_set_ipnetmask(from._internal_ipnetmask());
  }
  if (from._internal_prefixlength() != 0) {
    _internal_set_prefixlength(from._internal_prefixlength());
  }
  if (from._internal_publicudpport() != 0) {
    _internal_set_publicudpport(from._internal_publicudpport());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Device::CopyFrom(const Device& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:vl.core.Device)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Device::IsInitialized() const {
  return true;
}

void Device::InternalSwap(Device* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &clientid_, lhs_arena,
      &other->clientid_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &mac_, lhs_arena,
      &other->mac_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &ip_, lhs_arena,
      &other->ip_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &ipv6_, lhs_arena,
      &other->ipv6_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &publicip_, lhs_arena,
      &other->publicip_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &publicipv6_, lhs_arena,
      &other->publicipv6_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &publicipv6udpport_, lhs_arena,
      &other->publicipv6udpport_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &group_, lhs_arena,
      &other->group_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Device, publicudpport_)
      + sizeof(Device::publicudpport_)
      - PROTOBUF_FIELD_OFFSET(Device, mtu_)>(
          reinterpret_cast<char*>(&mtu_),
          reinterpret_cast<char*>(&other->mtu_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Device::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_Device_2eproto_getter, &descriptor_table_Device_2eproto_once,
      file_level_metadata_Device_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace core
}  // namespace vl
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::vl::core::Device* Arena::CreateMaybeMessage< ::vl::core::Device >(Arena* arena) {
  return Arena::CreateMessageInternal< ::vl::core::Device >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
