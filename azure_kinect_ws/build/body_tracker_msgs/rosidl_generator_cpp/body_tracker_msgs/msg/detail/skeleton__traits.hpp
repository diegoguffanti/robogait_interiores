// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from body_tracker_msgs:msg/Skeleton.idl
// generated code does not contain a copyright notice

#ifndef BODY_TRACKER_MSGS__MSG__DETAIL__SKELETON__TRAITS_HPP_
#define BODY_TRACKER_MSGS__MSG__DETAIL__SKELETON__TRAITS_HPP_

#include "body_tracker_msgs/msg/detail/skeleton__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'joint_position_head'
// Member 'joint_position_neck'
// Member 'joint_position_shoulder'
// Member 'joint_position_spine_top'
// Member 'joint_position_spine_mid'
// Member 'joint_position_spine_bottom'
// Member 'joint_position_left_shoulder'
// Member 'joint_position_left_elbow'
// Member 'joint_position_left_hand'
// Member 'joint_position_right_shoulder'
// Member 'joint_position_right_elbow'
// Member 'joint_position_right_hand'
// Member 'joint_position_right_hip'
// Member 'joint_position_right_knee'
// Member 'joint_position_right_ankle'
// Member 'joint_position_left_hip'
// Member 'joint_position_left_knee'
// Member 'joint_position_left_ankle'
#include "geometry_msgs/msg/detail/point32__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<body_tracker_msgs::msg::Skeleton>()
{
  return "body_tracker_msgs::msg::Skeleton";
}

template<>
inline const char * name<body_tracker_msgs::msg::Skeleton>()
{
  return "body_tracker_msgs/msg/Skeleton";
}

template<>
struct has_fixed_size<body_tracker_msgs::msg::Skeleton>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point32>::value> {};

template<>
struct has_bounded_size<body_tracker_msgs::msg::Skeleton>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point32>::value> {};

template<>
struct is_message<body_tracker_msgs::msg::Skeleton>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BODY_TRACKER_MSGS__MSG__DETAIL__SKELETON__TRAITS_HPP_
