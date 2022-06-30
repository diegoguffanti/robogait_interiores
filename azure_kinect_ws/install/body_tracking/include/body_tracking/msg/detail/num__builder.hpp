// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from body_tracking:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef BODY_TRACKING__MSG__DETAIL__NUM__BUILDER_HPP_
#define BODY_TRACKING__MSG__DETAIL__NUM__BUILDER_HPP_

#include "body_tracking/msg/detail/num__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace body_tracking
{

namespace msg
{

namespace builder
{

class Init_Num_num
{
public:
  Init_Num_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::body_tracking::msg::Num num(::body_tracking::msg::Num::_num_type arg)
  {
    msg_.num = std::move(arg);
    return std::move(msg_);
  }

private:
  ::body_tracking::msg::Num msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::body_tracking::msg::Num>()
{
  return body_tracking::msg::builder::Init_Num_num();
}

}  // namespace body_tracking

#endif  // BODY_TRACKING__MSG__DETAIL__NUM__BUILDER_HPP_
