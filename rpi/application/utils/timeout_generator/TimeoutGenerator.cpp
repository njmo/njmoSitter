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
	u32 nextDuration = timeoutDuration;
	Time time;
	while(!stopped)
	{
		while(suspended)
			;
		std::this_thread::sleep_for(std::chrono::milliseconds(nextDuration));
		//utils::Timer timer;
    auto t_start = std::chrono::high_resolution_clock::now();
		nanny.handleTimeout(time,timeoutDuration);
	//	u32 msPassed = timer.getMilisecondPassed();
    auto t_end = std::chrono::high_resolution_clock::now();
		u32 msPassed = std::chrono::duration<double, std::milli>(t_end-t_start).count();

		if(msPassed && msPassed < timeoutDuration)
		{
			nextDuration=timeoutDuration-msPassed;
		}
		else if(msPassed)
		{
			u32 wasted = msPassed - timeoutDuration;
			nannyLogError("Wasted " + std::to_string(wasted) + " miliseconds");
			nextDuration = 0;
		}

		time+=timeoutDuration;
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

