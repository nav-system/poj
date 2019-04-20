#ifndef __1006_H__
#define __1006_H__

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <list>
#include <algorithm>
#include <stdexcept>

bool IsFactorOf(int factor_candidate, int number) {
  try {
    if (factor_candidate < 1 || number < 1) {
      throw std::runtime_error("invalid factor or number, smaller than 1");
    }
    else if (factor_candidate < 2 || number < 4) {
      return false;
    }
    else if (number % factor_candidate != 0 ||
             factor_candidate >= number) {
      return false;
    }
    else {
      return true;
    }
  }
  catch (const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s\n", __FILE__, __LINE__, e.what());
    exit(1);
  }
}

void JudgeAllNumbersSmallerThanNIsPrime(int n, std::vector<bool>& is_prime) {
  try {
    is_prime.resize(n, false);

    // for number 1, 2, 3
    is_prime[0] = false;
    is_prime[1] = true;
    is_prime[2] = true;

    // do calculation
    for (int number = 1; number < n; ++number) {

      if (is_prime[number]) {
        continue;
      }
      else {

        std::vector<bool>::iterator start_position = is_prime.begin();

        int current_prime = 2;
        do {
          std::vector<bool>::iterator it =
            std::find(start_position, is_prime.end(), true);

          if (it == is_prime.end()) {
            start_position = it;
          }
          else {
            // if current_prime is factor of number && it = end() - 1
            // then number must equal to current_prime
            // which situation is impossible to appear here
            current_prime = std::distance(is_prime.begin(), it) + 1;
            start_position = it + 1;
          }
        } while (start_position != is_prime.end() &&
                 !IsFactorOf(current_prime, number));

        if (start_position == is_prime.end()) {
          is_prime[number-1] = true;
        }

      }

    }

  }
  catch (const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s\n", __FILE__, __LINE__, e.what());
    exit(1);
  }
}

void FindAllFactorNumberOf(int number,
                           const std::list<int>& all_prime,
                           std::list<int>& factor_list) {
  try {
    if (number < 1) {
      throw std::runtime_error("number smaller than 1");
    }
    else if (number == 1) {
      return;
    }
    else if (std::find(all_prime.begin(), all_prime.end(), number)
             != all_prime.end()) {
      factor_list.push_back(number);
    }
    else {
      std::list<int>::const_iterator it = all_prime.begin();
      while (it != all_prime.end()) {
        if (number % (*it) == 0) {
          factor_list.push_back(*it);
          number /= (*it);
          it = all_prime.begin();
        }
        else {
          ++it;
        }
      }
    }
  }
  catch (const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s\n", __FILE__, __LINE__, e.what());
    exit(1);
  }
}

#endif // __1006_H__