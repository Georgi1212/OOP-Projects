#ifndef __STRING_HPP
#define __STRING_HPP

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class String {
	
	private:
		unsigned int size;
		char* str;
		
		void copy(const String& other);
		void destroy();
		
		//
		void setStr (const char* _str);
		void setSize(const unsigned int _size);
		
	public:
		//unsigned int length() const;
		
		unsigned int getSize() const;
		
		const char* getStr() const;
		
		
		String();
		String(const char* _str);
		String(const String& other);
		~String();
		
		String& operator=(const String& other);
		
		String operator+(const String& other);
		String& operator+=(const String& other);
		
		const char& operator[](unsigned int index) const;
		char& operator[](unsigned int index);
		
		bool operator==(const String& other);
		bool operator!=(const String& other);
		
		bool contains(char c);
		
		friend std::ostream& operator<<(std::ostream& out, const String& s);
		friend std::istream& operator>>(std::istream& in, String& s);
		
		void helperFuncDeserialize(std::ifstream& in);
		
		//void serialize(std::ofstream& out) const;
		//void deserialize(std::ifstream& in);
		
};

void String::copy(const String& other)
{
	this->str = new char [strlen(other.str) + 1];
	strcpy(this->str, other.str);
	this->size = other.size;
}

void String::destroy()
{
	delete[] this->str;
}
/*
unsigned int String::length() const
{
	return size;
}*/

// setter for size
void String::setSize(const unsigned int _size)
{
	size = _size;
}

//getter for size
unsigned int String::getSize() const
{
	return this->size;
}

//setter for str
void String::setStr(const char* _str)
{
	if(str != NULL)
	{
		delete[] str;	
	}
	str = new char[strlen(_str) + 1];
	strcpy(str, _str);
}

//getter for str
const char* String::getStr() const
{
	return this->str;
}

//default constructor
String::String()
{
	size = 0;
	str = NULL;
}

//constructor
String::String(const char* _str)
{
	str = new char[strlen(_str) + 1];
    strcpy(str, _str);
}

//copy constructor
String::String(const String& other)
{
	copy(other);
}

//destructor
String::~String()
{
	destroy();
}

//operator= overloading
String& String::operator=(const String& other)
{
	if(this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;
}

// operator+ overloading
String String::operator+(const String& other)
{
	char* result = new char[size + other.size + 1];
    strcpy(result, str);
    strcat(result, other.str);
    
    String res(result);
    delete[] result;
    return res;
}

//operator+= overloading
String& String::operator+=(const String& other)
{
	unsigned int newSize = size + other.size;
	char* newStr = new char[newSize + 1];

	for (unsigned int i = 0; i < size; ++i)
	{
		newStr[i] = str[i];
	}

	for (unsigned int i = size; i < newSize; ++i)
	{
		newStr[i] = other.str[i - size];
	}
	newStr[newSize] = '\0';

	delete[] str;
	this->size = newSize;
	this->str = newStr;

	return *this;
}

//operator[] overloading (const)
const char& String::operator[](unsigned int index) const
{
	if(index < size) return str[index];
}

//operator[] overloading
char& String::operator[](unsigned int index)
{
	if(index < size) return str[index];
}

bool String::operator==(const String& other)
{
	return !strcmp(str, other.str);
}

bool String::operator!=(const String& other)
{
	return !(*this == other);
}

bool String::contains(char c)
{
	bool flag = false;
	
	for(unsigned int i = 0; i < size; ++i)
	{
		if(str[i] == c)
		{
			flag = true;
			break;
		}
	}
	return flag;
}

std::ostream& operator<<(std::ostream& out, const String& s)
{
	for (unsigned int i = 0; i < s.size; ++i)
	{
		out << s.str[i];
	}
	return out;
}

std::istream& operator>>(std::istream& in, String& s)
{
	char buffer[128];
	cin >> buffer;
	
	s.str = new char[strlen(buffer) + 1];
	strcpy(s.str,buffer);
	
	s.size = strlen(buffer);
	
	return in;
}

#endif
