// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from body_tracking:msg/HipCoordinates.idl
// generated code does not contain a copyright notice

#ifndef BODY_TRACKING__MSG__DETAIL__HIP_COORDINATES__FUNCTIONS_H_
#define BODY_TRACKING__MSG__DETAIL__HIP_COORDINATES__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "body_tracking/msg/rosidl_generator_c__visibility_control.h"

#include "body_tracking/msg/detail/hip_coordinates__struct.h"

/// Initialize msg/HipCoordinates message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * body_tracking__msg__HipCoordinates
 * )) before or use
 * body_tracking__msg__HipCoordinates__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_body_tracking
bool
body_tracking__msg__HipCoordinates__init(body_tracking__msg__HipCoordinates * msg);

/// Finalize msg/HipCoordinates message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_body_tracking
void
body_tracking__msg__HipCoordinates__fini(body_tracking__msg__HipCoordinates * msg);

/// Create msg/HipCoordinates message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * body_tracking__msg__HipCoordinates__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_body_tracking
body_tracking__msg__HipCoordinates *
body_tracking__msg__HipCoordinates__create();

/// Destroy msg/HipCoordinates message.
/**
 * It calls
 * body_tracking__msg__HipCoordinates__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_body_tracking
void
body_tracking__msg__HipCoordinates__destroy(body_tracking__msg__HipCoordinates * msg);


/// Initialize array of msg/HipCoordinates messages.
/**
 * It allocates the memory for the number of elements and calls
 * body_tracking__msg__HipCoordinates__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_body_tracking
bool
body_tracking__msg__HipCoordinates__Sequence__init(body_tracking__msg__HipCoordinates__Sequence * array, size_t size);

/// Finalize array of msg/HipCoordinates messages.
/**
 * It calls
 * body_tracking__msg__HipCoordinates__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_body_tracking
void
body_tracking__msg__HipCoordinates__Sequence__fini(body_tracking__msg__HipCoordinates__Sequence * array);

/// Create array of msg/HipCoordinates messages.
/**
 * It allocates the memory for the array and calls
 * body_tracking__msg__HipCoordinates__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_body_tracking
body_tracking__msg__HipCoordinates__Sequence *
body_tracking__msg__HipCoordinates__Sequence__create(size_t size);

/// Destroy array of msg/HipCoordinates messages.
/**
 * It calls
 * body_tracking__msg__HipCoordinates__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_body_tracking
void
body_tracking__msg__HipCoordinates__Sequence__destroy(body_tracking__msg__HipCoordinates__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // BODY_TRACKING__MSG__DETAIL__HIP_COORDINATES__FUNCTIONS_H_
