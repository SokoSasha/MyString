#include <iostream>
#include <string>
#include "my_string.h"
using namespace std;
#define MS MyString

//Дефотный конструктор с пустой строкой и нулевыми size и capacity
MS::MyString() {
	myStrSize = 0;
	myStrCapacity = 0;
	myString = nullptr;
}

//Принимает на вход строку
MS::MyString(const char String[]) {
	size_t size = 0;
	for (;; size++)
		if (String[size] == '\0') break;

	this->myStrSize = size;

	this->myString = new char[size + 1];

	size_t capacity = 0;
	for (;; capacity++)
		if (myString[capacity] == '\0') break;

	this->myStrCapacity = capacity;

	for (size_t i = 0; i < size; i++)
		this->myString[i] = String[i];
	this->myString[size] = '\0';
}

//Принимает на вход "список" из символов
//Почему-то плохо передаются параметры. Часто считывает лишнюю "М" в конце
MS::MyString(const char chr, ...) {
	char chrr = chr, chrcp = chr;
	va_list chars, charsCopy;
	va_start(chars, chr);
	va_copy(charsCopy, chars);

	size_t size = 0;
	while (chrr != '\0' && chrr) {
		size++;
		chrr = va_arg(chars, char);
	}
	va_end(chars);

	this->myString = new char[size + 1];

	size_t capacity = 0;
	for (;; capacity++)
		if (myString[capacity] == '\0') break;

	this->myStrCapacity = capacity;
	this->myStrSize = size;

	for (size_t i = 0; i < size; i++) {
		this->myString[i] = chrcp;
		chrcp = va_arg(charsCopy, char);
	}
	this->myString[size] = '\0';
	va_end(charsCopy);
}

//Принимает на вход string
MS::MyString(string stroka) {
	size_t size = stroka.size();
	size_t capacity = stroka.capacity();
	this->myStrSize = size;
	this->myStrCapacity = capacity;
	this->myString = new char[capacity];

	for (int i = 0; i < size; i++)
		this->myString[i] = stroka[i];
}

MS::MyString(const char String[], size_t count) {
	this->myStrSize = count;
	this->myString = new char[count + 1];

	size_t capacity = 0;
	for (;; capacity++)
		if (myString[capacity] == '\0') break;

	this->myStrCapacity = capacity;

	for (size_t i = 0; i < count; i++)
		this->myString[i] = String[i];
	this->myString[count] = '\0';
}

MS::MyString(size_t count, const char sim) {
	this->myStrSize = count;
	this->myString = new char[count + 1];

	size_t capacity = 0;
	for (;; capacity++)
		if (myString[capacity] == '\0') break;

	this->myStrCapacity = capacity;

	for (size_t i = 0; i < count; i++)
		this->myString[i] = sim;
	this->myString[count] = '\0';
}

MS::MyString(const MyString& other) {
	this->myStrSize = other.myStrSize;
	this->myStrCapacity = other.myStrCapacity;

	this->myString = new char[other.myStrSize + 1];
	size_t cp = sizeof(this->myString);
	for (size_t i = 0; i < other.myStrSize; i++)
		this->myString[i] = other.myString[i];
	this->myString[other.myStrSize] = '\0';
}

//Возвращает размер строки
size_t MS::size() {
	return this->myStrSize;
}

//Возвращает количество выделенной памяти для строки
size_t MS::capacity() {
	return this->myStrCapacity;
}

//Выводит строку
//Метод для проверки
void MS::Print() {
	for (int i = 0; i < this->myStrSize; i++)
		cout << this->myString[i];
}

int main() {
	setlocale(LC_ALL, "ru");
	MyString a1("Hello world!");
	MyString a2(a1);
	a1.Print();
	cout<< " " << a1.size() << " " << a1.capacity() << " " << a2.capacity();
	return 0;
}