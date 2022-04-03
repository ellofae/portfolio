#include <iostream>
#include "Header.h"
using namespace std;

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