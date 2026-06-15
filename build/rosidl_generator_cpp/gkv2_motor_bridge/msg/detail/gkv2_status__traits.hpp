// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gkv2_motor_bridge:msg/GKV2Status.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gkv2_motor_bridge/msg/gkv2_status.hpp"


#ifndef GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_STATUS__TRAITS_HPP_
#define GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "gkv2_motor_bridge/msg/detail/gkv2_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace gkv2_motor_bridge
{

namespace msg
{

inline void to_flow_style_yaml(
  const GKV2Status & msg,
  std::ostream & out)
{
  out << "{";
  // member: gps_state_status
  {
    out << "gps_state_status: ";
    rosidl_generator_traits::value_to_yaml(msg.gps_state_status, out);
    out << ", ";
  }

  // member: gps_num_satellites
  {
    out << "gps_num_satellites: ";
    rosidl_generator_traits::value_to_yaml(msg.gps_num_satellites, out);
    out << ", ";
  }

  // member: alg_state_status
  {
    out << "alg_state_status: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_state_status, out);
    out << ", ";
  }

  // member: rtk_fixed
  {
    out << "rtk_fixed: ";
    rosidl_generator_traits::value_to_yaml(msg.rtk_fixed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GKV2Status & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: gps_state_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gps_state_status: ";
    rosidl_generator_traits::value_to_yaml(msg.gps_state_status, out);
    out << "\n";
  }

  // member: gps_num_satellites
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gps_num_satellites: ";
    rosidl_generator_traits::value_to_yaml(msg.gps_num_satellites, out);
    out << "\n";
  }

  // member: alg_state_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "alg_state_status: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_state_status, out);
    out << "\n";
  }

  // member: rtk_fixed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rtk_fixed: ";
    rosidl_generator_traits::value_to_yaml(msg.rtk_fixed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GKV2Status & msg, bool use_flow_style = false)
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
  const gkv2_motor_bridge::msg::GKV2Status & msg,
  std::ostream & out, size_t indentation = 0)
{
  gkv2_motor_bridge::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gkv2_motor_bridge::msg::to_yaml() instead")]]
inline std::string to_yaml(const gkv2_motor_bridge::msg::GKV2Status & msg)
{
  return gkv2_motor_bridge::msg::to_yaml(msg);
}

template<>
inline const char * data_type<gkv2_motor_bridge::msg::GKV2Status>()
{
  return "gkv2_motor_bridge::msg::GKV2Status";
}

template<>
inline const char * name<gkv2_motor_bridge::msg::GKV2Status>()
{
  return "gkv2_motor_bridge/msg/GKV2Status";
}

template<>
struct has_fixed_size<gkv2_motor_bridge::msg::GKV2Status>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<gkv2_motor_bridge::msg::GKV2Status>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<gkv2_motor_bridge::msg::GKV2Status>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GKV2_MOTOR_BRIDGE__MSG__DETAIL__GKV2_STATUS__TRAITS_HPP_
