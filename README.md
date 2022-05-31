## About

A base template of a ROS2 package. This should be a good starting point when developing a new package for ROS2.
It has the following all setup
  - Two simple publisher nodes 
  - One simple subscriber node
  - Simple action client and action server nodes
  - Simple 
  - Several launch files to understand the programmatic launch approach of ROS2
  - A simple Github action workflow for CI/CD
  - Simple unit test template
  - Documentation template

## House Keping

### Coding Style 
[Google C++ style guide](https://google.github.io/styleguide/cppguide.html)

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

