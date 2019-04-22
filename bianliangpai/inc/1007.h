#ifndef __1007_H__
#define __1007_H__

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <stdexcept>

typedef std::pair<int, std::string> SortedPair;

struct SortedPairComp {
  bool operator()(const SortedPair& sp1, const SortedPair& sp2) {
    return sp1.first < sp2.first;
  }
};

int CalcSortedCoefficient(const std::string& s) {
  try {
    int coefficient = 0;
    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it) {
      for (std::string::const_iterator jt = it; jt != s.end(); ++jt) {
        if (*jt < *it) {
          ++coefficient;
        }
      }
    }
    return coefficient;
  }
  catch (const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s\n", __FILE__, __LINE__, e.what());
    exit(1);
  }
}

#endif // __1007_H__