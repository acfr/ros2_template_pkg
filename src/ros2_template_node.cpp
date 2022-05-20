#include "ros2_template_pkg/ros2_template_node.hpp"

RosTemplateNode::RosTemplateNode()
{

}

RosTemplateNode::~RosTemplateNode()
{

}

void RosTemplateNode::print(std::string message)
{
  std::cout << message;
}

int main(int argc, char ** argv)
{
  (void) argc;
  (void) argv;

  RosTemplateNode rosNode;
  rosNode.print("This is a ros2_template_pkg package node\n");

  return 0;
}
