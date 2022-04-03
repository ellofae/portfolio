#include <iostream>
#include "_String.h"
#include "Header.h"
using namespace std;

int main()
{
	_String str1, str2, str3, str4, helper;
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