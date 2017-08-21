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
#include <nanny/Nanny.hpp>
#include <thread>

namespace event {

class EventMain : public std::thread {
public:
	EventMain(app::Nanny& n)
		:std::thread(&EventMain::mainLoop, this),
		 eventHandler(n),
		 suspended(true),
		 stopped(false)
	{

	};

	void mainLoop();
	bool isSuspended() { return suspended; nannyLogInfo("suspended");}
	void suspend() { suspended = true; nannyLogInfo("Going to sleep"); }
	void kill(){ stopped = true; nannyLogInfo("received kill command"); }
	void wakeUp() { suspended = false; nannyLogInfo("wake up");}
	bool isRunning() { return !stopped; }
	virtual ~EventMain();
private:
	EventHandler eventHandler;
	volatile bool suspended;
	volatile bool stopped;
};

} /* namespace event */

#endif /* APPLICATION_EVENT_EVENTMAIN_HPP_ */
