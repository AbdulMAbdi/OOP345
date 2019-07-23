/*
 ============================================================================
 Name        : Sales.cpp
 Author      : Abdul Abdi
 Email       : aabdi39@myseneca.ca
 Student #   : 146779186
 Course Code : OOP345
 Section     : SCC
 Date        : July 5th, 2019
 Workshop    : Workshop 5 - Lab
 ============================================================================
 */
 /*
  ============================================================================
  Sales implementation file
  ============================================================================
 */
#include <fstream>
#include <string>
#include <iomanip>
#include "Sale.h"

extern int FW; 

namespace sict
{
	//one argument constructor - creates object from file data
	Sale::Sale(const char* fileName) {

		if ((fileName != nullptr) && (fileName[0] != '\0')) {

			std::string counter;
			int numOfProducts = 0;
			std::ifstream file;
			file.open(fileName);

			if (file.is_open()) {

				while (getline(file, counter))
				{
					numOfProducts++;
				}	
				file.clear();
				file.seekg(0, std::ios::beg);
				for (int i = 0; i < numOfProducts; i++)
				{
					products.push_back(readRecord(file));
				}
					
				file.close();

			}
			else {

				throw "Unable to open file";
			}

		}
		else {

			throw "File does not exist";
		}

	}
	//display function - displays all products and then the total
	void Sale::display(std::ostream & os) const {

		os << "\nProduct No" << std::setw(FW) << "Cost" << " " << "Taxable" << std::endl;
		double total = 0.0;
		for (auto& i : products) {

			os << *i;
			os << std::fixed << std::setprecision(2);
			os << std::endl; 
			total += i->price();

		}

		os << std::setw(FW) << "Total" << std::setw(FW) << total << std::endl;

	}

}

