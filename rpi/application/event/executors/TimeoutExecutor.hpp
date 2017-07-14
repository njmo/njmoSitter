/*
 * TimeoutExecutor.hpp
 *
 *  Created on: Jul 14, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_EVENT_EXECUTORS_TIMEOUTEXECUTOR_HPP_
#define APPLICATION_EVENT_EXECUTORS_TIMEOUTEXECUTOR_HPP_
#include "EventExecutor.hpp"
#include <event/queue/Response.hpp>
#include <utils/Logger/Logger.hpp>

namespace event {
namespace executor {

class TimeoutExecutor : public EventExecutor{
public:
	TimeoutExecutor();
	Response* execute(void *);
	virtual ~TimeoutExecutor();
};

}
}
#endif /* APPLICATION_EVENT_EXECUTORS_TIMEOUTEXECUTOR_HPP_ */
