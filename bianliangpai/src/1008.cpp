#include "1008.h"


int main() {
  try {

    static const int days_in_a_haab_year = 365;
    static const int days_in_a_tzolkin_year = 260;
    // for most case
    static const int days_in_a_haab_month = 20;
    static const int days_in_a_tzolkin_month = 13;
    static const int months_in_a_haab_year = 19;
    static const int months_in_a_tzolkin_year = 20;

    std::map<std::string, int> haab_month_map;
    InitHaabMonthMap(haab_month_map);

    std::vector<std::string> tzolkin_months;
    InitTzolkinMonths(tzolkin_months);

    std::string str_input_data_num;
    std::getline(std::cin, str_input_data_num);
    int input_data_num = std::atoi(str_input_data_num.c_str());
    std::cout << input_data_num << "\r\n";

    for (int input_cnt = 0; input_cnt < input_data_num; ++input_cnt) {

      std::string line;
      std::getline(std::cin, line);

      int haab_date, haab_years;
      std::string str_haab_month;
      GetHaabInfo(line, haab_date, str_haab_month, haab_years);
      int int_haab_month = haab_month_map[str_haab_month];

      int total_days = haab_years * days_in_a_haab_year +
                       int_haab_month * days_in_a_haab_month +  // int_haab_month counting starts from 0
                       haab_date + 1;                           // haab_date counting starts from 0

      int tzolkin_years;
      int residual_days_in_a_year;
      // total_days must bigger than 0
      if (total_days % days_in_a_tzolkin_year == 0) {
        tzolkin_years = total_days / days_in_a_tzolkin_year - 1;
        residual_days_in_a_year = days_in_a_tzolkin_year;
      }
      else {
        tzolkin_years = total_days / days_in_a_tzolkin_year;
        residual_days_in_a_year = total_days - tzolkin_years * days_in_a_tzolkin_year;
      }
      // tzolkin_month and tzolkin_date are individual
      int int_tzolkin_month = residual_days_in_a_year % months_in_a_tzolkin_year - 1;
      std::string tzolkin_month = tzolkin_months[int_tzolkin_month];
      int tzolkin_date = residual_days_in_a_year % days_in_a_tzolkin_month;

      std::cout << tzolkin_date << " "
                << tzolkin_month << " "
                << tzolkin_years << "\r\n";
    }

    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << "File: " << __FILE__ << ", Line: " << __LINE__
              << ", Reason: " << e.what() << std::endl;
    exit(1);
  }
}