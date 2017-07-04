/*
 * TestExecutor.hpp
 *
 *  Created on: Jun 27, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_EVENT_EXECUTORS_TESTEXECUTOR_TESTEXECUTOR_HPP_
#define APPLICATION_EVENT_EXECUTORS_TESTEXECUTOR_TESTEXECUTOR_HPP_
#include <EventExecutor.hpp>

namespace event {
namespace executor {

class TestExecutor : public EventExecutor {
public:
	TestExecutor();
	void* execute(void *);
	virtual ~TestExecutor();
};

} /* namespace event */

#endif /* APPLICATION_EVENT_EXECUTORS_TESTEXECUTOR_TESTEXECUTOR_HPP_ */
