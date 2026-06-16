// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gkv2_motor_bridge:msg/GKV2ConfigStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gkv2_motor_bridge/msg/gkv2_config_status.hpp"


#ifndef GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_CONFIG_STATUS__TRAITS_HPP_
#define GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_CONFIG_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "gkv2_motor_bridge/msg/detail/gkv2_config_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace gkv2_motor_bridge
{

namespace msg
{

inline void to_flow_style_yaml(
  const GKV2ConfigStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: device_name
  {
    out << "device_name: ";
    rosidl_generator_traits::value_to_yaml(msg.device_name, out);
    out << ", ";
  }

  // member: serial_number
  {
    out << "serial_number: ";
    rosidl_generator_traits::value_to_yaml(msg.serial_number, out);
    out << ", ";
  }

  // member: firmware_version
  {
    out << "firmware_version: ";
    rosidl_generator_traits::value_to_yaml(msg.firmware_version, out);
    out << ", ";
  }

  // member: algorithm_mode
  {
    out << "algorithm_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.algorithm_mode, out);
    out << ", ";
  }

  // member: connection_ok
  {
    out << "connection_ok: ";
    rosidl_generator_traits::value_to_yaml(msg.connection_ok, out);
    out << ", ";
  }

  // member: data_ready
  {
    out << "data_ready: ";
    rosidl_generator_traits::value_to_yaml(msg.data_ready, out);
    out << ", ";
  }

  // member: adc_overflow
  {
    out << "adc_overflow: ";
    rosidl_generator_traits::value_to_yaml(msg.adc_overflow, out);
    out << ", ";
  }

  // member: adc_skip
  {
    out << "adc_skip: ";
    rosidl_generator_traits::value_to_yaml(msg.adc_skip, out);
    out << ", ";
  }

  // member: gyroscope_fail
  {
    out << "gyroscope_fail: ";
    rosidl_generator_traits::value_to_yaml(msg.gyroscope_fail, out);
    out << ", ";
  }

  // member: accelerometer_fail
  {
    out << "accelerometer_fail: ";
    rosidl_generator_traits::value_to_yaml(msg.accelerometer_fail, out);
    out << ", ";
  }

  // member: packet_param_count
  {
    out << "packet_param_count: ";
    rosidl_generator_traits::value_to_yaml(msg.packet_param_count, out);
    out << ", ";
  }

  // member: packet_param_ids
  {
    if (msg.packet_param_ids.size() == 0) {
      out << "packet_param_ids: []";
    } else {
      out << "packet_param_ids: [";
      size_t pending_items = msg.packet_param_ids.size();
      for (auto item : msg.packet_param_ids) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: packet_structure_match
  {
    out << "packet_structure_match: ";
    rosidl_generator_traits::value_to_yaml(msg.packet_structure_match, out);
    out << ", ";
  }

  // member: status_message
  {
    out << "status_message: ";
    rosidl_generator_traits::value_to_yaml(msg.status_message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GKV2ConfigStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: device_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "device_name: ";
    rosidl_generator_traits::value_to_yaml(msg.device_name, out);
    out << "\n";
  }

  // member: serial_number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "serial_number: ";
    rosidl_generator_traits::value_to_yaml(msg.serial_number, out);
    out << "\n";
  }

  // member: firmware_version
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "firmware_version: ";
    rosidl_generator_traits::value_to_yaml(msg.firmware_version, out);
    out << "\n";
  }

  // member: algorithm_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "algorithm_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.algorithm_mode, out);
    out << "\n";
  }

  // member: connection_ok
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "connection_ok: ";
    rosidl_generator_traits::value_to_yaml(msg.connection_ok, out);
    out << "\n";
  }

  // member: data_ready
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data_ready: ";
    rosidl_generator_traits::value_to_yaml(msg.data_ready, out);
    out << "\n";
  }

  // member: adc_overflow
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "adc_overflow: ";
    rosidl_generator_traits::value_to_yaml(msg.adc_overflow, out);
    out << "\n";
  }

  // member: adc_skip
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "adc_skip: ";
    rosidl_generator_traits::value_to_yaml(msg.adc_skip, out);
    out << "\n";
  }

  // member: gyroscope_fail
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gyroscope_fail: ";
    rosidl_generator_traits::value_to_yaml(msg.gyroscope_fail, out);
    out << "\n";
  }

  // member: accelerometer_fail
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accelerometer_fail: ";
    rosidl_generator_traits::value_to_yaml(msg.accelerometer_fail, out);
    out << "\n";
  }

  // member: packet_param_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "packet_param_count: ";
    rosidl_generator_traits::value_to_yaml(msg.packet_param_count, out);
    out << "\n";
  }

  // member: packet_param_ids
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.packet_param_ids.size() == 0) {
      out << "packet_param_ids: []\n";
    } else {
      out << "packet_param_ids:\n";
      for (auto item : msg.packet_param_ids) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: packet_structure_match
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "packet_structure_match: ";
    rosidl_generator_traits::value_to_yaml(msg.packet_structure_match, out);
    out << "\n";
  }

  // member: status_message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status_message: ";
    rosidl_generator_traits::value_to_yaml(msg.status_message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GKV2ConfigStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace gkv2_motor_bridge

namespace rosidl_generator_traits
{

[[deprecated("use gkv2_motor_bridge::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const gkv2_motor_bridge::msg::GKV2ConfigStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  gkv2_motor_bridge::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gkv2_motor_bridge::msg::to_yaml() instead")]]
inline std::string to_yaml(const gkv2_motor_bridge::msg::GKV2ConfigStatus & msg)
{
  return gkv2_motor_bridge::msg::to_yaml(msg);
}

template<>
inline const char * data_type<gkv2_motor_bridge::msg::GKV2ConfigStatus>()
{
  return "gkv2_motor_bridge::msg::GKV2ConfigStatus";
}

template<>
inline const char * name<gkv2_motor_bridge::msg::GKV2ConfigStatus>()
{
  return "gkv2_motor_bridge/msg/GKV2ConfigStatus";
}

template<>
struct has_fixed_size<gkv2_motor_bridge::msg::GKV2ConfigStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<gkv2_motor_bridge::msg::GKV2ConfigStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<gkv2_motor_bridge::msg::GKV2ConfigStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_CONFIG_STATUS__TRAITS_HPP_
