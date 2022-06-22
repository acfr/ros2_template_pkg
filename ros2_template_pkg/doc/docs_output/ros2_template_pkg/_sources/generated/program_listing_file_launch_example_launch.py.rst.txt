
.. _program_listing_file_launch_example_launch.py:

Program Listing for File example_launch.py
==========================================

|exhale_lsh| :ref:`Return to documentation for file <file_launch_example_launch.py>` (``launch/example_launch.py``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: py

   # Copyright 2022 Australian Centre for Field Robotics
   #
   # Redistribution and use in source and binary forms, with or without
   # modification, are permitted provided that the following conditions are met:
   #
   #    * Redistributions of source code must retain the above copyright
   #      notice, this list of conditions and the following disclaimer.
   #
   #    * Redistributions in binary form must reproduce the above copyright
   #      notice, this list of conditions and the following disclaimer in the
   #      documentation and/or other materials provided with the distribution.
   #
   #    * Neither the name of the Australian Centre for Field Robotics nor the names of its
   #      contributors may be used to endorse or promote products derived from
   #      this software without specific prior written permission.
   #
   # THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   # AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   # IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   # ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
   # LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   # CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   # SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   # INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   # CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   # ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   # POSSIBILITY OF SUCH DAMAGE.
   
   
   from launch_ros.actions import Node
   
   from launch import LaunchDescription
   from launch.actions import DeclareLaunchArgument, ExecuteProcess, TimerAction
   from launch.conditions import IfCondition
   from launch.substitutions import LaunchConfiguration, PythonExpression
   
   
   def generate_launch_description():
       turtlesim_ns = LaunchConfiguration('turtlesim_ns')
       use_provided_red = LaunchConfiguration('use_provided_red')
       new_background_r = LaunchConfiguration('new_background_r')
   
       turtlesim_ns_launch_arg = DeclareLaunchArgument(
           'turtlesim_ns',
           default_value='turtlesim1'
       )
       use_provided_red_launch_arg = DeclareLaunchArgument(
           'use_provided_red',
           default_value='False'
       )
       new_background_r_launch_arg = DeclareLaunchArgument(
           'new_background_r',
           default_value='200'
       )
   
       turtlesim_node = Node(
           package='turtlesim',
           namespace=turtlesim_ns,
           executable='turtlesim_node',
           name='sim'
       )
       spawn_turtle = ExecuteProcess(
           cmd=[[
               'ros2 service call ',
               turtlesim_ns,
               '/spawn ',
               'turtlesim/srv/Spawn ',
               '"{x: 2, y: 2, theta: 0.2}"'
           ]],
           shell=True
       )
       change_background_r = ExecuteProcess(
           cmd=[[
               'ros2 param set ',
               turtlesim_ns,
               '/sim background_r ',
               '120'
           ]],
           shell=True
       )
       change_background_r_conditioned = ExecuteProcess(
           condition=IfCondition(
               PythonExpression([
                   new_background_r,
                   ' == 200',
                   ' and ',
                   use_provided_red
               ])
           ),
           cmd=[[
               'ros2 param set ',
               turtlesim_ns,
               '/sim background_r ',
               new_background_r
           ]],
           shell=True
       )
   
       return LaunchDescription([
           turtlesim_ns_launch_arg,
           use_provided_red_launch_arg,
           new_background_r_launch_arg,
           turtlesim_node,
           spawn_turtle,
           change_background_r,
           TimerAction(
               period=2.0,
               actions=[change_background_r_conditioned],
           )
       ])
