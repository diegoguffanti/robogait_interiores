// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from body_tracker_msgs:msg/SpineBottom.idl
// generated code does not contain a copyright notice
#include "body_tracker_msgs/msg/detail/spine_bottom__rosidl_typesupport_fastrtps_cpp.hpp"
#include "body_tracker_msgs/msg/detail/spine_bottom__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace geometry_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::Point32 &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  geometry_msgs::msg::Point32 &);
size_t get_serialized_size(
  const geometry_msgs::msg::Point32 &,
  size_t current_alignment);
size_t
max_serialized_size_Point32(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace geometry_msgs


namespace body_tracker_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_body_tracker_msgs
cdr_serialize(
  const body_tracker_msgs::msg::SpineBottom & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: body_id
  cdr << ros_message.body_id;
  // Member: tiempo
  cdr << ros_message.tiempo;
  // Member: joint_position_spine_bottom
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.joint_position_spine_bottom,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_body_tracker_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  body_tracker_msgs::msg::SpineBottom & ros_message)
{
  // Member: body_id
  cdr >> ros_message.body_id;

  // Member: tiempo
  cdr >> ros_message.tiempo;

  // Member: joint_position_spine_bottom
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.joint_position_spine_bottom);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_body_tracker_msgs
get_serialized_size(
  const body_tracker_msgs::msg::SpineBottom & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: body_id
  {
    size_t item_size = sizeof(ros_message.body_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tiempo
  {
    size_t item_size = sizeof(ros_message.tiempo);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: joint_position_spine_bottom

  current_alignment +=
    geometry_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.joint_position_spine_bottom, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_body_tracker_msgs
max_serialized_size_SpineBottom(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: body_id
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: tiempo
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: joint_position_spine_bottom
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        geometry_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Point32(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static bool _SpineBottom__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const body_tracker_msgs::msg::SpineBottom *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SpineBottom__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<body_tracker_msgs::msg::SpineBottom *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SpineBottom__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const body_tracker_msgs::msg::SpineBottom *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SpineBottom__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_SpineBottom(full_bounded, 0);
}

static message_type_support_callbacks_t _SpineBottom__callbacks = {
  "body_tracker_msgs::msg",
  "SpineBottom",
  _SpineBottom__cdr_serialize,
  _SpineBottom__cdr_deserialize,
  _SpineBottom__get_serialized_size,
  _SpineBottom__max_serialized_size
};

static rosidl_message_type_support_t _SpineBottom__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SpineBottom__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace body_tracker_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_body_tracker_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<body_tracker_msgs::msg::SpineBottom>()
{
  return &body_tracker_msgs::msg::typesupport_fastrtps_cpp::_SpineBottom__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, body_tracker_msgs, msg, SpineBottom)() {
  return &body_tracker_msgs::msg::typesupport_fastrtps_cpp::_SpineBottom__handle;
}

#ifdef __cplusplus
}
#endif
