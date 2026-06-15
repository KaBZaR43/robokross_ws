// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from gkv2_motor_bridge:msg/GKV2Status.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "gkv2_motor_bridge/msg/detail/gkv2_status__functions.h"
#include "gkv2_motor_bridge/msg/detail/gkv2_status__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace gkv2_motor_bridge
{

namespace msg
{

namespace rosidl_typesupport_cpp
{

typedef struct _GKV2Status_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GKV2Status_type_support_ids_t;

static const _GKV2Status_type_support_ids_t _GKV2Status_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GKV2Status_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GKV2Status_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GKV2Status_type_support_symbol_names_t _GKV2Status_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, gkv2_motor_bridge, msg, GKV2Status)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, gkv2_motor_bridge, msg, GKV2Status)),
  }
};

typedef struct _GKV2Status_type_support_data_t
{
  void * data[2];
} _GKV2Status_type_support_data_t;

static _GKV2Status_type_support_data_t _GKV2Status_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GKV2Status_message_typesupport_map = {
  2,
  "gkv2_motor_bridge",
  &_GKV2Status_message_typesupport_ids.typesupport_identifier[0],
  &_GKV2Status_message_typesupport_symbol_names.symbol_name[0],
  &_GKV2Status_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GKV2Status_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GKV2Status_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &gkv2_motor_bridge__msg__GKV2Status__get_type_hash,
  &gkv2_motor_bridge__msg__GKV2Status__get_type_description,
  &gkv2_motor_bridge__msg__GKV2Status__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace msg

}  // namespace gkv2_motor_bridge

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<gkv2_motor_bridge::msg::GKV2Status>()
{
  return &::gkv2_motor_bridge::msg::rosidl_typesupport_cpp::GKV2Status_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, gkv2_motor_bridge, msg, GKV2Status)() {
  return get_message_type_support_handle<gkv2_motor_bridge::msg::GKV2Status>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp
