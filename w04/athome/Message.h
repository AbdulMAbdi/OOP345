/*
 ============================================================================
 Name        : Message.h
 Author      : Abdul Abdi
 Email       : aabdi39@myseneca.ca
 Student #   : 146779186
 Course Code : OOP345
 Section     : SCC
 Date        : June 6th, 2019
 Workshop    : Workshop 4 - Lab
 ============================================================================
 */
 /*
  ============================================================================
  header file for message class which manages single message between users
  ============================================================================
 */
#ifndef SICT_MESSAGE_H
#define SICT_MESSAGE_H

#include <iostream>

namespace sict
{
	class Message
	{
		std::string user; 
		std::string reply; 
		std::string tweet; 
	public: 

		Message(); 
		Message(const std::string& str); 
		bool empty() const; 
		void display(std::ostream& os) const; 
	};
}

#endif // !SICT_MESSAGE_H
