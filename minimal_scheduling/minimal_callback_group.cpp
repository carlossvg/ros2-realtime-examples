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

#include <pthread.h>

#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher()
  : Node("minimal_publisher"), count1_(0), count2_(0)
  {
    publisher1_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    auto timer_callback1 =
      [this]() -> void {
        auto message = std_msgs::msg::String();
        message.data = "Hello, world! " + std::to_string(this->count1_++);
        RCLCPP_INFO(this->get_logger(), "Publishing     : '%s'", message.data.c_str());
        this->publisher1_->publish(message);
      };
    timer1_ = this->create_wall_timer(500ms, timer_callback1);

    realtime_callback_group_ = this->create_callback_group(
      rclcpp::CallbackGroupType::MutuallyExclusive, false);

    publisher2_ = this->create_publisher<std_msgs::msg::String>("topic_rt", 10);
    auto timer_callback2 =
      [this]() -> void {
        auto message = std_msgs::msg::String();
        message.data = "Hello, world! " + std::to_string(this->count2_++);
        RCLCPP_INFO(this->get_logger(), "Publishing (RT): '%s'", message.data.c_str());
        this->publisher2_->publish(message);
      };
    timer2_ = this->create_wall_timer(500ms, timer_callback2, realtime_callback_group_);
  }

  rclcpp::CallbackGroup::SharedPtr get_realtime_callback_group()
  {
    return realtime_callback_group_;
  }

private:
  rclcpp::TimerBase::SharedPtr timer1_, timer2_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher1_, publisher2_;
  size_t count1_, count2_;
  rclcpp::CallbackGroup::SharedPtr realtime_callback_group_;
};

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber()
  : Node("minimal_subscriber")
  {
    subscription1_ = this->create_subscription<std_msgs::msg::String>(
      "topic",
      10,
      [this](std_msgs::msg::String::UniquePtr msg) {
        RCLCPP_INFO(this->get_logger(), "I heard:        '%s'", msg->data.c_str());
      });

    realtime_callback_group_ = this->create_callback_group(
      rclcpp::CallbackGroupType::MutuallyExclusive, false);

    rclcpp::SubscriptionOptions subscription_options;
    subscription_options.callback_group = realtime_callback_group_;
    subscription2_ = this->create_subscription<std_msgs::msg::String>(
      "topic_rt",
      10,
      [this](std_msgs::msg::String::UniquePtr msg) {
        RCLCPP_INFO(this->get_logger(), "I heard (RT):   '%s'", msg->data.c_str());
      }, subscription_options);
  }

  rclcpp::CallbackGroup::SharedPtr get_realtime_callback_group()
  {
    return realtime_callback_group_;
  }

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription1_;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription2_;
  rclcpp::CallbackGroup::SharedPtr realtime_callback_group_;
};


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  auto node_pub = std::make_shared<MinimalPublisher>();
  auto node_sub = std::make_shared<MinimalSubscriber>();

  rclcpp::executors::StaticSingleThreadedExecutor default_callback_group_executor;
  rclcpp::executors::StaticSingleThreadedExecutor realtime_executor;

  default_callback_group_executor.add_node(node_pub);
  default_callback_group_executor.add_node(node_sub);

  // all the real-time callback groups are grouped on one specific executor
  realtime_executor.add_callback_group(
    node_pub->get_realtime_callback_group(), node_pub->get_node_base_interface());
  realtime_executor.add_callback_group(
    node_sub->get_realtime_callback_group(), node_sub->get_node_base_interface());

  // spin real-time tasks in a separate thread
  auto realtime_thread = std::thread(
    [&]() {
      realtime_executor.spin();
    });

  struct sched_param param {};
  int policy = SCHED_FIFO;
  param.sched_priority = 90;
  auto ret = pthread_setschedparam(realtime_thread.native_handle(), policy, &param);
  if (ret > 0) {
    printf("Couldn't set scheduling priority and policy. Error code %d", ret);
  }

  default_callback_group_executor.spin();
  realtime_thread.join();

  rclcpp::shutdown();
  return 0;
}
