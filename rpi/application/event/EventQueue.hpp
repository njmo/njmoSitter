/*
 * EventQueue.hpp
 *
 *  Created on: Jun 7, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_EVENT_EVENTQUEUE_HPP_
#define APPLICATION_EVENT_EVENTQUEUE_HPP_
#include <Event.hpp>

namespace event {

class EventQueue {
public:
	EventQueue();
	Event* popEvent();
	virtual ~EventQueue();
};

} /* namespace event */

#endif /* APPLICATION_EVENT_EVENTQUEUE_HPP_ */
