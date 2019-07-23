/*
 ============================================================================
 Name        : KVPair.h
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
  Class Template for a class that manages a key-value pair
  ============================================================================
 */

#ifndef SICT_KVPAIR_H
#define SICT_KVPAIR_H

#include <iostream>

extern int fieldWidth;

namespace sict
{
	template <class K, class V>
	class KVPair {
		K key;
		V value;

	public:
		KVPair() {}
		//Two argument constructor - sets key and value
		KVPair(const K& key_, const V& value_) {
			key = key_;
			value = value_;
		}
		//display insterts key and value into an ostream
		template<typename F>
		void display(std::ostream& os, F f) const {

			os.setf(std::ios::left);
			os.width(fieldWidth); 
			os << key << " : "; 
			os.setf(std::ios::right);
			os.width(fieldWidth);
			os << value; 
			os.setf(std::ios::right);
			os.width(fieldWidth);
		    os << f(value);
			os.unsetf(std::ios::right); 
		}

	};
}

#endif // !SICT_LVPAIR_H