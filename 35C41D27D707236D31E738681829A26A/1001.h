#pragma once
#include <string>
using std::string;

void calculate_expon(string& num_str, unsigned short& num_exp, string& res_str);

void clear_trailing_zeros(string& num_str);

void clear_leading_zeros(string& num_str);

void cal_after_and_remove_dot(string& num_str, unsigned short& after_dot);

void power(string& num_str, string& res_str, unsigned short& num_exp);

void multiple(string& num_1, string& num_2, string& product);

void add_dot(string& num_str, unsigned short& after_dot);