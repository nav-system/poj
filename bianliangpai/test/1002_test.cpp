#include <gtest/gtest.h>

#include "1002.h"

TEST(ConvertLetterToDigit, normal) {
  EXPECT_EQ(ConvertLetterToDigit('A'), '2');
  EXPECT_EQ(ConvertLetterToDigit('B'), '2');
  EXPECT_EQ(ConvertLetterToDigit('C'), '2');
  EXPECT_EQ(ConvertLetterToDigit('D'), '3');
  EXPECT_EQ(ConvertLetterToDigit('E'), '3');
  EXPECT_EQ(ConvertLetterToDigit('F'), '3');
  EXPECT_EQ(ConvertLetterToDigit('G'), '4');
  EXPECT_EQ(ConvertLetterToDigit('H'), '4');
  EXPECT_EQ(ConvertLetterToDigit('I'), '4');
  EXPECT_EQ(ConvertLetterToDigit('J'), '5');
  EXPECT_EQ(ConvertLetterToDigit('K'), '5');
  EXPECT_EQ(ConvertLetterToDigit('L'), '5');
  EXPECT_EQ(ConvertLetterToDigit('M'), '6');
  EXPECT_EQ(ConvertLetterToDigit('N'), '6');
  EXPECT_EQ(ConvertLetterToDigit('O'), '6');
  EXPECT_EQ(ConvertLetterToDigit('P'), '7');
  EXPECT_EQ(ConvertLetterToDigit('R'), '7');
  EXPECT_EQ(ConvertLetterToDigit('S'), '7');
  EXPECT_EQ(ConvertLetterToDigit('T'), '8');
  EXPECT_EQ(ConvertLetterToDigit('U'), '8');
  EXPECT_EQ(ConvertLetterToDigit('V'), '8');
  EXPECT_EQ(ConvertLetterToDigit('W'), '9');
  EXPECT_EQ(ConvertLetterToDigit('X'), '9');
  EXPECT_EQ(ConvertLetterToDigit('Y'), '9');
}

// 12
// 4873279
// ITS-EASY
// 888-4567
// 3-10-10-10
// 888-GLOP
// TUT-GLOP
// 967-11-11
// 310-GINO
// F101010
// 888-1200
// -4-8-7-3-2-7-9-
// 487-3279

TEST(GetTelephoneNumber, number_only) {
  std::string line;
  std::string r;

  line.assign("4873279");
  r = std::string(telephone_number_length, '\0');
  GetTelephoneNumber(line, r);
  EXPECT_EQ(r, "487-3279");
}

TEST(GetTelephoneNumber, letter_only) {
  std::string line;
  std::string r;

  line.assign("ITSEASY");
  r = std::string(telephone_number_length, '\0');
  GetTelephoneNumber(line, r);
  EXPECT_EQ(r, "487-3279");
}

TEST(GetTelephoneNumber, number_and_letter) {
  std::string line;
  std::string r;

  line.assign("487EASY");
  r = std::string(telephone_number_length, '\0');
  GetTelephoneNumber(line, r);
  EXPECT_EQ(r, "487-3279");
}

TEST(GetTelephoneNumber, number_and_minus_symbol) {
  std::string line;
  std::string r;

  line.assign("487-3279");
  r = std::string(telephone_number_length, '\0');
  GetTelephoneNumber(line, r);
  EXPECT_EQ(r, "487-3279");
}

TEST(GetTelephoneNumber, letter_and_minus_symbol) {
  std::string line;
  std::string r;

  line.assign("ITS-EASY");
  r = std::string(telephone_number_length, '\0');
  GetTelephoneNumber(line, r);
  EXPECT_EQ(r, "487-3279");
}

TEST(GetTelephoneNumber, number_and_letter_and_minus_symbol) {
  std::string line;
  std::string r;

  line.assign("487-EASY");
  r = std::string(telephone_number_length, '\0');
  GetTelephoneNumber(line, r);
  EXPECT_EQ(r, "487-3279");
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}