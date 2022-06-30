// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from body_tracking:msg/Skeleton.idl
// generated code does not contain a copyright notice

#ifndef BODY_TRACKING__MSG__DETAIL__SKELETON__STRUCT_H_
#define BODY_TRACKING__MSG__DETAIL__SKELETON__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

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
#include "geometry_msgs/msg/detail/point32__struct.h"

// Struct defined in msg/Skeleton in the package body_tracking.
typedef struct body_tracking__msg__Skeleton
{
  int32_t body_id;
  double tiempo;
  geometry_msgs__msg__Point32 joint_position_head;
  geometry_msgs__msg__Point32 joint_position_neck;
  geometry_msgs__msg__Point32 joint_position_shoulder;
  geometry_msgs__msg__Point32 joint_position_spine_top;
  geometry_msgs__msg__Point32 joint_position_spine_mid;
  geometry_msgs__msg__Point32 joint_position_spine_bottom;
  geometry_msgs__msg__Point32 joint_position_left_shoulder;
  geometry_msgs__msg__Point32 joint_position_left_elbow;
  geometry_msgs__msg__Point32 joint_position_left_hand;
  geometry_msgs__msg__Point32 joint_position_right_shoulder;
  geometry_msgs__msg__Point32 joint_position_right_elbow;
  geometry_msgs__msg__Point32 joint_position_right_hand;
  geometry_msgs__msg__Point32 joint_position_right_hip;
  geometry_msgs__msg__Point32 joint_position_right_knee;
  geometry_msgs__msg__Point32 joint_position_right_ankle;
  geometry_msgs__msg__Point32 joint_position_left_hip;
  geometry_msgs__msg__Point32 joint_position_left_knee;
  geometry_msgs__msg__Point32 joint_position_left_ankle;
} body_tracking__msg__Skeleton;

// Struct for a sequence of body_tracking__msg__Skeleton.
typedef struct body_tracking__msg__Skeleton__Sequence
{
  body_tracking__msg__Skeleton * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} body_tracking__msg__Skeleton__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BODY_TRACKING__MSG__DETAIL__SKELETON__STRUCT_H_
