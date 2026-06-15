// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from gkv2_motor_bridge:msg/NavigationStatus.idl
// generated code does not contain a copyright notice

#include "gkv2_motor_bridge/msg/detail/navigation_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_gkv2_motor_bridge
const rosidl_type_hash_t *
gkv2_motor_bridge__msg__NavigationStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x8c, 0xfc, 0xa0, 0x95, 0x32, 0xd7, 0xe8, 0x27,
      0x2a, 0xb1, 0x08, 0x28, 0xb4, 0x2f, 0xc0, 0xa8,
      0x15, 0x35, 0xae, 0xa1, 0xfe, 0x26, 0x08, 0x33,
      0x8b, 0x61, 0x89, 0xcd, 0xc1, 0x8e, 0xf6, 0xb8,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char gkv2_motor_bridge__msg__NavigationStatus__TYPE_NAME[] = "gkv2_motor_bridge/msg/NavigationStatus";

// Define type names, field names, and default values
static char gkv2_motor_bridge__msg__NavigationStatus__FIELD_NAME__current_mode[] = "current_mode";
static char gkv2_motor_bridge__msg__NavigationStatus__FIELD_NAME__gnss_available[] = "gnss_available";
static char gkv2_motor_bridge__msg__NavigationStatus__FIELD_NAME__rtk_fixed[] = "rtk_fixed";
static char gkv2_motor_bridge__msg__NavigationStatus__FIELD_NAME__gnss_satellites[] = "gnss_satellites";
static char gkv2_motor_bridge__msg__NavigationStatus__FIELD_NAME__gnss_quality[] = "gnss_quality";
static char gkv2_motor_bridge__msg__NavigationStatus__FIELD_NAME__odometry_drift[] = "odometry_drift";
static char gkv2_motor_bridge__msg__NavigationStatus__FIELD_NAME__time_since_gnss[] = "time_since_gnss";
static char gkv2_motor_bridge__msg__NavigationStatus__FIELD_NAME__status_message[] = "status_message";

