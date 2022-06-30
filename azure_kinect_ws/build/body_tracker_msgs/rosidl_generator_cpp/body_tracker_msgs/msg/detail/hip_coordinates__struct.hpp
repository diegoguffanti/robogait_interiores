// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from body_tracker_msgs:msg/HipCoordinates.idl
// generated code does not contain a copyright notice

#ifndef BODY_TRACKER_MSGS__MSG__DETAIL__HIP_COORDINATES__STRUCT_HPP_
#define BODY_TRACKER_MSGS__MSG__DETAIL__HIP_COORDINATES__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__body_tracker_msgs__msg__HipCoordinates __attribute__((deprecated))
#else
# define DEPRECATED__body_tracker_msgs__msg__HipCoordinates __declspec(deprecated)
#endif

namespace body_tracker_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HipCoordinates_
{
  using Type = HipCoordinates_<ContainerAllocator>;

  explicit HipCoordinates_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
    }
  }

  explicit HipCoordinates_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _z_type =
    double;
  _z_type z;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const double & _arg)
  {
    this->z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    body_tracker_msgs::msg::HipCoordinates_<ContainerAllocator> *;
  using ConstRawPtr =
    const body_tracker_msgs::msg::HipCoordinates_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<body_tracker_msgs::msg::HipCoordinates_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<body_tracker_msgs::msg::HipCoordinates_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      body_tracker_msgs::msg::HipCoordinates_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<body_tracker_msgs::msg::HipCoordinates_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      body_tracker_msgs::msg::HipCoordinates_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<body_tracker_msgs::msg::HipCoordinates_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<body_tracker_msgs::msg::HipCoordinates_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<body_tracker_msgs::msg::HipCoordinates_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__body_tracker_msgs__msg__HipCoordinates
    std::shared_ptr<body_tracker_msgs::msg::HipCoordinates_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__body_tracker_msgs__msg__HipCoordinates
    std::shared_ptr<body_tracker_msgs::msg::HipCoordinates_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HipCoordinates_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    return true;
  }
  bool operator!=(const HipCoordinates_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HipCoordinates_

// alias to use template instance with default allocator
using HipCoordinates =
  body_tracker_msgs::msg::HipCoordinates_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace body_tracker_msgs

#endif  // BODY_TRACKER_MSGS__MSG__DETAIL__HIP_COORDINATES__STRUCT_HPP_
