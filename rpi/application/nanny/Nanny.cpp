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

bool Nanny::shouldSendCamera(Time &time)
{
  

}

void Nanny::create()
{
	event::EventQueue::getInstance().registerAsWaiter(NANNY_ID,*this);
}

void Nanny::notify(void * ev)
{
  json* j = reinterpret_cast<json*>(ev);
  int nannyType_present = j->count("nannyType");
  int id_present = j->count("id");
  nannyLogInfo("Received json : " + j->dump() ) ;

  if( nannyType_present == 1 && id_present == 1)
  {
    int type = j->operator[]("nannyType").get<int>();
    int id = j->operator[]("id").get<int>();
	  nannyLogInfo("Nanny is notified by user " + std::to_string(id) + " request type: " + std::to_string(type));
	  switch(static_cast<NannyRequestType>(type)) // == static_cast<u8>(NannyRequestType::Register))
    {
      case NannyRequestType::NotifyWhenStartCrying:
      {
        int notifyType_present = j->count("notifyType");
        handleUserRequestForVoiceRecorderNotify({j->operator[]("notifyType").get<u8>()},id);
        //NannyResponse* nr = reinterpret_cast<NannyResponse*>(allocateNanny<NoResponseData,NannyResponse>());
        break;
      }
      case NannyRequestType::CaptureCamera:
      {
        int cameraType_present = j->count("cameraType");
        int fps_present = j->count("fps");
        if ( cameraType_present == 1 && fps_present == 1 )
          handleUserRequestForCaptureCamera({j->operator[]("cameraType").get<u8>(),
                                             j->operator[]("fps").get<u8>()},
                                            id);
        //NannyResponse* nr = reinterpret_cast<NannyResponse*>(allocateNanny<NoResponseData,NannyResponse>());
        break;
      }
    }
  }

  delete j;
}

void Nanny::sendBroadcastRequest()
{
	event::Event* broadcastEvent= reinterpret_cast<event::Event*>(allocate<TestData>());
	broadcastEvent->type = event::EventType::Broadcast;
	event::EventQueue::getInstance().push(broadcastEvent);
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
      sendBroadcastRequest();
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
  response->nannyId = NANNY_ID;

	userStorage.emplace(assignedId,User(assignedId));
}
void Nanny::handleUserRequestForVoiceRecorderNotify(const NotifyRequest& notifyRequest,u32 userId)
{
	User &user = userStorage.find(userId)->second;
	nannyLogInfo("Received VoiceRecorderNotify message " + std::to_string(user.getId()) + " notify type " + 
               std::to_string(notifyRequest.notifyType));
	if(notifyRequest.notifyType == static_cast<u8>(NotifyRequestType::registerNotify))
	{
		user.registerForVoiceRecorderNotify();
		isVoiceCheckRequested = true;
	}
	else
	{
		user.unRegisterForVoiceRecorderNotify();
	}
}
void Nanny::handleUserRequestForCaptureCamera(const CameraRequest &cameraRequest,u32 userId)
{
	User &user = userStorage.find(userId)->second;
	nannyLogInfo("Received CameraCapture message from user " + std::to_string(user.getId()));
	if(cameraRequest.cameraType == static_cast<u8>(CameraRequestType::registerForCamera))
	{
		user.registerForCamera();
		user.setFps(cameraRequest.fps);
		isCameraCheckActive = true;
		activeFps = cameraRequest.fps;
	}
	else if(cameraRequest.cameraType == static_cast<u8>(CameraRequestType::deregisterForCamera))
	{
		user.unRegisterForVoiceRecorderNotify();
		user.setFps(0);
		isCameraCheckActive = false;
		activeFps = 0;
	}
	else if(cameraRequest.cameraType == static_cast<u8>(CameraRequestType::changeFps))
	{
		user.setFps(cameraRequest.fps);
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
	vrResponse->size = response->size;

	memcpy(vrResponse->data,response->frame,response->size);
  freed(response);

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
