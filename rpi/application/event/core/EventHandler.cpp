/*
 * EventHandler.cpp
 *
 *  Created on: Jun 7, 2017
 *      Author: njmo
 */

#include "EventHandler.hpp"

namespace event {

EventHandler::EventHandler() {
	// TODO Auto-generated constructor stub

}

EventHandler::~EventHandler() {
	// TODO Auto-generated destructor stub
}

void handleEvent(Event *event)
{
	//logInfo "handled new Event"
	executor::EventExecutor *eventExecutor = nullptr;

	switch(event->type)
	{
		default:
		{
			break;
		}
	}

	if( eventExecutor->execute(event->payload) != executor::Status_OK )
	{
		//logERROR
	}
}

} /* namespace event */
