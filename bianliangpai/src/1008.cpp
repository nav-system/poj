#include "1008.h"


int main() {
  try {
    std::map<std::string, int> haab_month_map;
    InitHaabMonthMap(haab_month_map);

    std::vector<std::string> tzolkin_months;
    InitTzolkinMonths(tzolkin_months);

    std::string str_input_data_num;
    std::getline(std::cin, str_input_data_num);
    int input_data_num = std::stoi(str_input_data_num);
    std::cout << input_data_num << "\r\n";

    for (int input_cnt = 0; input_cnt < input_data_num; ++input_cnt) {

      std::string line;
      std::getline(std::cin, line);

      int haab_date, haab_years;
      std::string str_haab_month;
      GetHaabInfo(line, haab_date, str_haab_month, haab_years);
      int int_haab_month = haab_month_map[str_haab_month];

      int total_days = haab_years * 365 + int_haab_month * 20 + haab_date;

      int tzolkin_years = total_days / 360;
      int residual_days_in_a_year = total_days - tzolkin_years * 360;
      int int_tzolkin_month = residual_days_in_a_year / 13;
      std::string tzolkin_month = tzolkin_months[int_tzolkin_month];
      int tzolkin_date = residual_days_in_a_year % 13 + 1;

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