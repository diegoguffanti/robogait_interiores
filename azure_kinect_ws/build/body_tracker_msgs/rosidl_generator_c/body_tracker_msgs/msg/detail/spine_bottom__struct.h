// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from body_tracker_msgs:msg/SpineBottom.idl
// generated code does not contain a copyright notice

#ifndef BODY_TRACKER_MSGS__MSG__DETAIL__SPINE_BOTTOM__STRUCT_H_
#define BODY_TRACKER_MSGS__MSG__DETAIL__SPINE_BOTTOM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'joint_position_spine_bottom'
#include "geometry_msgs/msg/detail/point32__struct.h"

// Struct defined in msg/SpineBottom in the package body_tracker_msgs.
typedef struct body_tracker_msgs__msg__SpineBottom
{
  int32_t body_id;
  double tiempo;
  geometry_msgs__msg__Point32 joint_position_spine_bottom;
} body_tracker_msgs__msg__SpineBottom;

// Struct for a sequence of body_tracker_msgs__msg__SpineBottom.
typedef struct body_tracker_msgs__msg__SpineBottom__Sequence
{
  body_tracker_msgs__msg__SpineBottom * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} body_tracker_msgs__msg__SpineBottom__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BODY_TRACKER_MSGS__MSG__DETAIL__SPINE_BOTTOM__STRUCT_H_
