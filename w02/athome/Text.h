/*
 ============================================================================
 Name        : Text.h
 Author      : Abdul Abdi 
 Email       : aabdi39@myseneca.ca
 Student #   : 146779186
 Course Code : OOP345
 Section     : SCC 
 Date        : May 20, 2019 
 Workshop    : Workshop 2 - home
 ============================================================================
 */
/*
 ============================================================================
  Header file of text class;  Manages a dynamically allocated array of string
 objects. 
 ============================================================================
*/

#ifndef SICT_TEXT_H
#define SICT_TEXT_H

#include <iostream>
#include <string>

namespace sict
{

	class Text {

		std::string* records; 
		size_t numOfRecords; 
	public: 
		Text(); 
		Text(const char*); 
		Text(const Text&); 
		Text(Text&&);
		Text& operator=(const Text&); 
		Text& operator=(Text&&);
		~Text(); 
		size_t size()const; 
	};
}
#endif //SICT_TEXT_H !

