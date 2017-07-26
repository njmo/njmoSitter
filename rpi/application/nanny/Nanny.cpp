/*
 * Nanny.cpp
 *
 *  Created on: Jul 13, 2017
 *      Author: njmo
 */

#include "Nanny.hpp"
#include <event/event_data/MusicPlayerData.hpp>
#include <event/event_data/TestData.hpp>


namespace app {

Nanny::Nanny()
	:	isVoiceCheckRequested(false),
		timeVoiceLoud(0)
{
	nannyLogInfo("Nanny created");
}

Nanny::~Nanny() {
	nannyLogInfo("eventMain and  timeoutGenerator killed");
}

void Nanny::create()
{
	interfaceFinder.init("enp0s8");
	event::EventQueue::getInstance().registerAsWaiter(NANNY_ID,*this);
}

void Nanny::notify(void * ev)
{
	nannyLogInfo("Nanny is notified");
	freed(ev);
}
void Nanny::handleTimeout(Time &time)
{
	if(time.getMilisecond() == 0)
	{
		if((time.getSecond() % 1 )== 0)
		{
			if( isVoiceCheckRequested && sendVoiceRecorderCheck() )
			{
				if (++timeVoiceLoud > 5)
				{
					notifyAllRequestingUsers();
					isVoiceCheckRequested = false;
					timeVoiceLoud = 0;
				}
			}
			else
				timeVoiceLoud = 0;
		}
	}
}
void Nanny::handleUserRegistration(void* resp,u32 assignedId)
{
	RegisterResponse* response = reinterpret_cast<RegisterResponse*>(resp);
	nannyLogInfo("Nanny is notified to register user" + std::to_string(assignedId));

	response->registerStatus = static_cast<u8>(RegisterStatus::registered);
	response->assignedId = assignedId;

	userStorage.emplace(assignedId,User(assignedId));
}
void Nanny::handleUserRequestForVoiceRecorderNotify(void *req,u32 userId)
{
	NotifyRequest* r = reinterpret_cast<NotifyRequest*>(req);
	User &user = userStorage.find(userId)->second;
	nannyLogInfo("Nanny is notified by user" + std::to_string(user.getId()));
	nannyLogInfo(std::to_string(r->notifyType));
	if(r->notifyType == static_cast<u8>(NotifyRequestType::registerNotify))
	{
		user.registerForVoiceRecorderNotify();
		isVoiceCheckRequested = true;
		nannyLogInfo(std::to_string(isVoiceCheckRequested));
	}
	else
	{
		user.unRegisterForVoiceRecorderNotify();
	}
}
void Nanny::notifyAllRequestingUsers()
{
	NannyResponse* vrResponse = reinterpret_cast<NannyResponse*>(allocateNanny<NannyResponse,TestData>());
	vrResponse->size = 15;
	std::map<u32,User>::iterator it;
	for ( it = userStorage.begin(); it != userStorage.end(); it++ )
	{
		User &user = it->second;
		if ( user.hasRequestedForVoiceRecorderNotify())
		{
			nannyLogInfo("Nanny is notyfing user" + std::to_string(user.getId()));
			vrResponse->id = user.getId();
			user.unRegisterForVoiceRecorderNotify();
			event::EventQueue::getInstance().sendResponse(user.getId(),vrResponse);
		}
	}
	delete vrResponse;
}
bool Nanny::sendVoiceRecorderCheck()
{
	event::Event* checkVR = reinterpret_cast<event::Event*>(allocate<TestData>());
	checkVR->senderId = NANNY_ID;
	checkVR->type = event::EventType::VoiceRecorderEvent;

	VideoRecorderResponse * response = reinterpret_cast<VideoRecorderResponse *>(event::EventQueue::getInstance().pushImportantAndWaitForResponse(checkVR));
	if( response->state == VideoRecorderState::Loud )
	{
		freed(response);
		return true;
	}
	freed(response);
	return false;
}

} /* namespace app */
