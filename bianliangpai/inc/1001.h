#ifndef __1001_H__
#define __1001_H__

#include <cstdio>
#include <string>
#include <algorithm>
#include <exception>


void CalculateProductInString(const std::string& multiplier,
                              std::string& current_result) {
  try {
    std::string tmp_result(current_result);
    for (std::size_t it = 0; it < multiplier.length(); ++it) {
      char ch = multiplier[it];
      std::string product;

      //TODO: multiply interger string and char
    }
    std::swap(tmp_result, current_result);
  }
  catch(const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s", __FILE__, __LINE__, e.what());
  }
}

void CalculateIntergerExponentInString(const std::string& multiplier,
                                       int exponent,
                                       std::string& current_result) {
  try {
    if (exponent == 1) {
      return;
    }
    else {
      CalculateProductInString(multiplier, current_result);
      CalculateIntergerExponentInString(multiplier, exponent-1, current_result);
    }
  }
  catch(const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s", __FILE__, __LINE__, e.what());
  }
}

void ConvertBaseToInterger(std::string& number,
                           std::size_t& decimal_point_position) {
  try {
    std::string::iterator decimal_point_it =
      std::find(number.begin(), number.end(), ".");

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