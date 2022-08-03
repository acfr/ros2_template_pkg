// Copyright 2022 Australian Centre for Field Robotics
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//    * Redistributions of source code must retain the above copyright
//      notice, this list of conditions and the following disclaimer.
//
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
//
//    * Neither the name of the Australian Centre for Field Robotics nor the names of its
//      contributors may be used to endorse or promote products derived from
//      this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.


#ifndef ROS2_TEMPLATE_PKG__ROS2_TEMPLATE_NODE_HPP_
#define ROS2_TEMPLATE_PKG__ROS2_TEMPLATE_NODE_HPP_

#include <iostream>
#include <string>

//!  A template class for a ros2 node
/*!
  This is a template for ros2 nodes. Not to be mistaken for c++ template
*/
class RosTemplateNode
{
public:
  /**
     * \brief   The contructore of RosTemplateNode.
     *
     */
  RosTemplateNode();

  /**
     * \brief   The contructore of RosTemplateNode.
     *
     */
  ~RosTemplateNode();


  /**
     * \brief   The function print.
     *
     * \details This function does takes in std string and prints it using iostream to the console
     *
     * \note    This text shall only show you, how such a \"note\" section
     *          is looking. There is nothing which really needs your notice,
     *          so you do not really need to read this section.
     *
     * \param[in]     message    a std string.
     *
     * \return        returns nothing.
     *
     */
  void print(std::string message);


  /**
     * \brief   The function addTwoints.
     *
     * \details This function adds two ints together. This is not very useful. Just showcasing how to write
                Doxygen comments
    *
    * \note    Note that the the sum variable is written to by reference and the function always returns true
    *
    * \param[in]     a    An integer.
    * \param[in]     b    An integer.
    * \param[in,out] c    An integer written to by reference.
    *
    * \return        The return value of the function.
    *
    * \retval        true    True
    * \retval        false   Not true
    */
  bool addTwoInts(int a, int b, int & sum);
};

#endif  // ROS2_TEMPLATE_PKG__ROS2_TEMPLATE_NODE_HPP_
