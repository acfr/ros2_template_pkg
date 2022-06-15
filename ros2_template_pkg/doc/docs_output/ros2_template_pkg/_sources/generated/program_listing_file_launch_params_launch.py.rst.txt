
.. _program_listing_file_launch_params_launch.py:

Program Listing for File params_launch.py
=========================================

|exhale_lsh| :ref:`Return to documentation for file <file_launch_params_launch.py>` (``launch/params_launch.py``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: py

   from launch import LaunchDescription
   from launch_ros.actions import Node
   
   def generate_launch_description():
       return LaunchDescription([
           Node(
               package="ros2_template_pkg",
               executable="parameters",
               name="custom_parameter_node",
               output="screen",
               emulate_tty=True,
               parameters=[
                   {"my_parameter": "earth"}
               ]
           )
       ])
