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
	suspended = true;
	stopped = false;
	nannyLogInfo("Starting MainEvent loop");
	while(isRunning())
	{
		while(isSuspended())
			;

		Event *event = EventQueue::getInstance().pop();
		if(event)
		{
			eventHandler.handleEvent(event);
			delete[] (u8*)event;
		}
	}
	nannyLogInfo("Stopping MainEvent loop");
}

} /* namespace event */
