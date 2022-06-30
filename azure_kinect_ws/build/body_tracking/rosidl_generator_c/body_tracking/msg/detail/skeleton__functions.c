// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from body_tracking:msg/Skeleton.idl
// generated code does not contain a copyright notice
#include "body_tracking/msg/detail/skeleton__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `joint_position_head`
// Member `joint_position_neck`
// Member `joint_position_shoulder`
// Member `joint_position_spine_top`
// Member `joint_position_spine_mid`
// Member `joint_position_spine_bottom`
// Member `joint_position_left_shoulder`
// Member `joint_position_left_elbow`
// Member `joint_position_left_hand`
// Member `joint_position_right_shoulder`
// Member `joint_position_right_elbow`
// Member `joint_position_right_hand`
// Member `joint_position_right_hip`
// Member `joint_position_right_knee`
// Member `joint_position_right_ankle`
// Member `joint_position_left_hip`
// Member `joint_position_left_knee`
// Member `joint_position_left_ankle`
#include "geometry_msgs/msg/detail/point32__functions.h"

bool
body_tracking__msg__Skeleton__init(body_tracking__msg__Skeleton * msg)
{
  if (!msg) {
    return false;
  }
  // body_id
  // tiempo
  // joint_position_head
  if (!geometry_msgs__msg__Point32__init(&msg->joint_position_head)) {
    body_tracking__msg__Skeleton__fini(msg);
    return false;
  }
  // joint_position_neck
  if (!geometry_msgs__msg__Point32__init(&msg->joint_position_neck)) {
    body_tracking__msg__Skeleton__fini(msg);
    return false;
  }
  // joint_position_shoulder
  if (!geometry_msgs__msg__Point32__init(&msg->joint_position_shoulder)) {
    body_tracking__msg__Skeleton__fini(msg);
    return false;
  }
  // joint_position_spine_top
  if (!geometry_msgs__msg__Point32__init(&msg->joint_position_spine_top)) {
    body_tracking__msg__Skeleton__fini(msg);
    return false;
  }
  // joint_position_spine_mid
  if (!geometry_msgs__msg__Point32__init(&msg->joint_position_spine_mid)) {
    body_tracking__msg__Skeleton__fini(msg);
    return false;
  }
  // joint_position_spine_bottom
  if (!geometry_msgs__msg__Point32__init(&msg->joint_position_spine_bottom)) {
    body_tracking__msg__Skeleton__fini(msg);
    return false;
  }
  // joint_position_left_shoulder
  if (!geometry_msgs__msg__Point32__init(&msg->joint_position_left_shoulder)) {
    body_tracking__msg__Skeleton__fini(msg);
    return false;
  }
  // joint_position_left_elbow
  if (!geometry_msgs__msg__Point32__init(&msg->joint_position_left_elbow)) {
    body_tracking__msg__Skeleton__fini(msg);
    return false;
  }
  // joint_position_left_hand
  if (!geometry_msgs__msg__Point32__init(&msg->joint_position_left_hand)) {
    body_tracking__msg__Skeleton__fini(msg);
    return false;
  }
  // joint_position_right_shoulder
  if (!geometry_msgs__msg__Point32__init(&msg->joint_position_right_shoulder)) {
    body_tracking__msg__Skeleton__fini(msg);
    return false;
  }
  // joint_position_right_elbow
  if (!geometry_msgs__msg__Point32__init(&msg->joint_position_right_elbow)) {
    body_tracking__msg__Skeleton__fini(msg);
    return false;
  }
  // joint_position_right_hand
  if (!geometry_msgs__msg__Point32__init(&msg->joint_position_right_hand)) {
    body_tracking__msg__Skeleton__fini(msg);
    return false;
  }
  // joint_position_right_hip
  if (!geometry_msgs__msg__Point32__init(&msg->joint_position_right_hip)) {
    body_tracking__msg__Skeleton__fini(msg);
    return false;
  }
  // joint_position_right_knee
  if (!geometry_msgs__msg__Point32__init(&msg->joint_position_right_knee)) {
    body_tracking__msg__Skeleton__fini(msg);
    return false;
  }
  // joint_position_right_ankle
  if (!geometry_msgs__msg__Point32__init(&msg->joint_position_right_ankle)) {
    body_tracking__msg__Skeleton__fini(msg);
    return false;
  }
  // joint_position_left_hip
  if (!geometry_msgs__msg__Point32__init(&msg->joint_position_left_hip)) {
    body_tracking__msg__Skeleton__fini(msg);
    return false;
  }
  // joint_position_left_knee
  if (!geometry_msgs__msg__Point32__init(&msg->joint_position_left_knee)) {
    body_tracking__msg__Skeleton__fini(msg);
    return false;
  }
  // joint_position_left_ankle
  if (!geometry_msgs__msg__Point32__init(&msg->joint_position_left_ankle)) {
    body_tracking__msg__Skeleton__fini(msg);
    return false;
  }
  return true;
}

