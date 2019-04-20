#include "1006.h"

int main() {
  // pre-calculate
  std::vector<bool> is_prime;
  int max_number = 365; //(int)std::sqrt(365.f) + 1;
  JudgeAllNumbersSmallerThanNIsPrime(max_number, is_prime);

  std::list<int> all_prime;
  for (int number = 2; number <= is_prime.size(); ++number) {
    if (is_prime[number]) {
      all_prime.push_back(number);
    }
  }

  int p, e, i, d;
  while (true) {

    static int loop_cnt = 0;
    ++loop_cnt;

    std::scanf("%d%d%d%d", &p, &e, &i, &d);
    int least_common_multiple = 1;
    if (p == -1 && e == -1 && i == -1 && d == -1) {
      return 0;
    }
    else if (p == 0 || e == 0 || i == 0) {
      least_common_multiple = 21252;
    }
    else {
      std::list<int> factor_list;
      FindAllFactorNumberOf(p, all_prime, factor_list);
      FindAllFactorNumberOf(e, all_prime, factor_list);
      FindAllFactorNumberOf(i, all_prime, factor_list);

      for (std::list<int>::iterator it = factor_list.begin();
           it != factor_list.end(); ++it) {
        least_common_multiple *= (*it);
      }
    }

    printf("Case %d: the next triple peak occurs in %d days.\r\n",
           loop_cnt, least_common_multiple - d);
  }
}