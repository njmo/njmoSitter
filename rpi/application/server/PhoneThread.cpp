/*
 * phoneThread.cpp
 *
 *  Created on: Apr 10, 2017
 *      Author: njmo
 */

#include "PhoneThread.hpp"

PhoneThread::PhoneThread(int _socket,struct sockaddr_in* _saddr)
	: std::thread(&PhoneThread::test, this),
	  socket(_socket)
{
	bzero((char *) &clientAddr, sizeof(clientAddr));
	memcpy(&clientAddr,_saddr,sizeof(clientAddr));

	nannyLogInfo("Sending message to register");
	event::Event *query = reinterpret_cast<event::Event*>(allocateNannyQuery<RegisterUser>());
	query->type = static_cast<event::EventType>(event::NannyQuery);
	*reinterpret_cast<u32*>(query->payload) = 5;
	*reinterpret_cast<u32*>(&query->payload[4]) = 15;
	event::EventQueue::getInstance().push(query);
}

void PhoneThread::test()
{
	while(true)
	{
		u8 buffer[1024];
		int readBytes = read(socket,buffer,1024);
		if(readBytes <= 0)
		{
			nannyLogError("Connection lost");
			break;
		}
		nannyLogInfo("User received " + std::to_string(readBytes) + "bytes of data ");
	}
	nannyLogInfo("Killing PhoneThread connection");
}

void PhoneThread::notify(void *dataToSend)
{

}

PhoneThread::~PhoneThread()
{

}

