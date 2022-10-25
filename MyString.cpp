#include <iostream>
#include "my_string.h"
using namespace std;
#define MS MyString

//�������� ����������� � ������ ������� � �������� size � capacity
MS::MyString() {
	myStrSize = 0;
	myStrCapacity = 0;
	myString = nullptr;
}

//��������� �� ���� ������
MS::MyString(const char string[]) {
	int size = 0;
	for (;; size++)
		if (string[size] == '\0') break;

	this->myStrSize = size;
	this->myStrCapacity = size + 1;

	this->myString = new char[size + 1];

	for (int i = 0; i < size; i++)
		this->myString[i] = string[i];
	this->myString[size] = '\0';
}

//��������� �� ���� "������" �� ��������
//������-�� ����� ���������� ���������. ����� ��������� ������ "�" � �����
MS::MyString(const char chr, ...) {
	char chrr = chr, chrcp = chr;
	va_list chars, charsCopy;
	va_start(chars, chr);
	va_copy(charsCopy, chars);
	int size = 0;
	while (chrr != '\0' && chrr) {
		size++;
		chrr = va_arg(chars, char);
	}
	va_end(chars);
	this->myString = new char[size + 1];
	this->myStrSize = size;
	this->myStrCapacity = size + 1;
	for (int i = 0; i < size; i++) {
		this->myString[i] = chrcp;
		chrcp = va_arg(charsCopy, char);
	}

	va_end(charsCopy);
}

//���������� ������ ������
int MS::size() {
	return this->myStrSize;
}

//���������� ���������� ���������� ������ ��� ������
int MS::capacity() {
	return this->myStrCapacity;
}

//������� ������
//����� ��� ��������
void MS::Print() {
	for (int i = 0; i < this->myStrSize; i++)
		cout << this->myString[i];
}

int main() {
	setlocale(LC_ALL, "ru");
	MyString a1({ 'h', 'e', 'l', 'l', 'o'});
	a1.Print();
	cout<< " " << a1.size() << " " << a1.capacity();
	return 0;
}