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
  for (int it = 0; it < results.size(); ++it) {
    printf("%s\n", results[it].c_str());
  }
  return 0;
}