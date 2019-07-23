/*
 ============================================================================
 Name        : Timekeeper.cpp
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
  Implentation file of timekeeper class;  Manages an array of record objects. 
 ============================================================================
*/

#include <iostream>
#include <chrono>
#include <ctime>
#include <ratio>
#include <cstring>
#include "Timekeeper.h"

namespace sict
{       //default no argument constructor 
	Timekeeper::Timekeeper()
	{
		numOfRecords = 0; 
		for (int i = 0; i < max_records; i++)
		{
			record[i].message = nullptr;
			record[i].units = nullptr;
		}
	}
        
        // records star time for timekeeper object 
	void Timekeeper::start()
	{
		begin = std::chrono::steady_clock::now(); 
	}

        // records stop time for timekeeper object 
	void Timekeeper::stop()
	{
		end = std::chrono::steady_clock::now();
	}
       
	void Timekeeper::recordEvent(const char * message_)
	{
		int stringSize = strlen(message_); // find size of c-style strong recieved 
		record[numOfRecords].message = new  char[stringSize + 1]; // allocate memory for record.message c-style string 
		strncpy(record[numOfRecords].message, message_, stringSize); // copy over message 
		record[numOfRecords].message[stringSize] = '\0'; 
		record[numOfRecords].units = new  char[9]; // allocate memory of unit 
		strncpy(record[numOfRecords].units, unit, 8); // copy over unit c-style string 
		record[numOfRecords].units[8] = '\0'; 
		record[numOfRecords].totalTime = std::chrono::duration_cast<std::chrono::duration<double>>(end - begin); // cast duration to double seconds and calculate difference between start and stop 
		numOfRecords++; 
	}

	std::ostream& Timekeeper::report(std::ostream& os) const
	{
		os << std::endl;
		os << "Execution Times:" << std::endl; 
		for (int i = 0; i < numOfRecords; i++)
		{
			os << record[i].message << ": " << record[i].totalTime.count() << " " << record[i].units << std::endl; 
		}

		return os; 
	}
}