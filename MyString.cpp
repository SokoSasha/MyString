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

char* strtoch(char* chString, string stroka) {
	for (size_T i = 0; i <= stroka.size(); i++)
		chString[i] = stroka[i];

	return chString;
}

//Char array constructor
MS::MyString(const char String[]) {
	size_T size = charSize(String);
	this->myStrSize = size;
	this->myStrCapacity = this->myStrSize + 1;
	this->myString = new char[size + 1];

	for (size_T i = 0; i <= size; i++)
		this->myString[i] = String[i];
}

//Initializer list constructor
MS::MyString(initializer_list<char> chars) {
	this->myStrSize = chars.size();
	this->myStrCapacity = this->myStrSize;
	this->myString = new char[chars.size()];

	size_T i = 0;
	for (auto chr : chars)
		this->myString[i++] = chr;
	//this->myString[i] = '\0';
}

//std::string constructor
MS::MyString(const string stroka) {
	char* chString = new char[stroka.size() + 1];
	chString = strtoch(chString, stroka);

	*this = MyString(chString);
}

//Init class with count characters of “char string”
MS::MyString(const char String[], size_T count) {
	this->myStrSize = count;
	this->myStrCapacity = this->myStrSize + 1;
	this->myString = new char[count + 1];

	for (size_T i = 0; i < count; i++)
		this->myString[i] = String[i];
	this->myString[count] = '\0';
}

//Init class with count of characters
MS::MyString(size_T count, const char sim) {
	this->myStrSize = count;
	this->myStrCapacity = this->myStrSize + 1;
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
	temp.myStrCapacity = temp.myStrSize + 1;
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
	char* chString = new char[stroka.size() + 1];
	chString = strtoch(chString, stroka);

	return *this + chString;
}

//Assignment concatenate with char array
MyString MS::operator +=(const char String[]) {
	
	*this = *this + String;
	return *this;

}

//Assignment concatenate with std::string
MyString MS::operator +=(const string stroka) {
	*this = *this + stroka;
	return *this;
}

//Char string assignment
MyString MS::operator =(const char String[]) {

	MyString temp(String);
	*this = temp;

	return *this;
}

//std::string assignment
MyString MS::operator =(const string stroka) {
	MyString temp(stroka);
	*this = temp;

	return *this;
}

//Char assignment
MyString MS::operator =(const char chr) {
	char pChr[] = { chr, '\0' };
	MyString temp(pChr);
	*this = temp;

	return *this;
}

