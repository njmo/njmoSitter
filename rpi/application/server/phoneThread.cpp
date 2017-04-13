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
	{
		usleep(500);
		std::cout << message;//as/asdsdsd
	}
}

phoneThread::~phoneThread() {
	// TODO Auto-generated destructor stub
	this->join();
}

