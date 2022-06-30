// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from body_tracking:msg/HipCoordinates.idl
// generated code does not contain a copyright notice

#ifndef BODY_TRACKING__MSG__DETAIL__HIP_COORDINATES__TRAITS_HPP_
#define BODY_TRACKING__MSG__DETAIL__HIP_COORDINATES__TRAITS_HPP_

#include "body_tracking/msg/detail/hip_coordinates__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<body_tracking::msg::HipCoordinates>()
{
  return "body_tracking::msg::HipCoordinates";
}

template<>
inline const char * name<body_tracking::msg::HipCoordinates>()
{
  return "body_tracking/msg/HipCoordinates";
}

template<>
struct has_fixed_size<body_tracking::msg::HipCoordinates>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<body_tracking::msg::HipCoordinates>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<body_tracking::msg::HipCoordinates>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BODY_TRACKING__MSG__DETAIL__HIP_COORDINATES__TRAITS_HPP_
