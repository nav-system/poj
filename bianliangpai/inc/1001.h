#ifndef __1001_H__
#define __1001_H__

#include <cstdio>
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

void RemoveStringAheadZero(std::string& s) {
  try {
    for (std::string::iterator it = s.end()-1; it != s.begin(); ) {
      if (*it == '0') {
        --it;
        s.erase(it+1);
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


    // remove useless zero ahead of number, such as 0100 => 100
    RemoveStringAheadZero(result);

    // ahead code use std::string::push_back, so std::reverse here
    std::reverse(result.begin(), result.end());
  }
  catch(const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s\n", __FILE__, __LINE__, e.what());
    exit(1);
  }
}

void CalculateIntergerAdditionInString(const std::string& num1, std::string& num2) {
  try {
    CHECK_STRING_VALIDATION(num1);
    CHECK_STRING_VALIDATION(num2);

    // TODO: remove new memory allocation
    std::string longer_num, shorter_num;
    if (num1.length() >= num2.length()) {
      longer_num = num1;
      shorter_num = num2;
    }
    else {
      longer_num = num2;
      shorter_num = num1;
    }

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

    // remove useless zero ahead of number, such as 0100 => 100
    RemoveStringAheadZero(tmp_result);

    // ahead code use std::string::push_back, so std::reverse here
    std::reverse(tmp_result.begin(), tmp_result.end());

    std::swap(tmp_result, num2);
  }
  catch(const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s\n", __FILE__, __LINE__, e.what());
    exit(1);
  }
}

void CalculateIntergerProductInString(const std::string& multiplier,
                                      std::string& current_result) {
  try {
    CHECK_STRING_VALIDATION(multiplier);
    CHECK_STRING_VALIDATION(current_result);

    std::string tmp_result("0");
    for (std::string::const_reverse_iterator multiplier_reverse_it = multiplier.rbegin();
         multiplier_reverse_it != multiplier.rend(); ++multiplier_reverse_it) {

      std::string one_char_product;
      CalculateIntergerOneCharProductInString(current_result,
                                              *multiplier_reverse_it,
                                              one_char_product);

      // add one char result into tmp_result
      // string * 10 equal to push_back('0')
      std::size_t place_number =
        std::distance(multiplier.rbegin(), multiplier_reverse_it);
      if (place_number > multiplier.length()) {
        throw std::runtime_error("place_number > multiplier.length()");
      }
      else if (place_number > 0) {
        std::string tmp(place_number, '0');
        one_char_product += tmp;
      }
      CalculateIntergerAdditionInString(one_char_product, tmp_result);
    }
    std::swap(tmp_result, current_result);
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
      decimal_point_position = std::distance(decimal_point_it, number.end()-1);
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

void AdjustFormat(std::string& result, std::size_t decimal_point_position) {
  try {
    if (decimal_point_position > 0) {
      if (decimal_point_position <= result.length()) {
        result.insert(result.length()-decimal_point_position, 1, '.');
        // remove trailing '0'
        for (std::string::iterator it = result.end()-1;
             *it != '.' && *it == '0'; ) {
          it = result.erase(it);
          --it;
        }
      }
      else {
        std::string zero_ahead(decimal_point_position-result.length(), '0');
        result = std::string(".") + zero_ahead + result;
      }
    }
  }
  catch(const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s\n", __FILE__, __LINE__, e.what());
    exit(1);
  }
}

void CalculateIntergerExponentInString(const char* base,
                                       int exponent,
                                       std::string& result) {
  try {
    std::string multiplier(base);
    // end()-1 => 0
    std::size_t decimal_point_position = 0;
    ConvertBaseToInterger(multiplier, decimal_point_position);
    result.assign(multiplier);

    // result initialized as base ahead, so here use exponent-1
    for (int multiply_cnt = 0; multiply_cnt < exponent-1; ++multiply_cnt) {
      CalculateIntergerProductInString(multiplier, result);
    }
    AdjustFormat(result, decimal_point_position*exponent);
  }
  catch(const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s\n", __FILE__, __LINE__, e.what());
    exit(1);
  }
}

#endif // __1001_H__