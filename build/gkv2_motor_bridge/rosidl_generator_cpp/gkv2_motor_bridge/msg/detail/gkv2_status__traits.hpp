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

  // member: gnss_date_valid
  {
    out << "gnss_date_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_date_valid, out);
    out << ", ";
  }

  // member: gnss_time_valid
  {
    out << "gnss_time_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_time_valid, out);
    out << ", ";
  }

  // member: gnss_ambiguity_resolved
  {
    out << "gnss_ambiguity_resolved: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_ambiguity_resolved, out);
    out << ", ";
  }

  // member: gnss_coords_valid
  {
    out << "gnss_coords_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_coords_valid, out);
    out << ", ";
  }

  // member: gnss_diff_corrections
  {
    out << "gnss_diff_corrections: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_diff_corrections, out);
    out << ", ";
  }

  // member: gnss_fix_type
  {
    out << "gnss_fix_type: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_fix_type, out);
    out << ", ";
  }

  // member: rtk_status
  {
    out << "rtk_status: ";
    rosidl_generator_traits::value_to_yaml(msg.rtk_status, out);
    out << ", ";
  }

  // member: gps_rel_status
  {
    out << "gps_rel_status: ";
    rosidl_generator_traits::value_to_yaml(msg.gps_rel_status, out);
    out << ", ";
  }

  // member: rel_nav_valid
  {
    out << "rel_nav_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.rel_nav_valid, out);
    out << ", ";
  }

  // member: rel_diff_applied
  {
    out << "rel_diff_applied: ";
    rosidl_generator_traits::value_to_yaml(msg.rel_diff_applied, out);
    out << ", ";
  }

  // member: rel_coords_valid
  {
    out << "rel_coords_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.rel_coords_valid, out);
    out << ", ";
  }

  // member: rel_ambiguity_status
  {
    out << "rel_ambiguity_status: ";
    rosidl_generator_traits::value_to_yaml(msg.rel_ambiguity_status, out);
    out << ", ";
  }

  // member: rel_heading_mode
  {
    out << "rel_heading_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.rel_heading_mode, out);
    out << ", ";
  }

  // member: rel_heading_valid
  {
    out << "rel_heading_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.rel_heading_valid, out);
    out << ", ";
  }

  // member: alg_state_status
  {
    out << "alg_state_status: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_state_status, out);
    out << ", ";
  }

  // member: alg_stage
  {
    out << "alg_stage: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_stage, out);
    out << ", ";
  }

  // member: alg_correction
  {
    out << "alg_correction: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_correction, out);
    out << ", ";
  }

  // member: alg_fails
  {
    out << "alg_fails: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_fails, out);
    out << ", ";
  }

  // member: alg_navigation_ready
  {
    out << "alg_navigation_ready: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_navigation_ready, out);
    out << ", ";
  }

  // member: gps_num_satellites
  {
    out << "gps_num_satellites: ";
    rosidl_generator_traits::value_to_yaml(msg.gps_num_satellites, out);
    out << ", ";
  }

  // member: gnss_sig_lat
  {
    out << "gnss_sig_lat: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_sig_lat, out);
    out << ", ";
  }

  // member: gnss_sig_lon
  {
    out << "gnss_sig_lon: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_sig_lon, out);
    out << ", ";
  }

  // member: gnss_sig_alt
  {
    out << "gnss_sig_alt: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_sig_alt, out);
    out << ", ";
  }

  // member: alg_var_x
  {
    out << "alg_var_x: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_var_x, out);
    out << ", ";
  }

  // member: alg_var_y
  {
    out << "alg_var_y: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_var_y, out);
    out << ", ";
  }

  // member: alg_var_z
  {
    out << "alg_var_z: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_var_z, out);
    out << ", ";
  }

  // member: alg_var_vx
  {
    out << "alg_var_vx: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_var_vx, out);
    out << ", ";
  }

  // member: alg_var_vy
  {
    out << "alg_var_vy: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_var_vy, out);
    out << ", ";
  }

  // member: alg_var_vz
  {
    out << "alg_var_vz: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_var_vz, out);
    out << ", ";
  }

  // member: alg_var_psi
  {
    out << "alg_var_psi: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_var_psi, out);
    out << ", ";
  }

  // member: alg_var_theta
  {
    out << "alg_var_theta: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_var_theta, out);
    out << ", ";
  }

  // member: alg_var_phi
  {
    out << "alg_var_phi: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_var_phi, out);
    out << ", ";
  }

  // member: gps_rel_heading
  {
    out << "gps_rel_heading: ";
    rosidl_generator_traits::value_to_yaml(msg.gps_rel_heading, out);
    out << ", ";
  }

  // member: gps_rel_length
  {
    out << "gps_rel_length: ";
    rosidl_generator_traits::value_to_yaml(msg.gps_rel_length, out);
    out << ", ";
  }

  // member: heading_from_dual_antenna
  {
    out << "heading_from_dual_antenna: ";
    rosidl_generator_traits::value_to_yaml(msg.heading_from_dual_antenna, out);
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

  // member: gnss_date_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gnss_date_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_date_valid, out);
    out << "\n";
  }

  // member: gnss_time_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gnss_time_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_time_valid, out);
    out << "\n";
  }

  // member: gnss_ambiguity_resolved
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gnss_ambiguity_resolved: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_ambiguity_resolved, out);
    out << "\n";
  }

  // member: gnss_coords_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gnss_coords_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_coords_valid, out);
    out << "\n";
  }

  // member: gnss_diff_corrections
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gnss_diff_corrections: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_diff_corrections, out);
    out << "\n";
  }

  // member: gnss_fix_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gnss_fix_type: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_fix_type, out);
    out << "\n";
  }

  // member: rtk_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rtk_status: ";
    rosidl_generator_traits::value_to_yaml(msg.rtk_status, out);
    out << "\n";
  }

  // member: gps_rel_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gps_rel_status: ";
    rosidl_generator_traits::value_to_yaml(msg.gps_rel_status, out);
    out << "\n";
  }

  // member: rel_nav_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rel_nav_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.rel_nav_valid, out);
    out << "\n";
  }

  // member: rel_diff_applied
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rel_diff_applied: ";
    rosidl_generator_traits::value_to_yaml(msg.rel_diff_applied, out);
    out << "\n";
  }

  // member: rel_coords_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rel_coords_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.rel_coords_valid, out);
    out << "\n";
  }

  // member: rel_ambiguity_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rel_ambiguity_status: ";
    rosidl_generator_traits::value_to_yaml(msg.rel_ambiguity_status, out);
    out << "\n";
  }

  // member: rel_heading_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rel_heading_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.rel_heading_mode, out);
    out << "\n";
  }

  // member: rel_heading_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rel_heading_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.rel_heading_valid, out);
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

  // member: alg_stage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "alg_stage: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_stage, out);
    out << "\n";
  }

  // member: alg_correction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "alg_correction: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_correction, out);
    out << "\n";
  }

  // member: alg_fails
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "alg_fails: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_fails, out);
    out << "\n";
  }

  // member: alg_navigation_ready
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "alg_navigation_ready: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_navigation_ready, out);
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

  // member: gnss_sig_lat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gnss_sig_lat: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_sig_lat, out);
    out << "\n";
  }

  // member: gnss_sig_lon
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gnss_sig_lon: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_sig_lon, out);
    out << "\n";
  }

  // member: gnss_sig_alt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gnss_sig_alt: ";
    rosidl_generator_traits::value_to_yaml(msg.gnss_sig_alt, out);
    out << "\n";
  }

  // member: alg_var_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "alg_var_x: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_var_x, out);
    out << "\n";
  }

  // member: alg_var_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "alg_var_y: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_var_y, out);
    out << "\n";
  }

  // member: alg_var_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "alg_var_z: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_var_z, out);
    out << "\n";
  }

  // member: alg_var_vx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "alg_var_vx: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_var_vx, out);
    out << "\n";
  }

  // member: alg_var_vy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "alg_var_vy: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_var_vy, out);
    out << "\n";
  }

  // member: alg_var_vz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "alg_var_vz: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_var_vz, out);
    out << "\n";
  }

  // member: alg_var_psi
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "alg_var_psi: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_var_psi, out);
    out << "\n";
  }

  // member: alg_var_theta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "alg_var_theta: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_var_theta, out);
    out << "\n";
  }

  // member: alg_var_phi
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "alg_var_phi: ";
    rosidl_generator_traits::value_to_yaml(msg.alg_var_phi, out);
    out << "\n";
  }

  // member: gps_rel_heading
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gps_rel_heading: ";
    rosidl_generator_traits::value_to_yaml(msg.gps_rel_heading, out);
    out << "\n";
  }

  // member: gps_rel_length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gps_rel_length: ";
    rosidl_generator_traits::value_to_yaml(msg.gps_rel_length, out);
    out << "\n";
  }

  // member: heading_from_dual_antenna
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "heading_from_dual_antenna: ";
    rosidl_generator_traits::value_to_yaml(msg.heading_from_dual_antenna, out);
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
