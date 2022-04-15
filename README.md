# Minimal ROS 2 real-time cookbook recipes

* minimal_callback_group: shows how to create executables in different callback groups to run
 them in separate threads
* minimal_cpu_affinity: shows how to set the process and threads CPU affinity
* minimal_deadline_qos: shows how to use the DDS deadline QoS policy
* minimal_lifecycle: shows how to use node lifecycle to separate configuration and runtime
 real-time phases
* minimal_memory_check: shows how use verify that functions used in the real-time path
does not allocate dynamic memory
* minimal_memory_lock: shows how to lock the process memory and pre-allocate dynamic memory
* minimal_memory_strategies (TODO): shows how to use different memory strategies to avoid dynamic memory
 allocations during the runtime phase
* minimal_realtime_loop: shows different approaches to created typical real-time time based loops
* minimal_scheduling: shows how to configure the process or thread(s) scheduling policy and
 priority (TODO: add SCHED_DEADLINE example)
* minimal_data_sharing: shows how to use different data sharing approached to avoid
 blocking calls when sharing data between real-time and non real-time threads 
* minimal_dds_tuning: shows how to use DDS specific configurations to tune real-time
 related settings (TODO: add XML profiles for more DDS implementations)

## Building the examples

TODO

## Running the examples

### minimal_lifecycle

Terminal 1:

```bash
ros2 run minimal_lifecycle lifecycle_talker
```

Terminal 2:

```bash
ros2 run minimal_lifecycle lifecycle_listener
```

Terminal 3:

```bash
ros2 service call /talker/change_state lifecycle_msgs/ChangeState "{transition: {id: 1}}"
ros2 service call /listener/change_state lifecycle_msgs/ChangeState "{transition: {id: 1}}"
ros2 service call /talker/change_state lifecycle_msgs/ChangeState "{transition: {id: 3}}"
ros2 service call /listener/change_state lifecycle_msgs/ChangeState "{transition: {id: 3}}"
```



