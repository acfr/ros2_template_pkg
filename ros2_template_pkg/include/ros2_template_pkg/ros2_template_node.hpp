
#ifndef ROS2_TEMPLATE_NODE_HPP
#define ROS2_TEMPLATE_NODE_HPP

#include <iostream>
#include <string>

//!  A template class for a ros2 node
/*!
  This is a template for ros2 nodes. Not to be mistaken for c++ template
*/
class RosTemplateNode {
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
    bool addTwoInts(int a, int b, int &sum);
};

#endif //ROS2_TEMPLATE_NODE_HPP
