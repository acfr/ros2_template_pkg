cmake_minimum_required(VERSION 3.8)
project(ros2_template_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(std_msgs REQUIRED)
find_package(acfr_ros2_interfaces REQUIRED)

include_directories(include)

add_executable(ros2_template_node src/ros2_template_node.cpp)
ament_target_dependencies(ros2_template_node)

add_executable(action_server src/fibonaaci_action_server_node.cpp)
ament_target_dependencies(action_server rclcpp rclcpp_action acfr_ros2_interfaces)

add_executable(action_client src/fibonaaci_action_client_node.cpp)
ament_target_dependencies(action_client acfr_ros2_interfaces rclcpp rclcpp_action)

add_executable(service_server src/some_service_server_node.cpp)
ament_target_dependencies(service_server rclcpp acfr_ros2_interfaces)

add_executable(service_client src/some_service_client_node.cpp)
ament_target_dependencies(service_client rclcpp acfr_ros2_interfaces)

add_executable(talker src/talker_node.cpp)
ament_target_dependencies(talker rclcpp std_msgs)

add_executable(listener src/listener_node.cpp)
ament_target_dependencies(listener rclcpp std_msgs)

add_executable(timer src/timer_node.cpp)
ament_target_dependencies(timer rclcpp std_msgs)

add_executable(parameters src/parameters_node.cpp)
ament_target_dependencies(parameters rclcpp std_msgs)

target_include_directories(ros2_template_node PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include
$<INSTALL_INTERFACE:include>)

target_compile_features(ros2_template_node PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

install(TARGETS 
  ros2_template_node
  parameters
  talker
  listener
  timer
  service_server
  service_client
  action_server
  action_client
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_cmake_uncrustify REQUIRED)
  ament_uncrustify()

  find_package(ament_cmake_cppcheck REQUIRED)
  ament_cppcheck()

  find_package(ament_cmake_copyright REQUIRED)
  ament_copyright()

  find_package(ament_cmake_lint_cmake REQUIRED)
  ament_lint_cmake()

  find_package(ament_cmake_xmllint REQUIRED)
  ament_xmllint()

  find_package(ament_cmake_cpplint REQUIRED)
  ament_cpplint()
  
  find_package(ament_cmake_gtest REQUIRED)
  # Add a gtest named ${PROJECT_NAME}
  ament_add_gtest(${PROJECT_NAME} test/test_ros2_template_node.cpp)
  
endif()

#this must be added so launch files can be used from CLI
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME})

ament_package()
