#include "1001.h"

int main() {
  // c++ style I/O sucks
  constexpr int base_length = 6;
  char base[base_length] = { '\0' };
  int exponent = -1;
  while (2 == std::scanf("%s%d", base, &exponent)) {
    std::string result;
    CalculateIntergerExponentInString(base, exponent, result);
    printf("%s\n", result.c_str());
  }

  return 0;
}