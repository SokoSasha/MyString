#pragma once
#ifndef _MYSTRING_H_

#define _MYSTRING_H_
#include <iostream>
#include <cstdarg>
using namespace std;

class MyString {
public:
	MyString();
	MyString(const char String[]);
	MyString(const char chr, ...);
	MyString(string stroka);
	MyString(const char String[], size_t count);
	MyString(size_t count, const char sim);
	MyString(const MyString& other);
	size_t size();
	size_t capacity();
	void Print();
private:
	size_t myStrSize, myStrCapacity;
	char* myString;
};

#endif // _COMMON_H_