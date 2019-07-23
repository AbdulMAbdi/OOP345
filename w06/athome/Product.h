/*
 ============================================================================
 Name        : Products.h
 Author      : Abdul Abdi
 Email       : aabdi39@myseneca.ca
 Student #   : 146779186
 Course Code : OOP345
 Section     : SCC
 Date        : July 5th, 2019
 Workshop    : Workshop 6 - Lab
 ============================================================================
 */
 /*
  ============================================================================
  Products header file
  ============================================================================
 */
#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H

#include <iostream>
#include "iProduct.h"

namespace sict
{
	class Product : public iProduct
	{
		int prodNum;
		double prodPrice;
	public:
		Product(); 
		Product(int, double);
		double price() const;
		void display(std::ostream& os) const;

	};

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


#endif // !SICT_PRODUCT_H
