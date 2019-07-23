/*
 ============================================================================
 Name        : Message.cpp
 Author      : Abdul Abdi
 Email       : aabdi39@myseneca.ca
 Student #   : 146779186
 Course Code : OOP345
 Section     : SCC
 Date        : June 6th, 2019
 Workshop    : Workshop 4 - Lab
 ============================================================================
 */
 /*
  ============================================================================
  Implementation file for message class which manages single message between users
  ============================================================================
 */

#include <iostream>
#include <string>
#include "Message.h"

namespace sict
{
	Message::Message() // default constructor (empty state) 
	{
		tweet = ""; 
		user = ""; 
		reply = ""; 
	}

	Message::Message(const std::string& str)
	{
		std::string sub; 
		size_t pos = str.find(" "); // find postiton of first space in string recieved 
		size_t pos2; 
		if (pos != std::string::npos) // checks to see if find was successful
		{
			user = str.substr(0, pos); // assign user string to string until first space
			sub = str.substr(pos + 1);
			pos = sub.find("@"); // locate position of @ symbol 
		}
		
		if (pos!= std::string::npos) // check to see if find for @ symbol was successful 
		{
			pos2 = sub.find(" "); // locate space 
			reply = sub.substr(pos + 1, pos2 - 1); // assign reply string to position after @ until space
			sub = sub.substr(pos2 + 1); 
		}
		else // set reply to empty string if no @ found 
		{
			reply = ""; 
		}
		if (sub.length() > 0u) // check to see if there is a message
		{

			size_t end = sub.length() - 1; 
			tweet = sub.substr(0,end); 
  
		}
		else // if no message set object to safe empty state
		{
			*this = Message(); 
		}
		
	}

	bool Message::empty() const
	{
		if (tweet == "")
		{
			return true; 
		}
		else
		{
			return false; 
		}
	}

	void Message::display(std::ostream& os) const
	{
		if (!empty()) // check if object is not empty 
		{
			os << ">User  : " << user << std::endl;
			if (reply != "") // check to see if reply string is not empty
			{
				os << " Reply : " << reply << std::endl;
			}
			os << " Tweet : " << tweet << std::endl;
		}
	
	}
}