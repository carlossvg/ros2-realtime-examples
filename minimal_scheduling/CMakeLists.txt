cmake_minimum_required(VERSION 3.5)
project(minimal_scheduling)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(minimal_publisher minimal_scheduling.cpp)
ament_target_dependencies(minimal_publisher rclcpp std_msgs)

add_executable(minimal_publisher_child_thread minimal_scheduling_with_child_threads.cpp)
ament_target_dependencies(minimal_publisher_child_thread rclcpp std_msgs)

add_executable(minimal_spinner_thread minimal_spinner_thread.cpp)
ament_target_dependencies(minimal_spinner_thread rclcpp std_msgs)

install(TARGETS
  minimal_publisher
  minimal_publisher_child_thread
  minimal_spinner_thread
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
