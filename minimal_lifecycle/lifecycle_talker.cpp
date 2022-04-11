// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <utility>

#include "lifecycle_msgs/msg/transition.hpp"

#include "rclcpp/rclcpp.hpp"
#include "rclcpp/publisher.hpp"

#include "rclcpp_lifecycle/lifecycle_node.hpp"
#include "rclcpp_lifecycle/lifecycle_publisher.hpp"

#include "rcutils/logging_macros.h"

#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class LifecycleTalker : public rclcpp_lifecycle::LifecycleNode
{
public:
  explicit LifecycleTalker()
  : rclcpp_lifecycle::LifecycleNode("talker"), count_(0)
  {
    RCLCPP_INFO(get_logger(), "Waiting to configure the node");
  }

  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
  on_configure(const rclcpp_lifecycle::State &) override
  {
    pub_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    auto timer_callback =
        [this]() -> void {
          auto message = std_msgs::msg::String();
          message.data = "Hello, world! " + std::to_string(this->count_++);
          RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
          this->pub_->publish(message);
        };
    timer_ = this->create_wall_timer(1s, timer_callback);
    timer_->cancel();

    // TODO: preallocate here
    RCLCPP_INFO(get_logger(), "on_configure() is called.");
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
  }

  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
  on_activate(const rclcpp_lifecycle::State & state) override
  {
    LifecycleNode::on_activate(state);

    RCUTILS_LOG_INFO_NAMED(get_name(), "on_activate() is called.");
    RCUTILS_LOG_INFO_NAMED(get_name(), "waiting the subscription to match");
    // wait until a subscription is matched
    // TODO: move to function with chrono timeout
    std::uint32_t max_iterations = 1000U; // 10s
    std::uint32_t iterations = 0U;
    while (rclcpp::ok() &&  pub_->get_subscription_count() < 1U) {
      if (iterations >= max_iterations) {
        return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::FAILURE;
      }
      iterations++;
      rclcpp::sleep_for(10ms);
    }
    RCUTILS_LOG_INFO_NAMED(get_name(), "subscription matched");
    // activate timer
    timer_->reset();

    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
  }

  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
  on_deactivate(const rclcpp_lifecycle::State & state) override
  {
    LifecycleNode::on_deactivate(state);
    RCUTILS_LOG_INFO_NAMED(get_name(), "on_deactivate() is called.");
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
  }

  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
  on_cleanup(const rclcpp_lifecycle::State &) override
  {
    timer_.reset();
    pub_.reset();
    RCUTILS_LOG_INFO_NAMED(get_name(), "on cleanup is called.");
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
  }

  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
  on_shutdown(const rclcpp_lifecycle::State & state) override
  {
    timer_.reset();
    pub_.reset();

    RCUTILS_LOG_INFO_NAMED(
      get_name(),
      "on shutdown is called from state %s.",
      state.label().c_str());

    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
  }

private:
  std::shared_ptr<rclcpp_lifecycle::LifecyclePublisher<std_msgs::msg::String>> pub_;
  std::shared_ptr<rclcpp::TimerBase> timer_;
  size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<LifecycleTalker>()->get_node_base_interface());
  rclcpp::shutdown();
  return 0;
}
