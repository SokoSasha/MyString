#pragma once
#ifndef _MYSTRING_H_

#define _MYSTRING_H_
#include <iostream>
#include <string>
#include <cstdarg>
#include <initializer_list>
using namespace std;

#define MS MyString

class MyString {
public:
	MyString();
	MyString(const char String[]);
	MyString(initializer_list<char> chars);
	MyString(const string stroka);
	MyString(const char String[], size_t count);
	MyString(size_t count, const char sim);
	MyString(const MyString& other);
	~MyString(void);

	MyString operator =(const MyString& other);
	MyString operator =(const char String[]);
	MyString operator =(const string stroka);
	MyString operator =(const char chr);

	MyString operator +(const MyString &other);
	MyString operator +(const char String[]);
	MyString operator +(const string stroka);

	MyString operator +=(const char String[]);
	MyString operator +=(const string stroka);

	char operator [](int id);

	bool operator >(MyString& other);
	bool operator <(MyString& other);
	bool operator >=(MyString& other);
	bool operator <=(MyString& other);
	bool operator !=(MyString& other);
	bool operator ==(MyString& other);

	const char* c_str(void);
	const char* data(void);

	size_t size(void);
	size_t lenght(void);
	bool empty(void);
	size_t capacity(void);

	MyString shrink_to_fit(void);

	void Print();
private:
	size_t myStrSize, myStrCapacity;
	char* myString;
};

#endif // _MYSTRING_H_