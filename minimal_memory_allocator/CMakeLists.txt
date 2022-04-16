cmake_minimum_required(VERSION 3.5)
project(minimal_memory_allocator)

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
find_package(tlsf REQUIRED)

add_executable(minimal_custom_allocator minimal_custom_allocator.cpp)
ament_target_dependencies(allocator_tutorial rclcpp std_msgs)

add_executable(minimal_custom_allocator_tlsf minimal_custom_allocator_tlsf.cpp)
ament_target_dependencies(allocator_example rclcpp std_msgs tlsf)

add_executable(listener_message_pool listener_message_pool.cpp)
ament_target_dependencies(listener_message_pool rclcpp std_msgs tlsf)

install(TARGETS
  minimal_custom_allocator
  minimal_custom_allocator_tlsf
  listener_message_pool
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
