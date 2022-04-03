#include <iostream>
#include <cstring> // чтобы использовать strlen();
#include <string>
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
	void show() const;
	unsigned int return_size() const;
	void dinamic_cleaner();

	friend ostream& operator << (ostream& cout, String& other);
	friend istream& operator >> (istream& cin, String& other);


	//Перегруженные операторы
	void operator = (const String& other)
	{
		this->size = other.size;
		if (this->arr != nullptr)
		{
			delete[] this->arr;
		}

		this->arr = new char[other.size];
		for (int i = 0; i < other.size; i++)
		{
			this->arr[i] = other.arr[i];
		}
	}

	void operator = (const string& other)
	{
		this->size = other.size();
		if (this->arr != nullptr)
		{
			delete[] this->arr;
		}

		this->arr = new char[other.size() + 1];
		for (int i = 0; i < other.size(); i++)
		{
			this->arr[i] = other[i];
		}
	}

	char& operator[](int index)
	{
		return arr[index];
	}

	String operator +(const String& other)
	{
		String temp;

		temp.size = other.size + size;
		if (temp.arr != nullptr)
		{
			delete[] temp.arr;
		}

		temp.arr = new char[size + other.size];

		for (int i = 0; i < size; i++)
			temp.arr[i] = arr[i];

		for (int i = 0; i < other.size; i++)
			temp.arr[size + i] = other.arr[i];

		return temp;
	}

	void operator +=(const String& other)
	{
		String temp;

		temp.size = size;
		if (temp.arr != nullptr)
		{
			delete[] temp.arr;
		}
		temp.arr = new char[size];
		for (int i = 0; i < temp.size; i++)
			temp.arr[i] = arr[i];

		size = size + other.size;
		delete[] arr;
		arr = new char[size];

		for (int i = 0; i < temp.size; i++)
			arr[i] = temp.arr[i];

		for (int i = 0; i < other.size; i++)
			arr[temp.size + i] = other.arr[i];
	}

	bool operator ==(const String& other)
	{
		cout << "Size: " << size << endl;
		cout << "other.Size: " << other.size << endl;
		if (size == other.size)
			return true;
		else
			return false;
	}

	bool operator ==(int number)
	{
		cout << "Size: " << size << endl;
		cout << "number: " << number << endl;
		if (size == number)
			return true;
		else 
			return false;
	}
};

// Перегрузка ввод/вывод

ostream& operator << (ostream& cout, String& other)	
{
	for (int i = 0; i < other.size; i++)
	{
		cout << other.arr[i];
	}
	return cout;
}

istream& operator >> (istream& cin, String& other)
{
	const unsigned int MAX = 100;
	char test_arr[MAX];

	cin.ignore();
	cin.getline(test_arr, MAX);
	other.get_value(test_arr);

	return cin;
}

// Функции


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

void String::dinamic_cleaner()
{
	delete[] arr;
}

unsigned int String::return_size() const
{
	return size;
}

void String::show() const
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i);
	}
	cout << endl;
}

void cin_checker(int& var)
{
	cin >> var;

	if (cin.fail())
	{
		cin.clear();
		cout << "Wrong value typed...\n";
		exit(1);
	}
}

