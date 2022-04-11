// Copyright 2022 Carlos San Vicente
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

#include <memory>

#include "rclcpp_lifecycle/lifecycle_node.hpp"
#include "lifecycle_msgs/msg/transition_event.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class LifecycleListener : public rclcpp_lifecycle::LifecycleNode
{
public:
  LifecycleListener()
      : rclcpp_lifecycle::LifecycleNode("listener")
  {
    RCLCPP_INFO(get_logger(), "Waiting to configure the node");
  }

  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
  on_configure(const rclcpp_lifecycle::State &) override
  {
    subscription_ = this->create_subscription<std_msgs::msg::String>(
        "topic",
        10,
        [this](std_msgs::msg::String::UniquePtr msg) {
          if (this->get_current_state().id() == lifecycle_msgs::msg::State::PRIMARY_STATE_ACTIVE) {
            RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
          }
        });
    // TODO: preallocate here
    RCLCPP_INFO(get_logger(), "on_configure() is called.");
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
  }

  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
  on_activate(const rclcpp_lifecycle::State & state) override
  {
    LifecycleNode::on_activate(state);

    RCUTILS_LOG_INFO_NAMED(get_name(), "on_activate() is called.");
    RCUTILS_LOG_INFO_NAMED(get_name(), "waiting the publisher to match");

    // wait until a publisher is matched
    // TODO: move to function with chrono timeout
    std::uint32_t max_iterations = 1000U; // 10s
    std::uint32_t iterations = 0U;
    while (rclcpp::ok() &&  subscription_->get_publisher_count() < 1U) {
      if (iterations >= max_iterations) {
        return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::FAILURE;
      }
      iterations++;
      rclcpp::sleep_for(10ms);
    }
    RCUTILS_LOG_INFO_NAMED(get_name(), "publisher matched");

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
    RCUTILS_LOG_INFO_NAMED(get_name(), "on cleanup is called.");
    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
  }

  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
  on_shutdown(const rclcpp_lifecycle::State & state) override
  {
    RCUTILS_LOG_INFO_NAMED(
        get_name(),
        "on shutdown is called from state %s.",
        state.label().c_str());

    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
  }

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<LifecycleListener>()->get_node_base_interface());
  rclcpp::shutdown();
  return 0;
}
