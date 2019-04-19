#include "1006.h"

int main() {
  // pre-calculate
  std::vector<bool> is_prime;
  int max_number = (int)std::sqrt(365.f) + 1;
  JudgeAllNumbersSmallerThanNIsPrime(max_number, is_prime);

  int p, e, i, d;
  while (true) {

    std::scanf("%d%d%d%d", &p, &e, &i, &d);
    if (p == -1 && e == -1 && i == -1 && d == -1) {
      return 0;
    }

    //TODO:

  }
}