/*
 ============================================================================
 Name        : Utilities.cpp
 Author      : Abdul Abdi
 Email       : aabdi39@myseneca.ca
 Student #   : 146779186
 Course Code : OOP345
 Section     : SCC
 Date        : July 19th, 2019
 Workshop    : Workshop 8 - Lab
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

namespace sict {

	// Builds list of products using raw pointer
	//
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
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
}