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

	event::Event *testEvent = new event::Event;
	testEvent->type=static_cast<event::EventType>(0);
	TestResponse *resp = reinterpret_cast<TestResponse *>(event::EventQueue::getInstance().pushAndWaitForResponse(testEvent));
	std::cout << "A: " << resp->a << " b: " << resp->b << std::endl;
	delete[] (((u32*)resp)-2);
}

} /* namespace app */
