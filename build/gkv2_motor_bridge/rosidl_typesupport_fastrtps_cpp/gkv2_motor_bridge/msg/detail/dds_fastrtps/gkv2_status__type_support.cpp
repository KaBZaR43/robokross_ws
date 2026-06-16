// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from gkv2_motor_bridge:msg/GKV2Status.idl
// generated code does not contain a copyright notice
#include "gkv2_motor_bridge/msg/detail/gkv2_status__rosidl_typesupport_fastrtps_cpp.hpp"
#include "gkv2_motor_bridge/msg/detail/gkv2_status__functions.h"
#include "gkv2_motor_bridge/msg/detail/gkv2_status__struct.hpp"

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
  const gkv2_motor_bridge::msg::GKV2Status & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: gps_state_status
  cdr << ros_message.gps_state_status;

  // Member: gnss_date_valid
  cdr << (ros_message.gnss_date_valid ? true : false);

  // Member: gnss_time_valid
  cdr << (ros_message.gnss_time_valid ? true : false);

  // Member: gnss_ambiguity_resolved
  cdr << (ros_message.gnss_ambiguity_resolved ? true : false);

  // Member: gnss_coords_valid
  cdr << (ros_message.gnss_coords_valid ? true : false);

  // Member: gnss_diff_corrections
  cdr << (ros_message.gnss_diff_corrections ? true : false);

  // Member: gnss_fix_type
  cdr << ros_message.gnss_fix_type;

  // Member: rtk_status
  cdr << ros_message.rtk_status;

  // Member: gps_rel_status
  cdr << ros_message.gps_rel_status;

  // Member: rel_nav_valid
  cdr << (ros_message.rel_nav_valid ? true : false);

  // Member: rel_diff_applied
  cdr << (ros_message.rel_diff_applied ? true : false);

  // Member: rel_coords_valid
  cdr << (ros_message.rel_coords_valid ? true : false);

  // Member: rel_ambiguity_status
  cdr << ros_message.rel_ambiguity_status;

  // Member: rel_heading_mode
  cdr << (ros_message.rel_heading_mode ? true : false);

  // Member: rel_heading_valid
  cdr << (ros_message.rel_heading_valid ? true : false);

  // Member: alg_state_status
  cdr << ros_message.alg_state_status;

  // Member: alg_stage
  cdr << ros_message.alg_stage;

  // Member: alg_correction
  cdr << ros_message.alg_correction;

  // Member: alg_fails
  cdr << ros_message.alg_fails;

  // Member: alg_navigation_ready
  cdr << (ros_message.alg_navigation_ready ? true : false);

  // Member: gps_num_satellites
  cdr << ros_message.gps_num_satellites;

  // Member: gnss_sig_lat
  cdr << ros_message.gnss_sig_lat;

  // Member: gnss_sig_lon
  cdr << ros_message.gnss_sig_lon;

  // Member: gnss_sig_alt
  cdr << ros_message.gnss_sig_alt;

  // Member: alg_var_x
  cdr << ros_message.alg_var_x;

  // Member: alg_var_y
  cdr << ros_message.alg_var_y;

  // Member: alg_var_z
  cdr << ros_message.alg_var_z;

  // Member: alg_var_vx
  cdr << ros_message.alg_var_vx;

  // Member: alg_var_vy
  cdr << ros_message.alg_var_vy;

  // Member: alg_var_vz
  cdr << ros_message.alg_var_vz;

  // Member: alg_var_psi
  cdr << ros_message.alg_var_psi;

  // Member: alg_var_theta
  cdr << ros_message.alg_var_theta;

  // Member: alg_var_phi
  cdr << ros_message.alg_var_phi;

  // Member: gps_rel_heading
  cdr << ros_message.gps_rel_heading;

  // Member: gps_rel_length
  cdr << ros_message.gps_rel_length;

  // Member: heading_from_dual_antenna
  cdr << (ros_message.heading_from_dual_antenna ? true : false);

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gkv2_motor_bridge
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  gkv2_motor_bridge::msg::GKV2Status & ros_message)
{
  // Member: gps_state_status
  cdr >> ros_message.gps_state_status;

  // Member: gnss_date_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.gnss_date_valid = tmp ? true : false;
  }

  // Member: gnss_time_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.gnss_time_valid = tmp ? true : false;
  }

  // Member: gnss_ambiguity_resolved
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.gnss_ambiguity_resolved = tmp ? true : false;
  }

  // Member: gnss_coords_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.gnss_coords_valid = tmp ? true : false;
  }

  // Member: gnss_diff_corrections
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.gnss_diff_corrections = tmp ? true : false;
  }

  // Member: gnss_fix_type
  cdr >> ros_message.gnss_fix_type;

  // Member: rtk_status
  cdr >> ros_message.rtk_status;

  // Member: gps_rel_status
  cdr >> ros_message.gps_rel_status;

  // Member: rel_nav_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.rel_nav_valid = tmp ? true : false;
  }

  // Member: rel_diff_applied
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.rel_diff_applied = tmp ? true : false;
  }

  // Member: rel_coords_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.rel_coords_valid = tmp ? true : false;
  }

  // Member: rel_ambiguity_status
  cdr >> ros_message.rel_ambiguity_status;

  // Member: rel_heading_mode
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.rel_heading_mode = tmp ? true : false;
  }

  // Member: rel_heading_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.rel_heading_valid = tmp ? true : false;
  }

  // Member: alg_state_status
  cdr >> ros_message.alg_state_status;

  // Member: alg_stage
  cdr >> ros_message.alg_stage;

  // Member: alg_correction
  cdr >> ros_message.alg_correction;

  // Member: alg_fails
  cdr >> ros_message.alg_fails;

  // Member: alg_navigation_ready
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.alg_navigation_ready = tmp ? true : false;
  }

  // Member: gps_num_satellites
  cdr >> ros_message.gps_num_satellites;

  // Member: gnss_sig_lat
  cdr >> ros_message.gnss_sig_lat;

  // Member: gnss_sig_lon
  cdr >> ros_message.gnss_sig_lon;

  // Member: gnss_sig_alt
  cdr >> ros_message.gnss_sig_alt;

  // Member: alg_var_x
  cdr >> ros_message.alg_var_x;

  // Member: alg_var_y
  cdr >> ros_message.alg_var_y;

  // Member: alg_var_z
  cdr >> ros_message.alg_var_z;

  // Member: alg_var_vx
  cdr >> ros_message.alg_var_vx;

  // Member: alg_var_vy
  cdr >> ros_message.alg_var_vy;

  // Member: alg_var_vz
  cdr >> ros_message.alg_var_vz;

  // Member: alg_var_psi
  cdr >> ros_message.alg_var_psi;

  // Member: alg_var_theta
  cdr >> ros_message.alg_var_theta;

  // Member: alg_var_phi
  cdr >> ros_message.alg_var_phi;

  // Member: gps_rel_heading
  cdr >> ros_message.gps_rel_heading;

  // Member: gps_rel_length
  cdr >> ros_message.gps_rel_length;

  // Member: heading_from_dual_antenna
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.heading_from_dual_antenna = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gkv2_motor_bridge
get_serialized_size(
  const gkv2_motor_bridge::msg::GKV2Status & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: gps_state_status
  {
    size_t item_size = sizeof(ros_message.gps_state_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gnss_date_valid
  {
    size_t item_size = sizeof(ros_message.gnss_date_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gnss_time_valid
  {
    size_t item_size = sizeof(ros_message.gnss_time_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gnss_ambiguity_resolved
  {
    size_t item_size = sizeof(ros_message.gnss_ambiguity_resolved);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gnss_coords_valid
  {
    size_t item_size = sizeof(ros_message.gnss_coords_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gnss_diff_corrections
  {
    size_t item_size = sizeof(ros_message.gnss_diff_corrections);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gnss_fix_type
  {
    size_t item_size = sizeof(ros_message.gnss_fix_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: rtk_status
  {
    size_t item_size = sizeof(ros_message.rtk_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gps_rel_status
  {
    size_t item_size = sizeof(ros_message.gps_rel_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: rel_nav_valid
  {
    size_t item_size = sizeof(ros_message.rel_nav_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: rel_diff_applied
  {
    size_t item_size = sizeof(ros_message.rel_diff_applied);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: rel_coords_valid
  {
    size_t item_size = sizeof(ros_message.rel_coords_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: rel_ambiguity_status
  {
    size_t item_size = sizeof(ros_message.rel_ambiguity_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: rel_heading_mode
  {
    size_t item_size = sizeof(ros_message.rel_heading_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: rel_heading_valid
  {
    size_t item_size = sizeof(ros_message.rel_heading_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_state_status
  {
    size_t item_size = sizeof(ros_message.alg_state_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_stage
  {
    size_t item_size = sizeof(ros_message.alg_stage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_correction
  {
    size_t item_size = sizeof(ros_message.alg_correction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_fails
  {
    size_t item_size = sizeof(ros_message.alg_fails);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_navigation_ready
  {
    size_t item_size = sizeof(ros_message.alg_navigation_ready);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gps_num_satellites
  {
    size_t item_size = sizeof(ros_message.gps_num_satellites);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gnss_sig_lat
  {
    size_t item_size = sizeof(ros_message.gnss_sig_lat);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gnss_sig_lon
  {
    size_t item_size = sizeof(ros_message.gnss_sig_lon);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gnss_sig_alt
  {
    size_t item_size = sizeof(ros_message.gnss_sig_alt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_var_x
  {
    size_t item_size = sizeof(ros_message.alg_var_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_var_y
  {
    size_t item_size = sizeof(ros_message.alg_var_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_var_z
  {
    size_t item_size = sizeof(ros_message.alg_var_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_var_vx
  {
    size_t item_size = sizeof(ros_message.alg_var_vx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_var_vy
  {
    size_t item_size = sizeof(ros_message.alg_var_vy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_var_vz
  {
    size_t item_size = sizeof(ros_message.alg_var_vz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_var_psi
  {
    size_t item_size = sizeof(ros_message.alg_var_psi);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_var_theta
  {
    size_t item_size = sizeof(ros_message.alg_var_theta);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_var_phi
  {
    size_t item_size = sizeof(ros_message.alg_var_phi);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gps_rel_heading
  {
    size_t item_size = sizeof(ros_message.gps_rel_heading);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gps_rel_length
  {
    size_t item_size = sizeof(ros_message.gps_rel_length);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: heading_from_dual_antenna
  {
    size_t item_size = sizeof(ros_message.heading_from_dual_antenna);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gkv2_motor_bridge
max_serialized_size_GKV2Status(
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

  // Member: gps_state_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: gnss_date_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: gnss_time_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: gnss_ambiguity_resolved
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: gnss_coords_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: gnss_diff_corrections
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: gnss_fix_type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: rtk_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: gps_rel_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: rel_nav_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: rel_diff_applied
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: rel_coords_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: rel_ambiguity_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: rel_heading_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: rel_heading_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: alg_state_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: alg_stage
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: alg_correction
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: alg_fails
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // Member: alg_navigation_ready
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: gps_num_satellites
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // Member: gnss_sig_lat
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: gnss_sig_lon
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: gnss_sig_alt
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: alg_var_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: alg_var_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: alg_var_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: alg_var_vx
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: alg_var_vy
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: alg_var_vz
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: alg_var_psi
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: alg_var_theta
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: alg_var_phi
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: gps_rel_heading
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: gps_rel_length
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: heading_from_dual_antenna
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = gkv2_motor_bridge::msg::GKV2Status;
    is_plain =
      (
      offsetof(DataType, heading_from_dual_antenna) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gkv2_motor_bridge
cdr_serialize_key(
  const gkv2_motor_bridge::msg::GKV2Status & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: gps_state_status
  cdr << ros_message.gps_state_status;

  // Member: gnss_date_valid
  cdr << (ros_message.gnss_date_valid ? true : false);

  // Member: gnss_time_valid
  cdr << (ros_message.gnss_time_valid ? true : false);

  // Member: gnss_ambiguity_resolved
  cdr << (ros_message.gnss_ambiguity_resolved ? true : false);

  // Member: gnss_coords_valid
  cdr << (ros_message.gnss_coords_valid ? true : false);

  // Member: gnss_diff_corrections
  cdr << (ros_message.gnss_diff_corrections ? true : false);

  // Member: gnss_fix_type
  cdr << ros_message.gnss_fix_type;

  // Member: rtk_status
  cdr << ros_message.rtk_status;

  // Member: gps_rel_status
  cdr << ros_message.gps_rel_status;

  // Member: rel_nav_valid
  cdr << (ros_message.rel_nav_valid ? true : false);

  // Member: rel_diff_applied
  cdr << (ros_message.rel_diff_applied ? true : false);

  // Member: rel_coords_valid
  cdr << (ros_message.rel_coords_valid ? true : false);

  // Member: rel_ambiguity_status
  cdr << ros_message.rel_ambiguity_status;

  // Member: rel_heading_mode
  cdr << (ros_message.rel_heading_mode ? true : false);

  // Member: rel_heading_valid
  cdr << (ros_message.rel_heading_valid ? true : false);

  // Member: alg_state_status
  cdr << ros_message.alg_state_status;

  // Member: alg_stage
  cdr << ros_message.alg_stage;

  // Member: alg_correction
  cdr << ros_message.alg_correction;

  // Member: alg_fails
  cdr << ros_message.alg_fails;

  // Member: alg_navigation_ready
  cdr << (ros_message.alg_navigation_ready ? true : false);

  // Member: gps_num_satellites
  cdr << ros_message.gps_num_satellites;

  // Member: gnss_sig_lat
  cdr << ros_message.gnss_sig_lat;

  // Member: gnss_sig_lon
  cdr << ros_message.gnss_sig_lon;

  // Member: gnss_sig_alt
  cdr << ros_message.gnss_sig_alt;

  // Member: alg_var_x
  cdr << ros_message.alg_var_x;

  // Member: alg_var_y
  cdr << ros_message.alg_var_y;

  // Member: alg_var_z
  cdr << ros_message.alg_var_z;

  // Member: alg_var_vx
  cdr << ros_message.alg_var_vx;

  // Member: alg_var_vy
  cdr << ros_message.alg_var_vy;

  // Member: alg_var_vz
  cdr << ros_message.alg_var_vz;

  // Member: alg_var_psi
  cdr << ros_message.alg_var_psi;

  // Member: alg_var_theta
  cdr << ros_message.alg_var_theta;

  // Member: alg_var_phi
  cdr << ros_message.alg_var_phi;

  // Member: gps_rel_heading
  cdr << ros_message.gps_rel_heading;

  // Member: gps_rel_length
  cdr << ros_message.gps_rel_length;

  // Member: heading_from_dual_antenna
  cdr << (ros_message.heading_from_dual_antenna ? true : false);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gkv2_motor_bridge
get_serialized_size_key(
  const gkv2_motor_bridge::msg::GKV2Status & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: gps_state_status
  {
    size_t item_size = sizeof(ros_message.gps_state_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gnss_date_valid
  {
    size_t item_size = sizeof(ros_message.gnss_date_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gnss_time_valid
  {
    size_t item_size = sizeof(ros_message.gnss_time_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gnss_ambiguity_resolved
  {
    size_t item_size = sizeof(ros_message.gnss_ambiguity_resolved);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gnss_coords_valid
  {
    size_t item_size = sizeof(ros_message.gnss_coords_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gnss_diff_corrections
  {
    size_t item_size = sizeof(ros_message.gnss_diff_corrections);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gnss_fix_type
  {
    size_t item_size = sizeof(ros_message.gnss_fix_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: rtk_status
  {
    size_t item_size = sizeof(ros_message.rtk_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gps_rel_status
  {
    size_t item_size = sizeof(ros_message.gps_rel_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: rel_nav_valid
  {
    size_t item_size = sizeof(ros_message.rel_nav_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: rel_diff_applied
  {
    size_t item_size = sizeof(ros_message.rel_diff_applied);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: rel_coords_valid
  {
    size_t item_size = sizeof(ros_message.rel_coords_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: rel_ambiguity_status
  {
    size_t item_size = sizeof(ros_message.rel_ambiguity_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: rel_heading_mode
  {
    size_t item_size = sizeof(ros_message.rel_heading_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: rel_heading_valid
  {
    size_t item_size = sizeof(ros_message.rel_heading_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_state_status
  {
    size_t item_size = sizeof(ros_message.alg_state_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_stage
  {
    size_t item_size = sizeof(ros_message.alg_stage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_correction
  {
    size_t item_size = sizeof(ros_message.alg_correction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_fails
  {
    size_t item_size = sizeof(ros_message.alg_fails);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_navigation_ready
  {
    size_t item_size = sizeof(ros_message.alg_navigation_ready);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gps_num_satellites
  {
    size_t item_size = sizeof(ros_message.gps_num_satellites);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gnss_sig_lat
  {
    size_t item_size = sizeof(ros_message.gnss_sig_lat);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gnss_sig_lon
  {
    size_t item_size = sizeof(ros_message.gnss_sig_lon);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gnss_sig_alt
  {
    size_t item_size = sizeof(ros_message.gnss_sig_alt);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_var_x
  {
    size_t item_size = sizeof(ros_message.alg_var_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_var_y
  {
    size_t item_size = sizeof(ros_message.alg_var_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_var_z
  {
    size_t item_size = sizeof(ros_message.alg_var_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_var_vx
  {
    size_t item_size = sizeof(ros_message.alg_var_vx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_var_vy
  {
    size_t item_size = sizeof(ros_message.alg_var_vy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_var_vz
  {
    size_t item_size = sizeof(ros_message.alg_var_vz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_var_psi
  {
    size_t item_size = sizeof(ros_message.alg_var_psi);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_var_theta
  {
    size_t item_size = sizeof(ros_message.alg_var_theta);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: alg_var_phi
  {
    size_t item_size = sizeof(ros_message.alg_var_phi);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gps_rel_heading
  {
    size_t item_size = sizeof(ros_message.gps_rel_heading);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: gps_rel_length
  {
    size_t item_size = sizeof(ros_message.gps_rel_length);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: heading_from_dual_antenna
  {
    size_t item_size = sizeof(ros_message.heading_from_dual_antenna);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gkv2_motor_bridge
max_serialized_size_key_GKV2Status(
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

  // Member: gps_state_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: gnss_date_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: gnss_time_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: gnss_ambiguity_resolved
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: gnss_coords_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: gnss_diff_corrections
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: gnss_fix_type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: rtk_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: gps_rel_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: rel_nav_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: rel_diff_applied
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: rel_coords_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: rel_ambiguity_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: rel_heading_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: rel_heading_valid
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: alg_state_status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: alg_stage
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: alg_correction
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: alg_fails
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: alg_navigation_ready
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: gps_num_satellites
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: gnss_sig_lat
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: gnss_sig_lon
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: gnss_sig_alt
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: alg_var_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: alg_var_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: alg_var_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: alg_var_vx
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: alg_var_vy
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: alg_var_vz
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: alg_var_psi
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: alg_var_theta
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: alg_var_phi
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: gps_rel_heading
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: gps_rel_length
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: heading_from_dual_antenna
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = gkv2_motor_bridge::msg::GKV2Status;
    is_plain =
      (
      offsetof(DataType, heading_from_dual_antenna) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _GKV2Status__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const gkv2_motor_bridge::msg::GKV2Status *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GKV2Status__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<gkv2_motor_bridge::msg::GKV2Status *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GKV2Status__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const gkv2_motor_bridge::msg::GKV2Status *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GKV2Status__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_GKV2Status(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _GKV2Status__callbacks = {
  "gkv2_motor_bridge::msg",
  "GKV2Status",
  _GKV2Status__cdr_serialize,
  _GKV2Status__cdr_deserialize,
  _GKV2Status__get_serialized_size,
  _GKV2Status__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _GKV2Status__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GKV2Status__callbacks,
  get_message_typesupport_handle_function,
  &gkv2_motor_bridge__msg__GKV2Status__get_type_hash,
  &gkv2_motor_bridge__msg__GKV2Status__get_type_description,
  &gkv2_motor_bridge__msg__GKV2Status__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace gkv2_motor_bridge

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_gkv2_motor_bridge
const rosidl_message_type_support_t *
get_message_type_support_handle<gkv2_motor_bridge::msg::GKV2Status>()
{
  return &gkv2_motor_bridge::msg::typesupport_fastrtps_cpp::_GKV2Status__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, gkv2_motor_bridge, msg, GKV2Status)() {
  return &gkv2_motor_bridge::msg::typesupport_fastrtps_cpp::_GKV2Status__handle;
}

#ifdef __cplusplus
}
#endif
