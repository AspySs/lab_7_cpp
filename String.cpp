#include "String.h"
#include "functions.h"
/*Класс строк*/

String::String()
{
	length_ = 0;
	str_ = nullptr;
}

String::String(const char* string)
{
	length_ = str_len(string);
	str_ = new char[length_ + 1];
	for (int i = 0; i <= length_; i++) {
		str_[i] = string[i];
	}
	str_[length_] = '\0';
}

String::String(const String& other)
{
	if (length_ != 0) {
		str_ = nullptr;
		length_ = 0;
	}
	length_ = other.length_;
	str_ = new char[length_ + 1];
	for (int i = 0; i < length_; i++) {
		str_[i] = other.str_[i];
	}
	str_[length_] = '\0';
}

String::String(int len)
{
	length_ = len;
	str_ = new char[length_];
}

String::~String()
{
	delete[] str_;
}

int String::get_len()
{
	return length_;
}

char* String::get_data()
{
	return str_;
}

void String::push_back(const char elem)
{
	String temp(*this);
	length_++;
	delete[] str_;
	str_ = new char[length_ + 1];
	for (int i = 0; i < length_ - 1; i++) {
		str_[i] = temp[i];
	}
	str_[length_ - 1] = elem;
	str_[length_] = '\0';
}

String& String::operator =(const String& other)
{
	if (&other == this) {
		return *this;
	}
	if (length_ != 0) {
		delete[] str_;
	}
	length_ = other.length_;
	str_ = new char[length_ + 1];
	for (int i = 0; i < length_; i++) {
		str_[i] = other.str_[i];
	}

	str_[length_] = '\0';

	return *this;
}

String String::operator+(const String& other)
{
	String temp;
	temp.length_ = length_ + other.length_;
	temp.str_ = new char[temp.length_ + 1];
	for (int i = 0; i < length_; i++) {
		temp.str_[i] = str_[i];
	}
	int temp_len = length_;
	for (int j = 0; j < other.length_; j++, temp_len++) {
		temp.str_[temp_len] = other.str_[j];
	}
	temp.str_[temp.length_] = '\0';
	return temp;
}

char& String::operator[](int index)
{
	if (str_ == nullptr) {
		throw "Error";
	}
	if (index < 0 || index > length_) throw "Error";
	return str_[index];
}

bool String::operator==(const String& other)
{
	if (length_ != other.length_) {
		return false;
	}
	for (int i = 0; i < length_; i++) {
		if (str_[i] != other.str_[i]) {
			return false;
		}
	}
	return true;
}

bool String::operator!=(const String& other)
{
	if (length_ != other.length_) {
		return true;
	}
	int count = 0;
	for (int i = 0; i < length_; i++) {
		if (str_[i] == other.str_[i]) count++;
	}
	if (count == length_) {
		return false;
	}
	return true;
}

std::istream& operator >> (std::istream& stream, String& string)
{
	String temp;
	char c;
	int space = 0;
	while (stream.peek() != EOF) {
		c = stream.get();
		if (c == '\n' || c == '\t' || c == '\0' || c == ' ') {
			if (space == 0 && c == ' ') {
				space++;
				continue;
			}
			else { break; }

		}
		temp.push_back(c);
	}
	string = temp;
	if (string.length_ != 0) string.str_[string.length_] = '\0';
	return stream;
}

std::ostream& operator << (std::ostream& stream, const String& string)
{
	for (int i = 0; i < string.length_; i++) {
		stream << string.str_[i];
	}
	return stream;
}