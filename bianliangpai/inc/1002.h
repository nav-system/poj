#ifndef __1002_H__
#define __1002_H__

#include <cstdio>
#include <vector>
#include <string>
#include <stdexcept>

const static int telephone_number_length = 7;

// read console input char by char to throw '-' away
// which could reduce momory copy operation
void ReadTelephoneNumbersFromConsole(std::vector<std::string>& telephone_numbers) {
  try {
    // preprocessing input telephone number format
    for (std::vector<std::string>::iterator it = telephone_numbers.begin();
         it != telephone_numbers.end();
         ++it) {
      for (int telephone_number_it = 0; ; ) {
        char ch;
        std::scanf("%c", &ch);
        if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z')) {
          if (telephone_number_it >= telephone_number_length) {
            throw std::runtime_error("telephone number length invalid");
          }
          it->operator[](telephone_number_it) = ch;
          ++telephone_number_it;
        }
        else if (ch == '\n') {
          break;
        }
        // '\r', '-'
        else {
          continue;
        }
      }
    }
  }
  catch (const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s\n", __FILE__, __LINE__, e.what());
    exit(1);
  }
}

#endif // __1002_H__