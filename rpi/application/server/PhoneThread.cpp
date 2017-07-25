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
	std::lock_guard<std::mutex> lock(mutex);

	bzero((char *) &clientAddr, sizeof(clientAddr));
	memcpy(&clientAddr,_saddr,sizeof(clientAddr));

	nannyLogInfo("Sending message to register");
	event::Event *query = reinterpret_cast<event::Event*>(allocateNannyQuery<RegisterUser>());
	query->type = static_cast<event::EventType>(event::NannyQuery);
	*reinterpret_cast<u32*>(query->payload) = 5;
	void *response = event::EventQueue::getInstance().pushAndWaitForResponse(query);
	RegisterResponse *resp = reinterpret_cast<RegisterResponse*>(response);
	id=resp->assignedId;
	if(resp->registerStatus == static_cast<u8>(RegisterStatus::registered) )
		nannyLogInfo("Registration complete successfully id: " + std::to_string(id));
	delete resp;
	event::EventQueue::getInstance().registerAsWaiter(id,*this);
	//waking up thread
}

void PhoneThread::test()
{
	usleep(50); // use mutex before construction of PhoneThread object
	std::lock_guard<std::mutex> lock(mutex);
	nannyLogInfo("Starting PhoneThread connection");
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
	event::EventQueue::getInstance().deregister(id);
	nannyLogInfo("Killing PhoneThread connection");
}

void PhoneThread::notify(void *dataToSend)
{
	u32 size = *reinterpret_cast<u32*>(dataToSend);
	u32 *data = reinterpret_cast<u32*>(dataToSend);
	nannyLogError("Received data to send " + std::to_string(size));
	if( write(socket,&data[1],size) < size )
		nannyLogError("Error sending data to client");
}
void PhoneThread::kill()
{
	shutdown(socket, SHUT_RD);
}
PhoneThread::~PhoneThread()
{
	nannyLogInfo("PhoneThread destructor");
}

