/*
 ============================================================================
 Name        : MessagePack.h
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
  header file for messagepack class which manages a compostion of message objects
  ============================================================================
 */
#ifndef SICT_MESSAGEPACK_H
#define SICT_MESSAGEPACK_H

#include <iostream>
#include "Message.h"

namespace sict
{
	class MessagePack
	{
		Message** messages; 
		size_t numOfMessages; 
	public: 
		MessagePack(); 
		MessagePack(Message**, size_t); 
		MessagePack(const MessagePack&); 
		MessagePack& operator=(const MessagePack&); 
		MessagePack(MessagePack&&); 
		MessagePack& operator=(MessagePack&&); 
		~MessagePack(); 
		void display(std::ostream& os) const; 
		size_t size() const;
	
	};

	std::ostream& operator<< (std::ostream&, const MessagePack&);
}
#endif // !SICT_MESSAGEPACK_H
