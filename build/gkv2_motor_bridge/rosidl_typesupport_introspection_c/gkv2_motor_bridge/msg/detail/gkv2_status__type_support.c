// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from gkv2_motor_bridge:msg/GKV2Status.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "gkv2_motor_bridge/msg/detail/gkv2_status__rosidl_typesupport_introspection_c.h"
#include "gkv2_motor_bridge/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "gkv2_motor_bridge/msg/detail/gkv2_status__functions.h"
#include "gkv2_motor_bridge/msg/detail/gkv2_status__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void gkv2_motor_bridge__msg__GKV2Status__rosidl_typesupport_introspection_c__GKV2Status_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  gkv2_motor_bridge__msg__GKV2Status__init(message_memory);
}

void gkv2_motor_bridge__msg__GKV2Status__rosidl_typesupport_introspection_c__GKV2Status_fini_function(void * message_memory)
{
  gkv2_motor_bridge__msg__GKV2Status__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember gkv2_motor_bridge__msg__GKV2Status__rosidl_typesupport_introspection_c__GKV2Status_message_member_array[4] = {
  {
    "gps_state_status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge__msg__GKV2Status, gps_state_status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gps_num_satellites",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge__msg__GKV2Status, gps_num_satellites),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "alg_state_status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge__msg__GKV2Status, alg_state_status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rtk_fixed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge__msg__GKV2Status, rtk_fixed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers gkv2_motor_bridge__msg__GKV2Status__rosidl_typesupport_introspection_c__GKV2Status_message_members = {
  "gkv2_motor_bridge__msg",  // message namespace
  "GKV2Status",  // message name
  4,  // number of fields
  sizeof(gkv2_motor_bridge__msg__GKV2Status),
  false,  // has_any_key_member_
  gkv2_motor_bridge__msg__GKV2Status__rosidl_typesupport_introspection_c__GKV2Status_message_member_array,  // message members
  gkv2_motor_bridge__msg__GKV2Status__rosidl_typesupport_introspection_c__GKV2Status_init_function,  // function to initialize message memory (memory has to be allocated)
  gkv2_motor_bridge__msg__GKV2Status__rosidl_typesupport_introspection_c__GKV2Status_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t gkv2_motor_bridge__msg__GKV2Status__rosidl_typesupport_introspection_c__GKV2Status_message_type_support_handle = {
  0,
  &gkv2_motor_bridge__msg__GKV2Status__rosidl_typesupport_introspection_c__GKV2Status_message_members,
  get_message_typesupport_handle_function,
  &gkv2_motor_bridge__msg__GKV2Status__get_type_hash,
  &gkv2_motor_bridge__msg__GKV2Status__get_type_description,
  &gkv2_motor_bridge__msg__GKV2Status__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_gkv2_motor_bridge
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gkv2_motor_bridge, msg, GKV2Status)() {
  if (!gkv2_motor_bridge__msg__GKV2Status__rosidl_typesupport_introspection_c__GKV2Status_message_type_support_handle.typesupport_identifier) {
    gkv2_motor_bridge__msg__GKV2Status__rosidl_typesupport_introspection_c__GKV2Status_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &gkv2_motor_bridge__msg__GKV2Status__rosidl_typesupport_introspection_c__GKV2Status_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
