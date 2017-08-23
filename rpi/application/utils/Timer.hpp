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
		: start(std::chrono::high_resolution_clock::now())
	{

	}
	u32 getMilisecondPassed()
	{
    auto stop = std::chrono::high_resolution_clock::now();
		u32 msPassed = std::chrono::duration<double, std::milli>(stop-start).count();
    return msPassed;
	}
	~Timer()
	{

	}

  std::chrono::time_point<std::chrono::high_resolution_clock> start;
};

} /* namespace utils */

#endif /* APPLICATION_UTILS_TIMER_HPP_ */
