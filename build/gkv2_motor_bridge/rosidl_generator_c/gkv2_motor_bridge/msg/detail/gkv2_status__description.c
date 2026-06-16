// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from gkv2_motor_bridge:msg/GKV2Status.idl
// generated code does not contain a copyright notice

#include "gkv2_motor_bridge/msg/detail/gkv2_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_gkv2_motor_bridge
const rosidl_type_hash_t *
gkv2_motor_bridge__msg__GKV2Status__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x01, 0x91, 0x42, 0x4c, 0xe0, 0xc3, 0x94, 0x45,
      0x8f, 0xc7, 0x07, 0xfb, 0x97, 0x5d, 0x77, 0xcd,
      0xc5, 0x5d, 0x64, 0xee, 0x36, 0xb9, 0x0b, 0xd2,
      0x2f, 0x48, 0xed, 0x93, 0xe8, 0x95, 0x5c, 0x4f,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char gkv2_motor_bridge__msg__GKV2Status__TYPE_NAME[] = "gkv2_motor_bridge/msg/GKV2Status";

// Define type names, field names, and default values
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gps_state_status[] = "gps_state_status";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gnss_date_valid[] = "gnss_date_valid";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gnss_time_valid[] = "gnss_time_valid";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gnss_ambiguity_resolved[] = "gnss_ambiguity_resolved";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gnss_coords_valid[] = "gnss_coords_valid";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gnss_diff_corrections[] = "gnss_diff_corrections";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gnss_fix_type[] = "gnss_fix_type";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__rtk_status[] = "rtk_status";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gps_rel_status[] = "gps_rel_status";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__rel_nav_valid[] = "rel_nav_valid";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__rel_diff_applied[] = "rel_diff_applied";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__rel_coords_valid[] = "rel_coords_valid";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__rel_ambiguity_status[] = "rel_ambiguity_status";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__rel_heading_mode[] = "rel_heading_mode";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__rel_heading_valid[] = "rel_heading_valid";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_state_status[] = "alg_state_status";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_stage[] = "alg_stage";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_correction[] = "alg_correction";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_fails[] = "alg_fails";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_navigation_ready[] = "alg_navigation_ready";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gps_num_satellites[] = "gps_num_satellites";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gnss_sig_lat[] = "gnss_sig_lat";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gnss_sig_lon[] = "gnss_sig_lon";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gnss_sig_alt[] = "gnss_sig_alt";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_var_x[] = "alg_var_x";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_var_y[] = "alg_var_y";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_var_z[] = "alg_var_z";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_var_vx[] = "alg_var_vx";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_var_vy[] = "alg_var_vy";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_var_vz[] = "alg_var_vz";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_var_psi[] = "alg_var_psi";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_var_theta[] = "alg_var_theta";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_var_phi[] = "alg_var_phi";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gps_rel_heading[] = "gps_rel_heading";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gps_rel_length[] = "gps_rel_length";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__heading_from_dual_antenna[] = "heading_from_dual_antenna";

