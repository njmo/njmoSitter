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

namespace event {
namespace executor {

enum ResponseStatus
{
	Status_OK,
	Status_Error,
	Status_NotDefined
};

class EventExecutor {
public:
	EventExecutor();
	virtual ResponseStatus execute(void *);
	virtual ~EventExecutor();
};

}// namespace executor
}// namespace event

#endif /* APPLICATION_EVENT_EVENTEXECUTOR_HPP_ */
