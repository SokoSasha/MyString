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
	MyString(string stroka);
	MyString(const char String[], size_t count);
	MyString(size_t count, const char sim);
	MyString(const MyString& other);
	~MyString(void);

	MyString operator +(const MyString &other);
	MyString operator =(const MyString& other);

	size_t size();
	size_t capacity();
	void Print();
private:
	size_t myStrSize, myStrCapacity;
	char* myString;
};

#endif // _MYSTRING_H_