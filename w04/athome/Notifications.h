/*
 ============================================================================
 Name        : Notification.h
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
  header file for Notification class which manages an aggregation of message objects
  ============================================================================
 */
#ifndef SICT_NOTIFICATIONS_H
#define SICT_NOTIFICATIONS_H

#include <iostream>
#include "Message.h"

namespace sict
{
	class Notifications
	{
		const Message** messages;
		size_t currMessages;
		size_t maxMessages; 
	public:
		Notifications();
		Notifications(size_t);
		Notifications(const Notifications&);
		Notifications& operator=(const Notifications&);
		Notifications(Notifications&&);
		Notifications& operator=(Notifications&&);
		~Notifications();
		void display(std::ostream& os) const;
		Notifications& operator+=(const Message& msg); 
		Notifications& operator-=(const Message& msg);
		size_t size() const;

	};

	std::ostream& operator<< (std::ostream&, const Notifications&);
}
#endif // !SICT_NOTIFICATIONS_H
