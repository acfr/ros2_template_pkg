#include <gtest/gtest.h>

#include <iostream>

TEST(RosTemplateNodeTest, test_print) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
