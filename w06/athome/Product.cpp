/*
 ============================================================================
 Name        : Products.cpp
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
  Products implentation  file
  ============================================================================
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
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
			<< prodPrice; 
	}
	// price query - return price 
	double Product::price() const
	{
		return prodPrice; 
	}

	double TaxableProduct::HSTRate = 0.13;
	double TaxableProduct::PSTRate = 0.08;
	//default constructor - safe state 
	TaxableProduct::TaxableProduct() : Product()
	{

	}
	//three argument constructor - set values 
	TaxableProduct::TaxableProduct(int num, double price, status tax) : Product(num, price)
	{
		taxStatus = tax;
		switch (tax)
		{
		case HST:
			taxName = "HST";
			break;
		case PST:
			taxName = "PST";
			break;
		default:
			break;
		}
	}
	// display function - display product number + price 
	void TaxableProduct::display(std::ostream& os) const
	{
		Product::display(os);
		os << " " << taxName;
	}
	// price query - return price 
	double TaxableProduct::price() const
	{
		double taxRate = 0;
		switch (taxStatus)
		{
		case HST:
			taxRate = HSTRate;
			break;
		case PST:
			taxRate = PSTRate;
			break;
		default:
			break;
		}
		return Product::price() * (1 + taxRate);
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
		std::string taxChar;
		status tax;
		iProduct* product = nullptr;
		file >> num >> price;
		getline(file, taxChar);
		if (taxChar == " H")
		{
			tax = HST;
			product = new TaxableProduct(num, price, tax);
		}
		else if (taxChar == " P")
		{
			tax = PST;
			product = new TaxableProduct(num, price, tax);
		}
		else
		{
			product = new Product(num, price);
		}
		return product;
	}
}
