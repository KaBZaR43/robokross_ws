// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from gkv2_motor_bridge:msg/GKV2ConfigStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "gkv2_motor_bridge/msg/detail/gkv2_config_status__rosidl_typesupport_introspection_c.h"
#include "gkv2_motor_bridge/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "gkv2_motor_bridge/msg/detail/gkv2_config_status__functions.h"
#include "gkv2_motor_bridge/msg/detail/gkv2_config_status__struct.h"


// Include directives for member types
// Member `device_name`
// Member `serial_number`
// Member `status_message`
#include "rosidl_runtime_c/string_functions.h"
// Member `packet_param_ids`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__GKV2ConfigStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  gkv2_motor_bridge__msg__GKV2ConfigStatus__init(message_memory);
}

void gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__GKV2ConfigStatus_fini_function(void * message_memory)
{
  gkv2_motor_bridge__msg__GKV2ConfigStatus__fini(message_memory);
}

size_t gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__size_function__GKV2ConfigStatus__packet_param_ids(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__get_const_function__GKV2ConfigStatus__packet_param_ids(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__get_function__GKV2ConfigStatus__packet_param_ids(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__fetch_function__GKV2ConfigStatus__packet_param_ids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__get_const_function__GKV2ConfigStatus__packet_param_ids(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__assign_function__GKV2ConfigStatus__packet_param_ids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__get_function__GKV2ConfigStatus__packet_param_ids(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__resize_function__GKV2ConfigStatus__packet_param_ids(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__GKV2ConfigStatus_message_member_array[14] = {
  {
    "device_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge__msg__GKV2ConfigStatus, device_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "serial_number",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge__msg__GKV2ConfigStatus, serial_number),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "firmware_version",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge__msg__GKV2ConfigStatus, firmware_version),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "algorithm_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge__msg__GKV2ConfigStatus, algorithm_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "connection_ok",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge__msg__GKV2ConfigStatus, connection_ok),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "data_ready",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge__msg__GKV2ConfigStatus, data_ready),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "adc_overflow",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge__msg__GKV2ConfigStatus, adc_overflow),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "adc_skip",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge__msg__GKV2ConfigStatus, adc_skip),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gyroscope_fail",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge__msg__GKV2ConfigStatus, gyroscope_fail),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "accelerometer_fail",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge__msg__GKV2ConfigStatus, accelerometer_fail),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "packet_param_count",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge__msg__GKV2ConfigStatus, packet_param_count),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "packet_param_ids",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge__msg__GKV2ConfigStatus, packet_param_ids),  // bytes offset in struct
    NULL,  // default value
    gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__size_function__GKV2ConfigStatus__packet_param_ids,  // size() function pointer
    gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__get_const_function__GKV2ConfigStatus__packet_param_ids,  // get_const(index) function pointer
    gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__get_function__GKV2ConfigStatus__packet_param_ids,  // get(index) function pointer
    gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__fetch_function__GKV2ConfigStatus__packet_param_ids,  // fetch(index, &value) function pointer
    gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__assign_function__GKV2ConfigStatus__packet_param_ids,  // assign(index, value) function pointer
    gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__resize_function__GKV2ConfigStatus__packet_param_ids  // resize(index) function pointer
  },
  {
    "packet_structure_match",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge__msg__GKV2ConfigStatus, packet_structure_match),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "status_message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge__msg__GKV2ConfigStatus, status_message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__GKV2ConfigStatus_message_members = {
  "gkv2_motor_bridge__msg",  // message namespace
  "GKV2ConfigStatus",  // message name
  14,  // number of fields
  sizeof(gkv2_motor_bridge__msg__GKV2ConfigStatus),
  false,  // has_any_key_member_
  gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__GKV2ConfigStatus_message_member_array,  // message members
  gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__GKV2ConfigStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__GKV2ConfigStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__GKV2ConfigStatus_message_type_support_handle = {
  0,
  &gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__GKV2ConfigStatus_message_members,
  get_message_typesupport_handle_function,
  &gkv2_motor_bridge__msg__GKV2ConfigStatus__get_type_hash,
  &gkv2_motor_bridge__msg__GKV2ConfigStatus__get_type_description,
  &gkv2_motor_bridge__msg__GKV2ConfigStatus__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_gkv2_motor_bridge
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gkv2_motor_bridge, msg, GKV2ConfigStatus)() {
  if (!gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__GKV2ConfigStatus_message_type_support_handle.typesupport_identifier) {
    gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__GKV2ConfigStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &gkv2_motor_bridge__msg__GKV2ConfigStatus__rosidl_typesupport_introspection_c__GKV2ConfigStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
