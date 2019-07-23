/*
 ============================================================================
 Name        : List.h
 Author      : Abdul Abdi 
 Email       : aabdi39@myseneca.ca
 Student #   : 146779186
 Course Code : OOP345
 Section     : SCC 
 Date        : May 30, 2019 
 Workshop    : Workshop 3 - Lab
 ============================================================================
 */
/*
 ============================================================================
 Class Template for a class that can manage an array of any type 
 ============================================================================
*/

#ifndef SICT_LIST_H
#define SICT_LIST_H

#include <iostream>

namespace sict
{
	template <class T, int arraySize>
	class List {
		T listArray[arraySize];
		size_t currSize;

	public:
		List() : currSize{ 0u } {}
		size_t size() const { return currSize;  }
                //subscript operator overload - returns array element at index i
		const T& operator[](size_t i) {
			return listArray[i];
		} 
                //+= operator overload - adds t into array if array is not full. 
		void operator+=(const T& t) {
			if (currSize < arraySize)
			{
				listArray[currSize] = t; 
				currSize++; 
			}
		}
	};
}

#endif // !SICT_LIST_H
