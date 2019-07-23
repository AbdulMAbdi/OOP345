/*
 ============================================================================
 Name        : TaxableProduct.h
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
  TaxableProduct header file
  ============================================================================
 */
#ifndef SICT_TAXABLEPRODUCT_H
#define SICT_TAXABLEPRODUCT_H

#include <iostream>
#include "Product.h"

namespace sict
{
	enum status { HST, PST };
	class TaxableProduct : public Product
	{
		std::string taxName;  
		static double HSTRate;
		static double PSTRate;
		status taxStatus;
	public:
		TaxableProduct();
		TaxableProduct(int, double, status);
		double price() const;
		void display(std::ostream& os) const;

	};
}


#endif // !SICT_TAXABLEPRODUCT_H

