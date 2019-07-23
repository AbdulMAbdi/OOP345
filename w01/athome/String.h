// Workshop <Workshop 1>
// Name: <Abdul Abdi>
// Student #: <146779186>
// Course: OOP345 Summer 2019
// File: <String.h>

#ifndef SICT_STRING_H
#define SICT_STRING_H

#include <iostream>


extern const int INITIAL;

namespace sict
{

	class String
	{
		char* string; 
		void setString(const char*);
	public: 
		String(const char*); 
		String(const String&); 
		String& operator=(const String&); 
		~String(); 
		void display() const; 
	};

	std::ostream& operator<< (std::ostream&, const String&); 
}
#endif // !SICT_STRING_H

