/*
 ============================================================================
 Name        : Taxable.h
 Author      : Abdul Abdi
 Email       : aabdi39@myseneca.ca
 Student #   : 146779186
 Course Code : OOP345
 Section     : SCC
 Date        : June 11, 2019
 Workshop    : Workshop 5 - Lab
 ============================================================================
 */
 /*
  ============================================================================
  Functor for funtion that returns price including tax 
  ============================================================================
 */
#ifndef SICT_TAXABLE_H
#define SICT_TAXABLE_H

#include <iostream> 

namespace sict
{ 
	class Taxable {
		const float tax; 
	public:
		Taxable(float tax_) : tax(tax_){} // constructor -store tax to constant float instance variable 
		//function call operator overload 
		float operator()(float price) const {
			return price += (price * tax); 
		}
	};
}
#endif // !SICT_TAXABLE_H
