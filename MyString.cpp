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
	this->myStrCapacity = this->myStrSize + 5;
	this->myString = new char[size + 1];

	for (size_t i = 0; i < size; i++)
		this->myString[i] = String[i];
	this->myString[size] = '\0';
}

//Initializer list constructor
MS::MyString(initializer_list<char> chars) {
	this->myStrSize = chars.size();
	this->myStrCapacity = this->myStrSize + 5;
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
	this->myStrCapacity = this->myStrSize + 5;
	this->myString = new char[count + 1];

	size_t i = 0;
	for (; i < count; i++)
		this->myString[i] = String[i];
	this->myString [i] = '\0';
}

//Init class with count of characters
MS::MyString(size_t count, const char sim) {
	this->myStrSize = count;
	this->myStrCapacity = this->myStrSize + 5;
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
	temp.myStrCapacity = temp.myStrSize + 5;
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
	delete[] this->myString;

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

//Assignment concatenate with char array
MyString MS::operator +=(const char String[]) {
	size_t sizePlus = 0;
	while (String[sizePlus++] != '\0');
	sizePlus--;
	size_t size = this->myStrSize + sizePlus;
	char* temp = new char[size + 1];

	size_t i;
	for (i = 0; i < this->myStrSize; i++)
		temp[i] = this->myString[i];
	for (size_t j = 0; j < sizePlus; j++)
		temp[i++] = String[j];
	temp[i] = '\0';

	delete[] this->myString;
	this->myString = temp;
	this->myStrSize = size;
	this->myStrCapacity = size +5;

	return *this;
	
}

//Assignment concatenate with std::string
MyString MS::operator +=(const string stroka) {
	size_t size = this->myStrSize + stroka.size();
	size_t capacity = this->myStrSize + stroka.capacity();

	char* temp = new char[capacity - 4];

	size_t i;
	for (i = 0; i < this->myStrSize; i++)
		temp[i] = this->myString[i];
	for (size_t j = 0; j < stroka.size(); j++)
		temp[i++] = stroka[j];
	temp[i] = '\0';

	delete[] this->myString;
	this->myString = temp;
	this->myStrSize = size;
	this->myStrCapacity = capacity;

	return *this;
}

//Char string assignment
MyString MS::operator =(const char String[]) {
	delete[] this->myString;

	size_t size = 0;
	while (String[size++] != '\0');
	size--;

	this->myString = new char[size + 1];
	for (size_t i = 0; i < size; i++)
		this->myString[i] = String[i];
	this->myString[size] = '\0';

	this->myStrSize = size;
	this->myStrCapacity = size + 5;

	return *this;
}

//std::string assignment
MyString MS::operator =(const string stroka) {
	delete[] this->myString;

	this->myString = new char[stroka.capacity() - 4];
	for (size_t i = 0; i < stroka.size(); i++)
		this->myString[i] = stroka[i];
	this->myString[stroka.size()] = '\0';

	this->myStrSize = stroka.size();
	this->myStrCapacity = stroka.capacity();

	return *this;
}

//Char assignment
MyString MS::operator =(const char chr) {
	delete[] this->myString;
	this->myString = new char[2];
	this->myString[0] = chr;
	this->myString[1] = '\0';

	this->myStrSize = 1;
	this->myStrCapacity = 6;

	return *this;
}

//Index operator
char MS::operator [](int id) {
	if (id <= this->myStrSize && id >=0) return this->myString[id];
	else {
		cout << "Out of array" << endl;
		return '\0';
	}
}

//Lexicographical comparing
bool MS::operator >(MyString& other) {
	if (this->myStrSize == other.myStrSize) {
		size_t i = 0;
		while (this->myString[i] == other.myString[i++]);
		i--;
		return (this->myString[i] > other.myString[i]);
	}
	else return (this->myStrSize > other.myStrSize);
}

//Lexicographical comparing
bool MS::operator <(MyString& other) {
	if (this->myStrSize == other.myStrSize) {
		size_t i = 0;
		while (this->myString[i] == other.myString[i++]);
		i--;
		return (this->myString[i] < other.myString[i]);
	}
	else return (this->myStrSize < other.myStrSize);
}

//Lexicographical comparing
bool MS::operator >=(MyString& other) {
	if (this->myStrSize == other.myStrSize) {
		size_t i = 0;
		while (this->myString[i] == other.myString[i++]);
		i--;
		return (this->myString[i] >= other.myString[i]);
	}
	else return (this->myStrSize > other.myStrSize);
}

//Lexicographical comparing
bool MS::operator <=(MyString& other) {
	if (this->myStrSize == other.myStrSize) {
		size_t i = 0;
		while (this->myString[i] == other.myString[i++]);
		i--;
		return (this->myString[i] <= other.myString[i]);
	}
	else return (this->myStrSize > other.myStrSize);
}

//Lexicographical comparing
bool MS::operator !=(MyString& other) {
	if (this->myStrSize == other.myStrSize) {
		size_t i = 0;
		while (i < this->myStrSize)
			if (this->myString[i] != other.myString[i++]) return true;
		return false;
	}
	else return true;
}

//Lexicographical comparing
bool MS::operator ==(MyString& other) {
	if (this->myStrSize == other.myStrSize) {
		size_t i = 0;
		while (i < this->myStrSize)
			if (this->myString[i] != other.myString[i++]) return false;
		return true;
	}
	else return false;
}

//A pointer to null-terminated character array
const char* MS::c_str(void) {
	char* temp = new char[this->myStrSize + 2];
	size_t i = 0;
	while (i <= this->myStrSize) temp[i] = this->myString[i++];
	if (temp[this->myStrSize] != '\0')
		temp[this->myStrSize + 1] = '\0';
	return temp;
}

//A pointer to array data that not required to be null-terminated
const char* MS::data(void) {
	return this->myString;
}

//Return the number of char elements in string
size_t MS::size() {
	return this->myStrSize;
}

//Return the number of char elements in string
size_t MS::lenght() {
	return this->myStrSize;
}

//True if string is empty
bool MS::empty() {
	return this->myStrSize == 0;
}

//Return the current amount of allocated memory for array
size_t MS::capacity() {
	return this->myStrCapacity;
}

//Reduce the capacity to size
MyString MS::shrink_to_fit() {
	if (this->myStrSize + 1 != this->myStrCapacity) {
		char* temp = new char[this->myStrSize];
	}
	return *this;
}

//¬ыводит строку
//ћетод дл€ проверки
void MS::Print() {
	for (int i = 0; i < this->myStrSize; i++)
		cout << this->myString[i];
}

int main() {
	setlocale(LC_ALL, "ru");
	MyString a1("Hello world!");
	char* chr = new char;
	std::cout << a1[12] << std::endl;
	return 0;
}