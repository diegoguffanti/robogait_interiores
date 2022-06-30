// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from body_tracking:msg/HipCoordinates.idl
// generated code does not contain a copyright notice

#ifndef BODY_TRACKING__MSG__DETAIL__HIP_COORDINATES__BUILDER_HPP_
#define BODY_TRACKING__MSG__DETAIL__HIP_COORDINATES__BUILDER_HPP_

#include "body_tracking/msg/detail/hip_coordinates__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace body_tracking
{

namespace msg
{

namespace builder
{

class Init_HipCoordinates_z
{
public:
  explicit Init_HipCoordinates_z(::body_tracking::msg::HipCoordinates & msg)
  : msg_(msg)
  {}
  ::body_tracking::msg::HipCoordinates z(::body_tracking::msg::HipCoordinates::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::body_tracking::msg::HipCoordinates msg_;
};

class Init_HipCoordinates_y
{
public:
  explicit Init_HipCoordinates_y(::body_tracking::msg::HipCoordinates & msg)
  : msg_(msg)
  {}
  Init_HipCoordinates_z y(::body_tracking::msg::HipCoordinates::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_HipCoordinates_z(msg_);
  }

private:
  ::body_tracking::msg::HipCoordinates msg_;
};

class Init_HipCoordinates_x
{
public:
  Init_HipCoordinates_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HipCoordinates_y x(::body_tracking::msg::HipCoordinates::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_HipCoordinates_y(msg_);
  }

private:
  ::body_tracking::msg::HipCoordinates msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::body_tracking::msg::HipCoordinates>()
{
  return body_tracking::msg::builder::Init_HipCoordinates_x();
}

}  // namespace body_tracking

#endif  // BODY_TRACKING__MSG__DETAIL__HIP_COORDINATES__BUILDER_HPP_
