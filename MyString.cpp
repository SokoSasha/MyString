#include "my_string.h"

size_T charSize(const char String[]) {
	size_T size = 0;
	while (String[size++] != '\0');
	return size - 1;
}

//Default constructor
MS::MyString() {
	myStrSize = 0;
	myStrCapacity = 0;
	myString = nullptr;
}

//Char array constructor
MS::MyString(const char String[]) {
	size_T size = charSize(String);
	this->myStrSize = size;
	this->myStrCapacity = this->myStrSize + 5;
	this->myString = new char[size + 1];

	for (size_T i = 0; i < size; i++)
		this->myString[i] = String[i];
	this->myString[size] = '\0';
}

//Initializer list constructor
MS::MyString(initializer_list<char> chars) {
	this->myStrSize = chars.size();
	this->myStrCapacity = this->myStrSize + 5;
	this->myString = new char[chars.size() + 1];

	size_T i = 0;
	for (auto chr : chars)
		this->myString[i++] = chr;
	this->myString[i] = '\0';
}

//std::string constructor
MS::MyString(const string stroka) {
	size_T size = stroka.size();
	size_T capacity = stroka.capacity();
	this->myStrSize = size;
	this->myStrCapacity = capacity;
	this->myString = new char[capacity - 4];

	for (int i = 0; i < size; i++)
		this->myString[i] = stroka[i];
	this->myString[size] = '\0';
}

//Init class with count characters of “char string”
MS::MyString(const char String[], size_T count) {
	this->myStrSize = count;
	this->myStrCapacity = this->myStrSize + 5;
	this->myString = new char[count + 1];

	for (size_T i = 0; i < count; i++)
		this->myString[i] = String[i];
	this->myString[count] = '\0';
}

//Init class with count of characters
MS::MyString(size_T count, const char sim) {
	this->myStrSize = count;
	this->myStrCapacity = this->myStrSize + 5;
	this->myString = new char[count + 1];

	for (size_T i = 0; i < count; i++)
		this->myString[i] = sim;
	this->myString[count] = '\0';
}

//Copy constructor
MS::MyString(const MyString& other) {
	this->myStrSize = other.myStrSize;
	this->myStrCapacity = other.myStrCapacity;

	this->myString = new char[other.myStrSize + 1];
	size_T cp = sizeof(this->myString);
	for (size_T i = 0; i < other.myStrSize; i++)
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

	size_T i = 0;
	for (size_T k = 0; k < this->myStrSize; k++)
		temp.myString[i++] = this->myString[k];

	for (size_T k = 0; k < other.myStrSize; k++)
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
	for (size_T i = 0; i < this->myStrSize; i++)
		this->myString[i] = other.myString[i];
	this->myString[other.myStrSize] = '\0';

	return *this;
}

//Concatenate with char array
MyString MS::operator +(const char String[]) {
	MyString temp;

	size_T size = charSize(String);

	temp.myStrSize = size + this->myStrSize;
	temp.myStrCapacity = size + this->myStrCapacity;

	temp.myString = new char[temp.myStrSize + 1];

	size_T i = 0;
	for (size_T k = 0; k < this->myStrSize; k++)
		temp.myString[i++] = this->myString[k];
	for (size_T k = 0; k < size; k++)
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
	size_T i = 0;
	for (size_T k = 0; k < this->myStrSize; k++)
		temp.myString[i++] = this->myString[k];
	for (size_T k = 0; k < stroka.size(); k++)
		temp.myString[i++] = stroka[k];
	temp.myString[temp.myStrSize] = '\0';

	return temp;

}

//Assignment concatenate with char array
MyString MS::operator +=(const char String[]) {
	size_T sizePlus = charSize(String);
	size_T size = this->myStrSize + sizePlus;
	char* temp = new char[size + 1];

	size_T i;
	for (i = 0; i < this->myStrSize; i++)
		temp[i] = this->myString[i];
	for (size_T j = 0; j < sizePlus; j++)
		temp[i++] = String[j];
	temp[i] = '\0';

	delete[] this->myString;
	this->myString = temp;
	this->myStrSize = size;
	this->myStrCapacity = size + 5;

	return *this;

}

