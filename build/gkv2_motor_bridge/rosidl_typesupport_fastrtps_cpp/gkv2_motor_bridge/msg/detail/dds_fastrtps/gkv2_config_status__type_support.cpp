// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from gkv2_motor_bridge:msg/GKV2ConfigStatus.idl
// generated code does not contain a copyright notice
#include "gkv2_motor_bridge/msg/detail/gkv2_config_status__rosidl_typesupport_fastrtps_cpp.hpp"
#include "gkv2_motor_bridge/msg/detail/gkv2_config_status__functions.h"
#include "gkv2_motor_bridge/msg/detail/gkv2_config_status__struct.hpp"

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
  const gkv2_motor_bridge::msg::GKV2ConfigStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: device_name
  cdr << ros_message.device_name;

  // Member: serial_number
  cdr << ros_message.serial_number;

  // Member: firmware_version
  cdr << ros_message.firmware_version;

  // Member: algorithm_mode
  cdr << ros_message.algorithm_mode;

  // Member: connection_ok
  cdr << (ros_message.connection_ok ? true : false);

  // Member: data_ready
  cdr << (ros_message.data_ready ? true : false);

  // Member: adc_overflow
  cdr << (ros_message.adc_overflow ? true : false);

  // Member: adc_skip
  cdr << (ros_message.adc_skip ? true : false);

  // Member: gyroscope_fail
  cdr << (ros_message.gyroscope_fail ? true : false);

  // Member: accelerometer_fail
  cdr << (ros_message.accelerometer_fail ? true : false);

  // Member: packet_param_count
  cdr << ros_message.packet_param_count;

  // Member: packet_param_ids
  {
    cdr << ros_message.packet_param_ids;
  }

  // Member: packet_structure_match
  cdr << (ros_message.packet_structure_match ? true : false);

  // Member: status_message
  cdr << ros_message.status_message;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gkv2_motor_bridge
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  gkv2_motor_bridge::msg::GKV2ConfigStatus & ros_message)
{
  // Member: device_name
  cdr >> ros_message.device_name;

  // Member: serial_number
  cdr >> ros_message.serial_number;

  // Member: firmware_version
  cdr >> ros_message.firmware_version;

  // Member: algorithm_mode
  cdr >> ros_message.algorithm_mode;

  // Member: connection_ok
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.connection_ok = tmp ? true : false;
  }

  // Member: data_ready
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.data_ready = tmp ? true : false;
  }

  // Member: adc_overflow
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.adc_overflow = tmp ? true : false;
  }

  // Member: adc_skip
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.adc_skip = tmp ? true : false;
  }

  // Member: gyroscope_fail
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.gyroscope_fail = tmp ? true : false;
  }

  // Member: accelerometer_fail
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.accelerometer_fail = tmp ? true : false;
  }

  // Member: packet_param_count
  cdr >> ros_message.packet_param_count;

  // Member: packet_param_ids
  {
    cdr >> ros_message.packet_param_ids;
  }

  // Member: packet_structure_match
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.packet_structure_match = tmp ? true : false;
  }

  // Member: status_message
  cdr >> ros_message.status_message;

  return true;
}  // NOLINT(readability/fn_size)


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gkv2_motor_bridge
get_serialized_size(
  const gkv2_motor_bridge::msg::GKV2ConfigStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: device_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.device_name.size() + 1);

  // Member: serial_number
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.serial_number.size() + 1);

  // Member: firmware_version
  {
    size_t item_size = sizeof(ros_message.firmware_version);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: algorithm_mode
  {
    size_t item_size = sizeof(ros_message.algorithm_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: connection_ok
  {
    size_t item_size = sizeof(ros_message.connection_ok);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: data_ready
  {
    size_t item_size = sizeof(ros_message.data_ready);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: adc_overflow
  {
    size_t item_size = sizeof(ros_message.adc_overflow);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: adc_skip
  {
    size_t item_size = sizeof(ros_message.adc_skip);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gyroscope_fail
  {
    size_t item_size = sizeof(ros_message.gyroscope_fail);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: accelerometer_fail
  {
    size_t item_size = sizeof(ros_message.accelerometer_fail);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: packet_param_count
  {
    size_t item_size = sizeof(ros_message.packet_param_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: packet_param_ids
  {
    size_t array_size = ros_message.packet_param_ids.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.packet_param_ids[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: packet_structure_match
  {
    size_t item_size = sizeof(ros_message.packet_structure_match);
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
max_serialized_size_GKV2ConfigStatus(
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

  // Member: device_name
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
  // Member: serial_number
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
  // Member: firmware_version
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // Member: algorithm_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: connection_ok
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: data_ready
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: adc_overflow
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: adc_skip
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: gyroscope_fail
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: accelerometer_fail
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: packet_param_count
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: packet_param_ids
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: packet_structure_match
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
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
    using DataType = gkv2_motor_bridge::msg::GKV2ConfigStatus;
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
  const gkv2_motor_bridge::msg::GKV2ConfigStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: device_name
  cdr << ros_message.device_name;

  // Member: serial_number
  cdr << ros_message.serial_number;

  // Member: firmware_version
  cdr << ros_message.firmware_version;

  // Member: algorithm_mode
  cdr << ros_message.algorithm_mode;

  // Member: connection_ok
  cdr << (ros_message.connection_ok ? true : false);

  // Member: data_ready
  cdr << (ros_message.data_ready ? true : false);

  // Member: adc_overflow
  cdr << (ros_message.adc_overflow ? true : false);

  // Member: adc_skip
  cdr << (ros_message.adc_skip ? true : false);

  // Member: gyroscope_fail
  cdr << (ros_message.gyroscope_fail ? true : false);

  // Member: accelerometer_fail
  cdr << (ros_message.accelerometer_fail ? true : false);

  // Member: packet_param_count
  cdr << ros_message.packet_param_count;

  // Member: packet_param_ids
  {
    cdr << ros_message.packet_param_ids;
  }

  // Member: packet_structure_match
  cdr << (ros_message.packet_structure_match ? true : false);

  // Member: status_message
  cdr << ros_message.status_message;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gkv2_motor_bridge
get_serialized_size_key(
  const gkv2_motor_bridge::msg::GKV2ConfigStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: device_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.device_name.size() + 1);

  // Member: serial_number
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.serial_number.size() + 1);

  // Member: firmware_version
  {
    size_t item_size = sizeof(ros_message.firmware_version);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: algorithm_mode
  {
    size_t item_size = sizeof(ros_message.algorithm_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: connection_ok
  {
    size_t item_size = sizeof(ros_message.connection_ok);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: data_ready
  {
    size_t item_size = sizeof(ros_message.data_ready);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: adc_overflow
  {
    size_t item_size = sizeof(ros_message.adc_overflow);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: adc_skip
  {
    size_t item_size = sizeof(ros_message.adc_skip);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gyroscope_fail
  {
    size_t item_size = sizeof(ros_message.gyroscope_fail);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: accelerometer_fail
  {
    size_t item_size = sizeof(ros_message.accelerometer_fail);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: packet_param_count
  {
    size_t item_size = sizeof(ros_message.packet_param_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: packet_param_ids
  {
    size_t array_size = ros_message.packet_param_ids.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.packet_param_ids[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: packet_structure_match
  {
    size_t item_size = sizeof(ros_message.packet_structure_match);
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
max_serialized_size_key_GKV2ConfigStatus(
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

  // Member: device_name
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

  // Member: serial_number
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

  // Member: firmware_version
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: algorithm_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: connection_ok
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: data_ready
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: adc_overflow
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: adc_skip
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: gyroscope_fail
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: accelerometer_fail
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: packet_param_count
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: packet_param_ids
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: packet_structure_match
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
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
    using DataType = gkv2_motor_bridge::msg::GKV2ConfigStatus;
    is_plain =
      (
      offsetof(DataType, status_message) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _GKV2ConfigStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const gkv2_motor_bridge::msg::GKV2ConfigStatus *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GKV2ConfigStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<gkv2_motor_bridge::msg::GKV2ConfigStatus *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GKV2ConfigStatus__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const gkv2_motor_bridge::msg::GKV2ConfigStatus *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GKV2ConfigStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_GKV2ConfigStatus(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _GKV2ConfigStatus__callbacks = {
  "gkv2_motor_bridge::msg",
  "GKV2ConfigStatus",
  _GKV2ConfigStatus__cdr_serialize,
  _GKV2ConfigStatus__cdr_deserialize,
  _GKV2ConfigStatus__get_serialized_size,
  _GKV2ConfigStatus__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _GKV2ConfigStatus__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GKV2ConfigStatus__callbacks,
  get_message_typesupport_handle_function,
  &gkv2_motor_bridge__msg__GKV2ConfigStatus__get_type_hash,
  &gkv2_motor_bridge__msg__GKV2ConfigStatus__get_type_description,
  &gkv2_motor_bridge__msg__GKV2ConfigStatus__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace gkv2_motor_bridge

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_gkv2_motor_bridge
const rosidl_message_type_support_t *
get_message_type_support_handle<gkv2_motor_bridge::msg::GKV2ConfigStatus>()
{
  return &gkv2_motor_bridge::msg::typesupport_fastrtps_cpp::_GKV2ConfigStatus__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, gkv2_motor_bridge, msg, GKV2ConfigStatus)() {
  return &gkv2_motor_bridge::msg::typesupport_fastrtps_cpp::_GKV2ConfigStatus__handle;
}

#ifdef __cplusplus
}
#endif
