/*
 * EventQueue.hpp
 *
 *  Created on: Jun 7, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_EVENT_EVENTQUEUE_HPP_
#define APPLICATION_EVENT_EVENTQUEUE_HPP_
#include <Event.hpp>
#include <list>
#include <thread>
#include <mutex>

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
private:
	EventQueue() {}
	EventQueue(EventQueue const&)      = delete;
    void operator=(EventQueue const&)  = delete;

	std::list<Event *> eventList;
	std::mutex mutex;
};

} /* namespace event */

#endif /* APPLICATION_EVENT_EVENTQUEUE_HPP_ */
