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
			event::EventQueue::getInstance().sendResponse(0,(u8*)new u32(8));
			break;
		}
		case TestEvent:
		{
			nannyLogInfo("Catched TestEvent");
			eventExecutor = new executor::TestExecutor();
			break;
		}
		default:
		{
			break;
		}
	}

	if( eventExecutor  )
	{
		Response* resp = eventExecutor->execute(event->payload);
		if(resp->status == Reponse_Ok && resp->type == WithReponse)
		{
			 event::EventQueue::getInstance().sendResponse(event->senderId,resp->data);
			 delete resp;
		}
	}
}

} /* namespace event */
