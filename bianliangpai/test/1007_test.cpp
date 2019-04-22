#include <gtest/gtest.h>

#include "1007.h"

TEST(CalcSortedCoefficient, normal) {
  EXPECT_EQ(CalcSortedCoefficient("ABCDEF"), 0);
  EXPECT_EQ(CalcSortedCoefficient("FEDCBA"), 15);
  EXPECT_EQ(CalcSortedCoefficient("AAAAAA"), 0);
  EXPECT_EQ(CalcSortedCoefficient("FABCDE"), 5);
}

TEST(SortedPairComp, normal) {
  SortedPair sp1, sp2;
  SortedPairComp comp;

  sp1.first = 1;
  sp2.first = 1;
  EXPECT_EQ(comp(sp1, sp2), false);

  sp1.first = 1;
  sp2.first = 2;
  EXPECT_EQ(comp(sp1, sp2), true);

  sp1.first = 2;
  sp2.first = 1;
  EXPECT_EQ(comp(sp1, sp2), false);
}

TEST(sort, stable_sort) {
  SortedPair sp;
  std::vector<SortedPair> v;

  sp.first = 2;
  sp.second = "1";
  v.push_back(sp);
  sp.first = 2;
  sp.second = "2";
  v.push_back(sp);
  sp.first = 1;
  sp.second = "3";
  v.push_back(sp);
  sp.first = 1;
  sp.second = "4";
  v.push_back(sp);

  std::sort(v.begin(), v.end(), SortedPairComp());

  EXPECT_EQ(v[0].second, "3");
  EXPECT_EQ(v[1].second, "4");
  EXPECT_EQ(v[2].second, "1");
  EXPECT_EQ(v[3].second, "2");
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}