//Assignment concatenate with std::string
MyString MS::operator +=(const string stroka) {
	size_T size = this->myStrSize + stroka.size();
	size_T capacity = this->myStrSize + stroka.capacity();

	char* temp = new char[capacity - 4];

	size_T i;
	for (i = 0; i < this->myStrSize; i++)
		temp[i] = this->myString[i];
	for (size_T j = 0; j < stroka.size(); j++)
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

	size_T size = charSize(String);

	this->myString = new char[size + 1];
	for (size_T i = 0; i < size; i++)
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
	for (size_T i = 0; i < stroka.size(); i++)
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
char MS::operator [](const size_T id) {
	if (id <= this->myStrSize && id >= 0 && this->myStrSize > 0) return this->myString[id];
	else throw "Out of range";
}

//Lexicographical comparing
bool MS::operator >(MyString& other) {
	if (this->myStrSize == other.myStrSize) {
		size_T i = 0;
		while (this->myString[i] == other.myString[i++]);
		i--;
		return (this->myString[i] > other.myString[i]);
	}
	else return (this->myStrSize > other.myStrSize);
}

//Lexicographical comparing
bool MS::operator <(MyString& other) {
	if (this->myStrSize == other.myStrSize) {
		size_T i = 0;
		while (this->myString[i] == other.myString[i++]);
		i--;
		return (this->myString[i] < other.myString[i]);
	}
	else return (this->myStrSize < other.myStrSize);
}

//Lexicographical comparing
bool MS::operator >=(MyString& other) {
	if (this->myStrSize == other.myStrSize) {
		size_T i = 0;
		while (this->myString[i] == other.myString[i++]);
		i--;
		return (this->myString[i] >= other.myString[i]);
	}
	else return (this->myStrSize > other.myStrSize);
}

//Lexicographical comparing
bool MS::operator <=(MyString& other) {
	if (this->myStrSize == other.myStrSize) {
		size_T i = 0;
		while (this->myString[i] == other.myString[i++]);
		i--;
		return (this->myString[i] <= other.myString[i]);
	}
	else return (this->myStrSize > other.myStrSize);
}

//Lexicographical comparing
bool MS::operator !=(MyString& other) {
	if (this->myStrSize == other.myStrSize) {
		size_T i = 0;
		while (i < this->myStrSize)
			if (this->myString[i] != other.myString[i++]) return true;
		return false;
	}
	else return true;
}

//Lexicographical comparing
bool MS::operator ==(MyString& other) {
	if (this->myStrSize == other.myStrSize) {
		size_T i = 0;
		while (i < this->myStrSize)
			if (this->myString[i] != other.myString[i++]) return false;
		return true;
	}
	else return false;
}

//A pointer to null-terminated character array
const char* MS::c_str(void) {
	char* temp = new char[this->myStrSize + 2];
	size_T i = 0;
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
size_T MS::size() {
	return this->myStrSize;
}

//Return the number of char elements in string
size_T MS::lenght() {
	return this->myStrSize;
}

//True if string is empty
bool MS::empty() {
	return this->myStrSize == 0;
}

//Return the current amount of allocated memory for array
size_T MS::capacity() {
	return this->myStrCapacity;
}

//Reduce the capacity to size
MyString MS::shrink_to_fit() {
	if (this->myStrCapacity > this->myStrSize + 5) {
		char* temp = new char[this->myStrSize + 1];
		for (size_T i = 0; i <= this->myStrSize; i++)
			temp[i] = this->myString[i];
		delete[] this->myString;
		this->myString = temp;
		this->myStrCapacity = this->myStrSize + 5;
	}
	return *this;
}

//Remove all char element in string
void MS::clear() {
	for (size_T i = 0; i < this->myStrSize; i++)
		this->myString[i] = '\0';
	this->myStrSize = 0;
}

//
ostream& operator <<(ostream& os, MyString& MyS) {
	return os << MyS.myString;
}

//
istream& operator >>(istream& in, MyString& MyS) {
	if (!in) MyS = MyString();
	else {
		string str;
		in >> str;
		MyS = str;
		MyS.shrink_to_fit();
	}
	return in;
}

//Insert count of char in index position
MyString MS::insert(const size_T id, size_T count, char chr) {
	if (id > this->myStrSize + 1)
		throw "Out of range";

	char* temp = new char[this->myStrSize + count + 1];
	for (size_T i = 0; i < id; i++)
		temp[i] = this->myString[i];
	for (size_T i = id; i < id + count; i++)
		temp[i] = chr;
	for (size_T i = id; i <= this->myStrSize; i++)
		temp[i + count] = this->myString[i];

	delete[] this->myString;
	this->myString = temp;
	this->myStrSize = this->myStrSize + count;
	this->myStrCapacity = this->myStrSize + 5;
	return *this;
}

//Insert null-terminated char string at index position
MyString MS::insert(const size_T id, const char String[]) {
	if (id > this->myStrSize)
		throw "Out of range";

	size_T size = charSize(String);
	char* temp = new char[this->myStrSize + size + 1];

	size_T i = 0;
	for (; i < id; i++)
		temp[i] = this->myString[i];
	for (size_T j = 0; i < size; i++, j++)
		temp[i] = String[j];
	for (size_T j = id; j <= this->myStrSize; i++, j++)
		temp[i] = this->myString[j];

	delete[] this->myString;
	this->myString = temp;
	this->myStrSize = this->myStrSize + size;
	this->myStrCapacity = this->myStrSize + 5;

	return *this;
}

//Insert count of null-terminated char string at index position
MyString MS::insert(const size_T id, const char String[], size_T count) {
	if (id > this->myStrSize)
		throw "Out of range";

	size_T size = charSize(String);
	if (count > size)
		throw "Out of range";

	size_T i = 0;
	char* temp = new char[this->myStrSize + size * count + 1];
	for (; i < id; i++)
		temp[i] = this->myString[i];
	for (size_T k = 0; k < count && k < size; i++, k++)
		temp[i] = String[k];
	for (size_T j = id; j <= this->myStrSize; i++, j++)
		temp[i] = this->myString[j];

	delete[] this->myString;
	this->myString = temp;
	this->myStrSize = this->myStrSize + count;
	this->myStrCapacity = this->myStrSize + 5;

	return *this;
}

//Insert std::string at index position
MyString MS::insert(const size_T id, string stroka) {
	if (id > this->myStrSize)
		throw "Out of range";

	size_T size = stroka.size();

	size_T i = 0;
	char* temp = new char[this->myStrSize + size + 1];
	for (; i < id; i++)
		temp[i] = this->myString[i];
	for (size_T j = 0; j < size; i++, j++)
		temp[i] = stroka[j];
	for (size_T j = id; j <= this->myStrSize; i++, j++)
		temp[i] = this->myString[j];

	delete[] this->myString;
	this->myString = temp;
	this->myStrSize = this->myStrSize + size;
	this->myStrCapacity = this->myStrSize + 5;

	return *this;
}

//Insert count of std::string at index position
MyString MS::insert(const size_T id, string stroka, size_T count) {
	if (id > this->myStrSize)
		throw "Out of range";

	size_T size = stroka.size();
	if (count > size)
		throw "Out of range";

	size_T i = 0;
	char* temp = new char[this->myStrSize + size * count + 1];
	for (; i < id; i++)
		temp[i] = this->myString[i];
	for (size_T k = 0; k < count && k < size; i++, k++)
		temp[i] = stroka[k];
	for (size_T j = id; j <= this->myStrSize; i++, j++)
		temp[i] = this->myString[j];

	delete[] this->myString;
	this->myString = temp;
	this->myStrSize = this->myStrSize + count;
	this->myStrCapacity = this->myStrSize + 5;

	return *this;
}

//Erase count of char at index position
MyString MS::erase(const size_T id, size_T count) {
	if (id > this->myStrSize)
		throw "Out of range";

	count = min(count, this->myStrSize - id);
	
	char* temp = new char[this->myStrSize - count + 1];
	size_T i = 0;
	for (; i < id; i++)
		temp[i] = this->myString[i];
	for (size_T k = id + count; k <= this->myStrSize; k++, i++)
		temp[i] = this->myString[k];

	this->myStrSize = this->myStrSize - count;
	this->myStrCapacity = this->myStrSize + 5;
	delete[] this->myString;
	this->myString = temp;

	return *this;
}

//Append count of char
MyString MS::append(size_T count, const char chr) {
	size_T newSize = this->myStrSize + count;
	char* temp = new char[newSize + 1];
	for (size_T i = 0; i < this->myStrSize; i++)
		temp[i] = this->myString[i];
	for (size_T i = this->myStrSize; i < newSize; i++)
		temp[i] = chr;
	temp[newSize] = '\0';

	delete[] this->myString;
	this->myString = temp;
	this->myStrSize = newSize;
	this->myStrCapacity = newSize + 5;

	return *this;
}

//Append null-terminated char string
MyString MS::append(const char String[]) {
	size_T newSize = charSize(String) + this->myStrSize;
	char* temp = new char[newSize + 1];

	for (size_T i = 0; i < this->myStrSize; i++)
		temp[i] = this->myString[i];
	for (size_T i = this->myStrSize, k = 0; i <= newSize; i++, k++)
		temp[i] = String[k];

	delete[] this->myString;
	this->myString = temp;
	this->myStrSize = newSize;
	this->myStrCapacity = newSize + 5;

	return *this;
}

//Append a count of null-terminated char string by index position
MyString MS::append(const char String[], const size_T id, size_T count) {
	if (id > this->myStrSize)
		throw "Out of range";

	size_T chrSize = charSize(String);
	size_T newSize = this->myStrSize + min(count, chrSize);

	char* temp = new char[newSize + 1];
	size_T i = 0;
	for (; i < id; i++)
		temp[i] = this->myString[i];
	for (size_T k = 0; k < chrSize; i++, k++)
		temp[i] = String[k];
	for (size_T j = id; j <= this->myStrSize; i++, j++)
		temp[i] = this->myString[j];

	delete[] this->myString;
	this->myString = temp;
	this->myStrSize = newSize;
	this->myStrCapacity = this->myStrSize + 5;

	return *this;
}

//Append std:: string
MyString MS::append(const string stroka) {
	size_T newSize = stroka.size() + this->myStrSize;
	char* temp = new char[this->myStrSize + stroka.capacity() - 4];

	for (size_T i = 0; i < this->myStrSize; i++)
		temp[i] = this->myString[i];
	for (size_T i = this->myStrSize, k = 0; i <= newSize; i++, k++)
		temp[i] = stroka[k];

	delete[] this->myString;
	this->myString = temp;
	this->myStrCapacity = this->myStrSize + stroka.capacity();
	this->myStrSize = newSize;

	return *this;
}

//Append a count of std:: string by index position
MyString MS::append(const string stroka, const size_T id, size_T count) {
	if (id > this->myStrSize)
		throw "Out of range";

	size_T chrSize = stroka.size();
	size_T newSize = this->myStrSize + min(count, chrSize);

	char* temp = new char[this->myStrSize + stroka.capacity() - 4];
	size_T i = 0;
	for (; i < id; i++)
		temp[i] = this->myString[i];
	for (size_T k = 0; k < chrSize; i++, k++)
		temp[i] = stroka[k];
	for (size_T j = id; j <= this->myStrSize; i++, j++)
		temp[i] = this->myString[j];

	delete[] this->myString;
	this->myString = temp;
	this->myStrCapacity = this->myStrSize + stroka.capacity();
	this->myStrSize = newSize;

	return *this;
}
//Replace a count of char at index by “string”
MyString MS::replace(const size_T id, size_T count, const char String[]) {
	size_T chrSize = charSize(String);
	size_T newSize = this->myStrSize + (chrSize - count);

	char* temp = new char[newSize + 1];
	size_T i = 0;
	for (; i < id; i++)
		temp[i] = this->myString[i];
	for (size_T j = 0; j < chrSize; j++, i++)
		temp[i] = String[j];
	for (size_T j = id + count; j <= this->myStrSize; j++, i++)
		temp[i] = this->myString[j];

	delete[] this->myString;
	this->myString = temp;
	this->myStrSize = newSize;
	this->myStrCapacity = newSize + 5;

	return *this;
}

//Replace a count of char at index by std::string
MyString MS::replace(const size_T id, size_T count, const string stroka) {

	size_T chrSize = stroka.size();
	count = min(count, this->myStrSize - id);
	size_T newSize = this->myStrSize + (chrSize - count);
	size_T capacity = this->myStrSize - count + stroka.capacity();

	char* temp = new char[capacity - 4];
	size_T i = 0;
	for (; i < id; i++)
		temp[i] = this->myString[i];
	for (size_T j = 0; j < chrSize; j++, i++)
		temp[i] = stroka[j];
	for (size_T j = id + count; j <= this->myStrSize; j++, i++)
		temp[i] = this->myString[j];

	delete[] this->myString;
	this->myString = temp;
	this->myStrSize = newSize;
	this->myStrCapacity = capacity;

	return *this;
}

//Return a substring starts with index position
char* MS::substr(const size_T id) {
	if (id > this->myStrSize)
		throw "Out of range";

	return this->myString + id;
}

//Return a count of substring’s char starts with index position
char* MS::substr(const size_T id, size_T count) {
	if (id > this->myStrSize)
		throw "Out of range";

	count = min(count, this->myStrSize);

	char* temp = new char[count + 1];
	for (size_T i = 0, j = id; i < count; i++, j++)
		temp[i] = this->myString[j];
	temp[count] = '\0';

	return temp;
}

//If founded return the index of "char array" substring
size_T MS::find(const char String[]) {
	size_T size = charSize(String);
	size_T i = 0;
	for (; i <= this->myStrSize - size; i++)
		for (size_T j = 0; j < size; j++) {
			if (this->myString[i + j] != String[j]) {

				i += j;
				break;
			}
			if (j == size - 1 && this->myString[i + j] == String[j]) return i;
		}
	return -1;
}

//If founded return the index of "char array" substring. Search starts from index position
size_T MS::find(const char String[], const size_T id) {
	size_T size = charSize(String);
	size_T i = id;
	for (; i <= this->myStrSize - size; i++)
		for (size_T j = 0; j < size; j++) {
			if (this->myString[i + j] != String[j]) {

				i += j;
				break;
			}
			if (j == size - 1 && this->myString[i + j] == String[j]) return i;
		}
	return -1;
}

//If founded return the index of std::string substring
size_T MS::find(const string stroka) {
	size_T size = stroka.size();
	size_T i = 0;
	for (; i <= this->myStrSize - size; i++)
		for (size_T j = 0; j < size; j++) {
			if (this->myString[i + j] != stroka[j]) {

				i += j;
				break;
			}
			if (j == size - 1 && this->myString[i + j] == stroka[j]) return i;
		}
	return -1;
}

//If founded return the index of std::string substring. Search starts from index position
size_T MS::find(const string stroka, const size_T id) {
	size_T size = stroka.size();
	size_T i = id;
	for (; i <= this->myStrSize - size; i++)
		for (size_T j = 0; j < size; j++) {
			if (this->myString[i + j] != stroka[j]) {

				i += j;
				break;
			}
			if (j == size - 1 && this->myString[i + j] == stroka[j]) return i;
		}
	return -1;
}

int main() {
	setlocale(LC_ALL, "ru");
	MyString a = "hello amazing world amazing";
	int i;
	std::string s = "amazing";
	i = a.find(s, 21);
	std::cout << i << std::endl;

	return 0;
 }