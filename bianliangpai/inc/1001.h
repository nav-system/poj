#ifndef __1001_H__
#define __1001_H__

#include <cstdio>
#include <string>
#include <algorithm>
#include <exception>

void CalculateIntergerOneCharProductInString(const std::string& multiplier,
                                             char ch,
                                             std::string& result) {
  try {
    // do multiplication char by char
    int carry_number = 0;
    for (auto reverse_it = multiplier.rbegin();
         reverse_it != multiplier.rend(); ++reverse_it) {
      int tmp = (ch-'0') * (*reverse_it-'0') + carry_number;
      carry_number = tmp / 10;
      result.push_back((tmp % 10)+'0');
    }
    result.push_back(carry_number+'0');

    // remove useless zero ahead of number, such as 0100 => 100
    for (auto reverse_it = result.rbegin(); reverse_it != result.rend()-1; ) {
      if (*reverse_it == '0') {
        ++reverse_it;
        result.pop_back();
      }
      else {
        break;
      }
    }

    // ahead code use std::string::push_back, so std::reverse here
    std::reverse(result.begin(), result.end());
  }
  catch(const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s", __FILE__, __LINE__, e.what());
  }
}


void CalculateIntergerProductInString(const std::string& multiplier,
                                      std::string& current_result) {
  try {
    std::string tmp_result(current_result);
    for (auto multiplier_reverse_it = multiplier.rbegin();
         multiplier_reverse_it != multiplier.rend(); ++multiplier_reverse_it) {

      std::string one_char_product;
      CalculateIntergerOneCharProductInString(current_result,
                                              *multiplier_reverse_it,
                                              one_char_product);

      // add one char result into tmp_result
    }
    std::swap(tmp_result, current_result);
  }
  catch(const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s", __FILE__, __LINE__, e.what());
  }
}

void ConvertBaseToInterger(std::string& number,
                           std::size_t& decimal_point_position) {
  try {
    std::string::iterator decimal_point_it =
      std::find(number.begin(), number.end(), '.');

    if (decimal_point_it != number.end()) {
      decimal_point_position = std::distance(number.begin(), decimal_point_it);
      number.erase(decimal_point_it);
    }
    else {
      decimal_point_position = number.length();
    }
  }
  catch(const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s", __FILE__, __LINE__, e.what());
  }
}

void AdjustFormat(std::string& result) {
  try {

  }
  catch(const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s", __FILE__, __LINE__, e.what());
  }
}

#endif // __1001_H__