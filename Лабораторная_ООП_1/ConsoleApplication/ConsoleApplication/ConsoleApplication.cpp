// Быковский Сергей Сергеевич ИДБ-21-11
// разработать свою версию класса string
// ООП
#include <iostream>
#include <cstring> // чтобы использовать strlen();
using namespace std;

class String
{
private:
	unsigned int size = 1;
	char* arr = new char[size];
public:
	String()
	{
		*arr = '\0';
	}
	void get_value(char test_str[]);
	void get_size() const;
	void get_value_by_index(int n) const;
	void concatination(String& arr1, String& arr2);
	void show() const;
	unsigned int return_size() const;
	void dinamic_cleaner();
};

void String::dinamic_cleaner()
{
	delete[] arr;
}

unsigned int String::return_size() const
{
	return size;
}


void String::get_size() const
{
	cout << "The size is: " << size << endl;
}

void String::get_value_by_index(int n) const
{
	cout << "Value with index " << n << ": " << *(arr + n) << endl;
}

void String::show() const
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i);
	}
	cout << endl;
}

void String::get_value(char test_str[])
{
	size = strlen(test_str);
	delete[] arr;
	arr = new char[size];

	for (int i = 0; i < size; i++)
	{
		*(arr + i) = *(test_str + i);
	}
}

void String::concatination(String& arr1, String& arr2)
{
	size = arr1.size + arr2.size;
	delete[] arr;
	arr = new char[size];

	for (int i = 0; i < arr1.size; i++)
	{
		arr[i] = arr1.arr[i];
	}

	for (int i = 0; i < arr2.size; i++)
	{
		arr[arr1.size + i] = arr2.arr[i];
	}
}

void cin_checker(int& var)
{
	cin >> var;

	if (cin.fail())
	{
		cin.clear();
		cout << "Wrong value type...\n";
		exit(1);
	}
}


int main()
{
	String str1, str2, str3, helper;

	int counter = 1;
	const unsigned int MAX = 100;
	char ch = 'y';

	for (int i = 0; i < 2; i++)
	{
		cout << "Type in a sentence #" << i + 1 << ": ";
		char test_arr[MAX];
		cin.getline(test_arr, MAX);

		if (counter == 1)
			str1.get_value(test_arr);
		else if (counter == 2)
			str2.get_value(test_arr);

		counter++;
	}

	while (ch != 'n')
	{
		cout << "\nFunctions...\n1 - concatenation\n2 - get size\n3 - get i index\n4 - get a sentence by a literal\n\n";
		int choice;
		cin_checker(choice);

		if (choice == 1)
		{
			cout << "Sentence #1: "; str1.show();
			cout << "Sentence #2: "; str2.show();

			helper.concatination(str1, str2);

			cout << "Sentence1 + Sentence2: "; helper.show();
		}
		else if (choice == 2)
		{
			cout << "Choose which sentence's size do you want to get: 1 or 2..";
			int choice2;
			cin_checker(choice2);

			if (choice2 == 1)
				str1.get_size();
			else if (choice2 == 2)
				str2.get_size();
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
				if (indx >= 0 and indx < str1.return_size())
					str1.get_value_by_index(indx);
				else
					cout << "Such index does not exist...\n";
			}
			else if (choice2 == 2)
			{
				if (indx >= 0 and indx < str2.return_size())
					str2.get_value_by_index(indx);
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

			str3.get_value(test_arr);

			char ch;
			cout << "To show the sentence to in 'y': "; cin >> ch;
			if (ch == 'y')
				str3.show();
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

	str1.dinamic_cleaner();
	str2.dinamic_cleaner();
	str3.dinamic_cleaner();
	helper.dinamic_cleaner();

	return 0;
}
