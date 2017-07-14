/*
 * TimeoutGenerator.cpp
 *
 *  Created on: Jul 14, 2017
 *      Author: njmo
 */

#include "TimeoutGenerator.hpp"

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
		std::this_thread::sleep_for(std::chrono::milliseconds(timeoutDuration));
		event::Event *timeoutEvent = new event::Event;
		timeoutEvent->type = event::TimeoutEvent;
		TimeoutData *data = new TimeoutData;
		data->a = a++;
		data->b = b++;
		timeoutEvent->payload = reinterpret_cast<u8 *>(data);
		event::EventQueue::getInstance().push(timeoutEvent);
	}
}

TimeoutGenerator::~TimeoutGenerator() {
	// TODO Auto-generated destructor stub
}

