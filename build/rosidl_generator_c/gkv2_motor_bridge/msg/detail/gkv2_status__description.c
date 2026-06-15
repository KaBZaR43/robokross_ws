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
      0x45, 0x31, 0xe7, 0x68, 0xfd, 0xe4, 0x31, 0xea,
      0xbc, 0xc7, 0x62, 0xd6, 0x06, 0xc7, 0x4e, 0xee,
      0x98, 0x16, 0x63, 0xf2, 0xe1, 0x98, 0xb6, 0x67,
      0x25, 0x64, 0xce, 0x06, 0x70, 0x82, 0x0e, 0xe5,
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
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__gps_num_satellites[] = "gps_num_satellites";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_state_status[] = "alg_state_status";
static char gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__rtk_fixed[] = "rtk_fixed";

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
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__alg_state_status, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {gkv2_motor_bridge__msg__GKV2Status__FIELD_NAME__rtk_fixed, 9, 9},
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
      {gkv2_motor_bridge__msg__GKV2Status__FIELDS, 4, 4},
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
  "uint32 gps_state_status  # \\xd0\\xa1\\xd0\\xbb\\xd0\\xbe\\xd0\\xb2\\xd0\\xbe \\xd1\\x81\\xd0\\xbe\\xd1\\x81\\xd1\\x82\\xd0\\xbe\\xd1\\x8f\\xd0\\xbd\\xd0\\xb8\\xd1\\x8f \\xd0\\x93\\xd0\\x9d\\xd0\\xa1\\xd0\\xa1 \\xd0\\xbf\\xd1\\x80\\xd0\\xb8\\xd1\\x91\\xd0\\xbc\\xd0\\xbd\\xd0\\xb8\\xd0\\xba\\xd0\\xb0 (\\xd0\\xb1\\xd0\\xb8\\xd1\\x82\\xd0\\xbe\\xd0\\xb2\\xd0\\xbe\\xd0\\xb5 \\xd0\\xbf\\xd0\\xbe\\xd0\\xbb\\xd0\\xb5)\n"
  "uint16 gps_num_satellites # \\xd0\\x9a\\xd0\\xbe\\xd0\\xbb\\xd0\\xb8\\xd1\\x87\\xd0\\xb5\\xd1\\x81\\xd1\\x82\\xd0\\xb2\\xd0\\xbe \\xd1\\x81\\xd0\\xbf\\xd1\\x83\\xd1\\x82\\xd0\\xbd\\xd0\\xb8\\xd0\\xba\\xd0\\xbe\\xd0\\xb2 \\xd0\\xb2 \\xd1\\x80\\xd0\\xb5\\xd1\\x88\\xd0\\xb5\\xd0\\xbd\\xd0\\xb8\\xd0\\xb8\n"
  "float32 alg_state_status  # \\xd0\\xa1\\xd0\\xbe\\xd1\\x81\\xd1\\x82\\xd0\\xbe\\xd1\\x8f\\xd0\\xbd\\xd0\\xb8\\xd0\\xb5 \\xd0\\xbd\\xd0\\xb0\\xd0\\xb2\\xd0\\xb8\\xd0\\xb3\\xd0\\xb0\\xd1\\x86\\xd0\\xb8\\xd0\\xbe\\xd0\\xbd\\xd0\\xbd\\xd0\\xbe\\xd0\\xb3\\xd0\\xbe \\xd0\\xb0\\xd0\\xbb\\xd0\\xb3\\xd0\\xbe\\xd1\\x80\\xd0\\xb8\\xd1\\x82\\xd0\\xbc\\xd0\\xb0 (0-50: \\xd1\\x81\\xd0\\xb1\\xd1\\x80\\xd0\\xbe\\xd1\\x81, \\xd0\\xbf\\xd0\\xbe\\xd0\\xb8\\xd1\\x81\\xd0\\xba, \\xd0\\xbd\\xd0\\xb0\\xd0\\xb2\\xd0\\xb8\\xd0\\xb3\\xd0\\xb0\\xd1\\x86\\xd0\\xb8\\xd1\\x8f)\n"
  "bool rtk_fixed            # RTK Fixed (\\xd1\\x81\\xd0\\xb0\\xd0\\xbd\\xd1\\x82\\xd0\\xb8\\xd0\\xbc\\xd0\\xb5\\xd1\\x82\\xd1\\x80\\xd0\\xbe\\xd0\\xb2\\xd0\\xb0\\xd1\\x8f \\xd1\\x82\\xd0\\xbe\\xd1\\x87\\xd0\\xbd\\xd0\\xbe\\xd1\\x81\\xd1\\x82\\xd1\\x8c)";

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
    {toplevel_type_raw_source, 326, 326},
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
