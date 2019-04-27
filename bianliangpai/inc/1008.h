#ifndef __1008_H__
#define __1008_H__

#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

#define POJ_TRY(code)                                            \
do {                                                             \
  try {                                                          \
    code;                                                        \
  }                                                              \
  catch (const std::exception& e) {                              \
    std::cerr << "File: " << __FILE__ << ", Line: " << __LINE__  \
              << ", Reason: " << e.what() << std::endl;          \
    exit(1);                                                     \
  }                                                              \
} while (0);

static const int days_in_a_haab_year = 365;
static const int days_in_a_tzolkin_year = 260;
// for most case
static const int days_in_a_haab_month = 20;
static const int days_in_a_tzolkin_month = 13;
static const int months_in_a_haab_year = 19;
static const int months_in_a_tzolkin_year = 20;

void Split(std::string s, const std::string& delimiter,
           std::vector<std::string>& sc) {
  POJ_TRY (
    std::size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        sc.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    sc.push_back(s);
  )
}


void InitHaabMonthMap(std::map<std::string, int>& haab_month_map) {
  POJ_TRY (
    if (haab_month_map.empty()) {
      haab_month_map["pop"] = 0;
      haab_month_map["no"] = 1;
      haab_month_map["zip"] = 2;
      haab_month_map["zotz"] = 3;
      haab_month_map["tzec"] = 4;
      haab_month_map["xul"] = 5;
      haab_month_map["yoxkin"] = 6;
      haab_month_map["mol"] = 7;
      haab_month_map["chen"] = 8;
      haab_month_map["yax"] = 9;
      haab_month_map["zac"] = 10;
      haab_month_map["ceh"] = 11;
      haab_month_map["mac"] = 12;
      haab_month_map["kankin"] = 13;
      haab_month_map["muan"] = 14;
      haab_month_map["pax"] = 15;
      haab_month_map["koyab"] = 16;
      haab_month_map["cumhu"] = 17;
      haab_month_map["uayet"] = 18;
    }
  )
}

void InitTzolkinMonths(std::vector<std::string>& tzolkin_months) {
  POJ_TRY (
    if (tzolkin_months.empty()) {
      tzolkin_months.push_back("imix");
      tzolkin_months.push_back("ik");
      tzolkin_months.push_back("akbal");
      tzolkin_months.push_back("kan");
      tzolkin_months.push_back("chicchan");
      tzolkin_months.push_back("cimi");
      tzolkin_months.push_back("manik");
      tzolkin_months.push_back("lamat");
      tzolkin_months.push_back("muluk");
      tzolkin_months.push_back("ok");
      tzolkin_months.push_back("chuen");
      tzolkin_months.push_back("eb");
      tzolkin_months.push_back("ben");
      tzolkin_months.push_back("ix");
      tzolkin_months.push_back("mem");
      tzolkin_months.push_back("cib");
      tzolkin_months.push_back("caban");
      tzolkin_months.push_back("eznab");
      tzolkin_months.push_back("canac");
      tzolkin_months.push_back("ahau");
    }
  )
}

void GetHaabInfo(const std::string& line,
                 int& date, int& month, int& years) {
//  POJ_TRY (
    static std::map<std::string, int> haab_month_map;
    InitHaabMonthMap(haab_month_map);

    std::vector<std::string> words;
    Split(line, " ", words);

    // remove '.'
    words[0].erase(words[0].length()-1, 1);

    date = std::atoi(words[0].c_str());
    month = haab_month_map[words[1]];
    years = std::atoi(words[2].c_str());
//  )
}

void GetTzolkinCalendar(int total_days,
                        int& date, std::string& str_month, int& years) {
  POJ_TRY (
    static std::vector<std::string> tzolkin_months;
    InitTzolkinMonths(tzolkin_months);

    int residual_days_in_a_year;

    // total_days and residual_days must bigger than 0
    if (total_days % days_in_a_tzolkin_year == 0) {
      int times_total_days_of_days_in_a_tzolkin_year =
        total_days / days_in_a_tzolkin_year;
      if (times_total_days_of_days_in_a_tzolkin_year == 0) {
        years = 0;
        residual_days_in_a_year = total_days;
      }
      else {
        years = total_days / days_in_a_tzolkin_year - 1;
        residual_days_in_a_year = days_in_a_tzolkin_year;
      }
    }
    else {
      years = total_days / days_in_a_tzolkin_year;
      residual_days_in_a_year = total_days - years * days_in_a_tzolkin_year;
    }

    // tzolkin_month and tzolkin_date are individual
    int int_tzolkin_month;

    int_tzolkin_month = residual_days_in_a_year % months_in_a_tzolkin_year == 0 ?
                        months_in_a_tzolkin_year - 1 :
                        residual_days_in_a_year % months_in_a_tzolkin_year - 1;
    if (int_tzolkin_month >= months_in_a_tzolkin_year || int_tzolkin_month < 0) {
      throw std::runtime_error("int_tzolkin_month >= 20 or < 0");
    }
    str_month = tzolkin_months[int_tzolkin_month];

    date = residual_days_in_a_year % days_in_a_tzolkin_month == 0 ?
           days_in_a_tzolkin_month :
           residual_days_in_a_year % days_in_a_tzolkin_month;
    if (date > days_in_a_tzolkin_month || date <= 0) {
      throw std::runtime_error("date > 13 or <= 0");
    }
  )
}

#endif // __1008_H__