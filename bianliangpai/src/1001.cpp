#include "1001.h"

int main() {
  // c++ style I/O sucks
  constexpr int base_length = 6;
  char base[base_length] = { '\0' };
  int exponent = -1;
  while (2 == std::scanf("%s%d", base, &exponent)) {
    std::string multiplier(base);
    std::string result(base);
    std::size_t decimal_point_position = 0;
    ConvertBaseToInterger(base, multiplier, decimal_point);
    for (int multiply_cnt = 0; multiply_cnt < exponent; ++multiply_cnt) {
      CalculateIntergerProductInString(multiplier, result);
    }
    AdjustFormat(result);
    printf("%s\n", result.c_str());
  }

  return 0;
}