static rosidl_runtime_c__type_description__Field gkv2_motor_bridge__msg__NavigationStatus__FIELDS[] = {
  {
    {gkv2_motor_bridge__msg__NavigationStatus__FIELD_NAME__current_mode, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__NavigationStatus__FIELD_NAME__gnss_available, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__NavigationStatus__FIELD_NAME__rtk_fixed, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__NavigationStatus__FIELD_NAME__gnss_satellites, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__NavigationStatus__FIELD_NAME__gnss_quality, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__NavigationStatus__FIELD_NAME__odometry_drift, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__NavigationStatus__FIELD_NAME__time_since_gnss, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__NavigationStatus__FIELD_NAME__status_message, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
gkv2_motor_bridge__msg__NavigationStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {gkv2_motor_bridge__msg__NavigationStatus__TYPE_NAME, 38, 38},
      {gkv2_motor_bridge__msg__NavigationStatus__FIELDS, 8, 8},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# \\xd0\\xa1\\xd1\\x82\\xd0\\xb0\\xd1\\x82\\xd1\\x83\\xd1\\x81 \\xd0\\xbd\\xd0\\xb0\\xd0\\xb2\\xd0\\xb8\\xd0\\xb3\\xd0\\xb0\\xd1\\x86\\xd0\\xb8\\xd0\\xbe\\xd0\\xbd\\xd0\\xbd\\xd0\\xbe\\xd0\\xb9 \\xd1\\x81\\xd0\\xb8\\xd1\\x81\\xd1\\x82\\xd0\\xb5\\xd0\\xbc\\xd1\\x8b\n"
  "uint8 MODE_GNSS=0\n"
  "uint8 MODE_ODOMETRY=1\n"
  "uint8 MODE_FUSION=2\n"
  "\n"
  "uint8 current_mode          # \\xd0\\xa2\\xd0\\xb5\\xd0\\xba\\xd1\\x83\\xd1\\x89\\xd0\\xb8\\xd0\\xb9 \\xd1\\x80\\xd0\\xb5\\xd0\\xb6\\xd0\\xb8\\xd0\\xbc \\xd0\\xbd\\xd0\\xb0\\xd0\\xb2\\xd0\\xb8\\xd0\\xb3\\xd0\\xb0\\xd1\\x86\\xd0\\xb8\\xd0\\xb8 (0=\\xd0\\x93\\xd0\\x9d\\xd0\\xa1\\xd0\\xa1, 1=\\xd0\\x9e\\xd0\\xb4\\xd0\\xbe\\xd0\\xbc\\xd0\\xb5\\xd1\\x82\\xd1\\x80\\xd0\\xb8\\xd1\\x8f, 2=\\xd0\\xa1\\xd0\\xbb\\xd0\\xb8\\xd1\\x8f\\xd0\\xbd\\xd0\\xb8\\xd0\\xb5)\n"
  "bool gnss_available         # \\xd0\\x93\\xd0\\x9d\\xd0\\xa1\\xd0\\xa1 \\xd0\\xb4\\xd0\\xbe\\xd1\\x81\\xd1\\x82\\xd1\\x83\\xd0\\xbf\\xd0\\xb5\\xd0\\xbd \\xd0\\xb8 \\xd0\\xb8\\xd0\\xbc\\xd0\\xb5\\xd0\\xb5\\xd1\\x82 \\xd1\\x85\\xd0\\xbe\\xd1\\x80\\xd0\\xbe\\xd1\\x88\\xd0\\xb5\\xd0\\xb5 \\xd0\\xba\\xd0\\xb0\\xd1\\x87\\xd0\\xb5\\xd1\\x81\\xd1\\x82\\xd0\\xb2\\xd0\\xbe\n"
  "bool rtk_fixed              # RTK Fixed (\\xd1\\x81\\xd0\\xb0\\xd0\\xbd\\xd1\\x82\\xd0\\xb8\\xd0\\xbc\\xd0\\xb5\\xd1\\x82\\xd1\\x80\\xd0\\xbe\\xd0\\xb2\\xd0\\xb0\\xd1\\x8f \\xd1\\x82\\xd0\\xbe\\xd1\\x87\\xd0\\xbd\\xd0\\xbe\\xd1\\x81\\xd1\\x82\\xd1\\x8c)\n"
  "uint16 gnss_satellites      # \\xd0\\x9a\\xd0\\xbe\\xd0\\xbb\\xd0\\xb8\\xd1\\x87\\xd0\\xb5\\xd1\\x81\\xd1\\x82\\xd0\\xb2\\xd0\\xbe \\xd1\\x81\\xd0\\xbf\\xd1\\x83\\xd1\\x82\\xd0\\xbd\\xd0\\xb8\\xd0\\xba\\xd0\\xbe\\xd0\\xb2 \\xd0\\x93\\xd0\\x9d\\xd0\\xa1\\xd0\\xa1\n"
  "float32 gnss_quality        # \\xd0\\x9a\\xd0\\xb0\\xd1\\x87\\xd0\\xb5\\xd1\\x81\\xd1\\x82\\xd0\\xb2\\xd0\\xbe \\xd0\\x93\\xd0\\x9d\\xd0\\xa1\\xd0\\xa1 (0.0-1.0)\n"
  "float32 odometry_drift      # \\xd0\\x9d\\xd0\\xb0\\xd0\\xba\\xd0\\xbe\\xd0\\xbf\\xd0\\xbb\\xd0\\xb5\\xd0\\xbd\\xd0\\xbd\\xd0\\xb0\\xd1\\x8f \\xd0\\xbe\\xd1\\x88\\xd0\\xb8\\xd0\\xb1\\xd0\\xba\\xd0\\xb0 \\xd0\\xbe\\xd0\\xb4\\xd0\\xbe\\xd0\\xbc\\xd0\\xb5\\xd1\\x82\\xd1\\x80\\xd0\\xb8\\xd0\\xb8 (\\xd0\\xbc\\xd0\\xb5\\xd1\\x82\\xd1\\x80\\xd1\\x8b)\n"
  "float32 time_since_gnss     # \\xd0\\x92\\xd1\\x80\\xd0\\xb5\\xd0\\xbc\\xd1\\x8f \\xd1\\x81 \\xd0\\xbf\\xd0\\xbe\\xd1\\x81\\xd0\\xbb\\xd0\\xb5\\xd0\\xb4\\xd0\\xbd\\xd0\\xb5\\xd0\\xb9 \\xd1\\x85\\xd0\\xbe\\xd1\\x80\\xd0\\xbe\\xd1\\x88\\xd0\\xb5\\xd0\\xb9 \\xd0\\x93\\xd0\\x9d\\xd0\\xa1\\xd0\\xa1 \\xd0\\xbf\\xd0\\xbe\\xd0\\xb7\\xd0\\xb8\\xd1\\x86\\xd0\\xb8\\xd0\\xb8 (\\xd1\\x81\\xd0\\xb5\\xd0\\xba\\xd1\\x83\\xd0\\xbd\\xd0\\xb4\\xd1\\x8b)\n"
  "string status_message       # \\xd0\\xa2\\xd0\\xb5\\xd0\\xba\\xd1\\x81\\xd1\\x82\\xd0\\xbe\\xd0\\xb2\\xd0\\xbe\\xd0\\xb5 \\xd0\\xbe\\xd0\\xbf\\xd0\\xb8\\xd1\\x81\\xd0\\xb0\\xd0\\xbd\\xd0\\xb8\\xd0\\xb5 \\xd1\\x81\\xd1\\x82\\xd0\\xb0\\xd1\\x82\\xd1\\x83\\xd1\\x81\\xd0\\xb0";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
gkv2_motor_bridge__msg__NavigationStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {gkv2_motor_bridge__msg__NavigationStatus__TYPE_NAME, 38, 38},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 625, 625},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
gkv2_motor_bridge__msg__NavigationStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *gkv2_motor_bridge__msg__NavigationStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
