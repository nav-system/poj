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
  std::string result;
  CalculateIntergerAdditionInString(num1, num2, result);
  EXPECT_EQ(result, "17322");
}

TEST(CalculateIntergerAdditionInString, normal_2) {
  std::string num1 = "18000";
  std::string num2 = "8896";
  std::string result;
  CalculateIntergerAdditionInString(num1, num2, result);
  EXPECT_EQ(result, "26896");
}

TEST(CalculateIntergerAdditionInString, normal_3) {
  std::string num1 = "8000";
  std::string num2 = "18896";
  std::string result;
  CalculateIntergerAdditionInString(num1, num2, result);
  EXPECT_EQ(result, "26896");
}

TEST(CalculateIntergerAdditionInString, normal_4) {
  std::string num1 = "80";
  std::string num2 = "18896";
  std::string result;
  CalculateIntergerAdditionInString(num1, num2, result);
  EXPECT_EQ(result, "18976");
}

TEST(CalculateIntergerAdditionInString, normal_5) {
  std::string num1 = "18896";
  std::string num2 = "80";
  std::string result;
  CalculateIntergerAdditionInString(num1, num2, result);
  EXPECT_EQ(result, "18976");
}

TEST(CalculateIntergerAdditionInString, normal_and_zero) {
  std::string num1 = "8426";
  std::string num2 = "0000";
  std::string result;
  CalculateIntergerAdditionInString(num1, num2, result);
  EXPECT_EQ(result, "8426");
}

TEST(CalculateIntergerProductInString, normal_1) {
  std::string num1 = "147";
  std::string num2 = "258";
  std::string result;
  CalculateIntergerProductInString(num1, num2, result);
  EXPECT_EQ(result, "37926");
}

TEST(CalculateIntergerProductInString, normal_2) {
  std::string num1 = "4";
  std::string num2 = "256";
  std::string result;
  CalculateIntergerProductInString(num1, num2, result);
  EXPECT_EQ(result, "1024");
}

TEST(CalculateIntergerProductInString, normal_3) {
  std::string num1 = "256";
  std::string num2 = "4";
  std::string result;
  CalculateIntergerProductInString(num1, num2, result);
  EXPECT_EQ(result, "1024");
}

TEST(CalculateIntergerProductInString, normal_4) {
  std::string num1 = "256";
  std::string num2 = "16";
  std::string result;
  CalculateIntergerProductInString(num1, num2, result);
  EXPECT_EQ(result, "4096");
}

TEST(CalculateIntergerProductInString, normal_5) {
  std::string num1 = "16";
  std::string num2 = "256";
  std::string result;
  CalculateIntergerProductInString(num1, num2, result);
  EXPECT_EQ(result, "4096");
}

TEST(CalculateIntergerProductInString, zero_1) {
  std::string num1 = "147";
  std::string num2 = "000";
  std::string result;
  CalculateIntergerProductInString(num1, num2, result);
  EXPECT_EQ(result, "0");
}

TEST(CalculateIntergerProductInString, zero_2) {
  std::string num1 = "147";
  std::string num2 = "0";
  std::string result;
  CalculateIntergerProductInString(num1, num2, result);
  EXPECT_EQ(result, "0");
}

TEST(AdjustFormat, remove_ahead_zero_1) {
  std::string s = "000123456789";
  int decimal_point_position = 9;
  AdjustFormat(s, decimal_point_position);
  EXPECT_EQ(s, ".123456789");
}

TEST(AdjustFormat, remove_ahead_zero_2) {
  std::string s = "000123456789";
  int decimal_point_position = 6;
  AdjustFormat(s, decimal_point_position);
  EXPECT_EQ(s, "123.456789");
}

TEST(AdjustFormat, remove_trailing_zero_1) {
  std::string s = "123456789000";
  int decimal_point_position = 3;
  AdjustFormat(s, decimal_point_position);
  EXPECT_EQ(s, "123456789");
}

TEST(AdjustFormat, remove_trailing_zero_2) {
  std::string s = "123456789000";
  int decimal_point_position = 2;
  AdjustFormat(s, decimal_point_position);
  EXPECT_EQ(s, "1234567890");
}

TEST(AdjustFormat, remove_trailing_zero_3) {
  std::string s = "123456789000";
  int decimal_point_position = 0;
  AdjustFormat(s, decimal_point_position);
  EXPECT_EQ(s, "123456789000");
}

TEST(AdjustFormat, remove_trailing_dot) {
  std::string s = "000123456789";
  int decimal_point_position = 0;
  AdjustFormat(s, decimal_point_position);
  EXPECT_EQ(s, "123456789");
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

TEST(CalculateIntergerExponentInString, normal_7) {
  const char* base = ".00001";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, ".00001");
}

TEST(CalculateIntergerExponentInString, normal_8) {
  const char* base = ".12345";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, ".12345");
}

TEST(CalculateIntergerExponentInString, normal_9) {
  const char* base = "0001.1";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "1.1");
}

TEST(CalculateIntergerExponentInString, normal_9_5) {
  const char* base = "1.1000";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "1.1");
}

TEST(CalculateIntergerExponentInString, normal_10) {
  const char* base = "10.000";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "10");
}

TEST(CalculateIntergerExponentInString, normal_11) {
  const char* base = "000.10";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, ".1");
}

TEST(CalculateIntergerExponentInString, normal_12) {
  const char* base = "000000";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "0");
}

TEST(CalculateIntergerExponentInString, normal_13) {
  const char* base = "000.00";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "0");
}

TEST(CalculateIntergerExponentInString, normal_14) {
  const char* base = ".00000";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "0");
}