int main()
{
	String str1, str2, str3, str4, helper;
	string str_test;

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
		cout << "1 - Input and Output\n2 - to equate objects\n3 - to equate string to an object\n4 - get index of a sentence\n5 - sum sentences\n6 - compare two sentences\n";
		int choice;
		cin_checker(choice);

		if (choice == 1)
		{
			int choice_temp, choice_input;
			cout << "\nWhich sentence would you like to print out(1 or 2)?: ";
			cin_checker(choice_temp);

			if (choice_temp == 1)
				cout << str1;
			else if (choice_temp == 2)
				cout << str2;
			else
			{
				cout << "\nSuch sentance doesn't exist..\n";
				continue;
			}

			cout << "\nDo you want to input a sentance? If so, type in a number of a sentance(1 or 2) to replace(to exit - type '0'): ";
			cin_checker(choice_input);
			
			if (choice_input == 1)
				cin >> str1;
			else if (choice_input == 2)
				cin >> str2;
			else if (choice_input == 0)
				continue;
			else
			{
				cout << "\Such sentance doesn't exist..\n";
				continue;
			}
		}
		else if (choice == 2)
		{
			int choice_opr;
			cout << "Equte sentence 2 to 1, type 1..\nEqute sentence 1 to 2, type 2..:";
			cin_checker(choice_opr);

			if (choice_opr == 1)
			{
				cout << "\nSentence #1: "; str1.show();
				cout << "Sentence #2: "; str2.show();

				str1 = str2;

				cout << "\nSentence #1: "; str1.show();
				cout << "Sentence #2: "; str2.show();
			}
			else if (choice_opr == 2)
			{
				cout << "\nSentence #1: "; str1.show();
				cout << "Sentence #2: "; str2.show();

				str2 = str1;

				cout << "\nSentence #1: "; str1.show();
				cout << "Sentence #2: "; str2.show();
			}
			else
			{
				cout << "\Wrong value typed..\n";
				continue;
			}
		}
		else if (choice == 3)
		{
			int str_choice;

			cout << "Type in a string: ";
			cin.ignore();
			getline(cin, str_test);
			cout << "to which string would you like to equate the string(1 or 2): ";
			cin_checker(str_choice);

			if (str_choice == 1)
			{
				cout << "\nSentence #1: "; str1.show();
				cout << "Sentence #2: "; str2.show();

				str1 = str_test;

				cout << "\nSentence #1: "; str1.show();
				cout << "Sentence #2: "; str2.show();
			}
			else if (str_choice == 2)
			{
				cout << "\nSentence #1: "; str1.show();
				cout << "Sentence #2: "; str2.show();

				str2 = str_test;

				cout << "\nSentence #1: "; str1.show();
				cout << "Sentence #2: "; str2.show();
			}
			else
			{
				cout << "\You typed a non-existing sentence..\n";
				continue;
			}
		}
		else if (choice == 4)
		{
			int indx, choice2;
			cout << "Type in index which you want to get..: ";
			cin_checker(indx);
			cout << "Type in sentence which value you'd like to get..: ";
			cin_checker(choice2);

			if (choice2 == 1)
			{
				if (indx >= 0 and indx < str1.return_size())
					cout << str1[indx] << endl;
				else
					cout << "Such index does not exist...\n";
			}
			else if (choice2 == 2)
			{
				if (indx >= 0 and indx < str2.return_size())
					cout << str2[indx] << endl;
				else
					cout << "Such index does not exist...\n";
			}
			else
			{
				cout << "\nYou typed a non existing sentence..\n";
				continue;
			}
		}
		else if (choice == 5)
		{
			cout << "Sentece1 + Sentence2: ";
			str4 = str1 + str2;
			str4.show();

			cout << "Choose sentence(1 or 2) to add to Sentence4(previous one): ";
			int choice_4;
			cin_checker(choice_4);
			if (choice_4 == 1)
			{
				str4 += str1;
				str4.show();

			}
			else if (choice_4 == 2)
			{
				str4 += str2;
				str4.show();
			}
			else
			{
				cout << "\nYou typed a non existing sentence..\n";
				continue;
			}
		}
		else if (choice == 6)
		{
			cout << "\nComparing two sentences with each other.. \n";
			if (str1 == str2)
				cout << "Sentances have the same size...\n";
			else
				cout << "Sentances don't have the same size..\n";

			cout << "\nComparing a santence with a number.. type in a number: ";
			int temp_numb, sent_numb;
			cin_checker(temp_numb);
			cout << "Type in the sentence's number: ";
			cin_checker(sent_numb);

			if (sent_numb == 1)
				if (str1 == temp_numb)
					cout << "The sentance has the same size as a number " << temp_numb;
				else
					cout << "The sentance doesn't have the same size as a number " << temp_numb;
			else if (sent_numb == 2)
				if (str2 == temp_numb)
					cout << "The sentance has the same size as a number " << temp_numb;
				else
					cout << "The sentance doesn't have the same size as a number " << temp_numb;
			else
			{
				cout << "\nYou typed a non existing sentence..\n";
				continue;
			}
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
	str4.dinamic_cleaner();
	helper.dinamic_cleaner();

	return 0;
}