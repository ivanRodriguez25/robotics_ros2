// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from pubsub_interfaces:msg/TurtlePose.idl
// generated code does not contain a copyright notice

#ifndef PUBSUB_INTERFACES__MSG__DETAIL__TURTLE_POSE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define PUBSUB_INTERFACES__MSG__DETAIL__TURTLE_POSE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "pubsub_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "pubsub_interfaces/msg/detail/turtle_pose__struct.hpp"

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

#include "fastcdr/Cdr.h"

namespace pubsub_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pubsub_interfaces
cdr_serialize(
  const pubsub_interfaces::msg::TurtlePose & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pubsub_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  pubsub_interfaces::msg::TurtlePose & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pubsub_interfaces
get_serialized_size(
  const pubsub_interfaces::msg::TurtlePose & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pubsub_interfaces
max_serialized_size_TurtlePose(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace pubsub_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pubsub_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, pubsub_interfaces, msg, TurtlePose)();

#ifdef __cplusplus
}
#endif

#endif  // PUBSUB_INTERFACES__MSG__DETAIL__TURTLE_POSE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
