/*
 ============================================================================
 Name        : CustomerOrder.h
 Author      : Abdul Abdi
 Email       : aabdi39@myseneca.ca
 Student #   : 146779186
 Course Code : OOP345
 Section     : SCC
 Date        : July 19th, 2019
 Workshop    : Project - Milestone 2
 ============================================================================
 */
 /*
  ============================================================================
  CustomerOrder header file
  ============================================================================
 */

#ifndef SICT_CUSTOMER_ORDER_H
#define SICT_CUSTOMER_ORDER_H

#include<iostream>
#include<vector>
#include"ItemSet.h"

namespace sict
{
	class CustomerOrder
	{
		std::string custName; 
		std::string prodName; 
		struct ItemInfo
		{
			std::string name; 
			size_t serialNum; 
			bool filled; 
			ItemInfo() : name(""), serialNum(0u), filled(false) {};
			ItemInfo(std::string partName) : name(partName), serialNum(0u), filled(false) {};
			ItemInfo(std::string partName, size_t num, bool fill) : name(partName), serialNum(num), filled(fill) {};
		};
		std::vector<ItemInfo> items; 
		Utilities util; 
		static size_t fw; 

	public: 
		CustomerOrder(); 
		CustomerOrder(const std::string& stream); 
		CustomerOrder(const CustomerOrder&) = delete;
		CustomerOrder& operator=(const CustomerOrder&) = delete;
		CustomerOrder& operator=(CustomerOrder&&);
		CustomerOrder(CustomerOrder&& mv);
		void fillItem(ItemSet& item, std::ostream& os); 
		bool isFilled() const; 
		bool isItemFilled(const std::string& item) const; 
		std::string getNameProduct() const; 
		void display(std::ostream& os, bool showDetail = false);
	};
}
#endif // !SICT_CUSTOMER_ORDER_H
