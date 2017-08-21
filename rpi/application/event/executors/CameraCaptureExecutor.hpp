/*
 * CameraCaptureExecutor.hpp
 *
 *  Created on: Aug 21, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_EVENT_EXECUTORS_CAMERACAPTUREEXECUTOR_HPP_
#define APPLICATION_EVENT_EXECUTORS_CAMERACAPTUREEXECUTOR_HPP_
#include <inc/defines.hpp>
#include <utils/Logger/Logger.hpp>
#include <event/queue/Response.hpp>
#include <device/Camera.hpp>
#include "EventExecutor.hpp"
#include <interface/response/CameraCaptureResponse.hpp>
#include <inc/Messages.hpp>
#include <cstring>

namespace event {
namespace executor {

class CameraCaptureExecutor  : public EventExecutor {
public:
	CameraCaptureExecutor();
	Response* execute(void *);
	virtual ~CameraCaptureExecutor();

	//device::Camera camera;
};

} /* namespace executor */
} /* namespace event */

#endif /* APPLICATION_EVENT_EXECUTORS_CAMERACAPTUREEXECUTOR_HPP_ */
