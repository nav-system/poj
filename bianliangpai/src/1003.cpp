#include <cstdio>
#include <cstdlib>
#include <stdexcept>

int CalcMinimumNThatBiggerThanInputHarmonicSeries(float f) {
  try {
    float sum = 0.f;
    for (int i = 2; ; ++i) {
      sum += (1.f / i);
      if (sum > f) {
        return i-1;
      }
    }
  }
  catch (const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s\n", __FILE__, __LINE__, e.what());
    exit(1);
  }
}

int main() {
  float length;
  while (true) {

    std::scanf("%f", &length);
    if (length < 0.01f || length > 5.20f) {
      return 0;
    }

    int amount = CalcMinimumNThatBiggerThanInputHarmonicSeries(length);
    printf("%d card(s)\n", amount);
  }

  return 0;
}