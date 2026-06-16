// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from gkv2_motor_bridge:msg/GKV2ConfigStatus.idl
// generated code does not contain a copyright notice

#include "gkv2_motor_bridge/msg/detail/gkv2_config_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_gkv2_motor_bridge
const rosidl_type_hash_t *
gkv2_motor_bridge__msg__GKV2ConfigStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x69, 0x0c, 0x9f, 0x4c, 0xff, 0xc3, 0xa2, 0xdc,
      0x38, 0xa3, 0x08, 0x3e, 0x35, 0x1c, 0x4f, 0xc7,
      0x43, 0xb2, 0xea, 0x6b, 0x1d, 0x06, 0xc0, 0xda,
      0xee, 0x13, 0x73, 0x55, 0x13, 0x35, 0x42, 0xd9,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char gkv2_motor_bridge__msg__GKV2ConfigStatus__TYPE_NAME[] = "gkv2_motor_bridge/msg/GKV2ConfigStatus";

// Define type names, field names, and default values
static char gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__device_name[] = "device_name";
static char gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__serial_number[] = "serial_number";
static char gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__firmware_version[] = "firmware_version";
static char gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__algorithm_mode[] = "algorithm_mode";
static char gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__connection_ok[] = "connection_ok";
static char gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__data_ready[] = "data_ready";
static char gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__adc_overflow[] = "adc_overflow";
static char gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__adc_skip[] = "adc_skip";
static char gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__gyroscope_fail[] = "gyroscope_fail";
static char gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__accelerometer_fail[] = "accelerometer_fail";
static char gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__packet_param_count[] = "packet_param_count";
static char gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__packet_param_ids[] = "packet_param_ids";
static char gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__packet_structure_match[] = "packet_structure_match";
static char gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__status_message[] = "status_message";

