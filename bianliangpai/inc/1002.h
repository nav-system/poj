#ifndef __1002_H__
#define __1002_H__

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <stdexcept>

const static int telephone_number_length = 8;

char ConvertLetterToDigit(char ch) {
  try {
    switch (ch) {
    case 'A':
    case 'B':
    case 'C':
      return '2';
    case 'D':
    case 'E':
    case 'F':
      return '3';
    case 'G':
    case 'H':
    case 'I':
      return '4';
    case 'J':
    case 'K':
    case 'L':
      return '5';
    case 'M':
    case 'N':
    case 'O':
      return '6';
    case 'P':
    case 'R':
    case 'S':
      return '7';
    case 'T':
    case 'U':
    case 'V':
      return '8';
    case 'W':
    case 'X':
    case 'Y':
      return '9';
    default:
      throw std::runtime_error("error input");
    }
  }
  catch (const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s\n", __FILE__, __LINE__, e.what());
    exit(1);
  }
}

// read console input char by char to throw '-' away
// which could reduce momory copy operation
void GetTelephoneNumber(const std::string& line,
                        std::string& telephone_number) {
  try {
    std::string::const_iterator line_it = line.begin();

    for (int telephone_number_it = 0; ; ) {

      if (telephone_number_it > telephone_number_length) {
        throw std::runtime_error("telephone number length invalid");
      }
      if (line_it == line.end()) {
        break;
      }

      // result format is xxx-xxxx
      if (telephone_number_it == 3) {
        telephone_number[telephone_number_it] = '-';
        ++telephone_number_it;
      }

      char ch = *line_it;
      ++line_it;
      if ((ch >= '0' && ch <= '9')) {
        telephone_number[telephone_number_it] = ch;
        ++telephone_number_it;
      }
      else if (ch >= 'A' && ch <= 'Z') {
        telephone_number[telephone_number_it] = ConvertLetterToDigit(ch);
        ++telephone_number_it;
      }
      // '\r', '-'
      else {
        continue;
      }
    }
  }
  catch (const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s\n", __FILE__, __LINE__, e.what());
    exit(1);
  }
}

#endif // __1002_H__