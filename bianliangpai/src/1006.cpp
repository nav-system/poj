#include "1006.h"

int main() {
  int loop_cnt = 0;
  while (++loop_cnt) {

    int p, e, i, d;
    std::scanf("%d%d%d%d", &p, &e, &i, &d);

    int n;
    if (p == -1 && e == -1 && i == -1 && d == -1) {
      return 0;
    }
    else {
      n = GetMinimizedN(p, e, i, d);
    }

    printf("Case %d: the next triple peak occurs in %d days.\r\n",
       loop_cnt, n);
  }
}