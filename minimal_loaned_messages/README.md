# minimal_loaned_messages

## Setup 

Install rmw_iceoryx https://github.com/ros2/rmw_iceoryx

## How to run

```bash
/opt/ros/rolling/bin/iox-roudi
```

```bash
RMW_IMPLEMENTATION=rmw_iceoryx_cpp ros2 run minimal_loaned_messages talker_loaned_message
```

```bash
RMW_IMPLEMENTATION=rmw_iceoryx_cpp ros2 run minimal_loaned_messages listener_loaned_message
```

## Resources

- http://design.ros2.org/articles/zero_copy.html
- https://vimeo.com/379127778
- https://roscon.ros.org/2019/talks/roscon2019_truezerocopy.pdf 
- https://github.com/Karsten1987/fixed_size_ros2_demo
