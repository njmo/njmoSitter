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
	executor::EventExecutor *eventExecutor = nullptr;

	switch(event->type)
	{
		case LoggerEvent:
		{
			nannyLogInfo("Catched LoggerEvent");
			break;
		}
		case TestEvent:
		{
			nannyLogInfo("Catched TestEvent");
			eventExecutor = reinterpret_cast<executor::EventExecutor *>(&testExecutor);
			break;
		}
		case TimeoutEvent:
		{
			nannyLogInfo("Catched TimeoutEvent");
			eventExecutor = reinterpret_cast<executor::EventExecutor *>(&timeoutExecutor);
			break;
		}
		case MusicPlayerEvent:
		{
			nannyLogInfo("Catched MusicPlayerEvent");
			eventExecutor = reinterpret_cast<executor::EventExecutor *>(&musicPlayerExecutor);
			break;
		}
		default:
		{
			break;
		}
	}

	if( eventExecutor )
	{
		Response* resp = eventExecutor->execute(event->payload);
		if(resp->status == Reponse_Ok && resp->type == WithReponse)
		{
			 event::EventQueue::getInstance().sendResponse(event->senderId,resp->data);
		}
	}
}

} /* namespace event */
