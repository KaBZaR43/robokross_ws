// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from gkv2_motor_bridge:msg/GKV2Status.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "gkv2_motor_bridge/msg/detail/gkv2_status__functions.h"
#include "gkv2_motor_bridge/msg/detail/gkv2_status__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace gkv2_motor_bridge
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void GKV2Status_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) gkv2_motor_bridge::msg::GKV2Status(_init);
}

void GKV2Status_fini_function(void * message_memory)
{
  auto typed_message = static_cast<gkv2_motor_bridge::msg::GKV2Status *>(message_memory);
  typed_message->~GKV2Status();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GKV2Status_message_member_array[4] = {
  {
    "gps_state_status",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge::msg::GKV2Status, gps_state_status),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "gps_num_satellites",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge::msg::GKV2Status, gps_num_satellites),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "alg_state_status",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge::msg::GKV2Status, alg_state_status),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "rtk_fixed",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge::msg::GKV2Status, rtk_fixed),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GKV2Status_message_members = {
  "gkv2_motor_bridge::msg",  // message namespace
  "GKV2Status",  // message name
  4,  // number of fields
  sizeof(gkv2_motor_bridge::msg::GKV2Status),
  false,  // has_any_key_member_
  GKV2Status_message_member_array,  // message members
  GKV2Status_init_function,  // function to initialize message memory (memory has to be allocated)
  GKV2Status_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GKV2Status_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GKV2Status_message_members,
  get_message_typesupport_handle_function,
  &gkv2_motor_bridge__msg__GKV2Status__get_type_hash,
  &gkv2_motor_bridge__msg__GKV2Status__get_type_description,
  &gkv2_motor_bridge__msg__GKV2Status__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace gkv2_motor_bridge


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<gkv2_motor_bridge::msg::GKV2Status>()
{
  return &::gkv2_motor_bridge::msg::rosidl_typesupport_introspection_cpp::GKV2Status_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, gkv2_motor_bridge, msg, GKV2Status)() {
  return &::gkv2_motor_bridge::msg::rosidl_typesupport_introspection_cpp::GKV2Status_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
