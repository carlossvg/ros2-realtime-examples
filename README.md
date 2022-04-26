
Repository moved to: https://github.com/ros-realtime/ros2-realtime-examples

____


# Minimal ROS 2 real-time cookbook recipes

Collection of ROS 2 minimal examples showing how to leverage different POSIX and ROS 2 features to
create real-time applications.

* [minimal_scheduling](minimal_scheduling/README.md): shows how to configure the thread(s)
scheduling policy and priority (TODO: add SCHED_DEADLINE example)
* [minimal_cpu_affinity](minimal_cpu_affinity/README.md): shows how to set the process and threads CPU affinity
* [minimal_realtime_loop](minimal_realtime_loop/README.md): shows different approaches to created typical real-time time based loops
* [minimal_memory_lock](minimal_memory_lock/README.md): shows how to lock the process memory and
 pre-allocate dynamic memory to avoid memory page faults
* [minimal_deadline_qos](minimal_deadline_qos/README.md): shows how to use the DDS deadline QoS policy
* [minimal_lifecycle](minimal_lifecycle/README.md): shows how to use node lifecycle to separate configuration and runtime
 real-time phases
* [minimal_memory_check](minimal_memory_check/README.md): shows how use verify that functions used in the real-time path
does not allocate dynamic memory
* [minimal_memory_allocator](minimal_memory_allocator/README.md): shows how to use different memory strategies to avoid dynamic
 memory allocations during the runtime phase
* [minimal_loaned_messages](minimal_loaned_messages/README.md): shows how to use loaned messages APIs
* [minimal_data_sharing](minimal_data_sharing/README.md): shows how to use different data sharing approached to avoid
 blocking calls when sharing data between real-time and non real-time threads 
* [minimal_dds_tuning](minimal_dds_tuning/README.md): shows how to use DDS specific configurations to tune real-time
 related settings (TODO: add XML profiles for more DDS implementations)


## Requirements

- ROS 2 rolling release
- Linux based operating system (RT_PREEMPT is not mandatory to run the examples)
- Privileges to set priority, scheduling and memory lock limits. This can be achieved by having
 root privileges or adding user privileges to `/etc/security/limits.conf`


## Build instructions

### Create workspace

```bash
$ mkdir -p ros2_realtime_examples_ws/src
$ cd ros2_realtime_examples_ws/src
$ git clone https://github.com/carlossvg/ros2-realtime-examples.git
# Optional: Build rmw_iceoryx for zero-copy examples
$ git clone https://github.com/ros2/rmw_iceoryx
```

### Install dependencies 

Option 1: from debian packages:

```bash
$ sudo apt install ros-rolling-tlsf-cpp ros-rolling-tlsf \
  ros-rolling-apex-test-tools ros-rolling-apex-containers ros-rolling-test-msgs -y
```

Option 2: Using [rosdep](http://wiki.ros.org/ROS/Tutorials/rosdep):

```bash
$ cd ros2_realtime_examples_ws
$ rosdep install --from-paths src/ --ignore-src --rosdistro=rolling
```

### Build

Build examples

```bash
$ cd ros2_realtime_examples_ws
$ colcon build
```

**Note: Some examples might require to install additional RMW implementations**
