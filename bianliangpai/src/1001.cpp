#include "1001.h"

int _main() {
  // c++ style I/O sucks
  const static int base_length = 6;
  char base[base_length] = { '\0' };
  int exponent = -1;
  while (true) {
    int ret = std::scanf("%s%d", base, &exponent);
    if (2 == ret) {
      std::string result;
      CalculateIntergerExponentInString(base, exponent, result);
      printf("%s\r\n", result.c_str());
    }
    else if (ret == EOF) {
      break;
    }
  }
  return 0;
}


// for profiling
int main() {
  // c++ style I/O sucks
  const static int base_length = 6;
  char base[base_length] = "99.999";
  int exponent = 25;
  int cnt = 0;
  while (cnt++ < 10000) {
      std::string result;
      CalculateIntergerExponentInString(base, exponent, result);
  }
  return 0;
}