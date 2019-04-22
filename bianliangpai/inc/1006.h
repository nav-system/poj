#ifndef __1006_H__
#define __1006_H__

#include <cstdio>
#include <cstdlib>
#include <stdexcept>

// minimize n
// n = p_peroid * (t1-1) + p - d
//   = e_peroid * (t2-1) + e - d
//   = i_peroid * (t3-1) + i - d
//
// max_loop_cnt = e_peroid * i_peroid = 924
int GetMinimizedN(int p, int e, int i, int d) {
  static int p_peroid = 23;
  static int e_peroid = 28;
  static int i_peroid = 33;
  static int least_common_multiple = p_peroid * e_peroid * i_peroid; // 21252

  try {
    int n;

    p %= p_peroid;
    e %= e_peroid;
    i %= i_peroid;

    for (int t1 = 1; ; ++t1) {
      n = p_peroid * (t1-1) + p;
      if (n % e_peroid == e && n % i_peroid == i) {
        if (n <= d) {
          continue;
        }
        else {
          break;
        }
      }
    }

    return n - d;
  }
  catch (const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s\n", __FILE__, __LINE__, e.what());
    exit(1);
  }
}

#endif // __1006_H__