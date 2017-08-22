/*
 * Timer.hpp
 *
 *  Created on: Jul 26, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_UTILS_TIMER_HPP_
#define APPLICATION_UTILS_TIMER_HPP_
#include <chrono>

namespace utils {

class Timer {
public:
	Timer()
		:timeStarted(std::clock())
	{

	}
	u32 getMilisecondPassed()
	{
		return ( 1000 * ((float)clock() - timeStarted)) / CLOCKS_PER_SEC ;
	}
	~Timer()
	{

	}
	clock_t timeStarted;
};

} /* namespace utils */

#endif /* APPLICATION_UTILS_TIMER_HPP_ */
