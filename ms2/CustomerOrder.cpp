/*
 ============================================================================
 Name        : CustomerOrder.cpp
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
  CustomerOrder implementation file
  ============================================================================
 */

#include <iostream>
#include <string>
#include<vector>
#include <iomanip>
#include "CustomerOrder.h"


namespace sict
{
	size_t CustomerOrder::fw = 0; 
	//default constructor - sets empty state 
	//
	CustomerOrder::CustomerOrder() : custName(""), prodName("") {}
	//one argument constructor - recieves a string and extracts tokens to populate the CustomerOrder object
	//
	CustomerOrder::CustomerOrder(const std::string& stream)
	{
		size_t next_pos = 0u;
		custName = util.extractToken(stream, next_pos);
		prodName = util.extractToken(stream, next_pos);
		if (next_pos != std::string::npos)
		{
			while (next_pos != std::string::npos)
				items.push_back(ItemInfo(util.extractToken(stream, next_pos)));
		}
		else throw "No items requested";
		if (custName.length() > fw)
		{
			fw = custName.length() + 1; 
		}
		

	}
	//Fill item function - recieves an itemset object and fills an item request if possible or an appropriate message if not 
	//
	void CustomerOrder::fillItem(ItemSet& item, std::ostream& os)
	{
		for (size_t i = 0; i < items.size(); i++)
		{
			if (items[i].name == item.getName())
			{
				if (item.getQuantity() == 0)
				{
					os << " Unable to fill " << getNameProduct() << "[" << items[i].name
						<< "][" << item.getSerialNumber() << "]" << " out of stock" << std::endl;
				}
				else
				{
					if (items[i].filled)
					{
						os << " Unable to fill " << getNameProduct() << "[" << items[i].name
							<< "][" << items[i].serialNum << "]" << " already filled" << std::endl;
					}
					else
					{
						items[i].serialNum = item.getSerialNumber();
						items[i].filled = true;
						--item;
						os << " Filled " << getNameProduct() << "["  << items[i].name
							<< "][" << items[i].serialNum << "]" << std::endl;

					}
				}
			}
		}
	}
	// move assignment operator 
	//
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& rhs)
	{
		if (this != &rhs)
		{
			custName = rhs.custName;
			prodName = rhs.prodName;
			items = rhs.items;
			util = rhs.util;

			rhs.custName = "";
			rhs.prodName = "";
			rhs.items.clear();
			rhs.util = Utilities();
		}

		return *this;
	}
	// move constructor 
	//
	CustomerOrder::CustomerOrder(CustomerOrder&& mv)
	{
		*this = std::move(mv);
	}
	// isFilled function - checks to see if an order has been filled 
	//
	bool CustomerOrder::isFilled() const
	{
		int unfilled = 0;
		bool filled = false;

		for (size_t i = 0; i < items.size(); i++)
		{
			if (!items[i].filled)
			{
				unfilled++;
			}
		}

		if (unfilled == 0)
		{
			filled = true;
		}

		return filled;
	}
	// isItemFilled function - checks to see if a particular item in order has been filled 
	//
	bool CustomerOrder::isItemFilled(const std::string& item) const
	{
		int unfilled = 0;
		bool filled = true;

		for (size_t i = 0; i < items.size(); i++)
		{
			if (items[i].name == item && !items[i].filled)
			{
				unfilled++;
			}
		}

		if (unfilled > 0)
		{
			filled = false;
		}

		return filled;
	}
	// returns combination of customer name and product name of order
	//
	std::string CustomerOrder::getNameProduct() const
	{
		std::string nameProd = custName + " [" + prodName + "]";
		return nameProd;
	}
	// display function - displays order information with option to disable item details
	//
	void CustomerOrder::display(std::ostream& os, bool showDetail)
	{
		os << std::setw(fw) << custName << "[" << prodName << "]" << std::endl;

		if (!showDetail)
		{
			

			for (size_t i = 0; i < items.size(); ++i) {
				os << std::setfill(' ') << std::setw(fw) << "";
				os << items[i].name << std::endl;
			}
		}
		else
		{
			os << getNameProduct() << std::endl;

			for (size_t i = 0; i < items.size(); ++i) {
				os << std::setfill(' ') << std::setw(fw) << "";
				os << "[" << std::right << items[i].serialNum
					<< "] " << items[i].name << "-" << items[i].filled << std::endl;
			}
		}
	}
}