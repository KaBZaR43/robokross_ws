// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gkv2_motor_bridge:msg/NavigationStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "gkv2_motor_bridge/msg/navigation_status.hpp"


#ifndef GKV2_MOTOR_BRIDGE__MSG__DETAIL__NAVIGATION_STATUS__STRUCT_HPP_
#define GKV2_MOTOR_BRIDGE__MSG__DETAIL__NAVIGATION_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__gkv2_motor_bridge__msg__NavigationStatus __attribute__((deprecated))
#else
# define DEPRECATED__gkv2_motor_bridge__msg__NavigationStatus __declspec(deprecated)
#endif

namespace gkv2_motor_bridge
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavigationStatus_
{
  using Type = NavigationStatus_<ContainerAllocator>;

  explicit NavigationStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->current_mode = 0;
      this->gnss_available = false;
      this->rtk_fixed = false;
      this->gnss_satellites = 0;
      this->gnss_quality = 0.0f;
      this->odometry_drift = 0.0f;
      this->time_since_gnss = 0.0f;
      this->status_message = "";
    }
  }

  explicit NavigationStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : status_message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->current_mode = 0;
      this->gnss_available = false;
      this->rtk_fixed = false;
      this->gnss_satellites = 0;
      this->gnss_quality = 0.0f;
      this->odometry_drift = 0.0f;
      this->time_since_gnss = 0.0f;
      this->status_message = "";
    }
  }

  // field types and members
  using _current_mode_type =
    uint8_t;
  _current_mode_type current_mode;
  using _gnss_available_type =
    bool;
  _gnss_available_type gnss_available;
  using _rtk_fixed_type =
    bool;
  _rtk_fixed_type rtk_fixed;
  using _gnss_satellites_type =
    uint16_t;
  _gnss_satellites_type gnss_satellites;
  using _gnss_quality_type =
    float;
  _gnss_quality_type gnss_quality;
  using _odometry_drift_type =
    float;
  _odometry_drift_type odometry_drift;
  using _time_since_gnss_type =
    float;
  _time_since_gnss_type time_since_gnss;
  using _status_message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_message_type status_message;

  // setters for named parameter idiom
  Type & set__current_mode(
    const uint8_t & _arg)
  {
    this->current_mode = _arg;
    return *this;
  }
  Type & set__gnss_available(
    const bool & _arg)
  {
    this->gnss_available = _arg;
    return *this;
  }
  Type & set__rtk_fixed(
    const bool & _arg)
  {
    this->rtk_fixed = _arg;
    return *this;
  }
  Type & set__gnss_satellites(
    const uint16_t & _arg)
  {
    this->gnss_satellites = _arg;
    return *this;
  }
  Type & set__gnss_quality(
    const float & _arg)
  {
    this->gnss_quality = _arg;
    return *this;
  }
  Type & set__odometry_drift(
    const float & _arg)
  {
    this->odometry_drift = _arg;
    return *this;
  }
  Type & set__time_since_gnss(
    const float & _arg)
  {
    this->time_since_gnss = _arg;
    return *this;
  }
  Type & set__status_message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status_message = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t MODE_GNSS =
    0u;
  static constexpr uint8_t MODE_ODOMETRY =
    1u;
  static constexpr uint8_t MODE_FUSION =
    2u;

  // pointer types
  using RawPtr =
    gkv2_motor_bridge::msg::NavigationStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const gkv2_motor_bridge::msg::NavigationStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gkv2_motor_bridge::msg::NavigationStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gkv2_motor_bridge::msg::NavigationStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gkv2_motor_bridge::msg::NavigationStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gkv2_motor_bridge::msg::NavigationStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gkv2_motor_bridge::msg::NavigationStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gkv2_motor_bridge::msg::NavigationStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gkv2_motor_bridge::msg::NavigationStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gkv2_motor_bridge::msg::NavigationStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gkv2_motor_bridge__msg__NavigationStatus
    std::shared_ptr<gkv2_motor_bridge::msg::NavigationStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gkv2_motor_bridge__msg__NavigationStatus
    std::shared_ptr<gkv2_motor_bridge::msg::NavigationStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavigationStatus_ & other) const
  {
    if (this->current_mode != other.current_mode) {
      return false;
    }
    if (this->gnss_available != other.gnss_available) {
      return false;
    }
    if (this->rtk_fixed != other.rtk_fixed) {
      return false;
    }
    if (this->gnss_satellites != other.gnss_satellites) {
      return false;
    }
    if (this->gnss_quality != other.gnss_quality) {
      return false;
    }
    if (this->odometry_drift != other.odometry_drift) {
      return false;
    }
    if (this->time_since_gnss != other.time_since_gnss) {
      return false;
    }
    if (this->status_message != other.status_message) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavigationStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavigationStatus_

// alias to use template instance with default allocator
using NavigationStatus =
  gkv2_motor_bridge::msg::NavigationStatus_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavigationStatus_<ContainerAllocator>::MODE_GNSS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavigationStatus_<ContainerAllocator>::MODE_ODOMETRY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t NavigationStatus_<ContainerAllocator>::MODE_FUSION;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace gkv2_motor_bridge

#endif  // GKV2_MOTOR_BRIDGE__MSG__DETAIL__NAVIGATION_STATUS__STRUCT_HPP_
