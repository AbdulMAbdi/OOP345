/*
 ============================================================================
 Name        : Timekeeper.h
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
  Header file of timekeeper class;  Manages an array of record objects. 
 ============================================================================
*/

#ifndef SICT_TIMEKEEPER_H
#define SICT_TIMEKEEPER_H

#include <iostream>
#include <chrono>

namespace sict
{
	const int max_records = 10;
	const char unit[8] = "seconds"; 

	class Timekeeper
	{
		int numOfRecords; 
		std::chrono::steady_clock::time_point begin; 
		std::chrono::steady_clock::time_point end;
		struct {
			char* message; 
			char* units; 
			std::chrono::duration<double> totalTime;
		}record[max_records];
	public: 
		Timekeeper(); 
		void start(); 
		void stop(); 
		void recordEvent(const char*); 
		std::ostream& report(std::ostream&) const; 
	};
}
#endif // !SICT_TIMEKEEPER_H
