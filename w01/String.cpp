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
	
        // one argument constructor
	String::String(const char* string_)
	{
		if (string_ != nullptr && string_[0] != '\0')
		{
			strncpy(string, string_, MAX);
			string[MAX] = '\0';
		}
		else
			string[0] = '\0';
 	}

	void String::display() const
	{
		std::cout << string; 
	}
        // extraction operator overload
	std::ostream& operator<< (std::ostream& out, const String& arg)
	{
                static int currItem = INITIAL; 
		out << currItem << ": "; 
		arg.display(); 
		currItem++; 
		return out; 
	}
}