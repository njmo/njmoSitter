/*
 * Nanny.hpp
 *
 *  Created on: Jul 13, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_NANNY_HPP_
#define APPLICATION_NANNY_HPP_
#include <interface/message/NannyRequest.hpp>
#include <interface/response/NannyResponse.hpp>
#include <interface/message/RegisterUser.hpp>
#include <interface/response/RegisterResponse.hpp>
#include <interface/response/VideoRecorderResponse.hpp>
#include <interface/message/NotifyRequest.hpp>

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
	void handleTimeout(Time&);
	void handleUserRegistration(void*, u32);
	void handleUserRequestForVoiceRecorderNotify(void*,u32);
	void notify(void *);
	virtual ~Nanny();
private:
	bool sendVoiceRecorderCheck();
	void notifyAllRequestingUsers();

	volatile bool isVoiceCheckRequested;
	u32	timeVoiceLoud;
	InterfaceFinder interfaceFinder;
	std::map<u32,User> userStorage;
};

} /* namespace app */

#endif /* APPLICATION_NANNY_HPP_ */
