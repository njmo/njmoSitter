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
	Event *event = nullptr;
	if(!eventList.empty())
	{
		event = eventList.front();
		eventList.pop_front();
	}
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

void * EventQueue::pushAndWaitForResponse(Event *event)
{
	push(event);
	queue::Waiter waiter;
	nannyLogInfo("Creating new Waiter id " + std::to_string(waiterCounter));
	event->senderId = waiterCounter;
	waitingRoom.registerWaiter(waiterCounter++,waiter);
	void *response =  waiter.waitForResponse();
	return response;
}
void EventQueue::sendResponse(u32 sender,void* data)
{
	waitingRoom.notifyWaiter(sender,data);
}

} /* namespace event */
