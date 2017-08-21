/*
 * Nanny.cpp
 *
 *  Created on: Jul 13, 2017
 *      Author: njmo
 */

#include "Nanny.hpp"
#include <event/event_data/MusicPlayerData.hpp>
#include <event/event_data/TestData.hpp>

#define ONE_SECOND_IN_MILISECOND 1000
namespace app {

Nanny::Nanny()
	:	isVoiceCheckRequested(false),
		timeVoiceLoud(0),
		isCameraCheckActive(false),
		activeFps(0),
		currentTimeStep(500),
		sendedFps(0)
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
void Nanny::handleTimeout(Time &time,u32 &duration)
{
	if( isCameraCheckActive && ( time.getMilisecond() % (ONE_SECOND_IN_MILISECOND/activeFps) == 0))
	{
		sendCameraCapture();
		sendedFps++;
	}
	if(time.getMilisecond() == 0)
	{
		if((time.getSecond() % 1 )== 0)
		{
			if( isCameraCheckActive )
			{
				nannyLogInfo("Sending with fps: " + std::to_string(sendedFps));
				sendedFps = 0;
			}
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
	nannyLogInfo("Received UserRegistration message, assigned user id " + std::to_string(assignedId));

	response->registerStatus = static_cast<u8>(RegisterStatus::registered);
	response->assignedId = assignedId;

	userStorage.emplace(assignedId,User(assignedId));
}
void Nanny::handleUserRequestForVoiceRecorderNotify(void *req,u32 userId)
{
	NotifyRequest* r = reinterpret_cast<NotifyRequest*>(req);
	User &user = userStorage.find(userId)->second;
	nannyLogInfo("Received VoiceRecorderNotify message " + std::to_string(user.getId()));
	nannyLogInfo(std::to_string(r->notifyType));
	if(r->notifyType == static_cast<u8>(NotifyRequestType::registerNotify))
	{
		user.registerForVoiceRecorderNotify();
		isVoiceCheckRequested = true;
	}
	else
	{
		user.unRegisterForVoiceRecorderNotify();
	}
}
void Nanny::handleUserRequestForCaptureCamera(void *req,u32 userId)
{
	CameraRequest* r = reinterpret_cast<CameraRequest*>(req);
	User &user = userStorage.find(userId)->second;
	nannyLogInfo("Received CameraCapture message from user " + std::to_string(user.getId()));
	if(r->cameraType == static_cast<u8>(CameraRequestType::registerForCamera))
	{
		user.registerForCamera();
		user.setFps(r->fps);
		isCameraCheckActive = true;
		activeFps = r->fps;
	}
	else if(r->cameraType == static_cast<u8>(CameraRequestType::deregisterForCamera))
	{
		user.unRegisterForVoiceRecorderNotify();
		user.setFps(0);
		isCameraCheckActive = false;
		activeFps = 0;
	}
	else if(r->cameraType == static_cast<u8>(CameraRequestType::changeFps))
	{
		user.setFps(r->fps);
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
			nannyLogInfo("Sending notification to user " + std::to_string(user.getId()));
			vrResponse->id = user.getId();
			user.unRegisterForVoiceRecorderNotify();
			event::EventQueue::getInstance().sendResponse(user.getId(),vrResponse);
		}
	}
	delete vrResponse;
}
void Nanny::sendCameraCapture()
{
	event::Event* checkVR = reinterpret_cast<event::Event*>(allocate<TestData>());
	checkVR->senderId = NANNY_ID;
	checkVR->type = event::EventType::CameraCaptureFrame;
	CameraCaptureResponse * response = reinterpret_cast<CameraCaptureResponse *>(event::EventQueue::getInstance().pushImportantAndWaitForResponse(checkVR));

	NannyResponse* vrResponse = reinterpret_cast<NannyResponse*>(allocateNanny<NannyResponse,CameraData>());
	vrResponse->size = response->size*4;
  //nannyLogInfo("Size of message " + std::to_string(vrResponse->size);
	memcpy(vrResponse->data,response->frame,response->size);

	std::map<u32,User>::iterator it;
	for ( it = userStorage.begin(); it != userStorage.end(); it++ )
	{
		User &user = it->second;
		if ( user.hasRequestedForCamera())
		{
			//nannyLogInfo("Sending camera frame to user " + std::to_string(user.getId()));
			vrResponse->id = user.getId();
			user.unRegisterForVoiceRecorderNotify();
			event::EventQueue::getInstance().sendResponse(user.getId(),vrResponse);
		}
	}
	//delete vrResponse;
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
