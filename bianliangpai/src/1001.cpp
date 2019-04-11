#include "1001.h"

int main() {
  // c++ style I/O sucks
  const static int base_length = 6;
  char base[base_length] = { '\0' };
  int exponent = -1;
  std::vector<std::string> results;
  while (true) {
    int ret = std::scanf("%s%d", base, &exponent);
    if (2 == ret) {
      std::string result;
      CalculateIntergerExponentInString(base, exponent, result);
      results.push_back(result);
    }
    else if (ret == EOF) {
      break;
    }
  }
  for (int result_it = 0; result_it < results.size(); ++result_it) {
    printf("%s\n", results[result_it].c_str());
  }
  return 0;
}