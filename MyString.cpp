#include "my_string.h"

//Default constructor
MS::MyString() {
	myStrSize = 0;
	myStrCapacity = 0;
	myString = nullptr;
}

//Char array constructor
MS::MyString(const char String[]) {
	size_t size = 0;
	while (String[size++] != '\0');
	size--;

	this->myStrSize = size;
	this->myStrCapacity = this->myStrSize + 4;
	this->myString = new char[size + 1];

	for (size_t i = 0; i < size; i++)
		this->myString[i] = String[i];
	this->myString[size] = '\0';
}

//Initializer list constructor
MS::MyString(initializer_list<char> chars) {
	this->myStrSize = chars.size();
	this->myStrCapacity = this->myStrSize + 4;
	this->myString = new char[chars.size() + 1];
	
	size_t i = 0;
	for (auto chr : chars)
		this->myString[i++] = chr;
	this->myString[i] = '\0';
}

//std::string constructor
MS::MyString(const string stroka) {
	size_t size = stroka.size();
	size_t capacity = stroka.capacity();
	this->myStrSize = size;
	this->myStrCapacity = capacity;
	this->myString = new char[capacity];

	for (int i = 0; i < size; i++)
		this->myString[i] = stroka[i];
}

//Init class with count characters of Уchar stringФ
MS::MyString(const char String[], size_t count) {
	this->myStrSize = count;
	this->myStrCapacity = this->myStrSize + 4;
	this->myString = new char[count + 1];

	size_t i = 0;
	for (; i < count; i++)
		this->myString[i] = String[i];
	this->myString [i] = '\0';
}

//Init class with count of characters
MS::MyString(size_t count, const char sim) {
	this->myStrSize = count;
	this->myStrCapacity = this->myStrSize + 4;
	this->myString = new char[count + 1];

	for (size_t i = 0; i < count; i++)
		this->myString[i] = sim;
	this->myString[count] = '\0';
}

//Copy constructor
MS::MyString(const MyString& other) {
	this->myStrSize = other.myStrSize;
	this->myStrCapacity = other.myStrCapacity;

	this->myString = new char[other.myStrSize + 1];
	size_t cp = sizeof(this->myString);
	for (size_t i = 0; i < other.myStrSize; i++)
		this->myString[i] = other.myString[i];
	this->myString[other.myStrSize] = '\0';
}

//Destructor
MS::~MyString(void) {
	delete[] this->myString;
}

//Concatenate with Mystring
MyString MS::operator +(const MyString& other) {
	MyString temp;
	temp.myStrSize = this->myStrSize + other.myStrSize;
	temp.myStrCapacity = temp.myStrSize + 4;
	temp.myString = new char[temp.myStrSize + 1];

	size_t i = 0;
	for (size_t k = 0; k < this->myStrSize; k++)
		temp.myString[i++] = this->myString[k];

	for (size_t k = 0; k < other.myStrSize; k++)
		temp.myString[i++] = other.myString[k];

	temp.myString[i] = '\0';

	return temp;
}

//MyString assignment
MyString MS::operator =(const MyString& other) {
	this->myStrSize = other.myStrSize;
	this->myStrCapacity = other.myStrCapacity;
	this->myString = new char[this->myStrSize + 1];
	for (size_t i = 0; i < this->myStrSize; i++)
		this->myString[i] = other.myString[i];
	this->myString[other.myStrSize] = '\0';

	return *this;
}

//Concatenate with char array
MyString MS::operator +(const char String[]) {
	MyString temp;

	size_t size = 0;
	while (String[size++] != '\0');
	size--;

	temp.myStrSize = size + this->myStrSize;
	temp.myStrCapacity = size + this->myStrCapacity;

	temp.myString = new char[temp.myStrSize + 1];

	size_t i = 0;
	for (size_t k = 0; k < this->myStrSize; k++)
		temp.myString[i++] = this->myString[k];
	for (size_t k = 0; k < size; k++)
		temp.myString[i++] = String[k];
	temp.myString[temp.myStrSize] = '\0';

	return temp;
}

//Concatenate with std::string
MyString MS::operator +(const string stroka) {
	MyString temp;

	temp.myStrSize = this->myStrSize + stroka.size();
	temp.myStrCapacity = this->myStrSize + stroka.capacity();

	temp.myString = new char[temp.myStrCapacity - 4];
	size_t i = 0;
	for (size_t k = 0; k < this->myStrSize; k++)
		temp.myString[i++] = this->myString[k];
	for (size_t k = 0; k < stroka.size(); k++)
		temp.myString[i++] = stroka[k];
	temp.myString[temp.myStrSize] = '\0';

	return temp;

}

//MyString MS::operator +=(const char String[]) {
//	size_t i = this->myStrSize;
//}

//Return the number of char elements in string
size_t MS::size() {
	return this->myStrSize;
}

//Return the current amount of allocated memory for array
size_t MS::capacity() {
	return this->myStrCapacity;
}

//¬ыводит строку
//ћетод дл€ проверки
void MS::Print() {
	for (int i = 0; i < this->myStrSize; i++)
		cout << this->myString[i];
}

int main() {
	setlocale(LC_ALL, "ru");
	MyString a2("world"), a3;
	MyString a1("hel");
	string s = "lo";
	a3 = a1 + s;
	a3.Print();
	cout<< " " << a3.size() << " " << a3.capacity();
	return 0;
}