/*
 ============================================================================
 Name        : Notification.cpp
 Author      : Abdul Abdi
 Email       : aabdi39@myseneca.ca
 Student #   : 146779186
 Course Code : OOP345
 Section     : SCC
 Date        : June 6th, 2019
 Workshop    : Workshop 4 - Home
 ============================================================================
 */
 /*
  ============================================================================
  Implementation file for Notification class which manages an aggregation of message objects
  ============================================================================
 */
#include <iostream>
#include "Notifications.h"

namespace sict
{
	// defualt constructor 
	Notifications::Notifications()
	{
		messages = nullptr;
		currMessages = 0u;
		maxMessages = 0u; 
	}
	//one argument constructor 
	Notifications::Notifications(size_t size_) : Notifications()
	{
		if (size_ > 0)
		{
			messages = new const Message*[size_]; // dynamically allocate array of pointers to message objects
			maxMessages = size_;
		}
	}
	Notifications& Notifications::operator=(const Notifications& rhs) // copy assignment
	{
		if (this != &rhs)
		{
			delete[] messages; // delete array of pointers to message objects
			maxMessages = rhs.maxMessages;
			messages = new const Message*[maxMessages];
			messages = rhs.messages; 
		}

		return *this;
	}

	Notifications::Notifications(const Notifications& src)
	{
		*this = src;
	}
	Notifications::Notifications(Notifications&& src) : Notifications()
	{
		*this = std::move(src);
	}

	Notifications& Notifications::operator=(Notifications&& rhs) // move assignment 
	{
		if (this != &rhs)
		{
			delete[] messages;
			maxMessages = rhs.maxMessages;
			currMessages = rhs.currMessages; 
			messages = rhs.messages;
			rhs.messages = nullptr;
			rhs.currMessages = 0u;
			rhs.maxMessages = 0u; 
		}

		return *this;
	}

	Notifications::~Notifications()
	{
	
		delete[] messages; // delete array of pointers to message objects
	}

	void Notifications::display(std::ostream& os) const
	{
		for (size_t i = 0u; i < currMessages; i++)
		{
			messages[i]->display(os);
		}
	}

	size_t Notifications::size() const
	{
		return currMessages;
	}

	Notifications& Notifications::operator+=(const Message& msg)
	{
		if ((currMessages < maxMessages) && !msg.empty())// check if space for message and message recieved is not empty
		{
			messages[currMessages++] = &msg; 
		}

		return *this;
	}

	Notifications& Notifications::operator-=(const Message& msg)
	{
		size_t index = 0u; 
		bool check = false; 
		for (size_t i = 0u; i < currMessages; i++)
		{
			if (messages[i] == &msg)
			{
				messages[i] = nullptr; 
				index = i; 
				check = true; 
			}
		}
		if (check) // check if message removed 
		{
			for (size_t i = index; i < currMessages; i++) // shift array so empty space is at the end
			{
				messages[i] = messages[i + 1];
			}

			currMessages--; // lower current messages
		}
		return *this;
	}


	std::ostream& operator<< (std::ostream& os, const Notifications& src)
	{
		src.display(os);
		return os;
	}
}