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
	va_end(charsCopy);
}

//Принимает на вход string
MS::MyString(string stroka) {
	size_t size = stroka.size();
	size_t capacity = stroka.capacity();
	this->myStrSize = size;
	this->myStrCapacity = capacity;
	this->myString = new char[capacity];

	for (int i = 0; i < capacity; i++)
		this->myString[i] = stroka[i];
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
	string s = "hello";
	MyString a1(s);
	a1.Print();
	cout<< " " << a1.size() << " " << a1.capacity();
	return 0;
}