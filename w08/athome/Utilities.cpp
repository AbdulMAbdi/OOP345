/*
 ============================================================================
 Name        : Utilities.cpp
 Author      : Abdul Abdi
 Email       : aabdi39@myseneca.ca
 Student #   : 146779186
 Course Code : OOP345
 Section     : SCC
 Date        : July 19th, 2019
 Workshop    : Workshop 8 - Home
 ============================================================================
 */
 /*
  ============================================================================
  Utilities implementation file 
  ============================================================================
 */

// Workshop 8 - Smart Pointers
// Utilities.cpp
// Chris Szalwinski from Cornel Barna
// 2019/03/17

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sict
{
	// mergeRaw function - builds a list of products using raw pointers 
	// 
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (size_t i = 0; i < desc.size(); i++)
		{
			for (size_t n = 0; n < price.size(); n++)
			{
				if (desc[i].code == price[n].code)
				{
					Product* rawPtr = new Product(desc[i].desc, price[n].price);
					rawPtr->validate();
					priceList += rawPtr;

					delete rawPtr;
					rawPtr = nullptr;
				}
			}
		}

		return priceList;
	}
	// mergeSmart function - builds a list of products using smart pointers 
	// 
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) 
	{
		List<Product> priceList;
		for (size_t i = 0; i < desc.size(); i++)
		{
			for (size_t n = 0; n < price.size(); n++)
			{
				if (desc[i].code == price[n].code)
				{
					std::unique_ptr<Product> smartPtr(new Product(desc[i].desc, price[n].price));
					smartPtr->validate();
					priceList += smartPtr;
				}

			}

		}
		
		return priceList;
	}
}