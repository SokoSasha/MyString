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

//Initializer list constructor
MS::MyString(const char chr, ...) {
	char chrr = chr, chrcp = chr;
	va_list chars, charsCopy;
	va_start(chars, chr);
	va_copy(charsCopy, chars);

	size_t size = 0;
	char* nxt = (char*)(chars + 1);
	while (chrr != '\0' && nxt[0] == '\0') {
		size++;
		nxt = (char*)(chars + 1);
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

//std::string constructor
MS::MyString(string stroka) {
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
	this->myString = new char[count + 1];

	size_t capacity = 0;
	for (;; capacity++)
		if (myString[capacity] == '\0') break;

	this->myStrCapacity = capacity;

	for (size_t i = 0; i < count; i++)
		this->myString[i] = String[i];
	this->myString[count] = '\0';
}

//Init class with count of characters
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

//Copy constructor
MS::MyString(const MyString& other) {
	this->myStrSize = other.myStrSize;
	this->myStrCapacity = other.myStrCapacity;

	size_t *adr = &(this->myStrSize);
	size_t* adr2 = &(this->myStrCapacity);

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
	MyString a1({'h','e','l','l'});
	MyString a2(a1);
	a1.Print();
	cout<< " " << a1.size() << " " << a1.capacity() << " " << a2.capacity();
	return 0;
}