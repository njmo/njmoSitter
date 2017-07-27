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
#include <interface/data/CameraData.hpp>

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

#include <thread>
#include <iostream>
#include <map>

namespace app {

class Nanny : queue::IWaiter{
public:
	Nanny();
	void create();
	void handleTimeout(Time&,u32&);
	void handleUserRegistration(void*, u32);
	void handleUserRequestForVoiceRecorderNotify(void*,u32);
	void handleUserRequestForCaptureCamera(void*,u32);
	void notify(void *);
	virtual ~Nanny();
private:
	bool sendVoiceRecorderCheck();
	u32 calculateStep();
	void sendCameraCapture();
	void notifyAllRequestingUsers();

	volatile bool isVoiceCheckRequested;
	volatile bool isCameraCheckActive;
	u32	timeVoiceLoud;
	u8 activeFps;
	u16 currentTimeStep;
	u16 sendedFps;
	InterfaceFinder interfaceFinder;
	std::map<u32,User> userStorage;
};

} /* namespace app */

#endif /* APPLICATION_NANNY_HPP_ */
