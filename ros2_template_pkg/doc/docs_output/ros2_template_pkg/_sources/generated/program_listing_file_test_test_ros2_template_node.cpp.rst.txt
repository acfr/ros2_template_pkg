
.. _program_listing_file_test_test_ros2_template_node.cpp:

Program Listing for File test_ros2_template_node.cpp
====================================================

|exhale_lsh| :ref:`Return to documentation for file <file_test_test_ros2_template_node.cpp>` (``test/test_ros2_template_node.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   #include <gtest/gtest.h>
   
   #include <iostream>
   
   TEST(RosTemplateNodeTest, test_print) {
     EXPECT_EQ(1, 1);
   }
   
   int main(int argc, char **argv){
     testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
   }
