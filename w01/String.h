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
	const int MAX = 3; 

	class String
	{
		char string[MAX + 1]; 

	public: 
		String(const char*); 
		void display() const; 
	};

	std::ostream& operator<< (std::ostream&, const String&); 
}
#endif // !SICT_STRING_H

