#pragma once
#ifndef _MYSTRING_H_

#define _MYSTRING_H_
#include <iostream>
#include <string>
#include <cstdarg>
#include <initializer_list>
using namespace std;

#define MS MyString

typedef long long size_T;

class MyString {
public:
	MyString();
	MyString(const char String[]);
	MyString(initializer_list<char> chars);
	MyString(const string stroka);
	MyString(const char String[], size_T count);
	MyString(size_T count, const char sim);
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

	char operator [](const size_T id);

	bool operator >(MyString& other);
	bool operator <(MyString& other);
	bool operator >=(MyString& other);
	bool operator <=(MyString& other);
	bool operator !=(MyString& other);
	bool operator ==(MyString& other);

	const char* c_str(void);
	const char* data(void);

	size_T size(void);
	size_T lenght(void);
	bool empty(void);
	size_T capacity(void);

	MyString shrink_to_fit(void);

	void clear(void);

	friend ostream& operator <<(ostream& os, MyString& MyS);
	friend istream& operator >>(istream& in, MyString& MyS);

	MyString insert(const size_T id, size_T count, char chr);
	MyString insert(const size_T id, const char String[]);
	MyString insert(const size_T id, const char String[], size_T count);
	MyString insert(const size_T id, string stroka);
	MyString insert(const size_T id, string stroka, size_T count);

	MyString erase(const size_T id, size_T count);

	MyString append(size_T count, const char chr);
	MyString append(const char String[]);
	MyString append(const char String[], const size_T id, size_T count);
	MyString append(const string stroka);
	MyString append(const string stroka, const size_T id, size_T count);

	MyString replace(const size_T id, size_T count, const char String[]);
	MyString replace(const size_T id, size_T count, const string stroka);

	char* substr(const size_T id);
	char* substr(const size_T id, size_T count);

	size_T find(const char String[]);
	size_T find(const char String[], const size_T id);
	size_T find(const string stroka);
	size_T find(const string stroka, const size_T id);

private:
	size_T myStrSize, myStrCapacity;
	char* myString;
};

size_T charSize(const char String[]);
char* strtoch(char* chString, string stroka);
ostream& operator <<(ostream& os, MyString& MyS);
istream& operator >>(istream& in, MyString& MyS);

#endif // _MYSTRING_H_