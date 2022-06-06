## About

A base template of a ROS2 package. This should be a good starting point when developing a new package for ROS2.
It has the following all setup
  - Two simple publisher nodes 
  - One simple subscriber node
  - Simple action client and action server nodes
  - Simple service client and service server nodes
  - Several launch files to understand the programmatic launch approach of ROS2
  - A simple Github action workflow for CI/CD
  - Simple unit test template
  - Documentation template

## House Keping

### Coding Style 
[Google C++ style guide](https://google.github.io/styleguide/cppguide.html)

### ROS2 Package and Node Naming Convention
- Package name should be named like `ros2_<some>_pkg` where `<some>` is a short descriptive name of the package

- Package name must `ros2` as prefix so its easier to distinguid between ros1 and ros2 packages that may be designed for similar tasks

- All publisher or subscriber nodes must be named in this format `<some>_publisher_node` or `<some>_subscriber_node`

- All action nodes must be named in this format `<some>_action_client_node` or `<some>_action_server_node`

- All service nodes must be named in this format `<some>_service_client_node` or `<some>_service_server_node`

- Where `<some>` is a short descriptive name of the task the node does. Example: Fibonacci or AddTwoInts

- All nodes must end with `_node` postfix. This makes it easier to distinguish which files are node files without opening them.

### Documentation 
Doxygen used with rosdoc2 
See [doxygen](https://doxygen.nl/manual/index.html) to learn more about comment style 

### Unit Testing
[Google Tests](https://github.com/google/googletest)

## Dependencies

- [acfr_ros2_interfaces]() - Contains interface description files such .msg(s) and .srv(s) 
- [rosdoc2](https://github.com/ros-infrastructure/rosdoc2)
- doxygen
- gtest

