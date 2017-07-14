/*
 * Nanny.hpp
 *
 *  Created on: Jul 13, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_NANNY_HPP_
#define APPLICATION_NANNY_HPP_

#include <event/core/EventMain.hpp>
#include <event/queue/EventQueue.hpp>
#include <event/responses/TestResponse.hpp>
#include <utils/timeout_generator/TimeoutGenerator.hpp>

#include <thread>
#include <iostream>

namespace app {

class Nanny {
public:
	Nanny();
	void create();
	virtual ~Nanny();
private:
	event::EventMain eventMain;
	TimeoutGenerator timeoutGenerator;
};

} /* namespace app */

#endif /* APPLICATION_NANNY_HPP_ */
