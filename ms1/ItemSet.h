/*
 ============================================================================
 Name        : ItemSet.h
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
  ItemSet header  file
  ============================================================================
 */

#ifndef SICT_ITEMSET_H
#define SICT_ITEMSET_H

#include <iostream>
#include "Utilities.h"

namespace sict
{
	class ItemSet
	{
		unsigned int qty; 
		unsigned int serialNum; 
		std::string name; 
		std::string description; 
		Utilities util; 
	public:
		ItemSet(const std::string &str);
		ItemSet(const ItemSet&) = delete;
		ItemSet& operator=(const ItemSet&) = delete;
		ItemSet& operator=(ItemSet&&) = delete; 
		ItemSet(ItemSet&& mv); 
		const std::string& getName() const;
		const unsigned int getSerialNumber() const;
		const unsigned int getQuantity() const; 
		ItemSet& operator--(); 
		void display(std::ostream& os, bool full) const; 
	};
}
#endif // !SICT_ITEMSET_H
