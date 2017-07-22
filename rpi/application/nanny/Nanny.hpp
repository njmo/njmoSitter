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

#include "utils/InterfaceFinder.hpp"
#include <inc/Messages.hpp>

#include <thread>
#include <iostream>

namespace app {

class Nanny {
public:
	Nanny();
	void create();
	void handleTimeout();
	virtual ~Nanny();
private:
	InterfaceFinder interfaceFinder;
};

} /* namespace app */

#endif /* APPLICATION_NANNY_HPP_ */
