
.. _program_listing_file_src_parameters_node.cpp:

Program Listing for File parameters_node.cpp
============================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_parameters_node.cpp>` (``src/parameters_node.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   #include <rclcpp/rclcpp.hpp>
   
   #include <chrono>
   #include <string>
   #include <functional>
   
   using namespace std::chrono_literals;
   
   class ParametersClass: public rclcpp::Node
   {
     public:
       ParametersClass()
         : Node("parameter_node")
       {
         this->declare_parameter<std::string>("my_parameter", "world");
   
         timer_ = this->create_wall_timer(
         1000ms, std::bind(&ParametersClass::respond, this));
       }
       void respond()
       {
         this->get_parameter("my_parameter", parameter_string_);
   
         RCLCPP_INFO(this->get_logger(), "Hello %s", parameter_string_.c_str());
       }
     private:
       std::string parameter_string_;
       rclcpp::TimerBase::SharedPtr timer_;
   };
   
   int main(int argc, char** argv)
   {
     rclcpp::init(argc, argv);
     rclcpp::spin(std::make_shared<ParametersClass>());
     rclcpp::shutdown();
     return 0;
   }
