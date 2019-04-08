#include "1001.h"
#include <gtest/gtest.h>

TEST(ConvertBaseToInterger, left_decimal_point) {
  std::string number = "123.321";
  std::size_t decimal_point_position;
  ConvertBaseToInterger(number, decimal_point_position);
  EXPECT_EQ(number, "123321");
  EXPECT_EQ(decimal_point_position, 3);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}