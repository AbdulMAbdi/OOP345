/*
 ============================================================================
 Name        : iProducts.h
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
  Products interface file
  ============================================================================
 */
#ifndef SICT_IPRODUCT_H
#define SICT_IPRODUCT_H

#include <iostream>

extern int FW; 

namespace sict
{
	class iProduct
	{
	public:
		const int fieldwidth = FW;
		virtual double price() const = 0;
		virtual void display(std::ostream& os) const = 0;

	};

	std::ostream& operator<<(std::ostream& os, const iProduct& p);
	iProduct* readRecord(std::ifstream& file);
}


#endif // !SICT_IPRODUCT_H
