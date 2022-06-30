// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from body_tracker_msgs:msg/SpineBottom.idl
// generated code does not contain a copyright notice
#include "body_tracker_msgs/msg/detail/spine_bottom__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `joint_position_spine_bottom`
#include "geometry_msgs/msg/detail/point32__functions.h"

bool
body_tracker_msgs__msg__SpineBottom__init(body_tracker_msgs__msg__SpineBottom * msg)
{
  if (!msg) {
    return false;
  }
  // body_id
  // tiempo
  // joint_position_spine_bottom
  if (!geometry_msgs__msg__Point32__init(&msg->joint_position_spine_bottom)) {
    body_tracker_msgs__msg__SpineBottom__fini(msg);
    return false;
  }
  return true;
}

void
body_tracker_msgs__msg__SpineBottom__fini(body_tracker_msgs__msg__SpineBottom * msg)
{
  if (!msg) {
    return;
  }
  // body_id
  // tiempo
  // joint_position_spine_bottom
  geometry_msgs__msg__Point32__fini(&msg->joint_position_spine_bottom);
}

body_tracker_msgs__msg__SpineBottom *
body_tracker_msgs__msg__SpineBottom__create()
{
  body_tracker_msgs__msg__SpineBottom * msg = (body_tracker_msgs__msg__SpineBottom *)malloc(sizeof(body_tracker_msgs__msg__SpineBottom));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(body_tracker_msgs__msg__SpineBottom));
  bool success = body_tracker_msgs__msg__SpineBottom__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
body_tracker_msgs__msg__SpineBottom__destroy(body_tracker_msgs__msg__SpineBottom * msg)
{
  if (msg) {
    body_tracker_msgs__msg__SpineBottom__fini(msg);
  }
  free(msg);
}


bool
body_tracker_msgs__msg__SpineBottom__Sequence__init(body_tracker_msgs__msg__SpineBottom__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  body_tracker_msgs__msg__SpineBottom * data = NULL;
  if (size) {
    data = (body_tracker_msgs__msg__SpineBottom *)calloc(size, sizeof(body_tracker_msgs__msg__SpineBottom));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = body_tracker_msgs__msg__SpineBottom__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        body_tracker_msgs__msg__SpineBottom__fini(&data[i - 1]);
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
body_tracker_msgs__msg__SpineBottom__Sequence__fini(body_tracker_msgs__msg__SpineBottom__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      body_tracker_msgs__msg__SpineBottom__fini(&array->data[i]);
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

body_tracker_msgs__msg__SpineBottom__Sequence *
body_tracker_msgs__msg__SpineBottom__Sequence__create(size_t size)
{
  body_tracker_msgs__msg__SpineBottom__Sequence * array = (body_tracker_msgs__msg__SpineBottom__Sequence *)malloc(sizeof(body_tracker_msgs__msg__SpineBottom__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = body_tracker_msgs__msg__SpineBottom__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
body_tracker_msgs__msg__SpineBottom__Sequence__destroy(body_tracker_msgs__msg__SpineBottom__Sequence * array)
{
  if (array) {
    body_tracker_msgs__msg__SpineBottom__Sequence__fini(array);
  }
  free(array);
}
