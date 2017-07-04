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

void EventHandler::handleEvent(Event *event)
{
	nannyLogInfo("Handled new event");
	//logInfo "handled new Event"
	executor::EventExecutor *eventExecutor = nullptr;

	switch(event->type)
	{
		case LoggerEvent:
		{
			nannyLogInfo("Cached LoggerEvent");
			break;
		}
		default:
		{
			break;
		}
	}

	if( eventExecutor && eventExecutor->execute(event->payload) != executor::Status_OK )
	{
		nannyLogInfo("Cached LoggerEvent");
	}
}

} /* namespace event */
