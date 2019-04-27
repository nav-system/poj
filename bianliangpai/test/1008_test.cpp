#include <string>

#include <gtest/gtest.h>

#include "1008.h"


TEST(GetTzolkinCalendar, normal) {
  int total_days, tzolkin_date, tzolkin_years;
  std::string tzolkin_month;

  total_days = 1;
  GetTzolkinCalendar(total_days, tzolkin_date, tzolkin_month, tzolkin_years);
  EXPECT_EQ(tzolkin_date, 1);
  EXPECT_EQ(tzolkin_month, "imix");
  EXPECT_EQ(tzolkin_years, 0);

  total_days = 260;
  GetTzolkinCalendar(total_days, tzolkin_date, tzolkin_month, tzolkin_years);
  EXPECT_EQ(tzolkin_date, 13);
  EXPECT_EQ(tzolkin_month, "ahau");
  EXPECT_EQ(tzolkin_years, 0);

  total_days = 261;
  GetTzolkinCalendar(total_days, tzolkin_date, tzolkin_month, tzolkin_years);
  EXPECT_EQ(tzolkin_date, 1);
  EXPECT_EQ(tzolkin_month, "imix");
  EXPECT_EQ(tzolkin_years, 1);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}