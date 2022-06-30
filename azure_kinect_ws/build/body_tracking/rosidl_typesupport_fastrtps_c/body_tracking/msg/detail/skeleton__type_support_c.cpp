// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from body_tracking:msg/Skeleton.idl
// generated code does not contain a copyright notice
#include "body_tracking/msg/detail/skeleton__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "body_tracking/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "body_tracking/msg/detail/skeleton__struct.h"
#include "body_tracking/msg/detail/skeleton__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "geometry_msgs/msg/detail/point32__functions.h"  // joint_position_head, joint_position_left_ankle, joint_position_left_elbow, joint_position_left_hand, joint_position_left_hip, joint_position_left_knee, joint_position_left_shoulder, joint_position_neck, joint_position_right_ankle, joint_position_right_elbow, joint_position_right_hand, joint_position_right_hip, joint_position_right_knee, joint_position_right_shoulder, joint_position_shoulder, joint_position_spine_bottom, joint_position_spine_mid, joint_position_spine_top

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_body_tracking
size_t get_serialized_size_geometry_msgs__msg__Point32(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_body_tracking
size_t max_serialized_size_geometry_msgs__msg__Point32(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_body_tracking
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32)();


using _Skeleton__ros_msg_type = body_tracking__msg__Skeleton;

static bool _Skeleton__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Skeleton__ros_msg_type * ros_message = static_cast<const _Skeleton__ros_msg_type *>(untyped_ros_message);
  // Field name: body_id
  {
    cdr << ros_message->body_id;
  }

  // Field name: tiempo
  {
    cdr << ros_message->tiempo;
  }

  // Field name: joint_position_head
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->joint_position_head, cdr))
    {
      return false;
    }
  }

  // Field name: joint_position_neck
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->joint_position_neck, cdr))
    {
      return false;
    }
  }

  // Field name: joint_position_shoulder
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->joint_position_shoulder, cdr))
    {
      return false;
    }
  }

  // Field name: joint_position_spine_top
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->joint_position_spine_top, cdr))
    {
      return false;
    }
  }

  // Field name: joint_position_spine_mid
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->joint_position_spine_mid, cdr))
    {
      return false;
    }
  }

  // Field name: joint_position_spine_bottom
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->joint_position_spine_bottom, cdr))
    {
      return false;
    }
  }

  // Field name: joint_position_left_shoulder
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->joint_position_left_shoulder, cdr))
    {
      return false;
    }
  }

  // Field name: joint_position_left_elbow
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->joint_position_left_elbow, cdr))
    {
      return false;
    }
  }

  // Field name: joint_position_left_hand
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->joint_position_left_hand, cdr))
    {
      return false;
    }
  }

  // Field name: joint_position_right_shoulder
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->joint_position_right_shoulder, cdr))
    {
      return false;
    }
  }

  // Field name: joint_position_right_elbow
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->joint_position_right_elbow, cdr))
    {
      return false;
    }
  }

  // Field name: joint_position_right_hand
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->joint_position_right_hand, cdr))
    {
      return false;
    }
  }

  // Field name: joint_position_right_hip
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->joint_position_right_hip, cdr))
    {
      return false;
    }
  }

  // Field name: joint_position_right_knee
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->joint_position_right_knee, cdr))
    {
      return false;
    }
  }

  // Field name: joint_position_right_ankle
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->joint_position_right_ankle, cdr))
    {
      return false;
    }
  }

  // Field name: joint_position_left_hip
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->joint_position_left_hip, cdr))
    {
      return false;
    }
  }

  // Field name: joint_position_left_knee
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->joint_position_left_knee, cdr))
    {
      return false;
    }
  }

  // Field name: joint_position_left_ankle
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->joint_position_left_ankle, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _Skeleton__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Skeleton__ros_msg_type * ros_message = static_cast<_Skeleton__ros_msg_type *>(untyped_ros_message);
  // Field name: body_id
  {
    cdr >> ros_message->body_id;
  }

  // Field name: tiempo
  {
    cdr >> ros_message->tiempo;
  }

  // Field name: joint_position_head
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->joint_position_head))
    {
      return false;
    }
  }

  // Field name: joint_position_neck
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->joint_position_neck))
    {
      return false;
    }
  }

  // Field name: joint_position_shoulder
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->joint_position_shoulder))
    {
      return false;
    }
  }

  // Field name: joint_position_spine_top
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->joint_position_spine_top))
    {
      return false;
    }
  }

  // Field name: joint_position_spine_mid
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->joint_position_spine_mid))
    {
      return false;
    }
  }

  // Field name: joint_position_spine_bottom
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->joint_position_spine_bottom))
    {
      return false;
    }
  }

  // Field name: joint_position_left_shoulder
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->joint_position_left_shoulder))
    {
      return false;
    }
  }

  // Field name: joint_position_left_elbow
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->joint_position_left_elbow))
    {
      return false;
    }
  }

  // Field name: joint_position_left_hand
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->joint_position_left_hand))
    {
      return false;
    }
  }

  // Field name: joint_position_right_shoulder
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->joint_position_right_shoulder))
    {
      return false;
    }
  }

  // Field name: joint_position_right_elbow
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->joint_position_right_elbow))
    {
      return false;
    }
  }

  // Field name: joint_position_right_hand
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->joint_position_right_hand))
    {
      return false;
    }
  }

  // Field name: joint_position_right_hip
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->joint_position_right_hip))
    {
      return false;
    }
  }

  // Field name: joint_position_right_knee
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->joint_position_right_knee))
    {
      return false;
    }
  }

  // Field name: joint_position_right_ankle
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->joint_position_right_ankle))
    {
      return false;
    }
  }

  // Field name: joint_position_left_hip
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->joint_position_left_hip))
    {
      return false;
    }
  }

  // Field name: joint_position_left_knee
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->joint_position_left_knee))
    {
      return false;
    }
  }

  // Field name: joint_position_left_ankle
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Point32
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->joint_position_left_ankle))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_body_tracking
size_t get_serialized_size_body_tracking__msg__Skeleton(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Skeleton__ros_msg_type * ros_message = static_cast<const _Skeleton__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name body_id
  {
    size_t item_size = sizeof(ros_message->body_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tiempo
  {
    size_t item_size = sizeof(ros_message->tiempo);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name joint_position_head

  current_alignment += get_serialized_size_geometry_msgs__msg__Point32(
    &(ros_message->joint_position_head), current_alignment);
  // field.name joint_position_neck

  current_alignment += get_serialized_size_geometry_msgs__msg__Point32(
    &(ros_message->joint_position_neck), current_alignment);
  // field.name joint_position_shoulder

  current_alignment += get_serialized_size_geometry_msgs__msg__Point32(
    &(ros_message->joint_position_shoulder), current_alignment);
  // field.name joint_position_spine_top

  current_alignment += get_serialized_size_geometry_msgs__msg__Point32(
    &(ros_message->joint_position_spine_top), current_alignment);
  // field.name joint_position_spine_mid

  current_alignment += get_serialized_size_geometry_msgs__msg__Point32(
    &(ros_message->joint_position_spine_mid), current_alignment);
  // field.name joint_position_spine_bottom

  current_alignment += get_serialized_size_geometry_msgs__msg__Point32(
    &(ros_message->joint_position_spine_bottom), current_alignment);
  // field.name joint_position_left_shoulder

  current_alignment += get_serialized_size_geometry_msgs__msg__Point32(
    &(ros_message->joint_position_left_shoulder), current_alignment);
  // field.name joint_position_left_elbow

  current_alignment += get_serialized_size_geometry_msgs__msg__Point32(
    &(ros_message->joint_position_left_elbow), current_alignment);
  // field.name joint_position_left_hand

  current_alignment += get_serialized_size_geometry_msgs__msg__Point32(
    &(ros_message->joint_position_left_hand), current_alignment);
  // field.name joint_position_right_shoulder

  current_alignment += get_serialized_size_geometry_msgs__msg__Point32(
    &(ros_message->joint_position_right_shoulder), current_alignment);
  // field.name joint_position_right_elbow

  current_alignment += get_serialized_size_geometry_msgs__msg__Point32(
    &(ros_message->joint_position_right_elbow), current_alignment);
  // field.name joint_position_right_hand

  current_alignment += get_serialized_size_geometry_msgs__msg__Point32(
    &(ros_message->joint_position_right_hand), current_alignment);
  // field.name joint_position_right_hip

  current_alignment += get_serialized_size_geometry_msgs__msg__Point32(
    &(ros_message->joint_position_right_hip), current_alignment);
  // field.name joint_position_right_knee

  current_alignment += get_serialized_size_geometry_msgs__msg__Point32(
    &(ros_message->joint_position_right_knee), current_alignment);
  // field.name joint_position_right_ankle

  current_alignment += get_serialized_size_geometry_msgs__msg__Point32(
    &(ros_message->joint_position_right_ankle), current_alignment);
  // field.name joint_position_left_hip

  current_alignment += get_serialized_size_geometry_msgs__msg__Point32(
    &(ros_message->joint_position_left_hip), current_alignment);
  // field.name joint_position_left_knee

  current_alignment += get_serialized_size_geometry_msgs__msg__Point32(
    &(ros_message->joint_position_left_knee), current_alignment);
  // field.name joint_position_left_ankle

  current_alignment += get_serialized_size_geometry_msgs__msg__Point32(
    &(ros_message->joint_position_left_ankle), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _Skeleton__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_body_tracking__msg__Skeleton(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_body_tracking
size_t max_serialized_size_body_tracking__msg__Skeleton(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: body_id
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: tiempo
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: joint_position_head
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Point32(
        full_bounded, current_alignment);
    }
  }
  // member: joint_position_neck
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Point32(
        full_bounded, current_alignment);
    }
  }
  // member: joint_position_shoulder
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Point32(
        full_bounded, current_alignment);
    }
  }
  // member: joint_position_spine_top
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Point32(
        full_bounded, current_alignment);
    }
  }
  // member: joint_position_spine_mid
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Point32(
        full_bounded, current_alignment);
    }
  }
  // member: joint_position_spine_bottom
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Point32(
        full_bounded, current_alignment);
    }
  }
  // member: joint_position_left_shoulder
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Point32(
        full_bounded, current_alignment);
    }
  }
  // member: joint_position_left_elbow
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Point32(
        full_bounded, current_alignment);
    }
  }
  // member: joint_position_left_hand
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Point32(
        full_bounded, current_alignment);
    }
  }
  // member: joint_position_right_shoulder
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Point32(
        full_bounded, current_alignment);
    }
  }
  // member: joint_position_right_elbow
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Point32(
        full_bounded, current_alignment);
    }
  }
  // member: joint_position_right_hand
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Point32(
        full_bounded, current_alignment);
    }
  }
  // member: joint_position_right_hip
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Point32(
        full_bounded, current_alignment);
    }
  }
  // member: joint_position_right_knee
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Point32(
        full_bounded, current_alignment);
    }
  }
  // member: joint_position_right_ankle
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Point32(
        full_bounded, current_alignment);
    }
  }
  // member: joint_position_left_hip
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Point32(
        full_bounded, current_alignment);
    }
  }
  // member: joint_position_left_knee
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Point32(
        full_bounded, current_alignment);
    }
  }
  // member: joint_position_left_ankle
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Point32(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _Skeleton__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_body_tracking__msg__Skeleton(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Skeleton = {
  "body_tracking::msg",
  "Skeleton",
  _Skeleton__cdr_serialize,
  _Skeleton__cdr_deserialize,
  _Skeleton__get_serialized_size,
  _Skeleton__max_serialized_size
};

static rosidl_message_type_support_t _Skeleton__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Skeleton,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, body_tracking, msg, Skeleton)() {
  return &_Skeleton__type_support;
}

#if defined(__cplusplus)
}
#endif
