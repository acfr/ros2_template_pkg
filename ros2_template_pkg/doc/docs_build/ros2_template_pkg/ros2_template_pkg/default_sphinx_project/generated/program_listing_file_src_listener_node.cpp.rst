
.. _program_listing_file_src_listener_node.cpp:

Program Listing for File listener_node.cpp
==========================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_listener_node.cpp>` (``src/listener_node.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   #include <memory>
   
   #include "rclcpp/rclcpp.hpp"
   #include "std_msgs/msg/string.hpp"
   using std::placeholders::_1;
   
   class MinimalSubscriber : public rclcpp::Node
   {
     public:
       MinimalSubscriber()
       : Node("minimal_subscriber")
       {
         subscription_ = this->create_subscription<std_msgs::msg::String>(
         "chat", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
       }
   
     private:
       void topic_callback(const std_msgs::msg::String & msg) const
       {
         RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
       }
       rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
   };
   
   int main(int argc, char * argv[])
   {
     rclcpp::init(argc, argv);
     rclcpp::spin(std::make_shared<MinimalSubscriber>());
     rclcpp::shutdown();
     return 0;
   }
