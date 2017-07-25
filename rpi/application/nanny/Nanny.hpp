/*
 * Nanny.hpp
 *
 *  Created on: Jul 13, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_NANNY_HPP_
#define APPLICATION_NANNY_HPP_

#include <event/queue/EventQueue.hpp>
#include <event/responses/TestResponse.hpp>
#include <interface/message/RegisterUser.hpp>

#include "utils/InterfaceFinder.hpp"
#include <inc/Messages.hpp>
#include <event/queue/Waiter.hpp>
#include <nanny/User.hpp>

#include <thread>
#include <iostream>
#include <map>

namespace app {

class Nanny : queue::IWaiter{
public:
	Nanny();
	void create();
	void handleTimeout();
	void sendEvent();
	void handleUserRegistration(RegisterUser *);
	void notify(void *);
	virtual ~Nanny();
private:
	InterfaceFinder interfaceFinder;
	std::map<u32,User> userStorage;
};

} /* namespace app */

#endif /* APPLICATION_NANNY_HPP_ */
