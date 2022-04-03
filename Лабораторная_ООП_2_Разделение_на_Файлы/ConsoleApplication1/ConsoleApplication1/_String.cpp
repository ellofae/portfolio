#include "_String.h"
using namespace std;

// Перегрузка ввод/вывод

ostream& operator << (ostream& cout, _String& other)
{
	for (int i = 0; i < other.size; i++)
	{
		cout << other.arr[i];
	}
	return cout;
}

istream& operator >> (istream& cin, _String& other)
{
	const unsigned int MAX = 100;
	char test_arr[MAX];

	cin.ignore();
	cin.getline(test_arr, MAX);
	other.get_value(test_arr);

	return cin;
}

//Перегруженные операторы
void _String::operator = (const _String& other)
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

void _String::operator = (const string& other)
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

char& _String::operator[](int index)
{
	return arr[index];
}

_String _String::operator +(const _String& other)
{
	_String temp;

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

void _String::operator +=(const _String& other)
{
	_String temp;

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

bool _String::operator ==(const _String& other)
{
	cout << "Size1: " << size << endl;
	cout << "Size2: " << other.size << endl;
	if (size == other.size)
		return true;
	else
		return false;
}

bool _String::operator ==(int number)
{
	cout << "Size: " << size << endl;
	cout << "number: " << number << endl;
	if (size == number)
		return true;
	else
		return false;
}


// Функции
void _String::get_value(char test_str[])
{
	size = strlen(test_str);
	delete[] arr;
	arr = new char[size];

	for (int i = 0; i < size; i++)
	{
		*(arr + i) = *(test_str + i);
	}
}

void _String::dinamic_cleaner()
{
	delete[] arr;
}

unsigned int _String::return_size() const
{
	return size;
}

void _String::show() const
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i);
	}
	cout << endl;
}
