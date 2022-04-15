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


#include <gtest/gtest.h>

#include <memory>
#include <string>

#include "osrf_testing_tools_cpp/memory_tools/memory_tools.hpp"
#include "apex_test_tools/apex_test_tools.hpp"

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

using namespace std::chrono_literals;


class TestNodeMemory : public ::testing::Test
{
public:
  static void SetUpTestCase()
  {
    rclcpp::init(0, nullptr);
  }

  static void TearDownTestCase()
  {
    (void)rclcpp::shutdown();
  }

  void SetUp() override
  {
    node = std::make_shared<rclcpp::Node>("my_node");
    publisher = node->create_publisher<std_msgs::msg::Int32>("topic", 10);
  }

  rclcpp::Node::SharedPtr node;
  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher;
};


TEST_F(TestNodeMemory, apex_test_tools) {
  apex_test_tools::memory_test::start();
  if (publisher->can_loan_messages()) {
    auto loaned_msg = publisher->borrow_loaned_message();
    loaned_msg.get().data = 10;
    publisher->publish(loaned_msg.get());
  }
  apex_test_tools::memory_test::stop();
}

TEST_F(TestNodeMemory, osrf_testing_tools_cpp_memory_tools) {
  osrf_testing_tools_cpp::memory_tools::expect_no_malloc_begin();
  if (publisher->can_loan_messages()) {
    auto loaned_msg = publisher->borrow_loaned_message();
    loaned_msg.get().data = 10;
    publisher->publish(loaned_msg.get());
  }
  osrf_testing_tools_cpp::memory_tools::expect_no_malloc_end();
}