static rosidl_runtime_c__type_description__Field gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELDS[] = {
  {
    {gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__device_name, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__serial_number, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__firmware_version, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__algorithm_mode, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__connection_ok, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__data_ready, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__adc_overflow, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__adc_skip, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__gyroscope_fail, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__accelerometer_fail, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__packet_param_count, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__packet_param_ids, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__packet_structure_match, 22, 22},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELD_NAME__status_message, 14, 14},
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
gkv2_motor_bridge__msg__GKV2ConfigStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {gkv2_motor_bridge__msg__GKV2ConfigStatus__TYPE_NAME, 38, 38},
      {gkv2_motor_bridge__msg__GKV2ConfigStatus__FIELDS, 14, 14},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# \\xd0\\xa1\\xd1\\x82\\xd0\\xb0\\xd1\\x82\\xd1\\x83\\xd1\\x81 \\xd0\\xba\\xd0\\xbe\\xd0\\xbd\\xd1\\x84\\xd0\\xb8\\xd0\\xb3\\xd1\\x83\\xd1\\x80\\xd0\\xb0\\xd1\\x86\\xd0\\xb8\\xd0\\xb8 \\xd0\\x93\\xd0\\x9a\\xd0\\x922\n"
  "\n"
  "# \\xd0\\x9e\\xd0\\xb1\\xd1\\x89\\xd0\\xb0\\xd1\\x8f \\xd0\\xb8\\xd0\\xbd\\xd1\\x84\\xd0\\xbe\\xd1\\x80\\xd0\\xbc\\xd0\\xb0\\xd1\\x86\\xd0\\xb8\\xd1\\x8f\n"
  "string device_name           # \\xd0\\x9d\\xd0\\xb0\\xd0\\xb7\\xd0\\xb2\\xd0\\xb0\\xd0\\xbd\\xd0\\xb8\\xd0\\xb5 \\xd0\\xb8\\xd0\\xb7\\xd0\\xb4\\xd0\\xb5\\xd0\\xbb\\xd0\\xb8\\xd1\\x8f\n"
  "string serial_number         # \\xd0\\xa1\\xd0\\xb5\\xd1\\x80\\xd0\\xb8\\xd0\\xb9\\xd0\\xbd\\xd1\\x8b\\xd0\\xb9 \\xd0\\xbd\\xd0\\xbe\\xd0\\xbc\\xd0\\xb5\\xd1\\x80\n"
  "uint16 firmware_version      # \\xd0\\x92\\xd0\\xb5\\xd1\\x80\\xd1\\x81\\xd0\\xb8\\xd1\\x8f \\xd0\\xbf\\xd1\\x80\\xd0\\xbe\\xd1\\x88\\xd0\\xb8\\xd0\\xb2\\xd0\\xba\\xd0\\xb8\n"
  "uint8 algorithm_mode         # \\xd0\\xa2\\xd0\\xb5\\xd0\\xba\\xd1\\x83\\xd1\\x89\\xd0\\xb8\\xd0\\xb9 \\xd0\\xb0\\xd0\\xbb\\xd0\\xb3\\xd0\\xbe\\xd1\\x80\\xd0\\xb8\\xd1\\x82\\xd0\\xbc (9 = \\xd0\\xbd\\xd0\\xb0\\xd0\\xb2\\xd0\\xb8\\xd0\\xb3\\xd0\\xb0\\xd1\\x86\\xd0\\xb8\\xd1\\x8f)\n"
  "\n"
  "# \\xd0\\xa1\\xd1\\x82\\xd0\\xb0\\xd1\\x82\\xd1\\x83\\xd1\\x81 \\xd1\\x81\\xd0\\xbe\\xd0\\xb5\\xd0\\xb4\\xd0\\xb8\\xd0\\xbd\\xd0\\xb5\\xd0\\xbd\\xd0\\xb8\\xd1\\x8f\n"
  "bool connection_ok           # \\xd0\\xa1\\xd0\\xbe\\xd0\\xb5\\xd0\\xb4\\xd0\\xb8\\xd0\\xbd\\xd0\\xb5\\xd0\\xbd\\xd0\\xb8\\xd0\\xb5 \\xd1\\x81 \\xd0\\x93\\xd0\\x9a\\xd0\\x922 \\xd1\\x83\\xd1\\x81\\xd1\\x82\\xd0\\xb0\\xd0\\xbd\\xd0\\xbe\\xd0\\xb2\\xd0\\xbb\\xd0\\xb5\\xd0\\xbd\\xd0\\xbe\n"
  "bool data_ready              # \\xd0\\x94\\xd0\\xb0\\xd0\\xbd\\xd0\\xbd\\xd1\\x8b\\xd0\\xb5 \\xd0\\xb3\\xd0\\xbe\\xd1\\x82\\xd0\\xbe\\xd0\\xb2\\xd1\\x8b (\\xd0\\xb1\\xd0\\xb8\\xd1\\x82 11 \\xd1\\x81\\xd1\\x82\\xd0\\xb0\\xd1\\x82\\xd1\\x83\\xd1\\x81\\xd0\\xb0)\n"
  "bool adc_overflow            # \\xd0\\x9f\\xd0\\xb5\\xd1\\x80\\xd0\\xb5\\xd0\\xbf\\xd0\\xbe\\xd0\\xbb\\xd0\\xbd\\xd0\\xb5\\xd0\\xbd\\xd0\\xb8\\xd0\\xb5 \\xd0\\xbe\\xd1\\x87\\xd0\\xb5\\xd1\\x80\\xd0\\xb5\\xd0\\xb4\\xd0\\xb8 \\xd0\\x90\\xd0\\xa6\\xd0\\x9f (\\xd0\\xb1\\xd0\\xb8\\xd1\\x82 1)\n"
  "bool adc_skip                # \\xd0\\x9f\\xd1\\x80\\xd0\\xbe\\xd0\\xbf\\xd1\\x83\\xd1\\x81\\xd0\\xba \\xd0\\xb4\\xd0\\xb0\\xd0\\xbd\\xd0\\xbd\\xd1\\x8b\\xd1\\x85 \\xd0\\x90\\xd0\\xa6\\xd0\\x9f (\\xd0\\xb1\\xd0\\xb8\\xd1\\x82 2)\n"
  "bool gyroscope_fail          # \\xd0\\x9e\\xd1\\x82\\xd0\\xba\\xd0\\xb0\\xd0\\xb7 \\xd0\\xb3\\xd0\\xb8\\xd1\\x80\\xd0\\xbe\\xd1\\x81\\xd0\\xba\\xd0\\xbe\\xd0\\xbf\\xd0\\xb0 (\\xd0\\xb1\\xd0\\xb8\\xd1\\x82 4)\n"
  "bool accelerometer_fail      # \\xd0\\x9e\\xd1\\x82\\xd0\\xba\\xd0\\xb0\\xd0\\xb7 \\xd0\\xb0\\xd0\\xba\\xd1\\x81\\xd0\\xb5\\xd0\\xbb\\xd0\\xb5\\xd1\\x80\\xd0\\xbe\\xd0\\xbc\\xd0\\xb5\\xd1\\x82\\xd1\\x80\\xd0\\xb0 (\\xd0\\xb1\\xd0\\xb8\\xd1\\x82 5)\n"
  "\n"
  "# \\xd0\\x9a\\xd0\\xbe\\xd0\\xbd\\xd1\\x84\\xd0\\xb8\\xd0\\xb3\\xd1\\x83\\xd1\\x80\\xd0\\xb0\\xd1\\x86\\xd0\\xb8\\xd1\\x8f \\xd0\\xbd\\xd0\\xb0\\xd0\\xb1\\xd0\\xbe\\xd1\\x80\\xd0\\xbd\\xd0\\xbe\\xd0\\xb3\\xd0\\xbe \\xd0\\xbf\\xd0\\xb0\\xd0\\xba\\xd0\\xb5\\xd1\\x82\\xd0\\xb0\n"
  "uint8 packet_param_count     # \\xd0\\x9a\\xd0\\xbe\\xd0\\xbb\\xd0\\xb8\\xd1\\x87\\xd0\\xb5\\xd1\\x81\\xd1\\x82\\xd0\\xb2\\xd0\\xbe \\xd0\\xbf\\xd0\\xb0\\xd1\\x80\\xd0\\xb0\\xd0\\xbc\\xd0\\xb5\\xd1\\x82\\xd1\\x80\\xd0\\xbe\\xd0\\xb2 \\xd0\\xb2 \\xd0\\xbd\\xd0\\xb0\\xd0\\xb1\\xd0\\xbe\\xd1\\x80\\xd0\\xbd\\xd0\\xbe\\xd0\\xbc \\xd0\\xbf\\xd0\\xb0\\xd0\\xba\\xd0\\xb5\\xd1\\x82\\xd0\\xb5\n"
  "int32[] packet_param_ids     # ID \\xd0\\xbf\\xd0\\xb0\\xd1\\x80\\xd0\\xb0\\xd0\\xbc\\xd0\\xb5\\xd1\\x82\\xd1\\x80\\xd0\\xbe\\xd0\\xb2 \\xd0\\xb2 \\xd0\\xbd\\xd0\\xb0\\xd0\\xb1\\xd0\\xbe\\xd1\\x80\\xd0\\xbd\\xd0\\xbe\\xd0\\xbc \\xd0\\xbf\\xd0\\xb0\\xd0\\xba\\xd0\\xb5\\xd1\\x82\\xd0\\xb5\n"
  "bool packet_structure_match  # \\xd0\\xa1\\xd1\\x82\\xd1\\x80\\xd1\\x83\\xd0\\xba\\xd1\\x82\\xd1\\x83\\xd1\\x80\\xd0\\xb0 \\xd0\\xbf\\xd0\\xb0\\xd0\\xba\\xd0\\xb5\\xd1\\x82\\xd0\\xb0 \\xd1\\x81\\xd0\\xbe\\xd0\\xbe\\xd1\\x82\\xd0\\xb2\\xd0\\xb5\\xd1\\x82\\xd1\\x81\\xd1\\x82\\xd0\\xb2\\xd1\\x83\\xd0\\xb5\\xd1\\x82 \\xd0\\xbe\\xd0\\xb6\\xd0\\xb8\\xd0\\xb4\\xd0\\xb0\\xd0\\xb5\\xd0\\xbc\\xd0\\xbe\\xd0\\xb9\n"
  "\n"
  "# \\xd0\\xa2\\xd0\\xb5\\xd0\\xba\\xd1\\x81\\xd1\\x82\\xd0\\xbe\\xd0\\xb2\\xd0\\xbe\\xd0\\xb5 \\xd0\\xbe\\xd0\\xbf\\xd0\\xb8\\xd1\\x81\\xd0\\xb0\\xd0\\xbd\\xd0\\xb8\\xd0\\xb5 \\xd1\\x81\\xd1\\x82\\xd0\\xb0\\xd1\\x82\\xd1\\x83\\xd1\\x81\\xd0\\xb0\n"
  "string status_message";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
gkv2_motor_bridge__msg__GKV2ConfigStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {gkv2_motor_bridge__msg__GKV2ConfigStatus__TYPE_NAME, 38, 38},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 922, 922},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
gkv2_motor_bridge__msg__GKV2ConfigStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *gkv2_motor_bridge__msg__GKV2ConfigStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
