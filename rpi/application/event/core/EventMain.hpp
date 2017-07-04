/*
 * EventMain.hpp
 *
 *  Created on: Jun 7, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_EVENT_EVENTMAIN_HPP_
#define APPLICATION_EVENT_EVENTMAIN_HPP_
#include "EventHandler.hpp"
#include <event/queue/EventQueue.hpp>

namespace event {

class EventMain {
public:
	EventMain()
		:eventHandler(),
		 suspended(false),
		 stopped(false)
	{

	};

	void mainLoop();
	bool isSuspended() { return suspended; }
	void suspend() { suspended = true; }
	void wakeUp() { suspended = false; }
	bool isRunning() { return !stopped; }
	virtual ~EventMain();
private:
	EventHandler eventHandler;
	bool suspended;
	bool stopped;
};

} /* namespace event */

#endif /* APPLICATION_EVENT_EVENTMAIN_HPP_ */
