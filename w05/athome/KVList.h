/*
 ============================================================================
 Name        : KVList.h
 Author      : Abdul Abdi
 Email       : aabdi39@myseneca.ca
 Student #   : 146779186
 Course Code : OOP345
 Section     : SCC
 Date        : June 11, 2019
 Workshop    : Workshop 5 - Lab
 ============================================================================
 */
 /*
  ============================================================================
  Class Template for a class that dynamically manages an array of any type
  ============================================================================
 */

#ifndef SICT_LIST_H
#define SICT_LIST_H

#include <iostream>
#include"KVPair.h"

namespace sict
{
	template <class T>
	class KVList {
		T* listArray;
		int currSize;
		int maxSize;

	public:
		KVList() : currSize{ 0u }
		{
			listArray = nullptr;
		}

		KVList(int n) : KVList<T>()
		{
			if (n > 0)
			{
				maxSize = n;
				listArray = new T[n];
			}
			else
			{
				throw "Non postive array size!";
			}
		}

		KVList(const KVList&) = delete;

		KVList& operator=(const KVList&) = delete;

		KVList& operator=(KVList&&) = delete;

		KVList(KVList&& src) : KVList<T>()
		{
			delete[] listArray;
			currSize = src.currSize;
			maxSize = src.maxSize;
			listArray = src.listArray;
			src.currSize = 0u;
			src.maxSize = 0;
			src.listArray = nullptr;
		}

		~KVList()
		{
			delete[] listArray;
		}
		//subscript operator overload - returns array element at index i
		const T& operator[](int i) {
			if (i < currSize && i > 0)
			{
				return listArray[i];
			}
			else
			{
				throw i; 
			}
			
		}
		//adds t into array if array is not full. 
		void push_back(const T& t) {
			if (currSize < maxSize)
			{
				listArray[currSize] = t;
				currSize++;
			}
		}

		template<typename F>
		void display(std::ostream& os, F f) const {
			for (int i = 0; i < currSize; i++)
			{
				listArray[i].display(os, f);
				os << std::endl;
			}
		}
	};
}




#endif // !SICT_LIST_H
