// Copyright 2022 Carlos San Vicente
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
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/u_int32.hpp"

using namespace std::chrono_literals;

static_assert(std::atomic<std_msgs::msg::UInt32>::is_always_lock_free);

// Bigger data types are not lock free, this asserts would fail
// static_assert(std::atomic<std_msgs::msg::String>::is_always_lock_free);

class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher()
  : Node("minimal_scheduling"), msg_(std_msgs::msg::UInt32())
  {
    // Explore rclcpp::CallbackGroupType::MutuallyExclusive vs Reentrant
    // Callback Groups have a type, either 'Mutually Exclusive' or 'Reentrant'
    // and when creating one the type must be specified.
    //
    // Callbacks in Reentrant Callback Groups must be able to:
    //  - run at the same time as themselves (reentrant)
    //  - run at the same time as other callbacks in their group
    //  - run at the same time as other callbacks in other groups
    //
    // Callbacks in Mutually Exclusive Callback Groups:
    //  - will not be run multiple times simultaneously (non-reentrant)
    //  - will not be run at the same time as other callbacks in their group
    //  - but must run at the same time as callbacks in other groups

    auto reentrant_callback_group =
      this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    rclcpp::PublisherOptions options;
    options.callback_group = reentrant_callback_group;
    for (auto pub_index = 0; pub_index < 10; pub_index++) {
      auto publisher = this->create_publisher<std_msgs::msg::UInt32>("topic", 10, options);
      auto timer_callback =
        [this, pub_index, publisher]() -> void {
          msg_.data++;
          RCLCPP_INFO(this->get_logger(), "Publisher %d: '%d'", pub_index, msg_.data);
          publisher->publish(msg_);
        };
      timers_.push_back(this->create_wall_timer(100ms, timer_callback, reentrant_callback_group));
    }
  }

private:
  std::vector<rclcpp::TimerBase::SharedPtr> timers_;
  std_msgs::msg::UInt32 msg_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<MinimalPublisher>();
  rclcpp::executors::MultiThreadedExecutor executor;
  executor.add_node(node);
  executor.spin();
  rclcpp::shutdown();
  return 0;
}