TEST(CalculateIntergerExponentInString, normal_15) {
  const char* base = "000010";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "10");
}

TEST(CalculateIntergerExponentInString, normal_16) {
  const char* base = "000.10";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, ".1");
}

TEST(CalculateIntergerExponentInString, normal_17) {
  const char* base = "0000.1";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, ".1");
}

TEST(CalculateIntergerExponentInString, normal_18) {
  const char* base = "00.111";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, ".111");
}

TEST(CalculateIntergerExponentInString, normal_19) {
  const char* base = "0.0001";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, ".0001");
}

TEST(CalculateIntergerExponentInString, normal_20) {
  const char* base = "0.0001";
  int exponent = 3;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, ".000000000001");
}

TEST(CalculateIntergerExponentInString, normal_21) {
  const char* base = "0.0010";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, ".001");
}

TEST(CalculateIntergerExponentInString, normal_22) {
  const char* base = "0.0010";
  int exponent = 3;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, ".000000001");
}

TEST(CalculateIntergerExponentInString, normal_23) {
  const char* base = "0.0100";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, ".01");
}

TEST(CalculateIntergerExponentInString, normal_24) {
  const char* base = "0.0100";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, ".01");
}

TEST(CalculateIntergerExponentInString, normal_25) {
  const char* base = "0.0100";
  int exponent = 3;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, ".000001");
}

TEST(CalculateIntergerExponentInString, normal_26) {
  const char* base = "0.1000";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, ".1");
}

TEST(CalculateIntergerExponentInString, normal_27) {
  const char* base = "0.1000";
  int exponent = 3;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, ".001");
}

TEST(CalculateIntergerExponentInString, normal_28) {
  const char* base = "1.000";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "1");
}

TEST(CalculateIntergerExponentInString, normal_29) {
  const char* base = "1.0000";
  int exponent = 3;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "1");
}

TEST(CalculateIntergerExponentInString, normal_30) {
  const char* base = "1.0001";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "1.0001");
}

TEST(CalculateIntergerExponentInString, normal_31) {
  const char* base = "1.0001";
  int exponent = 3;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "1.000300030001");
}

TEST(CalculateIntergerExponentInString, normal_32) {
  const char* base = "1.0010";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "1.001");
}

TEST(CalculateIntergerExponentInString, normal_33) {
  const char* base = "1.0010";
  int exponent = 3;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "1.003003001");
}

TEST(CalculateIntergerExponentInString, normal_34) {
  const char* base = "1.0100";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "1.01");
}

TEST(CalculateIntergerExponentInString, normal_35) {
  const char* base = "1.0100";
  int exponent = 3;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "1.030301");
}

TEST(CalculateIntergerExponentInString, normal_36) {
  const char* base = "1.1000";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "1.1");
}

TEST(CalculateIntergerExponentInString, normal_37) {
  const char* base = "1.1000";
  int exponent = 3;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "1.331");
}

TEST(CalculateIntergerExponentInString, normal_38) {
  const char* base = "10.000";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "10");
}

TEST(CalculateIntergerExponentInString, normal_39) {
  const char* base = "10.000";
  int exponent = 3;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "1000");
}

TEST(CalculateIntergerExponentInString, normal_40) {
  const char* base = "10.001";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "10.001");
}

TEST(CalculateIntergerExponentInString, normal_41) {
  const char* base = "10.001";
  int exponent = 3;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "1000.300030001");
}

TEST(CalculateIntergerExponentInString, normal_42) {
  const char* base = "10.010";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "10.01");
}

TEST(CalculateIntergerExponentInString, normal_43) {
  const char* base = "10.010";
  int exponent = 3;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "1003.003001");
}

TEST(CalculateIntergerExponentInString, normal_44) {
  const char* base = "10.100";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "10.1");
}

TEST(CalculateIntergerExponentInString, normal_45) {
  const char* base = "10.100";
  int exponent = 3;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "1030.301");
}

TEST(CalculateIntergerExponentInString, normal_46) {
  const char* base = "99.000";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "99");
}

TEST(CalculateIntergerExponentInString, normal_47) {
  const char* base = "99.000";
  int exponent = 3;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "970299");
}

TEST(CalculateIntergerExponentInString, normal_48) {
  const char* base = "99.001";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "99.001");
}

TEST(CalculateIntergerExponentInString, normal_49) {
  const char* base = "99.001";
  int exponent = 3;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "970328.403297001");
}

TEST(CalculateIntergerExponentInString, normal_50) {
  const char* base = "99.010";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "99.01");
}

TEST(CalculateIntergerExponentInString, normal_51) {
  const char* base = "99.010";
  int exponent = 3;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "970593.059701");
}

TEST(CalculateIntergerExponentInString, normal_52) {
  const char* base = "99.100";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "99.1");
}

TEST(CalculateIntergerExponentInString, normal_53) {
  const char* base = "99.100";
  int exponent = 3;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "973242.271");
}

TEST(CalculateIntergerExponentInString, normal_54) {
  const char* base = "99.998";
  int exponent = 1;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "99.998");
}

TEST(CalculateIntergerExponentInString, normal_55) {
  const char* base = "99.998";
  int exponent = 3;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "999940.001199992");
}

TEST(CalculateIntergerExponentInString, normal_56) {
  const char* base = "99.999";
  int exponent = 25;
  std::string result;
  CalculateIntergerExponentInString(base, exponent, result);
  EXPECT_EQ(result, "99975002999770012649468717709519310815545705768715.426520024799744573673126042964184298069822900531298735002299997000002499999");
}



int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}