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
  Class Template for a class that manages a label-value pair as well as a summable
  label-value pair
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
		//two argument constructor 
		LVPair(const L& label_, const V& value_) {
			label = label_; 
			value = value_; 
		}
		// value query for derived class access
		const V& getValue() const
		{
			return value; 
		}
		// label query for derived class access
		const L& getLabel() const
		{
			return label;
		}
		// display function 
		virtual void display(std::ostream& os) const {
			os << label << " : " << value << std::endl; 
		}

	};
	//inseration operator overload
	template <class L, class V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L,V>& pair)
	{
		pair.display(os); 
		return os; 
	}

	template <class L, class V>
	class SummableLVPair : public LVPair<L,V> {
		static V intialValue; // class variable for initial value for sum 
		static size_t fieldWidth; // class variable for field width

	public:
		SummableLVPair() {}
		// two argument constructor
		SummableLVPair(const L& label_, const V& value_) : LVPair<L,V> (label_, value_) {
			//set class variable for field width if label larger than current field width
			if (fieldWidth <= label_.size())
			{
				fieldWidth = label_.size(); 
			}
		}
		// class function query for initial Value
		static const V& getInitialValue()
		{
			return intialValue; 
		}
		// sum function
		V sum(const L& label_, const V& sum_) const
		{
			V sum = sum_; // set sum to sum recived
			if (label_ == LVPair<L, V>::getLabel()) // check if label recieved same as current object label
			{
				sum += LVPair<L, V>::getValue(); // add current object value to sum
			}
			
			return sum; 

		}
		// display function for derived class 
		void display(std::ostream& os) const {
			os.setf(std::ios::left); 
			os.width(fieldWidth); 
			LVPair<L,V>::display(os); 
		}

	};
	// field width class variable definition
	template <class L, class V>
	size_t SummableLVPair<L, V>::fieldWidth = 0u; 
	// initial value class variable specialization for string and int pair 
	template <>
	int SummableLVPair<std::string, int>::intialValue = 0; 
	// initial value class variable specialization for string and string pair 
	template <>
	std::string SummableLVPair<std::string, std::string>::intialValue = "";
	// sum function specialization for string and string pair 
	template <>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& label_, const std::string& sum_) const
	{
		std::string sum = sum_; 
		if (label_ == LVPair<std::string, std::string>::getLabel())
		{
			sum = sum + " " + LVPair<std::string, std::string>::getValue(); 
		}
		
		return sum; 
	}
}

#endif // !SICT_LVPAIR_H