// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from gkv2_motor_bridge:msg/NavigationStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "gkv2_motor_bridge/msg/detail/navigation_status__rosidl_typesupport_introspection_c.h"
#include "gkv2_motor_bridge/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "gkv2_motor_bridge/msg/detail/navigation_status__functions.h"
#include "gkv2_motor_bridge/msg/detail/navigation_status__struct.h"


// Include directives for member types
// Member `status_message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void gkv2_motor_bridge__msg__NavigationStatus__rosidl_typesupport_introspection_c__NavigationStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  gkv2_motor_bridge__msg__NavigationStatus__init(message_memory);
}

void gkv2_motor_bridge__msg__NavigationStatus__rosidl_typesupport_introspection_c__NavigationStatus_fini_function(void * message_memory)
{
  gkv2_motor_bridge__msg__NavigationStatus__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember gkv2_motor_bridge__msg__NavigationStatus__rosidl_typesupport_introspection_c__NavigationStatus_message_member_array[8] = {
  {
    "current_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge__msg__NavigationStatus, current_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gnss_available",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge__msg__NavigationStatus, gnss_available),  // bytes offset in struct
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
    offsetof(gkv2_motor_bridge__msg__NavigationStatus, rtk_fixed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gnss_satellites",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge__msg__NavigationStatus, gnss_satellites),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gnss_quality",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge__msg__NavigationStatus, gnss_quality),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "odometry_drift",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge__msg__NavigationStatus, odometry_drift),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "time_since_gnss",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gkv2_motor_bridge__msg__NavigationStatus, time_since_gnss),  // bytes offset in struct
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
    offsetof(gkv2_motor_bridge__msg__NavigationStatus, status_message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers gkv2_motor_bridge__msg__NavigationStatus__rosidl_typesupport_introspection_c__NavigationStatus_message_members = {
  "gkv2_motor_bridge__msg",  // message namespace
  "NavigationStatus",  // message name
  8,  // number of fields
  sizeof(gkv2_motor_bridge__msg__NavigationStatus),
  false,  // has_any_key_member_
  gkv2_motor_bridge__msg__NavigationStatus__rosidl_typesupport_introspection_c__NavigationStatus_message_member_array,  // message members
  gkv2_motor_bridge__msg__NavigationStatus__rosidl_typesupport_introspection_c__NavigationStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  gkv2_motor_bridge__msg__NavigationStatus__rosidl_typesupport_introspection_c__NavigationStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t gkv2_motor_bridge__msg__NavigationStatus__rosidl_typesupport_introspection_c__NavigationStatus_message_type_support_handle = {
  0,
  &gkv2_motor_bridge__msg__NavigationStatus__rosidl_typesupport_introspection_c__NavigationStatus_message_members,
  get_message_typesupport_handle_function,
  &gkv2_motor_bridge__msg__NavigationStatus__get_type_hash,
  &gkv2_motor_bridge__msg__NavigationStatus__get_type_description,
  &gkv2_motor_bridge__msg__NavigationStatus__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_gkv2_motor_bridge
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gkv2_motor_bridge, msg, NavigationStatus)() {
  if (!gkv2_motor_bridge__msg__NavigationStatus__rosidl_typesupport_introspection_c__NavigationStatus_message_type_support_handle.typesupport_identifier) {
    gkv2_motor_bridge__msg__NavigationStatus__rosidl_typesupport_introspection_c__NavigationStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &gkv2_motor_bridge__msg__NavigationStatus__rosidl_typesupport_introspection_c__NavigationStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
