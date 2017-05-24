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
	}
}

phoneThread::~phoneThread() {
	// TODO Auto-generated destructor stub
	std::cout << "dying";
	this->join();
	std::cout << "dying2";
}

