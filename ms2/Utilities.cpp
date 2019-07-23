/*
 ============================================================================
 Name        : Utilities.cpp
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
  Utilities implentation  file
  ============================================================================
 */

#include <iostream>
#include <string>
#include "Utilities.h"

namespace sict
{
	//initialize delimiter class variable to safe state
	char Utilities::delimiter = '\0'; 
	//initialize fieldwidth class variable to safe state
	size_t Utilities::fieldWidth = 0u;

	Utilities::Utilities()
	{

	}

	// extractor function - returns an extracted token from string recieved/stores next position in variable recieved
	const std::string Utilities::extractToken(const std::string& str, size_t& next_pos)
	{
		size_t delim_pos = str.find(delimiter, next_pos); 
		size_t strLength = delim_pos - next_pos; 
		if (strLength > fieldWidth && delim_pos != std::string::npos) fieldWidth = strLength;
		std::string extractedToken = str.substr(next_pos, strLength); 
		if (delim_pos == std::string::npos)
		{
			next_pos = std::string::npos; 
		}
		else
		{
			next_pos = delim_pos + 1;
		}
		
		return extractedToken; 
	}

	// returns delimiter character
	const char Utilities::getDelimiter() const
	{
		return delimiter; 
	}

	//returns field width 
	size_t Utilities::getFieldWidth() const
	{
		return fieldWidth; 
	}

	//modifier to set delimiter character 
	void Utilities::setDelimiter(const char d)
	{
		delimiter = d; 
	}

	//modifer to set field width
	void Utilities::setFieldWidth(size_t fw)
	{
		fieldWidth = fw; 
	}
}