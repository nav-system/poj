#include "1008.h"


int main() {
  try {
    std::string str_input_data_num;
    std::getline(std::cin, str_input_data_num);
    int input_data_num = std::atoi(str_input_data_num.c_str());
    std::cout << input_data_num << "\r\n";

    for (int input_cnt = 0; input_cnt < input_data_num; ++input_cnt) {

      std::string line;
      std::getline(std::cin, line);

      int haab_date, haab_month, haab_years;
      GetHaabInfo(line, haab_date, haab_month, haab_years);

      int total_days = haab_years * days_in_a_haab_year +
                       haab_month * days_in_a_haab_month +  // int_haab_month counting starts from 0
                       haab_date + 1;                       // haab_date counting starts from 0

      int tzolkin_date, tzolkin_years;
      std::string tzolkin_month;
      GetTzolkinCalendar(total_days, tzolkin_date, tzolkin_month, tzolkin_years);

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