/*
 ============================================================================
 Name        : MessagePack.cpp
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
  Implementation file for messagepack class which manages a compostion of message objects
  ============================================================================
 */
#include <iostream>
#include "MessagePack.h"

namespace sict
{
	// default constructor
	MessagePack::MessagePack()
	{
		messages = nullptr; 
		numOfMessages = 0u;
	}
	//two argument constructor
	MessagePack::MessagePack(Message** messages_, size_t size_) : MessagePack()
	{
		if (messages_ != nullptr && size_ > 0) // check is array of pointers is null and size > 0 
		{ 
			messages = new Message*[size_]; // allocate memory for array of pointers to message objects 
			for (size_t i = 0u; i < size_; i++) // loop through array of pointers and dynamically allocate memory for each message object
			{
				if (!messages_[i]->empty())
				{
					messages[numOfMessages++] = new Message(*messages_[i]); // use copy constructor to create new message object
				}
			}
		}
	}
	MessagePack& MessagePack::operator=(const MessagePack& rhs) //copy assignment operator 
	{
		if (this != &rhs)
		{
			for (size_t i = 0u; i < numOfMessages; i++)// loop through and delete each message object 
			{
				delete messages[i];
			}
			delete[] messages; // delete array of pointers to message object 
			numOfMessages = rhs.numOfMessages; 
			messages = new Message*[numOfMessages]; 
			for (size_t i = 0u; i < numOfMessages; i++)
			{
				messages[i] = new Message(*rhs.messages[i]); 
			}
		}

		return *this; 
	}

	MessagePack::MessagePack(const MessagePack& src) 
	{
		*this = src; 
	}
	MessagePack::MessagePack(MessagePack&& src) : MessagePack()
	{
		*this = std::move(src);
	}

	MessagePack& MessagePack::operator=(MessagePack&& rhs)
	{
		if (this != &rhs)
		{ 
			for (size_t i = 0u; i < numOfMessages; i++) // loop through and delete each message object 
			{
				delete messages[i]; 
			}
			delete[] messages;// delete array of pointers to message object 
			numOfMessages = rhs.numOfMessages;
			messages = rhs.messages;
			rhs.messages = nullptr; 
			rhs.numOfMessages = 0u; 
		}

		return *this;
	}

	MessagePack::~MessagePack()
	{
		for (size_t i = 0u; i < numOfMessages; i++)
		{
			delete messages[i];
		}
		delete[] messages;
	}

	void MessagePack::display(std::ostream& os) const
	{
		for (size_t i = 0u; i < numOfMessages; i++)
		{
			messages[i]->display(os); 
		}
	}

	size_t MessagePack::size() const
	{
		return numOfMessages; 
	}

	std::ostream& operator<< (std::ostream& os, const MessagePack& src)
	{
		src.display(os); 
		return os; 
	}
}