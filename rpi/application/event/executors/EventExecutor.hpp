/*
 * EventExecutor.hpp
 *
 *  Created on: Jun 27, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_EVENT_EVENTEXECUTOR_HPP_
#define APPLICATION_EVENT_EVENTEXECUTOR_HPP_
#include <inc/defines.hpp>
#include <utils/Logger/Logger.hpp>
#include <event/queue/Response.hpp>

namespace event {
namespace executor {


class EventExecutor {
public:
	EventExecutor();
	virtual Response* execute(void *) = 0;
	virtual ~EventExecutor();
};

}// namespace executor
}// namespace event

#endif /* APPLICATION_EVENT_EVENTEXECUTOR_HPP_ */
