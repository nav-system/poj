#include "1007.h"

int main() {
  int n, m;
  std::scanf("%d%d", &n, &m);

  std::vector<SortedPair> all_data;
  all_data.reserve(m);

  // prepare for sort
  for (int read_cnt = 0; read_cnt < m; ++read_cnt) {

    SortedPair pair;

    char buf[n];
    std::scanf("%s", buf);
    pair.second.assign(buf);

    pair.first = CalcSortedCoefficient(pair.second);

    all_data.push_back(pair);

  }

  std::sort(all_data.begin(), all_data.end(), SortedPairComp());

  for (std::vector<SortedPair>::iterator it = all_data.begin();
       it != all_data.end(); ++it) {
    printf("%s\r\n", it->second.c_str());
  }

  return 0;
}