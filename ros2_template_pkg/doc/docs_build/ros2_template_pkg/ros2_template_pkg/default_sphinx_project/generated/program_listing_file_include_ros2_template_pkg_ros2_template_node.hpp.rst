
.. _program_listing_file_include_ros2_template_pkg_ros2_template_node.hpp:

Program Listing for File ros2_template_node.hpp
===============================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_ros2_template_pkg_ros2_template_node.hpp>` (``include/ros2_template_pkg/ros2_template_node.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef ROS2_TEMPLATE_NODE_HPP
   #define ROS2_TEMPLATE_NODE_HPP
   
   #include <iostream>
   #include <string>
   
   
   class RosTemplateNode {
   public:
       RosTemplateNode();
   
       ~RosTemplateNode();
   
   
       void print(std::string message);
   
   
       bool addTwoInts(int a, int b, int &sum);
   };
   
   #endif //ROS2_TEMPLATE_NODE_HPP
