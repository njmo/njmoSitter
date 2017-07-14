/*
 * TimeoutGenerator.hpp
 *
 *  Created on: Jul 14, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_UTILS_TIMEOUT_GENERATOR_TIMEOUTGENERATOR_HPP_
#define APPLICATION_UTILS_TIMEOUT_GENERATOR_TIMEOUTGENERATOR_HPP_
#include <inc/defines.hpp>
#include <event/queue/EventQueue.hpp>
#include <event/event_data/TimeoutData.hpp>
#include <thread>
#include <chrono>

class TimeoutGenerator : public std::thread{
public:
	TimeoutGenerator(u32 duration);
	void generateTimeouts();
	virtual ~TimeoutGenerator();
private:
	bool suspended;
	bool stopped;
	u32 timeoutDuration;
};

#endif /* APPLICATION_UTILS_TIMEOUT_GENERATOR_TIMEOUTGENERATOR_HPP_ */
