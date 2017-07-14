/*
 * Nanny.cpp
 *
 *  Created on: Jul 13, 2017
 *      Author: njmo
 */

#include "Nanny.hpp"

namespace app {

Nanny::Nanny()
	: timeoutGenerator(500)
{
	nannyLogInfo("Nanny created");
}

Nanny::~Nanny() {
	eventMain.kill();
	eventMain.join();
	nannyLogInfo("eventMain killed");
}

void Nanny::create()
{
	nannyLogInfo("Waking up eventMain");
	eventMain.wakeUp();

	event::Event *tempEvent = new event::Event;
	tempEvent->type=static_cast<event::EventType>(99);
	u8 * value = event::EventQueue::getInstance().pushAndWaitForResponse(tempEvent);
	std::cout << (u32) *value;
	nannyLogInfo("Code goe further");

	event::Event *testEvent = new event::Event;
	testEvent->type=static_cast<event::EventType>(0);
	u8 * response = event::EventQueue::getInstance().pushAndWaitForResponse(testEvent);
	TestResponse *resp = reinterpret_cast<TestResponse *>(response);
	std::cout << "A: " << resp->a << " b: " << resp->b << std::endl;
	delete resp;
}

} /* namespace app */
