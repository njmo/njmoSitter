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
	: timeoutGenerator(2000)
{
	nannyLogInfo("Nanny created");
}

Nanny::~Nanny() {
	eventMain.kill();
	timeoutGenerator.kill();
	eventMain.join();
	timeoutGenerator.join();
	nannyLogInfo("eventMain and  timeoutGenerator killed");
}

void Nanny::create()
{
	nannyLogInfo("Waking up eventMain");
	eventMain.wakeUp();
	timeoutGenerator.wakeUp();
	interfaceFinder.init("enp0s8");

	event::Event *musicPlayerEvent = reinterpret_cast<event::Event*>(allocate<MusicPlayerData>());
	musicPlayerEvent->type = static_cast<event::EventType>(9998);
	MusicPlayerData &mpData = reinterpret_cast<MusicPlayerData&>(musicPlayerEvent->payload);
	mpData.songId = 23;
	mpData.type = MusicPlayerRequestType::stopMusic;
	event::EventQueue::getInstance().push(musicPlayerEvent);

	for(int i = 0;i< 10;i++)
	{
		event::Event *testEvent = reinterpret_cast<event::Event*>(allocate<TestData>());
		testEvent->type=static_cast<event::EventType>(0);
		TestResponse *resp = reinterpret_cast<TestResponse *>(event::EventQueue::getInstance().pushAndWaitForResponse(testEvent));
		std::cout << "A: " << resp->a << " b: " << resp->b << std::endl;
		freed(resp);
	}

}

} /* namespace app */
