// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from gkv2_motor_bridge:msg/NavigationStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gkv2_motor_bridge/msg/navigation_status.h"


#ifndef GKV2_MOTOR_BRIDGE__MSG__DETAIL__NAVIGATION_STATUS__FUNCTIONS_H_
#define GKV2_MOTOR_BRIDGE__MSG__DETAIL__NAVIGATION_STATUS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "gkv2_motor_bridge/msg/rosidl_generator_c__visibility_control.h"

#include "gkv2_motor_bridge/msg/detail/navigation_status__struct.h"

/// Initialize msg/NavigationStatus message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * gkv2_motor_bridge__msg__NavigationStatus
 * )) before or use
 * gkv2_motor_bridge__msg__NavigationStatus__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_gkv2_motor_bridge
bool
gkv2_motor_bridge__msg__NavigationStatus__init(gkv2_motor_bridge__msg__NavigationStatus * msg);

/// Finalize msg/NavigationStatus message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkv2_motor_bridge
void
gkv2_motor_bridge__msg__NavigationStatus__fini(gkv2_motor_bridge__msg__NavigationStatus * msg);

/// Create msg/NavigationStatus message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * gkv2_motor_bridge__msg__NavigationStatus__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gkv2_motor_bridge
gkv2_motor_bridge__msg__NavigationStatus *
gkv2_motor_bridge__msg__NavigationStatus__create(void);

/// Destroy msg/NavigationStatus message.
/**
 * It calls
 * gkv2_motor_bridge__msg__NavigationStatus__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkv2_motor_bridge
void
gkv2_motor_bridge__msg__NavigationStatus__destroy(gkv2_motor_bridge__msg__NavigationStatus * msg);

/// Check for msg/NavigationStatus message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkv2_motor_bridge
bool
gkv2_motor_bridge__msg__NavigationStatus__are_equal(const gkv2_motor_bridge__msg__NavigationStatus * lhs, const gkv2_motor_bridge__msg__NavigationStatus * rhs);

/// Copy a msg/NavigationStatus message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkv2_motor_bridge
bool
gkv2_motor_bridge__msg__NavigationStatus__copy(
  const gkv2_motor_bridge__msg__NavigationStatus * input,
  gkv2_motor_bridge__msg__NavigationStatus * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_gkv2_motor_bridge
const rosidl_type_hash_t *
gkv2_motor_bridge__msg__NavigationStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_gkv2_motor_bridge
const rosidl_runtime_c__type_description__TypeDescription *
gkv2_motor_bridge__msg__NavigationStatus__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_gkv2_motor_bridge
const rosidl_runtime_c__type_description__TypeSource *
gkv2_motor_bridge__msg__NavigationStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_gkv2_motor_bridge
const rosidl_runtime_c__type_description__TypeSource__Sequence *
gkv2_motor_bridge__msg__NavigationStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/NavigationStatus messages.
/**
 * It allocates the memory for the number of elements and calls
 * gkv2_motor_bridge__msg__NavigationStatus__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkv2_motor_bridge
bool
gkv2_motor_bridge__msg__NavigationStatus__Sequence__init(gkv2_motor_bridge__msg__NavigationStatus__Sequence * array, size_t size);

/// Finalize array of msg/NavigationStatus messages.
/**
 * It calls
 * gkv2_motor_bridge__msg__NavigationStatus__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkv2_motor_bridge
void
gkv2_motor_bridge__msg__NavigationStatus__Sequence__fini(gkv2_motor_bridge__msg__NavigationStatus__Sequence * array);

/// Create array of msg/NavigationStatus messages.
/**
 * It allocates the memory for the array and calls
 * gkv2_motor_bridge__msg__NavigationStatus__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gkv2_motor_bridge
gkv2_motor_bridge__msg__NavigationStatus__Sequence *
gkv2_motor_bridge__msg__NavigationStatus__Sequence__create(size_t size);

/// Destroy array of msg/NavigationStatus messages.
/**
 * It calls
 * gkv2_motor_bridge__msg__NavigationStatus__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkv2_motor_bridge
void
gkv2_motor_bridge__msg__NavigationStatus__Sequence__destroy(gkv2_motor_bridge__msg__NavigationStatus__Sequence * array);

/// Check for msg/NavigationStatus message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkv2_motor_bridge
bool
gkv2_motor_bridge__msg__NavigationStatus__Sequence__are_equal(const gkv2_motor_bridge__msg__NavigationStatus__Sequence * lhs, const gkv2_motor_bridge__msg__NavigationStatus__Sequence * rhs);

/// Copy an array of msg/NavigationStatus messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_gkv2_motor_bridge
bool
gkv2_motor_bridge__msg__NavigationStatus__Sequence__copy(
  const gkv2_motor_bridge__msg__NavigationStatus__Sequence * input,
  gkv2_motor_bridge__msg__NavigationStatus__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // GKV2_MOTOR_BRIDGE__MSG__DETAIL__NAVIGATION_STATUS__FUNCTIONS_H_
