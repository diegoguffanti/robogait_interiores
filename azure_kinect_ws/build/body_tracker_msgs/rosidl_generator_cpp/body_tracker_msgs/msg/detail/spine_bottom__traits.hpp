// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from body_tracker_msgs:msg/SpineBottom.idl
// generated code does not contain a copyright notice

#ifndef BODY_TRACKER_MSGS__MSG__DETAIL__SPINE_BOTTOM__TRAITS_HPP_
#define BODY_TRACKER_MSGS__MSG__DETAIL__SPINE_BOTTOM__TRAITS_HPP_

#include "body_tracker_msgs/msg/detail/spine_bottom__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'joint_position_spine_bottom'
#include "geometry_msgs/msg/detail/point32__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<body_tracker_msgs::msg::SpineBottom>()
{
  return "body_tracker_msgs::msg::SpineBottom";
}

template<>
inline const char * name<body_tracker_msgs::msg::SpineBottom>()
{
  return "body_tracker_msgs/msg/SpineBottom";
}

template<>
struct has_fixed_size<body_tracker_msgs::msg::SpineBottom>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point32>::value> {};

template<>
struct has_bounded_size<body_tracker_msgs::msg::SpineBottom>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point32>::value> {};

template<>
struct is_message<body_tracker_msgs::msg::SpineBottom>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BODY_TRACKER_MSGS__MSG__DETAIL__SPINE_BOTTOM__TRAITS_HPP_
