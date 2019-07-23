/*
 ============================================================================
 Name        : Utilities.h
 Author      : Abdul Abdi
 Email       : aabdi39@myseneca.ca
 Student #   : 146779186
 Course Code : OOP345
 Section     : SCC
 Date        : July 10th, 2019
 Workshop    : Project - Milestone 1
 ============================================================================
 */
 /*
  ============================================================================
  Utilities header file
  ============================================================================
 */

#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H

#include <iostream>
#include <string>

namespace sict
{
	class Utilities
	{
		static char delimiter;
		static size_t fieldWidth;
	public:
		Utilities();
		const std::string extractToken(const std::string& str, size_t& next_pos);
		const char getDelimiter() const;
		size_t getFieldWidth() const;
		static void setDelimiter(const char d);
		void setFieldWidth(size_t);
	}; 
}
#endif // !SICT_UTILITIES_H
