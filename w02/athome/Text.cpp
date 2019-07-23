/*
 ============================================================================
 Name        : Text.cpp
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
  Implementation of text class, Manages a dynamically allocated array of string
 objects. 
 ============================================================================
*/

#include <iostream>
#include <string>
#include <fstream>
#include "Text.h"

namespace sict
{
	// default no argument constructor
	Text::Text()
	{
		records = nullptr;
		numOfRecords = 0;
	}
	
        //one - argument constructor
	Text::Text(const char* file_) : Text()
	{
		int count = 0; 
		std::string newLine;
		std::ifstream file(file_); // open file using file-name recieved from client code 
		if (file.is_open())
		{
			
			while (std::getline(file, newLine)) // count about of new lines in file (records) 
			{
				count++;

			}

			file.close(); 
			std::ifstream file(file_);

			records = new std::string[count]; // allocate memory for string array sized to amount of records 
			for (int i = 0; i < count; i++)
			{
				std::getline(file, records[i]); // store each line into a string array 
			}
			numOfRecords = count;   
			file.close();
		}
	}

	Text& Text::operator=(const Text& rhs)
	{

		if (this != &rhs) // self-assignment check 
		{
			delete[] records; // delete old allocation of records 
			numOfRecords = rhs.numOfRecords;
			records = new std::string[numOfRecords]; // allocate new memory for string array 
			for (size_t i = 0; i < numOfRecords; i++)
			{
				records[i] = rhs.records[i]; // copy over records 
			}

			
		}

		return *this;
	}
	//move assignment operator
	Text& Text::operator=(Text&& rhs)
	{

		if (this != &rhs) // self-assignment check 
		{
			delete[] records; // delete old allocation of records 
			numOfRecords = rhs.numOfRecords;
			records = rhs.records; // current object 'records' point to same address as rhs 'records' 
			rhs.records = nullptr; // rhs 'records' now points to nullptr, i.e empty 
			rhs.numOfRecords = 0; 
		}

		return *this;
	}
	Text::Text(const Text&copy):Text()
	{
		*this = copy; 
	}

	Text::Text(Text&& src) : Text()
	{
		*this = std::move(src);
	}

	Text::~Text() // deallocate memory
	{
		delete[] records;
	}

	size_t Text::size() const
	{
		
		return numOfRecords;
	}
}