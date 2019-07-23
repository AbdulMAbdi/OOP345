/*
 ============================================================================
 Name        : Sales.h
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
  Sales header file
  ============================================================================
 */

#ifndef SICT_SALE_H
#define SICT_SALE_H

#include <iostream> 
#include <vector>

#include "Product.h"

namespace sict
{
	class Sale {

		std::vector<iProduct*> products;

	public:
		Sale(const char* file);
		void display(std::ostream& os) const;

	};
}

#endif // !SICT_SALE_H
