/*
 * EEventType.hpp
 *
 *  Created on: Jun 7, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_EVENT_EVENTTYPE_HPP_
#define APPLICATION_EVENT_EVENTTYPE_HPP_


namespace event {

enum EventType
{
	LoggerEvent = 99,
	MusicPlayerEvent = 9998,
	VoiceRecorderEvent,
	CameraCaptureFrame,
	DisableQueueEvent,
	NannyQuery,
	TestEvent = 0
};

}


#endif /* APPLICATION_EVENT_EVENTTYPE_HPP_ */
