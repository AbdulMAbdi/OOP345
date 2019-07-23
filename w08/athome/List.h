#ifndef SICT_LIST_H
#define SICT_LIST_H
/*
 ============================================================================
 Name        : List.h
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
  List templates header file 
  ============================================================================
 */

// Workshop 8 - Smart Pointers
// List.h
// Chris Szalwinski from Cornel Barna
// 2019/03/17

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sict {
    template <typename T>
    class List {
		std::vector<T> list;
	public:
		List() { }
		List(const char* fn) {
			std::ifstream file(fn);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(fn) + std::string(" ***");
            while (file) {
                T e;
                if (e.load(file))
                    list.push_back(*new T(e));
            }
		}
		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//operator += overload - adds on to list vector using the smart pointer passed in the second operand 
		// 
		void operator += (const std::unique_ptr<T>& smartPtr)
		{
			list.push_back(*smartPtr);
		}
	

		//operator += overload - adds on to list vector using the raw pointer passed in the second operand 
		// 
		void operator += (const T* rawPtr)
		{
			list.push_back(*rawPtr);
		}




		void display(std::ostream& os) const {
            os << std::fixed << std::setprecision(2);
            for (auto& e : list)
                e.display(os);
        }
	};

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const List<T>& l) {
		l.display(os);
		return os;
	}
}
#endif