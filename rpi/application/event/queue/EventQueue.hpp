/*
 * EventQueue.hpp
 *
 *  Created on: Jun 7, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_EVENT_EVENTQUEUE_HPP_
#define APPLICATION_EVENT_EVENTQUEUE_HPP_
#include <event/queue/Event.hpp>
#include "WaitingRoom.hpp"
#include <list>
#include <thread>
#include <mutex>
#include <map>

namespace event {

class EventQueue {
public:
	static EventQueue& getInstance()
	{
		static EventQueue queue;

		return queue;
	}
	Event* pop();
	void push(Event *);
	void pushImportant(Event *);
	void * pushAndWaitForResponse(Event *);
	void * pushImportantAndWaitForResponse(Event *);
	void notifyOnResponse(Event *,queue::IWaiter &);
	void registerAsWaiter(u32,queue::IWaiter &);
	void deregister(u32);
	u32  generateUserId();
	void sendResponse(u32,void*);
private:
	EventQueue()
		: waiterCounter(102)
	{

	}
	EventQueue(EventQueue const&)      = delete;
    void operator=(EventQueue const&)  = delete;

	std::list<Event *> eventList;
	queue::WaitingRoom waitingRoom;
	u32 waiterCounter;

	std::mutex mutex;
};

} /* namespace event */

#endif /* APPLICATION_EVENT_EVENTQUEUE_HPP_ */
