#include <gtest/gtest.h>

#include "1006.h"


TEST(GetMinimizedN, normal) {
  int p, e, i, d, n;

#define ASSIGN_PEID(p_, e_, i_, d_) \
 do {                               \
  p = p_;                           \
  e = e_;                           \
  i = i_;                           \
  d = d_;                           \
 } while (0);

  ASSIGN_PEID(0,0,0,0);
  n = GetMinimizedN(p, e, i, d);
  EXPECT_EQ(n, 21252);

  ASSIGN_PEID(0,0,0,100);
  n = GetMinimizedN(p, e, i, d);
  EXPECT_EQ(n, 21152);

  ASSIGN_PEID(0,0,0,21251);
  n = GetMinimizedN(p, e, i, d);
  EXPECT_EQ(n, 1);

  ASSIGN_PEID(24,29,34,2);
  n = GetMinimizedN(p, e, i, d);
  EXPECT_EQ(n, 21251);

  ASSIGN_PEID(24,29,34,1);
  n = GetMinimizedN(p, e, i, d);
  EXPECT_EQ(n, 21252);

  ASSIGN_PEID(24,29,34,0);
  n = GetMinimizedN(p, e, i, d);
  EXPECT_EQ(n, 1);

  ASSIGN_PEID(5,20,34,325);
  n = GetMinimizedN(p, e, i, d);
  EXPECT_EQ(n, 19575);

  ASSIGN_PEID(4,5,6,7);
  n = GetMinimizedN(p, e, i, d);
  EXPECT_EQ(n, 16994);

  ASSIGN_PEID(283,102,23,320);
  n = GetMinimizedN(p, e, i, d);
  EXPECT_EQ(n, 8910);

  ASSIGN_PEID(203,301,203,40);
  n = GetMinimizedN(p, e, i, d);
  EXPECT_EQ(n, 10789);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}