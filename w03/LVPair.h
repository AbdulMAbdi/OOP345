/*
 ============================================================================
 Name        : LVPair.h
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
 Class Template for a class that manages a label-value pair
 ============================================================================
*/

#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H

#include <iostream>

namespace sict
{
	template <class L, class V>
	class LVPair {
		L label; 
		V value; 
		
	public:
		LVPair() {} 
                //Two argument constructor - sets label and value
		LVPair(const L& label_, const V& value_) {
			label = label_; 
			value = value_; 
		}
                //display insterts label and value into an ostream
		void display(std::ostream& os) const {
			os << label << " : " << value << std::endl; 
		}

	};
       // insertion operator overload 
	template <class L, class V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L,V>& pair)
	{
		pair.display(os); 
		return os; 
	}
}

#endif // !SICT_LVPAIR_H