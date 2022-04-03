#include <iostream>
using namespace std;

struct String
{
	unsigned int size = 1;
	char* arr = new char[size];
};

void get_value(String& str, char test_str[]);
void show(const String& str);
void get_size(const String& str);
void dinamic_cleaner(String& str);
void concatination(String& str_main, const String& str1, const String& str2);
unsigned int return_size(const String& str);
void get_value_by_index(const String& str, int n);
int cin_checker(int& var);


int main()
{
	String str1, str2, str3, helper;
	str1.arr[0] = '\0';
	str2.arr[0] = '\0';
	str3.arr[0] = '\0';
	helper.arr[0] = '\0';

	int counter = 1;
	const unsigned int MAX = 100;
	char ch = 'y';

	for (int i = 0; i < 2; i++)
	{
		cout << "Type in a sentence #" << i + 1 << ": ";
		char test_arr[MAX];
		cin.getline(test_arr, MAX);

		if (counter == 1)
			get_value(str1, test_arr);
		else if (counter == 2)
			get_value(str2, test_arr);

		counter++;
	}

	while (ch != 'n')
	{
		cout << "\nFunctions...\n1 - concatenation\n2 - get size\n3 - get i index\n4 - get a sentence by a literal\n\n";
		int choice;
		cin_checker(choice);

		if (choice == 1)
		{
			cout << "Sentence #1: "; show(str1);
			cout << "\nSentence #2: "; show(str2);

			concatination(helper, str1, str2);

			cout << "\nSentence1 + Sentence2: "; show(helper);
			cout << endl;
		}
		else if (choice == 2)
		{
			cout << "Choose which sentence's size do you want to get: 1 or 2..";
			int choice2;
			cin_checker(choice2);

			if (choice2 == 1)
				get_size(str1);
			else if (choice2 == 2)
				get_size(str2);
			else
			{
				cout << "\nYou typed a non existing sentence..\n";
				continue;
			}
		}

		else if (choice == 3)
		{
			int indx, choice2;
			cout << "Type in index which you want to get..: ";
			cin_checker(indx);
			cout << "Type in sentence which value you'd like to get..: ";
			cin_checker(choice2);

			if (choice2 == 1)
			{
				if (indx >= 0 and indx < return_size(str1))
					get_value_by_index(str1, indx);
				else
					cout << "Such index does not exist...\n";
			}
			else if (choice2 == 2)
			{
				if (indx >= 0 and indx < return_size(str2))
					get_value_by_index(str2, indx);
				else
					cout << "Such index does not exist...\n";
			}
			else
			{
				cout << "\nYou typed a non existing sentence..\n";
				continue;
			}
		}
		else if (choice == 4)
		{
			cout << "Type in a sentence: ";
			char test_arr[MAX];

			cin.ignore();
			cin.getline(test_arr, MAX);

			get_value(str3, test_arr);

			char ch;
			cout << "To show the sentence to in 'y': "; cin >> ch;
			if (ch == 'y')
				show(str3);
			else
				continue;
		}
		else
		{
			cout << "\nYou typed a non existing function number..\n";
			continue;
		}

		cout << "\nContinue to use programm(y/n)?: "; cin >> ch;
		if (ch != 'n')
		{
			if (ch == 'y')
				continue;
			else
			{
				cout << "\nWrong value typed..\n";
				break;
			}
		}

	}

	dinamic_cleaner(str1);
	dinamic_cleaner(str2);
	dinamic_cleaner(str3);
	dinamic_cleaner(helper);

	return 0;
}

void get_value(String& str, char test_str[])
{
	str.size = strlen(test_str);
	delete[] str.arr;
	str.arr = new char[str.size];

	for (int i = 0; i < str.size; i++)
	{
		*(str.arr + i) = *(test_str + i);
	}
}

void show(const String& str)
{
	for (int i = 0; i < str.size; i++)
		cout << str.arr[i];
}

void dinamic_cleaner(String& str)
{
	delete[] str.arr;
}

void get_size(const String& str)
{
	cout << "Size: " << str.size << endl;
}

void concatination(String& str_main, const String& str1, const String& str2)
{
	str_main.size = str1.size + str2.size;
	delete[] str_main.arr;
	str_main.arr = new char[str_main.size];

	for (int i = 0; i < str1.size; i++)
	{
		str_main.arr[i] = str1.arr[i];
	}

	for (int i = 0; i < str2.size; i++)
	{
		str_main.arr[str1.size + i] = str2.arr[i];
	}
}

unsigned int return_size(const String& str)
{
	return str.size;
}

void get_value_by_index(const String& str, int n)
{
	cout << "Value with index " << n << ": " << str.arr[n] << endl;
}

int cin_checker(int& var)
{
	cin >> var;

	if (cin.fail())
	{
		cin.clear();
		cout << "Wrong value type...\n";
		exit(1);
	}
}