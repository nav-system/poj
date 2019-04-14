#ifndef __1001_H__
#define __1001_H__

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

void CheckStringValidation(const std::string& s, int functioncall_line_num) {
  try {
    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it) {
    // for (char ch : s) {
      if (*it < '0' || *it > '9') {
        throw std::runtime_error("string s invalid");
      }
    }
  }
  catch(const std::exception& e) {
    printf("input parameter s: %s\n", s.c_str());
    printf("File: %s, Line: %d, Reason: %s\n", __FILE__, functioncall_line_num, e.what());
    exit(1);
  }
}

#define CHECK_STRING_VALIDATION(s)      \
  do {                                  \
    CheckStringValidation(s, __LINE__); \
  } while(0)

void RemoveStringAhead(const char& ch, std::string& s) {
  try {
    for (std::string::iterator it = s.begin(); it != s.end(); ) {
      if (*it == ch) {
        it = s.erase(it);
      }
      else {
        break;
      }
    }
  }
  catch(const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s\n", __FILE__, __LINE__, e.what());
    exit(1);
  }
}

void RemoveStringTrailing(const char& ch, std::string& s) {
  try {
    for (std::string::iterator it = s.end()-1; it != s.begin(); ) {
      if (*it == ch) {
        --it;
        s.erase(it+1);
      }
      else {
        break;
      }
    }
  }
  catch (const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s\n", __FILE__, __LINE__, e.what());
    exit(1);
  }
}

void CalculateIntergerOneCharProductInString(const std::string& multiplier,
                                             char ch,
                                             std::string& result) {
  try {
    // check input parameter validation
    if (ch > '9' || ch < '0') {
      printf("ch: %c\n", ch);
      throw std::runtime_error("input parameter ch invalid");
    }
    CHECK_STRING_VALIDATION(multiplier);

    // do multiplication char by char
    int carry_number = 0;
    for (std::string::const_reverse_iterator reverse_it = multiplier.rbegin();
         reverse_it != multiplier.rend(); ++reverse_it) {
      int char_char_multiplication = (ch-'0') * (*reverse_it-'0') + carry_number;
      carry_number = char_char_multiplication / 10;
      int current_byte_number = char_char_multiplication % 10;
      result.push_back(current_byte_number+'0');
    }
    result.push_back(carry_number+'0');

    RemoveStringTrailing('0', result);
    // ahead code use std::string::push_back, so std::reverse here
    std::reverse(result.begin(), result.end());
  }
  catch(const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s\n", __FILE__, __LINE__, e.what());
    exit(1);
  }
}

void CalculateIntergerAdditionInString(const std::string& num1,
                                       const std::string& num2,
                                       std::string& result) {
  try {
    CHECK_STRING_VALIDATION(num1);
    CHECK_STRING_VALIDATION(num2);

    // TODO: remove new memory allocation
    std::string longer_num  = num1.length() > num2.length() ? num1 : num2;
    std::string shorter_num = num1.length() > num2.length() ? num2 : num1;

    // do addition char by char
    std::string tmp_result;
    int carry_number = 0;
    for (int long_it = longer_num.length()-1; long_it >= 0; --long_it) {
      int shorter_it = shorter_num.length() - (longer_num.length() - long_it);
      if (longer_num[long_it] < '0' || longer_num[long_it] > '9') {
        throw std::runtime_error("longer_num[long_it] value invalid");
      }
      int char_char_addition;
      if (shorter_it >= 0) {
        if (shorter_num[shorter_it] < '0' || shorter_num[shorter_it] > '9') {
          throw std::runtime_error("shorter_num[shorter_it] value invalid");
        }
        char_char_addition =
          (longer_num[long_it]-'0') + (shorter_num[shorter_it]-'0') + carry_number;
      }
      else {
        char_char_addition = (longer_num[long_it]-'0') + carry_number;
      }
      carry_number = char_char_addition / 10;
      tmp_result.push_back((char_char_addition % 10)+'0');
    }
    tmp_result.push_back(carry_number+'0');

    RemoveStringTrailing('0', tmp_result);
    // ahead code use std::string::push_back, so std::reverse here
    std::reverse(tmp_result.begin(), tmp_result.end());

    std::swap(tmp_result, result);
  }
  catch(const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s\n", __FILE__, __LINE__, e.what());
    exit(1);
  }
}

