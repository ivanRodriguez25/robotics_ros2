// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pubsub_interfaces:msg/TurtlePose.idl
// generated code does not contain a copyright notice

#ifndef PUBSUB_INTERFACES__MSG__DETAIL__TURTLE_POSE__TRAITS_HPP_
#define PUBSUB_INTERFACES__MSG__DETAIL__TURTLE_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pubsub_interfaces/msg/detail/turtle_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace pubsub_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TurtlePose & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: theta
  {
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
    out << ", ";
  }

  // member: linear_velocity
  {
    out << "linear_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_velocity, out);
    out << ", ";
  }

  // member: angular_velocity
  {
    out << "angular_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_velocity, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TurtlePose & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: theta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
    out << "\n";
  }

  // member: linear_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linear_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_velocity, out);
    out << "\n";
  }

  // member: angular_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_velocity, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TurtlePose & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace pubsub_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use pubsub_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const pubsub_interfaces::msg::TurtlePose & msg,
  std::ostream & out, size_t indentation = 0)
{
  pubsub_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pubsub_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const pubsub_interfaces::msg::TurtlePose & msg)
{
  return pubsub_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pubsub_interfaces::msg::TurtlePose>()
{
  return "pubsub_interfaces::msg::TurtlePose";
}

template<>
inline const char * name<pubsub_interfaces::msg::TurtlePose>()
{
  return "pubsub_interfaces/msg/TurtlePose";
}

template<>
struct has_fixed_size<pubsub_interfaces::msg::TurtlePose>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<pubsub_interfaces::msg::TurtlePose>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<pubsub_interfaces::msg::TurtlePose>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PUBSUB_INTERFACES__MSG__DETAIL__TURTLE_POSE__TRAITS_HPP_