//Index operator
char MS::operator [](const size_T id) {
	if (id <= this->myStrSize && id >= 0 && this->myStrSize > 0)
		return this->myString[id];
	else
		throw "Out of range";
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

//Lexicographical comparing
bool MS::operator !=(MyString& other) {
	return !(*this == other);
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
	return !((*this > other) || (*this == other));
}

//Lexicographical comparing
bool MS::operator >=(MyString& other) {
	return !(*this < other);
}

//Lexicographical comparing
bool MS::operator <=(MyString& other) {
	return !(*this > other);
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
	if (this->myStrCapacity > this->myStrSize + 1) {
		char* temp = new char[this->myStrSize + 1];
		for (size_T i = 0; i <= this->myStrSize; i++)
			temp[i] = this->myString[i];
		delete[] this->myString;
		this->myString = temp;
		this->myStrCapacity = this->myStrSize + 1;
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
	for (size_T i = 0; i < MyS.myStrSize; i++)
		os << MyS.myString[i];
	return os;
}

//
istream& operator >>(istream& in, MyString& MyS) {
	if (!in) MyS = MyString();
	else {

		char* chString = new char[INT32_MAX];
		//in >> String;
		cin.getline(chString, INT32_MAX);
		MyS = chString;
		MyS.shrink_to_fit();
	}
	return in;
}

//Insert count of null-terminated char string at index position
//Main insert
MyString MS::insert(const size_T id, const char String[], size_T count) {
	if (id > this->myStrSize)
		throw "Out of range";

	size_T size = min(count, charSize(String));

	if (this->myStrCapacity > this->myStrSize + size) {
		size_T i = this->myStrSize + size - 1;
		for (; i >= id + size; i--)
			this->myString[i] = this->myString[i - size];
		for (size_T j = size - 1; i >= id; i--, j--)
			this->myString[i] = String[j];

		this->myStrSize += size;
	}
	else {
		size_T i = 0;

		char* temp = new char[this->myStrSize + size + 1];
		for (; i < id; i++)
			temp[i] = this->myString[i];
		for (size_T k = 0; k < count && k < size; i++, k++)
			temp[i] = String[k];
		for (size_T j = id; j <= this->myStrSize; i++, j++)
			temp[i] = this->myString[j];

		delete[] this->myString;
		this->myString = temp;
		this->myStrSize += size;
		this->myStrCapacity = this->myStrSize + 1;
	}

	return *this;
}

//Insert count of char in index position
MyString MS::insert(const size_T id, const size_T count, char chr) {
	if (id > this->myStrSize + 1)
		throw "Out of range";
	
	char pChr[] = { chr, '\0' };
	for (size_T i = id; i < id + count; i++) {
		this->insert(i, pChr, 1);
	}

	return *this;
}

//Insert null-terminated char string at index position
MyString MS::insert(const size_T id, const char String[]) {
	if (id > this->myStrSize)
		throw "Out of range";
	
	this->insert(id, String, charSize(String));

	return *this;
}

//Insert std::string at index position
MyString MS::insert(const size_T id, string stroka) {
	if (id > this->myStrSize)
		throw "Out of range";

	size_T size = stroka.size();

	char* chString = new char[size + 1];

	chString = strtoch(chString, stroka);

	this->insert(id, chString);

	delete[] chString;

	return *this;
}

//Insert count of std::string at index position
MyString MS::insert(const size_T id, string stroka, size_T count) {
	if (id > this->myStrSize)
		throw "Out of range";

	size_T size = min(stroka.size(), (size_t)count);

	char* chString = new char[size + 1];
	chString = strtoch(chString, stroka);

	this->insert(id, chString, size);

	delete[] chString;

	return *this;
}

//Erase count of char at index position
MyString MS::erase(const size_T id, size_T count) {
	if (id > this->myStrSize)
		throw "Out of range";

	size_T i = id;
	for (; i < this->myStrSize - count; i++)
		this->myString[i] = this->myString[i + count];
	while (i < this->myStrSize)
		this->myString[i++] = '\0';

	this->myStrSize = this->myStrSize - count;

	return *this;
}

//Append count of char
MyString MS::append(size_T count, const char chr) {
	size_T id = this->myStrSize;

	this->insert(id, count, chr);

	return *this;
}

//Append null-terminated char string
MyString MS::append(const char String[]) {
	
	this->insert(this->myStrSize, String, charSize(String));

	return *this;
}

//Append a count of null-terminated char string by index position
MyString MS::append(const char String[], const size_T id, size_T count) {
	if (id > this->myStrSize)
		throw "Out of range";

	this->insert(id, String, count);

	return *this;
}

//Append std:: string
MyString MS::append(const string stroka) {
	
	this->insert(this->myStrSize, stroka);

	return *this;
}

//Append a count of std:: string by index position
MyString MS::append(const string stroka, const size_T id, size_T count) {
	if (id > this->myStrSize)
		throw "Out of range";

	size_T size = min(stroka.size(), (size_t)count);

	char* chString = new char[size + 1];
	chString = strtoch(chString, stroka);

	this->insert(id, chString, size);

	delete[] chString;

	return *this;
}

//Replace a count of char at index by “string”
MyString MS::replace(const size_T id, size_T count, const char String[]) {
	this->erase(id, count);

	this->insert(id, String);

	return *this;
}

//Replace a count of char at index by std::string
MyString MS::replace(const size_T id, size_T count, const string stroka) {
	this->erase(id, count);

	char* chString = new char[stroka.size() + 1];
	chString = strtoch(chString, stroka);

	this->insert(id, chString);

	delete[] chString;

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

//If founded return the index of "char array" substring. Search starts from index position
//Main find
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

//If founded return the index of "char array" substring
size_T MS::find(const char String[]) {
	return this->find(String, 0);
}

//If founded return the index of std::string substring
size_T MS::find(const string stroka) {
	
	char* chString = new char[stroka.size() + 1];
	chString = strtoch(chString, stroka);

	return this->find(chString);
}

//If founded return the index of std::string substring. Search starts from index position
size_T MS::find(const string stroka, const size_T id) {
	char* chString = new char[stroka.size() + 1];
	chString = strtoch(chString, stroka);

	return this->find(chString, id);
}

int main() {
	setlocale(LC_ALL, "ru");
	string s = "Hello!";
	MyString a({'h', 'a', 'a'});

	//a.erase(5, 6);

	const char* chr = a.data();

	cout << "\'" << a << "\'" << "\n\tsize " << a.size() << ", capacity " << a.capacity() << endl;

	return 0;
 }