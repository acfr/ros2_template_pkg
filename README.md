[![pre-commit](https://img.shields.io/badge/pre--commit-enabled-brightgreen?logo=pre-commit&logoColor=white)](https://github.com/pre-commit/pre-commit)

## Build Status
[![Test Template](https://github.com/acfr/ros2_template_pkg/actions/workflows/ci_actions.yml/badge.svg)](https://github.com/acfr/ros2_template_pkg/actions/workflows/ci_actions.yml)

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

## How to build
### Prerequisites
- Ubuntu 22.04
- ROS2 Humble
- Docker
- Pre-Commit

### Install ROS2

To install ROS2 follow the official instructions provided here.

Make sure to install the version that corresponds to the branch you require or slight modifications may be required to compile the code.

https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debians.html

### Create a Development Workspace
``` bash
mkdir -p ~/dev_ws/src
```
### Clone a Package
``` bash
cd ~/dev_ws/src
git clone -c http.sslverify=false https://github.com/acfr/ros2_template_pkg.git
cd ros2_template_pkg
git submodule init
pre-commit install
git -c http.sslverify=false submodule update
cd ../..
rosdep install -i --from-path src --rosdistro humble -y
colcon build
```

### Setup your Worksapce
- Install pip
`sudo apt install python3-pip`

- Install Pre-Commit
`pip install pre-commit`

- Install docker using the following instructions
https://docs.docker.com/engine/install/ubuntu/

- By default, Docker is only accessible with root privileges (sudo). If you want to use docker as a regular user, you need to add your user to the docker group.
``` bash
sudo addgroup --system docker
sudo adduser $USER docker
newgrp docker
sudo snap disable docker
sudo snap enable docker
```

## How to run

### Using ros2 run
- You can run each node individually using ros2 run using
  `ros2 run <package_name> <node_executable_name>`
- Example
`ros2 run ros2_template_pkg talker`

### Using ros2 launch
- Launch files are wrtitten using python scripts
- To invoke a node you can run the python script using ros2 launch like below
  `ros2 launch <package_name> <launch_file_name.py>`
- Example
  `ros2 launch ros2_template_pkg all_launch.py`

## Unit Testing
TODO: write notes on how to use

## Running in Docker
TODO: Setup docker image

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
- To invoke a node you can run the python script from its root folder like below
must end with `_node` postfix. This makes it easier to distinguish which files are node files without opening them.

### Documentation
Doxygen used with rosdoc2
See [doxygen](https://doxygen.nl/manual/index.html) to learn more about comment style

#### Install rosdoc2
- Clone the repo to some location in your computer
`git clone https://github.com/ros-infrastructure/rosdoc2.git`

- From the root of this repo execute
`pip install --user --upgrade .`

- Intasll doxygen `sudo apt install doxygen`

#### Generate Docs
- Navigate one folder level deep from the root of the repository into ros2_template_pkg folder
`cd ros2_template_pkg`

- Create a folder called doc and move into it
`mkdir doc` and `cd doc`

- Execute the command to generate the docs. This let's rosdoc2 know to place the documentation in this folder(where you are currently executing the command from) and provides the path of the package which is one folder level above.
`rosdoc2 build --package-path ..`

### Unit Testing
[Google Tests](https://github.com/google/googletest)

## Dependencies

- [acfr_ros2_interfaces](https://github.com/acfr/acfr_ros2_interfaces.git) - Contains interface description files such .msg(s) and .srv(s)
- [rosdoc2](https://github.com/ros-infrastructure/rosdoc2)
- doxygen
- gtest

