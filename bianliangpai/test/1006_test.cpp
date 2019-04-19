#include <vector>
#include <algorithm>

#include <gtest/gtest.h>

#include "1006.h"

TEST(IsFactorOf, normal) {
  EXPECT_EQ(IsFactorOf(1, 2), false);
  EXPECT_EQ(IsFactorOf(2, 2), false);
  EXPECT_EQ(IsFactorOf(2, 4), true);
  EXPECT_EQ(IsFactorOf(2, 5), false);
}

TEST(JudgeAllNumbersSmallerThanNIsPrime, normal) {

  std::vector<int> prime_list = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
    73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151,
    157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233,
    239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317,
    331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419,
    421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503,
    509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607,
    613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701,
    709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811,
    821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911,
    919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997
  };

  std::vector<bool> prime_result;
  JudgeAllNumbersSmallerThanNIsPrime(1000, prime_result);

  for (int number = 2; number <= prime_result.size(); ++number) {
    if (std::find(prime_list.begin(), prime_list.end(), number)
          != prime_list.end()) {
      EXPECT_EQ(prime_result[number-1], 1);
    }
    else {
      EXPECT_EQ(prime_result[number-1], 0);
    }
  }
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}