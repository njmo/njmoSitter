/*
 * TestExecutor.hpp
 *
 *  Created on: Jun 27, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_EVENT_EXECUTORS_TESTEXECUTOR_TESTEXECUTOR_HPP_
#define APPLICATION_EVENT_EXECUTORS_TESTEXECUTOR_TESTEXECUTOR_HPP_
#include "EventExecutor.hpp"
#include <event/responses/TestResponse.hpp>
#include <inc/Messages.hpp>

namespace event {
namespace executor {

class TestExecutor : public EventExecutor {
public:
	TestExecutor();
	Response* execute(void *);
	virtual ~TestExecutor();
};

} /* namespace event */
} /* namespace executor */

#endif /* APPLICATION_EVENT_EXECUTORS_TESTEXECUTOR_TESTEXECUTOR_HPP_ */
