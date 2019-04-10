#include "1001.h"
#include <gtest/gtest.h>

TEST(ConvertBaseToInterger, middle_decimal_point) {
  std::string number = "123.321";
  std::size_t decimal_point_position;
  ConvertBaseToInterger(number, decimal_point_position);
  EXPECT_EQ(number, "123321");
  EXPECT_EQ(decimal_point_position, 3);
}

TEST(ConvertBaseToInterger, left_decimal_point) {
  std::string number = ".123321";
  std::size_t decimal_point_position;
  ConvertBaseToInterger(number, decimal_point_position);
  EXPECT_EQ(number, "123321");
  EXPECT_EQ(decimal_point_position, 0);
}

TEST(ConvertBaseToInterger, right_decimal_point) {
  std::string number = "123321.";
  std::size_t decimal_point_position;
  ConvertBaseToInterger(number, decimal_point_position);
  EXPECT_EQ(number, "123321");
  EXPECT_EQ(decimal_point_position, 6);
}

TEST(ConvertBaseToInterger, no_decimal_point) {
  std::string number = "123321";
  std::size_t decimal_point_position;
  ConvertBaseToInterger(number, decimal_point_position);
  EXPECT_EQ(number, "123321");
  EXPECT_EQ(decimal_point_position, 6);
}

TEST(CalculateIntergerOneCharProductInString, normal_1) {
  std::string multiplier = "999";
  char ch = '9';
  std::string result;
  CalculateIntergerOneCharProductInString(multiplier, ch, result);
  EXPECT_EQ(result, "8991");
}

TEST(CalculateIntergerOneCharProductInString, zero_ahead_1) {
  std::string multiplier = "090";
  char ch = '9';
  std::string result;
  CalculateIntergerOneCharProductInString(multiplier, ch, result);
  EXPECT_EQ(result, "810");
}

TEST(CalculateIntergerOneCharProductInString, zero_ahead_2) {
  std::string multiplier = "0090";
  char ch = '9';
  std::string result;
  CalculateIntergerOneCharProductInString(multiplier, ch, result);
  EXPECT_EQ(result, "810");
}

TEST(CalculateIntergerOneCharProductInString, zero) {
  std::string multiplier = "0000";
  char ch = '9';
  std::string result;
  CalculateIntergerOneCharProductInString(multiplier, ch, result);
  EXPECT_EQ(result, "0");
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}