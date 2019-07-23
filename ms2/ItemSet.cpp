/*
 ============================================================================
 Name        : ItemSet.cpp
 Author      : Abdul Abdi
 Email       : aabdi39@myseneca.ca
 Student #   : 146779186
 Course Code : OOP345
 Section     : SCC
 Date        : July 10th, 2019
 Workshop    : Project - Milestone 1
 ============================================================================
 */
 /*
  ============================================================================
  ItemSet implentation  file
  ============================================================================
 */
#include <string>
#include <iomanip>
#include "ItemSet.h"


namespace sict
{

	//one argument constructor - create object and populate tokens
	ItemSet::ItemSet(const std::string &str)
	{
		size_t next_pos = 0u; 
		name = util.extractToken(str, next_pos);
		serialNum = std::stoul(util.extractToken(str, next_pos)); 
		qty = std::stoul(util.extractToken(str, next_pos));
		description = util.extractToken(str, next_pos);
	}
	// return name token 
	const std::string& ItemSet::getName() const
	{
		return name; 
	}
	//return serial number token 
	const unsigned int ItemSet::getSerialNumber() const
	{
		return serialNum; 
	}

	//return quantity token 
	const unsigned int ItemSet::getQuantity() const
	{
		return qty; 
	}

	// decrement operator overload - Decrease quantity and increase serial number by 1 
	ItemSet& ItemSet::operator--()
	{
		qty--; 
		serialNum++; 

		return *this; 
	}
	// move constructor 
	ItemSet::ItemSet(ItemSet&& mv)
	{
		if (this != &mv)
		{
			name = mv.name;
			serialNum = mv.serialNum;
			qty = mv.qty;
			description = mv.description;

			mv.name = ""; 
			mv.serialNum = 0u; 
			mv.qty = 0u; 
			mv.description = ""; 
		}
	}

	void ItemSet::display(std::ostream& os, bool full) const
	{
		size_t fieldWidth = util.getFieldWidth();
		if (full)
		{
			os.setf(std::ios::left);
			os << std::setw(fieldWidth) << name  << " [" << std::setfill('0') << std::setw(5) 
			   << serialNum << std::setfill(' ') <<  "]" << " Quantity " << std::setw(3) << qty
			   << " Description: " << description  << std::endl; 
		}
		else
		{
			os << std::setw(fieldWidth) << name << " " << serialNum + 1 << std::endl; 
		}
	}
}