void
body_tracking__msg__Skeleton__fini(body_tracking__msg__Skeleton * msg)
{
  if (!msg) {
    return;
  }
  // body_id
  // tiempo
  // joint_position_head
  geometry_msgs__msg__Point32__fini(&msg->joint_position_head);
  // joint_position_neck
  geometry_msgs__msg__Point32__fini(&msg->joint_position_neck);
  // joint_position_shoulder
  geometry_msgs__msg__Point32__fini(&msg->joint_position_shoulder);
  // joint_position_spine_top
  geometry_msgs__msg__Point32__fini(&msg->joint_position_spine_top);
  // joint_position_spine_mid
  geometry_msgs__msg__Point32__fini(&msg->joint_position_spine_mid);
  // joint_position_spine_bottom
  geometry_msgs__msg__Point32__fini(&msg->joint_position_spine_bottom);
  // joint_position_left_shoulder
  geometry_msgs__msg__Point32__fini(&msg->joint_position_left_shoulder);
  // joint_position_left_elbow
  geometry_msgs__msg__Point32__fini(&msg->joint_position_left_elbow);
  // joint_position_left_hand
  geometry_msgs__msg__Point32__fini(&msg->joint_position_left_hand);
  // joint_position_right_shoulder
  geometry_msgs__msg__Point32__fini(&msg->joint_position_right_shoulder);
  // joint_position_right_elbow
  geometry_msgs__msg__Point32__fini(&msg->joint_position_right_elbow);
  // joint_position_right_hand
  geometry_msgs__msg__Point32__fini(&msg->joint_position_right_hand);
  // joint_position_right_hip
  geometry_msgs__msg__Point32__fini(&msg->joint_position_right_hip);
  // joint_position_right_knee
  geometry_msgs__msg__Point32__fini(&msg->joint_position_right_knee);
  // joint_position_right_ankle
  geometry_msgs__msg__Point32__fini(&msg->joint_position_right_ankle);
  // joint_position_left_hip
  geometry_msgs__msg__Point32__fini(&msg->joint_position_left_hip);
  // joint_position_left_knee
  geometry_msgs__msg__Point32__fini(&msg->joint_position_left_knee);
  // joint_position_left_ankle
  geometry_msgs__msg__Point32__fini(&msg->joint_position_left_ankle);
}

body_tracking__msg__Skeleton *
body_tracking__msg__Skeleton__create()
{
  body_tracking__msg__Skeleton * msg = (body_tracking__msg__Skeleton *)malloc(sizeof(body_tracking__msg__Skeleton));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(body_tracking__msg__Skeleton));
  bool success = body_tracking__msg__Skeleton__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
body_tracking__msg__Skeleton__destroy(body_tracking__msg__Skeleton * msg)
{
  if (msg) {
    body_tracking__msg__Skeleton__fini(msg);
  }
  free(msg);
}


bool
body_tracking__msg__Skeleton__Sequence__init(body_tracking__msg__Skeleton__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  body_tracking__msg__Skeleton * data = NULL;
  if (size) {
    data = (body_tracking__msg__Skeleton *)calloc(size, sizeof(body_tracking__msg__Skeleton));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = body_tracking__msg__Skeleton__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        body_tracking__msg__Skeleton__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
body_tracking__msg__Skeleton__Sequence__fini(body_tracking__msg__Skeleton__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      body_tracking__msg__Skeleton__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

body_tracking__msg__Skeleton__Sequence *
body_tracking__msg__Skeleton__Sequence__create(size_t size)
{
  body_tracking__msg__Skeleton__Sequence * array = (body_tracking__msg__Skeleton__Sequence *)malloc(sizeof(body_tracking__msg__Skeleton__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = body_tracking__msg__Skeleton__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
body_tracking__msg__Skeleton__Sequence__destroy(body_tracking__msg__Skeleton__Sequence * array)
{
  if (array) {
    body_tracking__msg__Skeleton__Sequence__fini(array);
  }
  free(array);
}
