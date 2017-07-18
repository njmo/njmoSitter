/*
 * EventHandler.hpp
 *
 *  Created on: Jun 7, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_EVENT_EVENTHANDLER_HPP_
#define APPLICATION_EVENT_EVENTHANDLER_HPP_
#include <iostream>

#include <event/queue/Event.hpp>
#include <event/queue/EventQueue.hpp>

#include <event/executors/TestExecutor.hpp>
#include <event/executors/TimeoutExecutor.hpp>
#include <event/executors/MusicPlayerExecutor.hpp>

namespace event {

class EventHandler {
public:
	EventHandler();
	void handleEvent(Event *);
	virtual ~EventHandler();
private:
	//message executors
	executor::TestExecutor testExecutor;
	executor::TimeoutExecutor timeoutExecutor;
	executor::MusicPlayerExecutor musicPlayerExecutor;
};

} /* namespace event */

#endif /* APPLICATION_EVENT_EVENTHANDLER_HPP_ */
