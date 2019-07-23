// Workshop <Workshop 1>
// Name: <Abdul Abdi>
// Student #: <146779186>
// Course: OOP345 Summer 2019
// File: <String.cpp>

#include <iostream> 
#include <cstring> 
#include "String.h" 
 


namespace sict
{ 
	void String::setString(const char* string_)
	{
		if (string_ != nullptr && string_[0] != '\0')
		{
			int arraySize = strlen(string_) + 1;
			string = new char[arraySize];
			strncpy(string, string_, arraySize);
			string[arraySize - 1] = '\0';
		}
		else
			string = nullptr;
	}
	String::String(const char* string_)
	{
		setString(string_); 
 	}
	String::String(const String& copy)
	{
		setString(copy.string); 
	}
	String& String::operator=(const String& rhs)
	{
		if (this != &rhs)
		{
			delete[] string;
			setString(rhs.string);
		}

		return *this;
	}
	String::~String()
	{
		delete[] string; 
	}
	void String::display() const
	{
		std::cout << string; 
	}

	std::ostream& operator<< (std::ostream& out, const String& a)
	{
		static int currItem = INITIAL;
		out << currItem << ": "; 
		a.display(); 
		currItem++; 
		return out; 
	}
}