/*
 * EventHandler.cpp
 *
 *  Created on: Jun 7, 2017
 *      Author: njmo
 */

#include "EventHandler.hpp"

namespace event {

EventHandler::EventHandler(app::Nanny &_n)
	:	nanny(_n)
{
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
		case TimeoutEvent:
		{
			nannyLogInfo("Catched TimeoutEvent");
			break;
		}
		case MusicPlayerEvent:
		{
			nannyLogInfo("Catched MusicPlayerEvent");
			eventExecutor = reinterpret_cast<executor::EventExecutor *>(&musicPlayerExecutor);
			break;
		}
		case VoiceRecorderEvent:
		{
			nannyLogInfo("Catched VoiceRecorderEvent");
			eventExecutor = reinterpret_cast<executor::EventExecutor *>(&voiceRecorderExecutor);
			break;
		}
		case NannyQuery:
		{
			NannyRequest* nreq = reinterpret_cast<NannyRequest*>(event);
			nannyLogInfo("Catched NannyQuery" + std::to_string(nreq->queryType));

			switch(static_cast<NannyRequestType>(nreq->queryType)) // == static_cast<u8>(NannyRequestType::Register))
			{
				case NannyRequestType::Register:
				{
					nannyLogInfo("Handled user registration query");

					NannyResponse* nr = reinterpret_cast<NannyResponse*>(allocateNanny<RegisterResponse,NannyResponse>());
					nr->size = sizeof(RegisterResponse);

					nanny.handleUserRegistration(nr->data,event::EventQueue::getInstance().generateUserId());

					event::EventQueue::getInstance().sendResponse(event->senderId,nr);
					break;
				}
				case NannyRequestType::NotifyWhenStartCrying:
				{
					nanny.handleUserRequestForVoiceRecorderNotify(nreq->payload,nreq->senderId);
					//NannyResponse* nr = reinterpret_cast<NannyResponse*>(allocateNanny<NoResponseData,NannyResponse>());
					break;
				}
			}
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
		else
		{
			delete resp;
		}
	}
}

} /* namespace event */
