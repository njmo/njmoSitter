/*
 * Nanny.cpp
 *
 *  Created on: Jul 13, 2017
 *      Author: njmo
 */

#include "Nanny.hpp"
#include <event/event_data/MusicPlayerData.hpp>
#include <event/event_data/TestData.hpp>

namespace app {

Nanny::Nanny()
{
	nannyLogInfo("Nanny created");
}

Nanny::~Nanny() {
	nannyLogInfo("eventMain and  timeoutGenerator killed");
}

void Nanny::create()
{
	interfaceFinder.init("enp0s8");
}
void Nanny::sendEvent()
{
	nannyLogInfo("Nanny is registering for status");
	event::Event *nanny = reinterpret_cast<event::Event*>(allocate<TestData>());
	nanny->type = static_cast<event::EventType>(event::TestEvent);
	nanny->senderId=999;

	nannyLogInfo("Nanny is goint to register");
	event::EventQueue::getInstance().notifyOnResponse(nanny,*this);
	nannyLogInfo("Nanny is registered");
}
void Nanny::notify(void * ev)
{
	nannyLogInfo("Nanny is notified");
	freed(ev);
}
void Nanny::handleTimeout()
{
	event::Event *musicPlayerEvent = reinterpret_cast<event::Event*>(allocate<MusicPlayerData>());
	musicPlayerEvent->type = static_cast<event::EventType>(9998);
	MusicPlayerData &mpData = reinterpret_cast<MusicPlayerData&>(musicPlayerEvent->payload);
	mpData.songId = 23;
	mpData.type = MusicPlayerRequestType::stopMusic;
	event::EventQueue::getInstance().push(musicPlayerEvent);

	for(int i = 0;i< 1;i++)
	{
		event::Event *testEvent = reinterpret_cast<event::Event*>(allocate<TestData>());
		testEvent->type=static_cast<event::EventType>(0);
		TestResponse *resp = reinterpret_cast<TestResponse *>(event::EventQueue::getInstance().pushAndWaitForResponse(testEvent));
		std::cout << "A: " << resp->a << " b: " << resp->b << std::endl;
		freed(resp);
	}
}

} /* namespace app */
