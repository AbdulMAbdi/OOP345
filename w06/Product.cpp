/*
 ============================================================================
 Name        : Products.cpp
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
  Products implentation  file
  ============================================================================
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Product.h"

namespace sict
{
	//default constructor - safe state 
	Product::Product()
	{
		prodNum = 0; 
		prodPrice = 0; 
	}
	//two argument constructor - set values 
	Product::Product(int num, double price)
	{
		prodNum = num; 
		prodPrice = price; 
	}
	// display function - display product number + price 
	void Product::display(std::ostream& os) const
	{
		os << std::setw(fieldwidth) << prodNum << std::setw(fieldwidth)
			<< prodPrice << std::endl; 
	}
	// price query - return price 
	double Product::price() const
	{
		return prodPrice; 
	}
	//operator overload to display product from ostream 
	std::ostream& operator<<(std::ostream& os, const iProduct& p)
	{
		p.display(os); 
		return os; 
	}
	// creates product from file 
	iProduct* readRecord(std::ifstream& file)
	{
		int num;
		double price; 
		iProduct* product = nullptr; 
		file >> num >> price; 
		product = new Product(num, price); 
		return product; 
	}
}
