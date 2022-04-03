#pragma once
#include <iostream>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class _String
{
private:
	unsigned int size = 1;
	char* arr = new char[size];
public:
	_String()
	{
		*arr = '\0';
	}
	void get_value(char test_str[]);
	void show() const;
	unsigned int return_size() const;
	void dinamic_cleaner();

	friend ostream& operator << (ostream& cout, _String& other);
	friend istream& operator >> (istream& cin, _String& other);

	void operator = (const _String& other);
	void operator = (const string& other);
	char& operator[](int index);
	_String operator +(const _String& other);
	void operator +=(const _String& other);
	bool operator ==(const _String& other);
	bool operator ==(int number);

};
