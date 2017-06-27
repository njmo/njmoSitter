/*
 * EventHandler.hpp
 *
 *  Created on: Jun 7, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_EVENT_EVENTHANDLER_HPP_
#define APPLICATION_EVENT_EVENTHANDLER_HPP_
#include <Event.hpp>
#include <executors/EventExecutor.hpp>

#include <iostream>
namespace event {

class EventHandler {
public:
	EventHandler();
	void handleEvent(Event *);
	virtual ~EventHandler();
};

} /* namespace event */

#endif /* APPLICATION_EVENT_EVENTHANDLER_HPP_ */
