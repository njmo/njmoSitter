/*
 * TimeoutGenerator.cpp
 *
 *  Created on: Jul 14, 2017
 *      Author: njmo
 */

#include "TimeoutGenerator.hpp"
#include <inc/Messages.hpp>

TimeoutGenerator::TimeoutGenerator(u32 duration)
	: std::thread(&TimeoutGenerator::generateTimeouts, this),
	  suspended(true),
	  stopped(false),
	  timeoutDuration(duration)
{
	// TODO Auto-generated constructor stub

}

void TimeoutGenerator::generateTimeouts()
{
	u32 a = 0;
	u32 b = 2;
	while(!stopped)
	{
		while(suspended)
			;
		std::this_thread::sleep_for(std::chrono::milliseconds(timeoutDuration));

		event::Event *timeoutEvent = reinterpret_cast<event::Event*>(allocate<TimeoutData>());
		timeoutEvent->type = event::TimeoutEvent;
		TimeoutData &tmData = reinterpret_cast<TimeoutData&>(timeoutEvent->payload);
		tmData.a = a++;
		tmData.b = b++;

		event::EventQueue::getInstance().push(timeoutEvent);
	}
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

