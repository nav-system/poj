#include <iostream>
#include <vector>
#include <sstream>

#include "1001.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ostringstream;

//int main(int argc,char* argv[])
//{
//	string num_str, res_str;
//	unsigned short num_expon(0);
//	while (cin >> num_str >> num_expon)
//	{
//		calculate_expon(num_str, num_expon, res_str);
//		cout << res_str << endl;
//	}
//}

void calculate_expon(string & num_str, unsigned short & num_exp, string & res_str)
{
	if (num_exp == 0)
	{
		res_str = "1";
	}
	else
	{
		res_str.clear();
		unsigned short after_dot(0);
		clear_trailing_zeros(num_str);
		cal_after_and_remove_dot(num_str, after_dot);
		//cout << after_dot << endl;
		after_dot *= num_exp;
		//cout << after_dot << endl;
		power(num_str, res_str, num_exp);
		add_dot(res_str, after_dot);
		clear_trailing_zeros(res_str);
		clear_leading_zeros(res_str);
		if (res_str.length() == 0)
		{
			res_str = "0";
		}
	}
}

void clear_trailing_zeros(string& num_str)
{
	bool has_dot = false;
	bool stop_cal_zero = false;
	if (num_str.length() > 1 && num_str.at(num_str.length() - 1) == '0')
	{
		size_t tail_index = num_str.length() - 1, zero_length = 1;
		for (int count = num_str.length() - 2; count >= 0; count--)
		{
			if (num_str.at(count) == '0' && stop_cal_zero == false)
			{
				zero_length++;
			}
			else if (num_str.at(count) == '.')
			{
				has_dot = true;
				break;
			}
			else
			{
				stop_cal_zero = true;
			}
		}
		if (has_dot)
		{
			num_str.erase(tail_index - zero_length + 1, zero_length);
		}
	}
	//cout << num_str << endl;
}

void clear_leading_zeros(string& num_str)
{
	if (num_str.length() > 1 && num_str.at(0) == '0')
	{
		size_t start_index = 0, zero_length = 1;
		for (size_t count = 1; count < num_str.length(); count++)
		{
			if (num_str.at(count) == '0')
			{
				zero_length++;
			}
			else
			{
				break;
			}
		}
		if (zero_length == num_str.length())
		{
			num_str = "0";
		}
		else
		{
			num_str.erase(start_index, zero_length);
		}
	}
}

void cal_after_and_remove_dot(string& num_str, unsigned short& after_dot)
{
	bool has_dot = false;
	for (int count = num_str.length() - 1; count >= 0; count--)
	{
		if (num_str.at(count) != '.')
		{
			after_dot++;
		}
		else
		{
			has_dot = true;
			num_str.erase(count, 1);
			break;
		}
	}
	if (!has_dot)
	{
		after_dot = 0;
	}
	return;
}

void power(string& num_str, string& res_str, unsigned short& num_exp)
{
	res_str = num_str;
	while ((--num_exp) > 0)
	{
		multiple(num_str, res_str, res_str);
	}
	return;
}

void multiple(string& num_1, string& num_2, string& product)
{
	vector<unsigned short> res_arr( num_1.length() + num_2.length() - 1, 0);
	for (size_t count_1 = 0; count_1 < num_1.length(); count_1++)
	{
		for (size_t count_2 = 0; count_2 < num_2.length(); count_2++)
		{
			res_arr.at(count_1 + count_2) += ((unsigned short)num_1.at(count_1) - '0') * ((unsigned short)num_2.at(count_2) - '0');
		}
	}
	for (size_t count = res_arr.size() - 1; count > 0; count--)
	{
		if (res_arr.at(count) / 10 != 0)
		{
			res_arr.at(count - 1) += res_arr.at(count) / 10;
			res_arr.at(count) %= 10;
		}
	}
	ostringstream oss;
	for (size_t count = 0; count < res_arr.size(); count++)
	{
		oss << (unsigned int)res_arr.at(count);
	}
	product = oss.str();
	return;
}

void add_dot(string& num_str, unsigned short& after_dot) 
{
	if (after_dot != 0)
	{
		num_str.insert(num_str.length() - after_dot, ".");
	}
	return;
}