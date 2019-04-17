#include <gtest/gtest.h>

#include "1002.h"

TEST(ConvertLetterToDigit, normal) {
  EXPECT_EQ(ConvertLetterToDigit('A'), 2);
  EXPECT_EQ(ConvertLetterToDigit('B'), 2);
  EXPECT_EQ(ConvertLetterToDigit('C'), 2);
  EXPECT_EQ(ConvertLetterToDigit('D'), 3);
  EXPECT_EQ(ConvertLetterToDigit('E'), 3);
  EXPECT_EQ(ConvertLetterToDigit('F'), 3);
  EXPECT_EQ(ConvertLetterToDigit('G'), 4);
  EXPECT_EQ(ConvertLetterToDigit('H'), 4);
  EXPECT_EQ(ConvertLetterToDigit('I'), 4);
  EXPECT_EQ(ConvertLetterToDigit('J'), 5);
  EXPECT_EQ(ConvertLetterToDigit('K'), 5);
  EXPECT_EQ(ConvertLetterToDigit('L'), 5);
  EXPECT_EQ(ConvertLetterToDigit('M'), 6);
  EXPECT_EQ(ConvertLetterToDigit('N'), 6);
  EXPECT_EQ(ConvertLetterToDigit('O'), 6);
  EXPECT_EQ(ConvertLetterToDigit('P'), 7);
  EXPECT_EQ(ConvertLetterToDigit('R'), 7);
  EXPECT_EQ(ConvertLetterToDigit('S'), 7);
  EXPECT_EQ(ConvertLetterToDigit('T'), 8);
  EXPECT_EQ(ConvertLetterToDigit('U'), 8);
  EXPECT_EQ(ConvertLetterToDigit('V'), 8);
  EXPECT_EQ(ConvertLetterToDigit('W'), 9);
  EXPECT_EQ(ConvertLetterToDigit('X'), 9);
  EXPECT_EQ(ConvertLetterToDigit('Y'), 9);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}