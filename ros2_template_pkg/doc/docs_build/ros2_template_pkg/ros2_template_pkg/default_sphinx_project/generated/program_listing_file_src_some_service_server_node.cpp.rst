
.. _program_listing_file_src_some_service_server_node.cpp:

Program Listing for File some_service_server_node.cpp
=====================================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_some_service_server_node.cpp>` (``src/some_service_server_node.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   #include "rclcpp/rclcpp.hpp"
   #include "acfr_ros2_interfaces/srv/add_two_ints.hpp"
   
   #include <memory>
   
   void add(const std::shared_ptr<acfr_ros2_interfaces::srv::AddTwoInts::Request> request,
             std::shared_ptr<acfr_ros2_interfaces::srv::AddTwoInts::Response>      response)
   {
     response->sum = request->a + request->b;
     RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld" " b: %ld",
                   request->a, request->b);
     RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]", (long int)response->sum);
   }
   
   int main(int argc, char **argv)
   {
     rclcpp::init(argc, argv);
   
     std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_two_ints_server");
   
     rclcpp::Service<acfr_ros2_interfaces::srv::AddTwoInts>::SharedPtr service =
       node->create_service<acfr_ros2_interfaces::srv::AddTwoInts>("add_two_ints", &add);
   
     RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to add two ints.");
   
     rclcpp::spin(node);
     rclcpp::shutdown();
   }