/*
 * EventHandler.hpp
 *
 *  Created on: Jun 7, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_EVENT_EVENTHANDLER_HPP_
#define APPLICATION_EVENT_EVENTHANDLER_HPP_
#include <iostream>
#include <inc/Messages.hpp>

#include <event/queue/Event.hpp>
#include <event/queue/EventQueue.hpp>

#include <event/executors/MusicPlayerExecutor.hpp>
#include <event/executors/VoiceRecorderExecutor.hpp>
#include <event/executors/CameraCaptureExecutor.hpp>
#include <event/executors/MotorExecutor.hpp>
#include <utils/Broadcaster.hpp>

#include <nanny/Nanny.hpp>

namespace event {

class EventHandler {
public:
	EventHandler(app::Nanny&);
	void handleEvent(Event *);
	void handleNanny(NannyRequest &);
	virtual ~EventHandler();
private:
	//message executors
	executor::MusicPlayerExecutor musicPlayerExecutor;
	executor::CameraCaptureExecutor cameraCaptureExecutor;
	executor::VoiceRecorderExecutor voiceRecorderExecutor;
	executor::MotorExecutor motorExecutor;

  Broadcaster broadcaster;
	app::Nanny &nanny;
};

} /* namespace event */

#endif /* APPLICATION_EVENT_EVENTHANDLER_HPP_ */