void CalculateIntergerProductInString(const std::string& multiplier1,
                                      const std::string& multiplier2,
                                      std::string& result) {
  try {
    CHECK_STRING_VALIDATION(multiplier1);
    CHECK_STRING_VALIDATION(multiplier2);
    CHECK_STRING_VALIDATION(result);

    std::string history_addition_result("0");
    for (std::string::const_reverse_iterator multiplier_reverse_it = multiplier2.rbegin();
         multiplier_reverse_it != multiplier2.rend(); ++multiplier_reverse_it) {

      std::string one_char_product;
      CalculateIntergerOneCharProductInString(multiplier1,
                                              *multiplier_reverse_it,
                                              one_char_product);

      // add one char result into history_addition_result
      // string * 10 equal to push_back('0')
      std::size_t place_number =
        std::distance(multiplier2.rbegin(), multiplier_reverse_it);
      if (place_number > multiplier2.length()) {
        throw std::runtime_error("place_number > multiplier2.length()");
      }
      else if (place_number > 0) {
        std::string tmp(place_number, '0');
        one_char_product += tmp;
      }

      // add one_char_product to history result
      std::string new_addition_result;
      CalculateIntergerAdditionInString(one_char_product,
                                        history_addition_result,
                                        new_addition_result);
      std::swap(history_addition_result, new_addition_result);
    }
    std::swap(history_addition_result, result);
  }
  catch(const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s\n", __FILE__, __LINE__, e.what());
    exit(1);
  }
}

void ConvertBaseToInterger(std::string& number,
                           std::size_t& decimal_point_position) {
  try {
    std::string::iterator decimal_point_it =
      std::find(number.begin(), number.end(), '.');

    if (decimal_point_it != number.end()) {
      decimal_point_position = std::distance(decimal_point_it, number.end())-1;
      number.erase(decimal_point_it);
    }
    else {
      decimal_point_position = 0;
    }

    CHECK_STRING_VALIDATION(number);
  }
  catch(const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s\n", __FILE__, __LINE__, e.what());
    exit(1);
  }
}

// 1. when being passed into this function, 'result' contained no '.'
// 2. decimal_point_position counting start from right side of string
void AdjustFormat(std::string& result, std::size_t decimal_point_position) {
  try {
    // push '.' to the position it should to be
    if (decimal_point_position > 0 &&
        decimal_point_position <= result.length()) {
      result.insert(result.length()-decimal_point_position, 1, '.');
    }
    else if (decimal_point_position > result.length()) {
      std::string zero_ahead(decimal_point_position-result.length(), '0');
      result = std::string(".") + zero_ahead + result;
    }
    // for case 'decimal_point_position == 0'
    // no decimal point in number string or decimal point position is end()-1
    else {
      result += ".";
    }

    RemoveStringAhead('0', result);
    RemoveStringTrailing('0', result);

    RemoveStringTrailing('.', result);
    // if just single '.', then replaced with '0'
    if (result.length() == 1 && result[0] == '.') {
        result[0] = '0';
    }
  }
  catch(const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s\n", __FILE__, __LINE__, e.what());
    exit(1);
  }
}

void CalculateIntergerExponentInString(const std::string& base,
                                       int exponent,
                                       std::string& result) {
  try {
    std::string multiplier(base);
    // end()-1 => 0
    std::size_t decimal_point_position = 0;
    ConvertBaseToInterger(multiplier, decimal_point_position);

    std::string history_product_result(multiplier);

    // history_product_result initialized as multiplier, so exponent-1 here
    for (int multiply_cnt = 0; multiply_cnt < exponent-1; ++multiply_cnt) {
      std::string tmp_result;
      CalculateIntergerProductInString(multiplier,
                                       history_product_result,
                                       tmp_result);
      history_product_result.assign(tmp_result);
    }

    AdjustFormat(history_product_result, decimal_point_position*exponent);

    std::swap(history_product_result, result);
  }
  catch(const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s\n", __FILE__, __LINE__, e.what());
    exit(1);
  }
}

#endif // __1001_H__