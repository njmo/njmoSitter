/*
 * EventMain.cpp
 *
 *  Created on: Jun 7, 2017
 *      Author: njmo
 */

#include "EventMain.hpp"

namespace event {

EventMain::~EventMain() {
	// TODO Auto-generated destructor stub
}

void EventMain::mainLoop()
{
	while(isRunning())
	{
		while(isSuspended())
			;
		Event *event = EventQueue::getInstance().pop();
		eventHandler.handleEvent(event);
		delete event;
	}
}

} /* namespace event */
