#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

typedef struct __tire_node
{
	bool is_complete_phone_numer;
	int  phone_number_cnt;
	struct  __tire_node* next[10];
}tire_node_t, *tire_node_handle_t;

tire_node_handle_t tire_root = NULL;

char char_to_number[26] =
{
	'2', '2', '2',
	'3', '3', '3',
	'4', '4', '4',
	'5', '5', '5',
	'6', '6', '6',
	'7', '0', '7',
	'7', '8', '8',
	'8', '9', '9',
	'9', '0'
};

bool is_repeat_number = false;

tire_node_handle_t create_tire_node()
{
	tire_node_handle_t node_of_tire = NULL;
	node_of_tire = (tire_node_handle_t)calloc(1, sizeof(tire_node_t));

	node_of_tire->is_complete_phone_numer = false;
	node_of_tire->phone_number_cnt = 0;

	return node_of_tire;
}

void insert_into_tire(string phone_number)
{
	tire_node_handle_t node_tire = tire_root;

    
	for (int j = 0; j < phone_number.length(); j ++)
	{
        if (phone_number[j] == '-' || phone_number[j] == 'Q' || phone_number[j] == 'Z')
        {
            continue;
        }

        /** get the phone number position in the tire*/
		int i;
		if ((int)phone_number[j] >= 'A')
		{
			i = char_to_number[phone_number[j] - 'A'] - '0';
		}
		else
		{
			i = phone_number[j] - '0';
		}

        /** mark the number*/
        if (node_tire->next[i] == NULL)
        {
        	node_tire->next[i] = create_tire_node();
        }
        node_tire = node_tire->next[i];
	}

	node_tire->phone_number_cnt += 1;
	if (node_tire->phone_number_cnt > 1)
	{
		node_tire->is_complete_phone_numer = true;
	}
}

void dfs_tire(tire_node_handle_t tire_node)
{
	int i = 0;
	static string phone_num = "";

	if (tire_node == NULL)
	{
		return;
	}

	for (i = 0; i < 10; i++)
	{
		if (tire_node->next[i] == NULL)
		{
			continue;
		}

		char mid_c = i + '0';
		phone_num += mid_c;

		if (tire_node->next[i]->is_complete_phone_numer == true)
		{
			if (tire_node->next[i]->phone_number_cnt > 1)
			{
				is_repeat_number = true;
				cout << phone_num.substr(0, 3) << '-' << phone_num.substr(3) << ' ' << tire_node->next[i]->phone_number_cnt << endl;
			}
		}

		dfs_tire(tire_node->next[i]);
		phone_num = phone_num.substr(0, phone_num.length() - 1);
		//printf("%s\n", phone_num.c_str());
	}
	return;
}

int main()
{
	string num_str;
	int num;
	string input = "";

	/** init tire node*/
	tire_root = create_tire_node();

	/** get the cnts of phone number*/
	getline(cin, num_str);
	num = atoi(num_str.c_str());

	/** load phone num*/
	while(num)
	{
		getline(cin, input);
		insert_into_tire(input);
		num --;
	}

	/** dfs*/
	dfs_tire(tire_root);

	if (is_repeat_number == false)
	{
		cout << "No duplicates." << endl;
	}
}