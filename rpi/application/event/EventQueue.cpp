/*
 * EventQueue.cpp
 *
 *  Created on: Jun 7, 2017
 *      Author: njmo
 */

#include "EventQueue.hpp"

namespace event {

Event* EventQueue::pop()
{
	std::lock_guard<std::mutex> lock(mutex);
	Event *event = eventList.front();
	eventList.pop_front();
	return event;
}

void EventQueue::push(Event * event)
{
	std::lock_guard<std::mutex> lock(mutex);
	eventList.push_back(event);
}

void EventQueue::pushImportant(Event * event)
{
	std::lock_guard<std::mutex> lock(mutex);
	eventList.push_front(event);
}

} /* namespace event */
