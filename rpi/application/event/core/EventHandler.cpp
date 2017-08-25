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
	executor::EventExecutor *eventExecutor = nullptr;

	switch(event->type)
	{
		case LoggerEvent:
		{
			break;
		}
    case Broadcast:
    {
      broadcaster.broadcastNannyAddress();
      break;
    }
		case MusicPlayerEvent:
		{
			eventExecutor = reinterpret_cast<executor::EventExecutor *>(&musicPlayerExecutor);
			break;
		}
		case VoiceRecorderEvent:
		{
			eventExecutor = reinterpret_cast<executor::EventExecutor *>(&voiceRecorderExecutor);
			break;
		}
		case CameraCaptureFrame:
		{
			eventExecutor = reinterpret_cast<executor::EventExecutor *>(&cameraCaptureExecutor);
			break;
		}
		case NannyQuery:
		{
			handleNanny(*reinterpret_cast<NannyRequest*>(event));
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

void EventHandler::handleNanny(NannyRequest &nannyRequest)
{
	switch(static_cast<NannyRequestType>(nannyRequest.queryType)) // == static_cast<u8>(NannyRequestType::Register))
	{
		case NannyRequestType::Register:
		{
			NannyResponse* nr = reinterpret_cast<NannyResponse*>(allocateNanny<RegisterResponse,NannyResponse>());
			nr->size = sizeof(RegisterResponse);

			nanny.handleUserRegistration(nr->data,event::EventQueue::getInstance().generateUserId());

			event::EventQueue::getInstance().sendResponse(nannyRequest.senderId,nr);
			break;
		}
		case NannyRequestType::NotifyWhenStartCrying:
		{
			nanny.handleUserRequestForVoiceRecorderNotify(nannyRequest.payload,nannyRequest.senderId);
			//NannyResponse* nr = reinterpret_cast<NannyResponse*>(allocateNanny<NoResponseData,NannyResponse>());
			break;
		}
		case NannyRequestType::CaptureCamera:
		{
			nanny.handleUserRequestForCaptureCamera(nannyRequest.payload,nannyRequest.senderId);
			//NannyResponse* nr = reinterpret_cast<NannyResponse*>(allocateNanny<NoResponseData,NannyResponse>());
			break;
		}
	}
}

} /* namespace event */
