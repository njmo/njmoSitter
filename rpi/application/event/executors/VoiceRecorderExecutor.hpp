/*
 * VoiceRecorderExecutor.hpp
 *
 *  Created on: Jul 26, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_EVENT_EXECUTORS_VOICERECORDEREXECUTOR_HPP_
#define APPLICATION_EVENT_EXECUTORS_VOICERECORDEREXECUTOR_HPP_
#include "EventExecutor.hpp"
#include <event/responses/TestResponse.hpp>
#include <inc/Messages.hpp>
#include <interface/response/VideoRecorderResponse.hpp>

namespace event {
namespace executor {

class VoiceRecorderExecutor  : public EventExecutor {
public:
	VoiceRecorderExecutor();
	Response* execute(void *);
	virtual ~VoiceRecorderExecutor();
};

} /* namespace executor */
} /* namespace event */

#endif /* APPLICATION_EVENT_EXECUTORS_VOICERECORDEREXECUTOR_HPP_ */
