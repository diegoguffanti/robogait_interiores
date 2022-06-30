// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from body_tracker_msgs:msg/SpineBottom.idl
// generated code does not contain a copyright notice

#ifndef BODY_TRACKER_MSGS__MSG__DETAIL__SPINE_BOTTOM__FUNCTIONS_H_
#define BODY_TRACKER_MSGS__MSG__DETAIL__SPINE_BOTTOM__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "body_tracker_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "body_tracker_msgs/msg/detail/spine_bottom__struct.h"

/// Initialize msg/SpineBottom message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * body_tracker_msgs__msg__SpineBottom
 * )) before or use
 * body_tracker_msgs__msg__SpineBottom__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_body_tracker_msgs
bool
body_tracker_msgs__msg__SpineBottom__init(body_tracker_msgs__msg__SpineBottom * msg);

/// Finalize msg/SpineBottom message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_body_tracker_msgs
void
body_tracker_msgs__msg__SpineBottom__fini(body_tracker_msgs__msg__SpineBottom * msg);

/// Create msg/SpineBottom message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * body_tracker_msgs__msg__SpineBottom__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_body_tracker_msgs
body_tracker_msgs__msg__SpineBottom *
body_tracker_msgs__msg__SpineBottom__create();

/// Destroy msg/SpineBottom message.
/**
 * It calls
 * body_tracker_msgs__msg__SpineBottom__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_body_tracker_msgs
void
body_tracker_msgs__msg__SpineBottom__destroy(body_tracker_msgs__msg__SpineBottom * msg);


/// Initialize array of msg/SpineBottom messages.
/**
 * It allocates the memory for the number of elements and calls
 * body_tracker_msgs__msg__SpineBottom__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_body_tracker_msgs
bool
body_tracker_msgs__msg__SpineBottom__Sequence__init(body_tracker_msgs__msg__SpineBottom__Sequence * array, size_t size);

/// Finalize array of msg/SpineBottom messages.
/**
 * It calls
 * body_tracker_msgs__msg__SpineBottom__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_body_tracker_msgs
void
body_tracker_msgs__msg__SpineBottom__Sequence__fini(body_tracker_msgs__msg__SpineBottom__Sequence * array);

/// Create array of msg/SpineBottom messages.
/**
 * It allocates the memory for the array and calls
 * body_tracker_msgs__msg__SpineBottom__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_body_tracker_msgs
body_tracker_msgs__msg__SpineBottom__Sequence *
body_tracker_msgs__msg__SpineBottom__Sequence__create(size_t size);

/// Destroy array of msg/SpineBottom messages.
/**
 * It calls
 * body_tracker_msgs__msg__SpineBottom__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_body_tracker_msgs
void
body_tracker_msgs__msg__SpineBottom__Sequence__destroy(body_tracker_msgs__msg__SpineBottom__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // BODY_TRACKER_MSGS__MSG__DETAIL__SPINE_BOTTOM__FUNCTIONS_H_
