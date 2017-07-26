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
#include <nanny/Nanny.hpp>
#include <thread>
#include <chrono>
#include <utils/Timer.hpp>
#include <utils/Time.hpp>

class TimeoutGenerator : public std::thread{
public:
	TimeoutGenerator(u32 duration,app::Nanny&);
	void generateTimeouts();
	virtual ~TimeoutGenerator();
	void suspend();
	void wakeUp();
	void kill();
private:
	volatile bool suspended;
	volatile bool stopped;
	u32 timeoutDuration;
	app::Nanny &nanny;
};

#endif /* APPLICATION_UTILS_TIMEOUT_GENERATOR_TIMEOUTGENERATOR_HPP_ */
