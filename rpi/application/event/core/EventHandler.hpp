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

#include <event/executors/TestExecutor.hpp>
#include <event/executors/MusicPlayerExecutor.hpp>
#include <event/executors/VoiceRecorderExecutor.hpp>

#include <nanny/Nanny.hpp>

namespace event {

class EventHandler {
public:
	EventHandler(app::Nanny&);
	void handleEvent(Event *);
	virtual ~EventHandler();
private:
	//message executors
	executor::TestExecutor testExecutor;
	executor::MusicPlayerExecutor musicPlayerExecutor;
	executor::VoiceRecorderExecutor voiceRecorderExecutor;
	app::Nanny &nanny;
};

} /* namespace event */

#endif /* APPLICATION_EVENT_EVENTHANDLER_HPP_ */
