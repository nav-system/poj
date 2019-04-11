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
  EXPECT_EQ(decimal_point_position, 6);
}

TEST(ConvertBaseToInterger, right_decimal_point) {
  std::string number = "123321.";
  std::size_t decimal_point_position;
  ConvertBaseToInterger(number, decimal_point_position);
  EXPECT_EQ(number, "123321");
  EXPECT_EQ(decimal_point_position, 0);
}

TEST(ConvertBaseToInterger, no_decimal_point) {
  std::string number = "123321";
  std::size_t decimal_point_position;
  ConvertBaseToInterger(number, decimal_point_position);
  EXPECT_EQ(number, "123321");
  EXPECT_EQ(decimal_point_position, 0);
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

TEST(CalculateIntergerAdditionInString, normal_1) {
  std::string num1 = "8426";
  std::string num2 = "8896";
  CalculateIntergerAdditionInString(num1, num2);
  EXPECT_EQ(num2, "17322");
}

TEST(CalculateIntergerAdditionInString, normal_2) {
  std::string num1 = "18000";
  std::string num2 = "8896";
  CalculateIntergerAdditionInString(num1, num2);
  EXPECT_EQ(num2, "26896");
}

TEST(CalculateIntergerAdditionInString, normal_3) {
  std::string num1 = "8000";
  std::string num2 = "18896";
  CalculateIntergerAdditionInString(num1, num2);
  EXPECT_EQ(num2, "26896");
}

TEST(CalculateIntergerAdditionInString, normal_4) {
  std::string num1 = "80";
  std::string num2 = "18896";
  CalculateIntergerAdditionInString(num1, num2);
  EXPECT_EQ(num2, "18976");
}

TEST(CalculateIntergerAdditionInString, normal_5) {
  std::string num1 = "18896";
  std::string num2 = "80";
  CalculateIntergerAdditionInString(num1, num2);
  EXPECT_EQ(num2, "18976");
}

TEST(CalculateIntergerAdditionInString, normal_and_zero) {
  std::string num1 = "8426";
  std::string num2 = "0000";
  CalculateIntergerAdditionInString(num1, num2);
  EXPECT_EQ(num2, "8426");
}

TEST(CalculateIntergerProductInString, normal_1) {
  std::string num1 = "147";
  std::string num2 = "258";
  CalculateIntergerProductInString(num1, num2);
  EXPECT_EQ(num2, "37926");
}

TEST(CalculateIntergerProductInString, normal_2) {
  std::string num1 = "4";
  std::string num2 = "256";
  CalculateIntergerProductInString(num1, num2);
  EXPECT_EQ(num2, "1024");
}

TEST(CalculateIntergerProductInString, normal_3) {
  std::string num1 = "256";
  std::string num2 = "4";
  CalculateIntergerProductInString(num1, num2);
  EXPECT_EQ(num2, "1024");
}

TEST(CalculateIntergerProductInString, normal_4) {
  std::string num1 = "256";
  std::string num2 = "16";
  CalculateIntergerProductInString(num1, num2);
  EXPECT_EQ(num2, "4096");
}

TEST(CalculateIntergerProductInString, normal_5) {
  std::string num1 = "16";
  std::string num2 = "256";
  CalculateIntergerProductInString(num1, num2);
  EXPECT_EQ(num2, "4096");
}

TEST(CalculateIntergerProductInString, zero_1) {
  std::string num1 = "147";
  std::string num2 = "000";
  CalculateIntergerProductInString(num1, num2);
  EXPECT_EQ(num2, "0");
}

TEST(CalculateIntergerProductInString, zero_2) {
  std::string num1 = "147";
  std::string num2 = "0";
  CalculateIntergerProductInString(num1, num2);
  EXPECT_EQ(num2, "0");
}

TEST(CalculateIntergerExponentInString, normal_1) {
  const char* base = "95.123";
  int exponent = 12;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "548815620517731830194541.899025343415715973535967221869852721");
}

TEST(CalculateIntergerExponentInString, normal_2) {
  const char* base = "0.4321";
  int exponent = 20;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, ".00000005148554641076956121994511276767154838481760200726351203835429763013462401");
}

TEST(CalculateIntergerExponentInString, normal_3) {
  const char* base = "5.1234";
  int exponent = 15;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "43992025569.928573701266488041146654993318703707511666295476720493953024");
}

TEST(CalculateIntergerExponentInString, normal_4) {
  const char* base = "6.7592";
  int exponent = 9;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "29448126.764121021618164430206909037173276672");
}

TEST(CalculateIntergerExponentInString, normal_5) {
  const char* base = "98.999";
  int exponent = 10;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "90429072743629540498.107596019456651774561044010001");
}

TEST(CalculateIntergerExponentInString, normal_6) {
  const char* base = "1.0100";
  int exponent = 12;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "1.126825030131969720661201");
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}