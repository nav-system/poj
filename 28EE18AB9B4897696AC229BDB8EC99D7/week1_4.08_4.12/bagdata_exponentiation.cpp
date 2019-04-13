#include<iostream>
#include<string>
#include<vector>
using namespace std;
 
string BigDataMultipy(string str1, string str2);
 
int main()
{
	string input;
	while (getline(cin, input))
	{
		if (input.length() != 9)
		{
			cout << "" << endl;
			continue;
		}
		string integer_str = "";
		int n = 0;
		int dotCount = 0;

		/** get the number_str and the exponentiation*/
		int index = input.find(".");

		/** if not found the point
		 *  the number_str is 0 within length 6
		 *  the exponentiation is 7 within length 2
		 */
		if (index == string::npos)
		{
			dotCount = 0;
			integer_str = input.substr(0, 6);
			/** atoi is to get the int_value from string*/
			n = atoi(input.substr(7, 2).c_str());
		}
		/** if found the point, dot_pos = 5 - point_index
		 *  the number_str is 0 within length point_index + point_index + 1 within length dot_pos
		 *  the exponentiation is 7 within length 2
		 */
		else
		{
			dotCount = 5 - index;
			integer_str = input.substr(0, index) + input.substr(index + 1, dotCount);
			n = atoi(input.substr( 7, 2 ).c_str());
		}

		if (atoi(integer_str.c_str()) == 0)
		{
			cout << "0" << endl;
			continue;
		}

        string answer = integer_str;
		int i;
		for (i = 1; i < n; i++)
		{
			answer = BigDataMultipy(answer, integer_str);
		}

        /** number_str add the dot*/
		int TotalDotCount = dotCount * n;
		if (TotalDotCount != 0)
		{
			answer = answer.substr(0, answer.length() - TotalDotCount)
			      + "." 
			      + answer.substr(answer.length() - TotalDotCount, TotalDotCount);
		}
 
        /** find the 0 position in the frount*/
        int j;
		for (j = 0; j < answer.length() && answer[j] == '0'; j++);

        /** find the 0 position in the last*/
		int k;
		for (k = answer.length() - 1; k >= 0 && answer[k] == '0' && dotCount != 0; k--);

		/** if there is no number behind the dot*/
		if (answer[k] == '.')
		{
			k--;
		}
 
        /** anwser is j whith length (k - j + 1)*/
        /** 000123.56700, j = 3, k = 9, length is 9 - 3 + 1 = 7*/
		answer = answer.substr(j, k + 1 - j);
		cout << answer << endl;
	}
	return 0;
}

 
/**vector to realize the bigdata_exponentiation*/
string BigDataMultipy(string str1, string str2)
{
	/** get the number length*/
	int len1 = str1.length();
	int len2 = str2.length();

	/** init the vector<int>*/
	vector<int> mid_answer(len1 + len2, 0);

	/** reverse the number string
	 *  cause we need calculate from the number in the low position
	*/
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int i, j, k;
	for (i = 0; i < len1; i++)  
	{
		for (j = 0; j < len2; j++)
		{
			/** num_str - '0' to get int value*/
			mid_answer[i+j] += (str1[i] - '0') * (str2[j] - '0');
		}
	}

	for (k = 0; k < len1 + len2; k++)
	{
		if (mid_answer[k] >= 10)
		{
			/** add mod to the high pos*/
			mid_answer[k+1] += mid_answer[k] / 10;
			/** get the self pos value*/
			mid_answer[k] %= 10;
		}
	}

    /** get the answer_string*/
	string Answer = "";
	for( k = 0; k < len1 + len2; k++ )
	{
		char c = '0' + mid_answer[k];
		Answer += c;
	}

    /** the answer number reversie*/
	reverse(Answer.begin(), Answer.end());
	return Answer;
}