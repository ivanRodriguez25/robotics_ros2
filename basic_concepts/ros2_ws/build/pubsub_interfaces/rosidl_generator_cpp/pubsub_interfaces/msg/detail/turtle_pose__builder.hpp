// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pubsub_interfaces:msg/TurtlePose.idl
// generated code does not contain a copyright notice

#ifndef PUBSUB_INTERFACES__MSG__DETAIL__TURTLE_POSE__BUILDER_HPP_
#define PUBSUB_INTERFACES__MSG__DETAIL__TURTLE_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pubsub_interfaces/msg/detail/turtle_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pubsub_interfaces
{

namespace msg
{

namespace builder
{

class Init_TurtlePose_angular_velocity
{
public:
  explicit Init_TurtlePose_angular_velocity(::pubsub_interfaces::msg::TurtlePose & msg)
  : msg_(msg)
  {}
  ::pubsub_interfaces::msg::TurtlePose angular_velocity(::pubsub_interfaces::msg::TurtlePose::_angular_velocity_type arg)
  {
    msg_.angular_velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pubsub_interfaces::msg::TurtlePose msg_;
};

class Init_TurtlePose_linear_velocity
{
public:
  explicit Init_TurtlePose_linear_velocity(::pubsub_interfaces::msg::TurtlePose & msg)
  : msg_(msg)
  {}
  Init_TurtlePose_angular_velocity linear_velocity(::pubsub_interfaces::msg::TurtlePose::_linear_velocity_type arg)
  {
    msg_.linear_velocity = std::move(arg);
    return Init_TurtlePose_angular_velocity(msg_);
  }

private:
  ::pubsub_interfaces::msg::TurtlePose msg_;
};

class Init_TurtlePose_theta
{
public:
  explicit Init_TurtlePose_theta(::pubsub_interfaces::msg::TurtlePose & msg)
  : msg_(msg)
  {}
  Init_TurtlePose_linear_velocity theta(::pubsub_interfaces::msg::TurtlePose::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return Init_TurtlePose_linear_velocity(msg_);
  }

private:
  ::pubsub_interfaces::msg::TurtlePose msg_;
};

class Init_TurtlePose_y
{
public:
  explicit Init_TurtlePose_y(::pubsub_interfaces::msg::TurtlePose & msg)
  : msg_(msg)
  {}
  Init_TurtlePose_theta y(::pubsub_interfaces::msg::TurtlePose::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_TurtlePose_theta(msg_);
  }

private:
  ::pubsub_interfaces::msg::TurtlePose msg_;
};

class Init_TurtlePose_x
{
public:
  Init_TurtlePose_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TurtlePose_y x(::pubsub_interfaces::msg::TurtlePose::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_TurtlePose_y(msg_);
  }

private:
  ::pubsub_interfaces::msg::TurtlePose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pubsub_interfaces::msg::TurtlePose>()
{
  return pubsub_interfaces::msg::builder::Init_TurtlePose_x();
}

}  // namespace pubsub_interfaces

#endif  // PUBSUB_INTERFACES__MSG__DETAIL__TURTLE_POSE__BUILDER_HPP_
