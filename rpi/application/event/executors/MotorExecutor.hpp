/*
 * MotorExecutor.hpp
 *
 *  Created on: Aug 21, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_EVENT_EXECUTORS_MOTOREXECUTOR_HPP_
#define APPLICATION_EVENT_EXECUTORS_MOTOREXECUTOR_HPP_
#include <inc/defines.hpp>
#include <utils/Logger/Logger.hpp>
#include <event/queue/Response.hpp>
#include <inc/Messages.hpp>
#include <device/Motor.hpp>
#include <interface/message/MotorRequest.hpp>

#include "EventExecutor.hpp"

namespace event {
namespace executor {

class MotorExecutor  : public EventExecutor {
public:
	MotorExecutor();
	Response* execute(void *);
	virtual ~MotorExecutor();
private:
  device::Motor motor;

};

} /* namespace executor */
} /* namespace event */

#endif /* APPLICATION_EVENT_EXECUTORS_MOTOREXECUTOR_HPP_ */
