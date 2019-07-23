#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H
/*
 ============================================================================
 Name        : Utilities.h
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
  Utilities header file
  ============================================================================
 */

// Workshop 8 - Smart Pointers
// Utilities.h
// Chris Szalwinski from Cornel Barna
// 2019/03/17

#include "List.h"
#include "Element.h"

namespace sict {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
}

#endif