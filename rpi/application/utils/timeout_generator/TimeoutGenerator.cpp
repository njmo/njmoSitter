/*
 * TimeoutGenerator.cpp
 *
 *  Created on: Jul 14, 2017
 *      Author: njmo
 */

#include "TimeoutGenerator.hpp"
#include <inc/Messages.hpp>

TimeoutGenerator::TimeoutGenerator(u32 duration,app::Nanny &_n)
	: std::thread(&TimeoutGenerator::generateTimeouts, this),
	  nanny(_n),
	  suspended(true),
	  stopped(false),
	  timeoutDuration(duration)
{
	// TODO Auto-generated constructor stub

}

void TimeoutGenerator::generateTimeouts()
{
	int i=0;
	while(!stopped)
	{
		while(suspended)
			;
		std::this_thread::sleep_for(std::chrono::milliseconds(timeoutDuration));

		/*event::Event *timeoutEvent = reinterpret_cast<event::Event*>(allocate<TimeoutData>());
		timeoutEvent->type = event::TimeoutEvent;
		TimeoutData &tmData = reinterpret_cast<TimeoutData&>(timeoutEvent->payload);
		tmData.a = a++;
		tmData.b = b++;*/
		i++;
		if(i > 10)
			break;
		nanny.handleTimeout();
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	nannyLogInfo("registering nanny");
	nanny.sendEvent();
}
void TimeoutGenerator::suspend()
{
	suspended = true;
}
void TimeoutGenerator::wakeUp()
{
	suspended = false;
}
void TimeoutGenerator::kill()
{
	stopped = true;
}
TimeoutGenerator::~TimeoutGenerator() {
	nannyLogInfo("timeoutGenerator killed");
}

