#ifndef __1008_H__
#define __1008_H__

#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>


template<
  typename T = std::string,
  template <typename = T, typename = std::allocator<T>> class SequenceContainer
>
void Split(std::string s, const std::string& delimiter,
           SequenceContainer<std::string>& sc) {
  try {
    std::size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        sc.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    sc.push_back(s);
  }
  catch (const std::exception& e) {
    std::cerr << "File: " << __FILE__ << ", Line: " << __LINE__
              << ", Reason: " << e.what() << std::endl;
    exit(1);
  }
}


void InitHaabMonthMap(std::map<std::string, int>& haab_month_map) {
  try {
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
  catch (const std::exception& e) {
    std::cerr << "File: " << __FILE__ << ", Line: " << __LINE__
              << ", Reason: " << e.what() << std::endl;
    exit(1);
  }
}

void InitTzolkinMonths(std::vector<std::string>& tzolkin_months) {
  try {
    tzolkin_months.reserve(20);
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
  catch (const std::exception& e) {
    std::cerr << "File: " << __FILE__ << ", Line: " << __LINE__
              << ", Reason: " << e.what() << std::endl;
    exit(1);
  }
}

void GetHaabInfo(const std::string& line,
                 int& date, std::string& str_month, int& years) {
  try {
    std::vector<std::string> words;
    Split(line, " ", words);
    words[0].erase(words[0].length()-1, 1);

    date = std::stoi(words[0]);
    str_month = words[1];
    years = std::stoi(words[2]);
  }
  catch (const std::exception& e) {
    std::cerr << "File: " << __FILE__ << ", Line: " << __LINE__
              << ", Reason: " << e.what() << std::endl;
    exit(1);
  }
}



#endif // __1008_H__