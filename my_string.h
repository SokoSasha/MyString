#pragma once
#ifndef _MYSTRING_H_

#define _MYSTRING_H_
#include <iostream>
#include <cstdarg>
using namespace std;

class MyString {
public:
	MyString();
	MyString(const char string[]);
	MyString(const char chr, ...);
	int size();
	int capacity();
	void Print();
private:
	int myStrSize, myStrCapacity;
	char* myString;
};

#endif // _COMMON_H_