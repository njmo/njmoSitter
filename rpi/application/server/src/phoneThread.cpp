/*
 * phoneThread.cpp
 *
 *  Created on: Apr 10, 2017
 *      Author: njmo
 */

#include "phoneThread.h"

void phoneThread::test()
{ // ssss
	for(int i=0;i<20;i++)
	{//asas
		usleep(1000);
		std::cout << message;//as/asdsdsd
		event::Event *event = new event::Event;
		event->type=static_cast<event::EEventType>(0);
		event->payload[0]=i;
		event::EventQueue::getInstance().push(event);
	}
}

phoneThread::~phoneThread() {
	// TODO Auto-generated destructor stub
	std::cout << "dying";
	this->join();
	std::cout << "dying2";
}

