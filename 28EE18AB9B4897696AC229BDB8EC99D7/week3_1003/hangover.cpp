#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string input;
	double sample_in;
	double answer_length = 0.0;
	int card_cnt = 0;
    while (getline(cin, input))
    {
        sample_in = atof(input.c_str());
		if (sample_in < 0.01 || sample_in > 5.20)
		{
		    continue;
		}
		
		if (double(1/2.0) >= sample_in)
		{
			cout << '1' << ' ' << "card(s)" << endl; 
			continue;
		}
		else
		{
			card_cnt = 2;
			answer_length = 0.5;
		}

		while ((answer_length += double(1/(card_cnt + 1.0))) < sample_in)
		{
		    card_cnt += 1;
		}
		cout << card_cnt << " " << "card(s)" << endl;
	}
}
