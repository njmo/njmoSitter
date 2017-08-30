/*
 * Nanny.hpp
 *
 *  Created on: Jul 13, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_NANNY_HPP_
#define APPLICATION_NANNY_HPP_
#include <interface/response/NannyResponse.hpp>
#include <interface/response/RegisterResponse.hpp>
#include <interface/response/VideoRecorderResponse.hpp>
#include <interface/response/CameraCaptureResponse.hpp>
#include <interface/data/CameraData.hpp>
#include <interface/data/MicrophoneData.hpp>
#include <event/event_data/MusicPlayerData.hpp>

#include <interface/message/RegisterUser.hpp>
#include <interface/message/NannyRequest.hpp>
#include <interface/message/NotifyRequest.hpp>
#include <interface/message/CameraRequest.hpp>

#include <event/queue/EventQueue.hpp>
#include <event/responses/TestResponse.hpp>

#include "utils/InterfaceFinder.hpp"
#include <inc/Messages.hpp>
#include <event/queue/Waiter.hpp>
#include <nanny/User.hpp>
#include <utils/Time.hpp>

// downloaded from https://github.com/nlohmann/json
#include <utils/json.hpp>
using nlohmann::json;

#include <thread>
#include <iostream>
#include <map>
#include <string>

namespace app {

class Nanny : queue::IWaiter{
public:
	Nanny();
	void create();
	void handleTimeout(Time&,u32&);
	void handleUserRegistration(void*, u32);
	void notify(void *);
	virtual ~Nanny();
private:
	bool sendVoiceRecorderCheck();
	u32 calculateStep();
  bool shouldSendCamera(Time &);
	void sendCameraCapture();
	void notifyAllRequestingUsers();
  void sendBroadcastRequest();
  void sendResponseJson( u8,  u8);

	void handleUserRequestForVoiceRecorderNotify( const NotifyRequest&, u32);
	void handleUserRequestForCaptureCamera( const CameraRequest &, u32);
  void handleUserRequesstForMusicPlayer(const MusicPlayerData &,u32);

	volatile bool isVoiceCheckRequested;
	volatile bool isCameraCheckActive;
	u32	timeVoiceLoud;
	u8 activeFps;
	u16 currentTimeStep;
	u16 sendedFps;
	std::map<u32,User> userStorage;
};

} /* namespace app */

#endif /* APPLICATION_NANNY_HPP_ */
