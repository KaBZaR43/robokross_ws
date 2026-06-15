// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from gkv2_motor_bridge:msg/NavigationStatus.idl
// generated code does not contain a copyright notice
#include "gkv2_motor_bridge/msg/detail/navigation_status__rosidl_typesupport_fastrtps_cpp.hpp"
#include "gkv2_motor_bridge/msg/detail/navigation_status__functions.h"
#include "gkv2_motor_bridge/msg/detail/navigation_status__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace gkv2_motor_bridge
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gkv2_motor_bridge
cdr_serialize(
  const gkv2_motor_bridge::msg::NavigationStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: current_mode
  cdr << ros_message.current_mode;

  // Member: gnss_available
  cdr << (ros_message.gnss_available ? true : false);

  // Member: rtk_fixed
  cdr << (ros_message.rtk_fixed ? true : false);

  // Member: gnss_satellites
  cdr << ros_message.gnss_satellites;

  // Member: gnss_quality
  cdr << ros_message.gnss_quality;

  // Member: odometry_drift
  cdr << ros_message.odometry_drift;

  // Member: time_since_gnss
  cdr << ros_message.time_since_gnss;

  // Member: status_message
  cdr << ros_message.status_message;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gkv2_motor_bridge
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  gkv2_motor_bridge::msg::NavigationStatus & ros_message)
{
  // Member: current_mode
  cdr >> ros_message.current_mode;

  // Member: gnss_available
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.gnss_available = tmp ? true : false;
  }

  // Member: rtk_fixed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.rtk_fixed = tmp ? true : false;
  }

  // Member: gnss_satellites
  cdr >> ros_message.gnss_satellites;

  // Member: gnss_quality
  cdr >> ros_message.gnss_quality;

  // Member: odometry_drift
  cdr >> ros_message.odometry_drift;

  // Member: time_since_gnss
  cdr >> ros_message.time_since_gnss;

  // Member: status_message
  cdr >> ros_message.status_message;

  return true;
}  // NOLINT(readability/fn_size)


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gkv2_motor_bridge
get_serialized_size(
  const gkv2_motor_bridge::msg::NavigationStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: current_mode
  {
    size_t item_size = sizeof(ros_message.current_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gnss_available
  {
    size_t item_size = sizeof(ros_message.gnss_available);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: rtk_fixed
  {
    size_t item_size = sizeof(ros_message.rtk_fixed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gnss_satellites
  {
    size_t item_size = sizeof(ros_message.gnss_satellites);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gnss_quality
  {
    size_t item_size = sizeof(ros_message.gnss_quality);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: odometry_drift
  {
    size_t item_size = sizeof(ros_message.odometry_drift);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: time_since_gnss
  {
    size_t item_size = sizeof(ros_message.time_since_gnss);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: status_message
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.status_message.size() + 1);

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gkv2_motor_bridge
max_serialized_size_NavigationStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: current_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: gnss_available
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: rtk_fixed
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: gnss_satellites
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // Member: gnss_quality
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: odometry_drift
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: time_since_gnss
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: status_message
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = gkv2_motor_bridge::msg::NavigationStatus;
    is_plain =
      (
      offsetof(DataType, status_message) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gkv2_motor_bridge
cdr_serialize_key(
  const gkv2_motor_bridge::msg::NavigationStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: current_mode
  cdr << ros_message.current_mode;

  // Member: gnss_available
  cdr << (ros_message.gnss_available ? true : false);

  // Member: rtk_fixed
  cdr << (ros_message.rtk_fixed ? true : false);

  // Member: gnss_satellites
  cdr << ros_message.gnss_satellites;

  // Member: gnss_quality
  cdr << ros_message.gnss_quality;

  // Member: odometry_drift
  cdr << ros_message.odometry_drift;

  // Member: time_since_gnss
  cdr << ros_message.time_since_gnss;

  // Member: status_message
  cdr << ros_message.status_message;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gkv2_motor_bridge
get_serialized_size_key(
  const gkv2_motor_bridge::msg::NavigationStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: current_mode
  {
    size_t item_size = sizeof(ros_message.current_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gnss_available
  {
    size_t item_size = sizeof(ros_message.gnss_available);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: rtk_fixed
  {
    size_t item_size = sizeof(ros_message.rtk_fixed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gnss_satellites
  {
    size_t item_size = sizeof(ros_message.gnss_satellites);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gnss_quality
  {
    size_t item_size = sizeof(ros_message.gnss_quality);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: odometry_drift
  {
    size_t item_size = sizeof(ros_message.odometry_drift);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: time_since_gnss
  {
    size_t item_size = sizeof(ros_message.time_since_gnss);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: status_message
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.status_message.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gkv2_motor_bridge
max_serialized_size_key_NavigationStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: current_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: gnss_available
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: rtk_fixed
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: gnss_satellites
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: gnss_quality
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: odometry_drift
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: time_since_gnss
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: status_message
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = gkv2_motor_bridge::msg::NavigationStatus;
    is_plain =
      (
      offsetof(DataType, status_message) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _NavigationStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const gkv2_motor_bridge::msg::NavigationStatus *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _NavigationStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<gkv2_motor_bridge::msg::NavigationStatus *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _NavigationStatus__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const gkv2_motor_bridge::msg::NavigationStatus *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _NavigationStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_NavigationStatus(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _NavigationStatus__callbacks = {
  "gkv2_motor_bridge::msg",
  "NavigationStatus",
  _NavigationStatus__cdr_serialize,
  _NavigationStatus__cdr_deserialize,
  _NavigationStatus__get_serialized_size,
  _NavigationStatus__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _NavigationStatus__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_NavigationStatus__callbacks,
  get_message_typesupport_handle_function,
  &gkv2_motor_bridge__msg__NavigationStatus__get_type_hash,
  &gkv2_motor_bridge__msg__NavigationStatus__get_type_description,
  &gkv2_motor_bridge__msg__NavigationStatus__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace gkv2_motor_bridge

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_gkv2_motor_bridge
const rosidl_message_type_support_t *
get_message_type_support_handle<gkv2_motor_bridge::msg::NavigationStatus>()
{
  return &gkv2_motor_bridge::msg::typesupport_fastrtps_cpp::_NavigationStatus__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, gkv2_motor_bridge, msg, NavigationStatus)() {
  return &gkv2_motor_bridge::msg::typesupport_fastrtps_cpp::_NavigationStatus__handle;
}

#ifdef __cplusplus
}
#endif
