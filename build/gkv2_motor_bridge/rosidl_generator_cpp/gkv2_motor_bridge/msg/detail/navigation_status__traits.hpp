// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gkv2_motor_bridge:msg/NavigationStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gkv2_motor_bridge/msg/navigation_status.hpp"


#ifndef GKV2_MOTOR_BRIDGE__MSG__DETAIL__NAVIGATION_STATUS__TRAITS_HPP_
#define GKV2_MOTOR_BRIDGE__MSG__DETAIL__NAVIGATION_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "gkv2_motor_bridge/msg/detail/navigation_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace gkv2_motor_bridge
{

namespace msg
{

inline void to_flow_style_yaml(
  const NavigationStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: current_mode
  {
    out << "current_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.current_mode, out);
    out << ", ";
  }

  // member: gnss_available
  {
    out << "gnss_available: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_available, out);
    out << ", ";
  }

  // member: rtk_fixed
  {
    out << "rtk_fixed: ";
    rosidl_generator_traits::value_to_yaml(msg.rtk_fixed, out);
    out << ", ";
  }

  // member: gnss_satellites
  {
    out << "gnss_satellites: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_satellites, out);
    out << ", ";
  }

  // member: gnss_quality
  {
    out << "gnss_quality: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_quality, out);
    out << ", ";
  }

  // member: odometry_drift
  {
    out << "odometry_drift: ";
    rosidl_generator_traits::value_to_yaml(msg.odometry_drift, out);
    out << ", ";
  }

  // member: time_since_gnss
  {
    out << "time_since_gnss: ";
    rosidl_generator_traits::value_to_yaml(msg.time_since_gnss, out);
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
  const NavigationStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: current_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.current_mode, out);
    out << "\n";
  }

  // member: gnss_available
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gnss_available: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_available, out);
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

  // member: gnss_satellites
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gnss_satellites: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_satellites, out);
    out << "\n";
  }

  // member: gnss_quality
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gnss_quality: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_quality, out);
    out << "\n";
  }

  // member: odometry_drift
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "odometry_drift: ";
    rosidl_generator_traits::value_to_yaml(msg.odometry_drift, out);
    out << "\n";
  }

  // member: time_since_gnss
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_since_gnss: ";
    rosidl_generator_traits::value_to_yaml(msg.time_since_gnss, out);
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

inline std::string to_yaml(const NavigationStatus & msg, bool use_flow_style = false)
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
  const gkv2_motor_bridge::msg::NavigationStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  gkv2_motor_bridge::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gkv2_motor_bridge::msg::to_yaml() instead")]]
inline std::string to_yaml(const gkv2_motor_bridge::msg::NavigationStatus & msg)
{
  return gkv2_motor_bridge::msg::to_yaml(msg);
}

template<>
inline const char * data_type<gkv2_motor_bridge::msg::NavigationStatus>()
{
  return "gkv2_motor_bridge::msg::NavigationStatus";
}

template<>
inline const char * name<gkv2_motor_bridge::msg::NavigationStatus>()
{
  return "gkv2_motor_bridge/msg/NavigationStatus";
}

template<>
struct has_fixed_size<gkv2_motor_bridge::msg::NavigationStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<gkv2_motor_bridge::msg::NavigationStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<gkv2_motor_bridge::msg::NavigationStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GKV2_MOTOR_BRIDGE__MSG__DETAIL__NAVIGATION_STATUS__TRAITS_HPP_
