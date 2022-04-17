# minimal_scheduling

## Setup 

Adjust permissions for the scheduler, see (https://docs.ros.org/en/foxy/Tutorials/Real-Time-Programming.html#setting-permissions-for-the-scheduler)
or run as root.

## How to run

```bash
ros2 run minimal_scheduling minimal_publisher
```

```bash
ros2 run minimal_scheduling minimal_scheduling_middleware_threads
```

```bash
ros2 run minimal_scheduling minimal_spinner_thread
```

```bash
ros2 run minimal_scheduling minimal_callback_group
```

## Resources

- https://wiki.linuxfoundation.org/realtime/documentation/technical_basics/sched_policy_prio/start
- https://wiki.linuxfoundation.org/realtime/documentation/howto/applications/application_base
- https://linux.die.net/man/3/pthread_setschedparam
- Callback groups executor - Ralph Lange [video](https://www.youtube.com/watch?v=5Sd5bvvZeb0
), [slides](https://www.apex.ai/_files/ugd/984e93_f3791ae0711042a883bfc40f827d6268.pdf)
- https://github.com/ros2/examples/tree/master/rclcpp/executors/cbg_executor
- https://wiki.linuxfoundation.org/realtime/documentation/technical_basics/sched_policy_prio/sched_deadline

## Building the examples
