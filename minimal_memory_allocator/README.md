# minimal_memory_allocator

Summary of the allocator tutorial, pass memory allocator to:
- Subscriber
- Publisher
- Messages (broken? https://github.com/ros2/rosidl/issues/566)
- Executor
- intra_process_manager (broken? https://github.com/ros2/realtime_support/pull/102)

Current state:
- https://github.com/ros2/rosidl/issues/566
- https://github.com/ros2/rclcpp/issues/1254
- https://github.com/ros2/rclcpp/issues/1061
- https://github.com/ros2/realtime_support/pull/103
- https://github.com/ros2/rclcpp/pull/1324
- https://github.com/ros2/demos/pull/467/files

Resources
- https://docs.ros.org/en/eloquent/Tutorials/Allocator-Template-Tutorial.html
- https://www.apex.ai/post/porting-algorithms-from-ros-1-to-ros-2 (Avoiding dynamic memory allocation)
- http://design.ros2.org/articles/zero_copy.html
- https://github.com/ros/ros_realtime
- https://fast-dds.docs.eprosima.com/en/latest/fastdds/use_cases/realtime/allocations.html
- https://vimeo.com/379127767