static rosidl_runtime_c__type_description__Field gkv2_motor_bridge__msg__GKV2Status__FIELDS[] = {
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gps_state_status, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gnss_date_valid, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gnss_time_valid, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gnss_ambiguity_resolved, 23, 23},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gnss_coords_valid, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gnss_diff_corrections, 21, 21},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gnss_fix_type, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__rtk_status, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gps_rel_status, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__rel_nav_valid, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__rel_diff_applied, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__rel_coords_valid, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__rel_ambiguity_status, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__rel_heading_mode, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__rel_heading_valid, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_state_status, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_stage, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_correction, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_fails, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_navigation_ready, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gps_num_satellites, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gnss_sig_lat, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gnss_sig_lon, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gnss_sig_alt, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_var_x, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_var_y, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_var_z, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_var_vx, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_var_vy, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_var_vz, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_var_psi, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_var_theta, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_var_phi, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gps_rel_heading, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gps_rel_length, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__heading_from_dual_antenna, 25, 25},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
gkv2_motor_bridge__msg__GKV2Status__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {gkv2_motor_bridge__msg__GKV2Status__TYPE_NAME, 32, 32},
      {gkv2_motor_bridge__msg__GKV2Status__FIELDS, 36, 36},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# \\xd0\\xa1\\xd1\\x82\\xd0\\xb0\\xd1\\x82\\xd1\\x83\\xd1\\x81 \\xd0\\xbd\\xd0\\xb0\\xd0\\xb2\\xd0\\xb8\\xd0\\xb3\\xd0\\xb0\\xd1\\x86\\xd0\\xb8\\xd0\\xbe\\xd0\\xbd\\xd0\\xbd\\xd0\\xbe\\xd0\\xb3\\xd0\\xbe \\xd1\\x80\\xd0\\xb5\\xd1\\x88\\xd0\\xb5\\xd0\\xbd\\xd0\\xb8\\xd1\\x8f \\xd0\\x93\\xd0\\x9a\\xd0\\x922\n"
  "# \\xd0\\xa1\\xd0\\xbe\\xd0\\xb3\\xd0\\xbb\\xd0\\xb0\\xd1\\x81\\xd0\\xbd\\xd0\\xbe \\xd0\\x9b\\xd0\\x9c\\xd0\\x90\\xd0\\x9f.402131.009\\xd0\\x941 \\xd0\\xbf. 7.7.8.3 (ZED-F9P) \\xd0\\xb8 \\xd0\\xbf. 7.5 (alg_state_status)\n"
  "\n"
  "# \\xd0\\xa1\\xd0\\xbb\\xd0\\xbe\\xd0\\xb2\\xd0\\xbe \\xd1\\x81\\xd0\\xbe\\xd1\\x81\\xd1\\x82\\xd0\\xbe\\xd1\\x8f\\xd0\\xbd\\xd0\\xb8\\xd1\\x8f \\xd0\\x93\\xd0\\x9d\\xd0\\xa1\\xd0\\xa1 \\xd0\\xbf\\xd1\\x80\\xd0\\xb8\\xd1\\x91\\xd0\\xbc\\xd0\\xbd\\xd0\\xb8\\xd0\\xba\\xd0\\xb0 (gps_state_status, ID 72)\n"
  "uint32 gps_state_status\n"
  "bool gnss_date_valid           # \\xd0\\x91\\xd0\\xb8\\xd1\\x82 0: \\xd0\\xb3\\xd0\\xbe\\xd0\\xb4\\xd0\\xbd\\xd0\\xbe\\xd1\\x81\\xd1\\x82\\xd1\\x8c \\xd0\\xb4\\xd0\\xb0\\xd1\\x82\\xd1\\x8b\n"
  "bool gnss_time_valid           # \\xd0\\x91\\xd0\\xb8\\xd1\\x82 1: \\xd0\\xb3\\xd0\\xbe\\xd0\\xb4\\xd0\\xbd\\xd0\\xbe\\xd1\\x81\\xd1\\x82\\xd1\\x8c \\xd0\\xb2\\xd1\\x80\\xd0\\xb5\\xd0\\xbc\\xd0\\xb5\\xd0\\xbd\\xd0\\xb8\n"
  "bool gnss_ambiguity_resolved   # \\xd0\\x91\\xd0\\xb8\\xd1\\x82 2: \\xd0\\xb2\\xd1\\x80\\xd0\\xb5\\xd0\\xbc\\xd0\\xb5\\xd0\\xbd\\xd0\\xbd\\xd0\\xb0\\xd1\\x8f \\xd0\\xbd\\xd0\\xb5\\xd0\\xbe\\xd0\\xb4\\xd0\\xbd\\xd0\\xbe\\xd0\\xb7\\xd0\\xbd\\xd0\\xb0\\xd1\\x87\\xd0\\xbd\\xd0\\xbe\\xd1\\x81\\xd1\\x82\\xd1\\x8c \\xd1\\x80\\xd0\\xb5\\xd1\\x88\\xd0\\xb5\\xd0\\xbd\\xd0\\xb0\n"
  "bool gnss_coords_valid         # \\xd0\\x91\\xd0\\xb8\\xd1\\x82 16: \\xd0\\xb3\\xd0\\xbe\\xd0\\xb4\\xd0\\xbd\\xd0\\xbe\\xd1\\x81\\xd1\\x82\\xd1\\x8c \\xd0\\xba\\xd0\\xbe\\xd0\\xbe\\xd1\\x80\\xd0\\xb4\\xd0\\xb8\\xd0\\xbd\\xd0\\xb0\\xd1\\x82, DOP \\xd0\\xb8 \\xd0\\xbe\\xd1\\x86\\xd0\\xb5\\xd0\\xbd\\xd0\\xbe\\xd0\\xba \\xd1\\x82\\xd0\\xbe\\xd1\\x87\\xd0\\xbd\\xd0\\xbe\\xd1\\x81\\xd1\\x82\\xd0\\xb8\n"
  "bool gnss_diff_corrections     # \\xd0\\x91\\xd0\\xb8\\xd1\\x82 17: \\xd0\\xbf\\xd1\\x80\\xd0\\xb8\\xd0\\xbc\\xd0\\xb5\\xd0\\xbd\\xd1\\x8f\\xd1\\x8e\\xd1\\x82\\xd1\\x81\\xd1\\x8f \\xd0\\xb4\\xd0\\xb8\\xd1\\x84\\xd1\\x84\\xd0\\xb5\\xd1\\x80\\xd0\\xb5\\xd0\\xbd\\xd1\\x86\\xd0\\xb8\\xd0\\xb0\\xd0\\xbb\\xd1\\x8c\\xd0\\xbd\\xd1\\x8b\\xd0\\xb5 \\xd0\\xbf\\xd0\\xbe\\xd0\\xbf\\xd1\\x80\\xd0\\xb0\\xd0\\xb2\\xd0\\xba\\xd0\\xb8\n"
  "uint8  gnss_fix_type           # \\xd0\\x91\\xd0\\xb8\\xd1\\x82\\xd1\\x8b 8-15: 0=\\xd0\\xbd\\xd0\\xb5\\xd1\\x82, 2=2D, 3=3D, 5=time\n"
  "uint8  rtk_status              # \\xd0\\x91\\xd0\\xb8\\xd1\\x82\\xd1\\x8b 22-23: 0=\\xd0\\xbd\\xd0\\xb5\\xd1\\x82, 1=float, 2=fixed\n"
  "\n"
  "# \\xd0\\xa1\\xd0\\xbb\\xd0\\xbe\\xd0\\xb2\\xd0\\xbe \\xd1\\x81\\xd0\\xbe\\xd1\\x81\\xd1\\x82\\xd0\\xbe\\xd1\\x8f\\xd0\\xbd\\xd0\\xb8\\xd1\\x8f \\xd1\\x80\\xd0\\xbe\\xd0\\xb2\\xd0\\xb5\\xd1\\x80\\xd0\\xb0 (gps_rel_status, ID 29) \\xe2\\x80\\x94 \\xd0\\xb4\\xd0\\xbb\\xd1\\x8f \\xd0\\xb4\\xd0\\xb2\\xd1\\x83\\xd1\\x85 \\xd0\\xb0\\xd0\\xbd\\xd1\\x82\\xd0\\xb5\\xd0\\xbd\\xd0\\xbd\n"
  "uint32 gps_rel_status\n"
  "bool rel_nav_valid             # \\xd0\\x91\\xd0\\xb8\\xd1\\x82 0: \\xd0\\xb3\\xd0\\xbe\\xd0\\xb4\\xd0\\xbd\\xd0\\xbe\\xd1\\x81\\xd1\\x82\\xd1\\x8c \\xd0\\xbd\\xd0\\xb0\\xd0\\xb2\\xd0\\xb8\\xd0\\xb3\\xd0\\xb0\\xd1\\x86\\xd0\\xb8\\xd0\\xbe\\xd0\\xbd\\xd0\\xbd\\xd0\\xbe\\xd0\\xb3\\xd0\\xbe \\xd1\\x80\\xd0\\xb5\\xd1\\x88\\xd0\\xb5\\xd0\\xbd\\xd0\\xb8\\xd1\\x8f\n"
  "bool rel_diff_applied          # \\xd0\\x91\\xd0\\xb8\\xd1\\x82 1: \\xd0\\xb4\\xd0\\xb8\\xd1\\x84. \\xd0\\xbf\\xd0\\xbe\\xd0\\xbf\\xd1\\x80\\xd0\\xb0\\xd0\\xb2\\xd0\\xba\\xd0\\xb8 \\xd0\\xbf\\xd1\\x80\\xd0\\xb8\\xd0\\xbc\\xd0\\xb5\\xd0\\xbd\\xd0\\xb5\\xd0\\xbd\\xd1\\x8b\n"
  "bool rel_coords_valid          # \\xd0\\x91\\xd0\\xb8\\xd1\\x82 2: \\xd0\\xb3\\xd0\\xbe\\xd0\\xb4\\xd0\\xbd\\xd0\\xbe\\xd1\\x81\\xd1\\x82\\xd1\\x8c \\xd1\\x82\\xd0\\xbe\\xd1\\x87\\xd0\\xbd\\xd0\\xbe\\xd1\\x81\\xd1\\x82\\xd0\\xb8 \\xd0\\xbe\\xd1\\x82\\xd0\\xbd\\xd0\\xbe\\xd1\\x81\\xd0\\xb8\\xd1\\x82\\xd0\\xb5\\xd0\\xbb\\xd1\\x8c\\xd0\\xbd\\xd1\\x8b\\xd1\\x85 \\xd0\\xba\\xd0\\xbe\\xd0\\xbe\\xd1\\x80\\xd0\\xb4\\xd0\\xb8\\xd0\\xbd\\xd0\\xb0\\xd1\\x82\n"
  "uint8  rel_ambiguity_status    # \\xd0\\x91\\xd0\\xb8\\xd1\\x82\\xd1\\x8b 3-4: 0=\\xd0\\xbd\\xd0\\xb5 \\xd1\\x80\\xd0\\xb5\\xd1\\x88\\xd0\\xb5\\xd0\\xbd\\xd0\\xb0, 1=diff, 2=fixed\n"
  "bool rel_heading_mode          # \\xd0\\x91\\xd0\\xb8\\xd1\\x82 5: \\xd1\\x80\\xd0\\xb5\\xd0\\xb6\\xd0\\xb8\\xd0\\xbc \\xd0\\xb2\\xd1\\x8b\\xd1\\x87\\xd0\\xb8\\xd1\\x81\\xd0\\xbb\\xd0\\xb5\\xd0\\xbd\\xd0\\xb8\\xd1\\x8f \\xd0\\xba\\xd1\\x83\\xd1\\x80\\xd1\\x81\\xd0\\xb0 \\xd0\\xbf\\xd0\\xbe \\xd0\\xb4\\xd0\\xb2\\xd1\\x83\\xd0\\xbc \\xd0\\xb0\\xd0\\xbd\\xd1\\x82\\xd0\\xb5\\xd0\\xbd\\xd0\\xbd\\xd0\\xb0\\xd0\\xbc\n"
  "bool rel_heading_valid         # \\xd0\\x91\\xd0\\xb8\\xd1\\x82 8: \\xd0\\xb3\\xd0\\xbe\\xd0\\xb4\\xd0\\xbd\\xd0\\xbe\\xd1\\x81\\xd1\\x82\\xd1\\x8c \\xd0\\xb2\\xd1\\x8b\\xd1\\x87\\xd0\\xb8\\xd1\\x81\\xd0\\xbb\\xd0\\xb5\\xd0\\xbd\\xd0\\xb8\\xd1\\x8f \\xd0\\xba\\xd1\\x83\\xd1\\x80\\xd1\\x81\\xd0\\xb0\n"
  "\n"
  "# \\xd0\\xa1\\xd0\\xbe\\xd1\\x81\\xd1\\x82\\xd0\\xbe\\xd1\\x8f\\xd0\\xbd\\xd0\\xb8\\xd0\\xb5 \\xd0\\xbd\\xd0\\xb0\\xd0\\xb2\\xd0\\xb8\\xd0\\xb3\\xd0\\xb0\\xd1\\x86\\xd0\\xb8\\xd0\\xbe\\xd0\\xbd\\xd0\\xbd\\xd0\\xbe\\xd0\\xb3\\xd0\\xbe \\xd0\\xb0\\xd0\\xbb\\xd0\\xb3\\xd0\\xbe\\xd1\\x80\\xd0\\xb8\\xd1\\x82\\xd0\\xbc\\xd0\\xb0 (alg_state_status, ID 96)\n"
  "uint32 alg_state_status\n"
  "uint8  alg_stage               # \\xd0\\x91\\xd0\\xb8\\xd1\\x82\\xd1\\x8b 7-0: \\xd1\\x8d\\xd1\\x82\\xd0\\xb0\\xd0\\xbf (0=\\xd1\\x81\\xd0\\xb1\\xd1\\x80\\xd0\\xbe\\xd1\\x81, 1-2=\\xd0\\xbf\\xd0\\xbe\\xd0\\xb8\\xd1\\x81\\xd0\\xba, 10=\\xd0\\xbe\\xd0\\xb6\\xd0\\xb8\\xd0\\xb4\\xd0\\xb0\\xd0\\xbd\\xd0\\xb8\\xd0\\xb5 \\xd0\\xba\\xd1\\x83\\xd1\\x80\\xd1\\x81\\xd0\\xb0, 30=\\xd0\\xbf\\xd1\\x80\\xd0\\xb5\\xd0\\xb4\\xd0\\xbd\\xd0\\xb0\\xd0\\xb2\\xd0\\xb8\\xd0\\xb3\\xd0\\xb0\\xd1\\x86\\xd0\\xb8\\xd1\\x8f, 50=\\xd0\\xbf\\xd0\\xbe\\xd0\\xbb\\xd0\\xbd\\xd0\\xb0\\xd1\\x8f \\xd0\\xbd\\xd0\\xb0\\xd0\\xb2\\xd0\\xb8\\xd0\\xb3\\xd0\\xb0\\xd1\\x86\\xd0\\xb8\\xd1\\x8f)\n"
  "uint8  alg_correction          # \\xd0\\x91\\xd0\\xb8\\xd1\\x82\\xd1\\x8b 15-8: \\xd1\\x82\\xd0\\xb8\\xd0\\xbf \\xd0\\xba\\xd0\\xbe\\xd1\\x80\\xd1\\x80\\xd0\\xb5\\xd0\\xba\\xd1\\x86\\xd0\\xb8\\xd0\\xb8 (0=\\xd0\\xbd\\xd0\\xb5\\xd1\\x82, 1=\\xd0\\xbf\\xd0\\xbe \\xd1\\x81\\xd0\\xba\\xd0\\xbe\\xd1\\x80\\xd0\\xbe\\xd1\\x81\\xd1\\x82\\xd0\\xb8 \\xd0\\x93\\xd0\\x9d\\xd0\\xa1\\xd0\\xa1, 3=\\xd0\\xbf\\xd0\\xbe \\xd0\\xbf\\xd0\\xbe\\xd0\\xbb\\xd0\\xbe\\xd0\\xb6\\xd0\\xb5\\xd0\\xbd\\xd0\\xb8\\xd1\\x8e \\xd0\\xb8 \\xd1\\x81\\xd0\\xba\\xd0\\xbe\\xd1\\x80\\xd0\\xbe\\xd1\\x81\\xd1\\x82\\xd0\\xb8, 18=\\xd0\\xbf\\xd0\\xbe \\xd0\\xba\\xd1\\x83\\xd1\\x80\\xd1\\x81\\xd1\\x83 \\xd0\\x93\\xd0\\x9d\\xd0\\xa1\\xd0\\xa1)\n"
  "uint16 alg_fails               # \\xd0\\x91\\xd0\\xb8\\xd1\\x82\\xd1\\x8b 31-16: \\xd0\\xbe\\xd1\\x88\\xd0\\xb8\\xd0\\xb1\\xd0\\xba\\xd0\\xb8 \\xd0\\xb0\\xd0\\xbb\\xd0\\xb3\\xd0\\xbe\\xd1\\x80\\xd0\\xb8\\xd1\\x82\\xd0\\xbc\\xd0\\xb0\n"
  "bool alg_navigation_ready      # stage == 50 && fails == 0\n"
  "\n"
  "# \\xd0\\x9a\\xd0\\xbe\\xd0\\xbb\\xd0\\xb8\\xd1\\x87\\xd0\\xb5\\xd1\\x81\\xd1\\x82\\xd0\\xb2\\xd0\\xbe \\xd1\\x81\\xd0\\xbf\\xd1\\x83\\xd1\\x82\\xd0\\xbd\\xd0\\xb8\\xd0\\xba\\xd0\\xbe\\xd0\\xb2 (ID 79)\n"
  "uint16 gps_num_satellites\n"
  "\n"
  "# \\xd0\\xa1\\xd0\\x9a\\xd0\\x9e \\xd0\\xba\\xd0\\xbe\\xd0\\xbe\\xd1\\x80\\xd0\\xb4\\xd0\\xb8\\xd0\\xbd\\xd0\\xb0\\xd1\\x82 \\xd0\\xbe\\xd1\\x82 \\xd0\\x93\\xd0\\x9d\\xd0\\xa1\\xd0\\xa1 (ID 85-87), \\xd0\\xbc\\xd0\\xb5\\xd1\\x82\\xd1\\x80\\xd1\\x8b\n"
  "float32 gnss_sig_lat           # \\xd0\\xa1\\xd0\\x9a\\xd0\\x9e \\xd0\\xbf\\xd0\\xbe \\xd0\\xbe\\xd1\\x81\\xd0\\xb8 X (\\xd1\\x81\\xd0\\xb5\\xd0\\xb2\\xd0\\xb5\\xd1\\x80)\n"
  "float32 gnss_sig_lon           # \\xd0\\xa1\\xd0\\x9a\\xd0\\x9e \\xd0\\xbf\\xd0\\xbe \\xd0\\xbe\\xd1\\x81\\xd0\\xb8 Y (\\xd0\\xb2\\xd0\\xbe\\xd1\\x81\\xd1\\x82\\xd0\\xbe\\xd0\\xba)\n"
  "float32 gnss_sig_alt           # \\xd0\\xa1\\xd0\\x9a\\xd0\\x9e \\xd0\\xbf\\xd0\\xbe \\xd0\\xbe\\xd1\\x81\\xd0\\xb8 Z (\\xd0\\xb2\\xd0\\xbd\\xd0\\xb8\\xd0\\xb7)\n"
  "\n"
  "# \\xd0\\x94\\xd0\\xb8\\xd1\\x81\\xd0\\xbf\\xd0\\xb5\\xd1\\x80\\xd1\\x81\\xd0\\xb8\\xd0\\xb8 \\xd0\\xbe\\xd1\\x88\\xd0\\xb8\\xd0\\xb1\\xd0\\xba\\xd0\\xb8 \\xd0\\xbd\\xd0\\xb0\\xd0\\xb2\\xd0\\xb8\\xd0\\xb3\\xd0\\xb0\\xd1\\x86\\xd0\\xb8\\xd0\\xbe\\xd0\\xbd\\xd0\\xbd\\xd0\\xbe\\xd0\\xb3\\xd0\\xbe \\xd0\\xb0\\xd0\\xbb\\xd0\\xb3\\xd0\\xbe\\xd1\\x80\\xd0\\xb8\\xd1\\x82\\xd0\\xbc\\xd0\\xb0 (ID 98-106)\n"
  "float32 alg_var_x              # \\xd0\\x94\\xd0\\xb8\\xd1\\x81\\xd0\\xbf\\xd0\\xb5\\xd1\\x80\\xd1\\x81\\xd0\\xb8\\xd1\\x8f \\xd0\\xbe\\xd1\\x88\\xd0\\xb8\\xd0\\xb1\\xd0\\xba\\xd0\\xb8 \\xd0\\xbf\\xd0\\xbe\\xd0\\xbb\\xd0\\xbe\\xd0\\xb6\\xd0\\xb5\\xd0\\xbd\\xd0\\xb8\\xd1\\x8f X, \\xd0\\xbc\\xc2\\xb2\n"
  "float32 alg_var_y              # \\xd0\\x94\\xd0\\xb8\\xd1\\x81\\xd0\\xbf\\xd0\\xb5\\xd1\\x80\\xd1\\x81\\xd0\\xb8\\xd1\\x8f \\xd0\\xbe\\xd1\\x88\\xd0\\xb8\\xd0\\xb1\\xd0\\xba\\xd0\\xb8 \\xd0\\xbf\\xd0\\xbe\\xd0\\xbb\\xd0\\xbe\\xd0\\xb6\\xd0\\xb5\\xd0\\xbd\\xd0\\xb8\\xd1\\x8f Y, \\xd0\\xbc\\xc2\\xb2\n"
  "float32 alg_var_z              # \\xd0\\x94\\xd0\\xb8\\xd1\\x81\\xd0\\xbf\\xd0\\xb5\\xd1\\x80\\xd1\\x81\\xd0\\xb8\\xd1\\x8f \\xd0\\xbe\\xd1\\x88\\xd0\\xb8\\xd0\\xb1\\xd0\\xba\\xd0\\xb8 \\xd0\\xbf\\xd0\\xbe\\xd0\\xbb\\xd0\\xbe\\xd0\\xb6\\xd0\\xb5\\xd0\\xbd\\xd0\\xb8\\xd1\\x8f Z, \\xd0\\xbc\\xc2\\xb2\n"
  "float32 alg_var_vx             # \\xd0\\x94\\xd0\\xb8\\xd1\\x81\\xd0\\xbf\\xd0\\xb5\\xd1\\x80\\xd1\\x81\\xd0\\xb8\\xd1\\x8f \\xd0\\xbe\\xd1\\x88\\xd0\\xb8\\xd0\\xb1\\xd0\\xba\\xd0\\xb8 \\xd1\\x81\\xd0\\xba\\xd0\\xbe\\xd1\\x80\\xd0\\xbe\\xd1\\x81\\xd1\\x82\\xd0\\xb8 X, (\\xd0\\xbc/\\xd1\\x81)\\xc2\\xb2\n"
  "float32 alg_var_vy             # \\xd0\\x94\\xd0\\xb8\\xd1\\x81\\xd0\\xbf\\xd0\\xb5\\xd1\\x80\\xd1\\x81\\xd0\\xb8\\xd1\\x8f \\xd0\\xbe\\xd1\\x88\\xd0\\xb8\\xd0\\xb1\\xd0\\xba\\xd0\\xb8 \\xd1\\x81\\xd0\\xba\\xd0\\xbe\\xd1\\x80\\xd0\\xbe\\xd1\\x81\\xd1\\x82\\xd0\\xb8 Y, (\\xd0\\xbc/\\xd1\\x81)\\xc2\\xb2\n"
  "float32 alg_var_vz             # \\xd0\\x94\\xd0\\xb8\\xd1\\x81\\xd0\\xbf\\xd0\\xb5\\xd1\\x80\\xd1\\x81\\xd0\\xb8\\xd1\\x8f \\xd0\\xbe\\xd1\\x88\\xd0\\xb8\\xd0\\xb1\\xd0\\xba\\xd0\\xb8 \\xd1\\x81\\xd0\\xba\\xd0\\xbe\\xd1\\x80\\xd0\\xbe\\xd1\\x81\\xd1\\x82\\xd0\\xb8 Z, (\\xd0\\xbc/\\xd1\\x81)\\xc2\\xb2\n"
  "float32 alg_var_psi            # \\xd0\\x94\\xd0\\xb8\\xd1\\x81\\xd0\\xbf\\xd0\\xb5\\xd1\\x80\\xd1\\x81\\xd0\\xb8\\xd1\\x8f \\xd0\\xbe\\xd1\\x88\\xd0\\xb8\\xd0\\xb1\\xd0\\xba\\xd0\\xb8 \\xd0\\xba\\xd1\\x83\\xd1\\x80\\xd1\\x81\\xd0\\xb0, \\xd1\\x80\\xd0\\xb0\\xd0\\xb4\\xc2\\xb2\n"
  "float32 alg_var_theta          # \\xd0\\x94\\xd0\\xb8\\xd1\\x81\\xd0\\xbf\\xd0\\xb5\\xd1\\x80\\xd1\\x81\\xd0\\xb8\\xd1\\x8f \\xd0\\xbe\\xd1\\x88\\xd0\\xb8\\xd0\\xb1\\xd0\\xba\\xd0\\xb8 \\xd1\\x82\\xd0\\xb0\\xd0\\xbd\\xd0\\xb3\\xd0\\xb0\\xd0\\xb6\\xd0\\xb0, \\xd1\\x80\\xd0\\xb0\\xd0\\xb4\\xc2\\xb2\n"
  "float32 alg_var_phi            # \\xd0\\x94\\xd0\\xb8\\xd1\\x81\\xd0\\xbf\\xd0\\xb5\\xd1\\x80\\xd1\\x81\\xd0\\xb8\\xd1\\x8f \\xd0\\xbe\\xd1\\x88\\xd0\\xb8\\xd0\\xb1\\xd0\\xba\\xd0\\xb8 \\xd0\\xba\\xd1\\x80\\xd0\\xb5\\xd0\\xbd\\xd0\\xb0, \\xd1\\x80\\xd0\\xb0\\xd0\\xb4\\xc2\\xb2\n"
  "\n"
  "# \\xd0\\x94\\xd0\\xb2\\xd1\\x83\\xd1\\x85\\xd0\\xb0\\xd0\\xbd\\xd1\\x82\\xd0\\xb5\\xd0\\xbd\\xd0\\xbd\\xd0\\xbe\\xd0\\xb5 \\xd1\\x80\\xd0\\xb5\\xd1\\x88\\xd0\\xb5\\xd0\\xbd\\xd0\\xb8\\xd0\\xb5 (ID 13-14)\n"
  "float32 gps_rel_heading        # \\xd0\\x9a\\xd1\\x83\\xd1\\x80\\xd1\\x81 \\xd0\\xbc\\xd0\\xb5\\xd0\\xb6\\xd0\\xb4\\xd1\\x83 \\xd0\\xb0\\xd0\\xbd\\xd1\\x82\\xd0\\xb5\\xd0\\xbd\\xd0\\xbd\\xd0\\xb0\\xd0\\xbc\\xd0\\xb8, \\xd1\\x80\\xd0\\xb0\\xd0\\xb4\n"
  "float32 gps_rel_length         # \\xd0\\xa0\\xd0\\xb0\\xd1\\x81\\xd1\\x81\\xd1\\x82\\xd0\\xbe\\xd1\\x8f\\xd0\\xbd\\xd0\\xb8\\xd0\\xb5 \\xd0\\xbc\\xd0\\xb5\\xd0\\xb6\\xd0\\xb4\\xd1\\x83 \\xd0\\xb0\\xd0\\xbd\\xd1\\x82\\xd0\\xb5\\xd0\\xbd\\xd0\\xbd\\xd0\\xb0\\xd0\\xbc\\xd0\\xb8, \\xd0\\xbc\n"
  "bool heading_from_dual_antenna # rel_heading_valid && rel_heading_mode";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
gkv2_motor_bridge__msg__GKV2Status__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {gkv2_motor_bridge__msg__GKV2Status__TYPE_NAME, 32, 32},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 2817, 2817},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
gkv2_motor_bridge__msg__GKV2Status__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *gkv2_motor_bridge__msg__GKV2Status__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
