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
	NannyRequest *nannyRequest = reinterpret_cast<NannyRequest*>(allocateNanny<RegisterUser,NannyRequest>());
	nannyRequest->requestType = static_cast<u32>(event::NannyQuery);
	nannyRequest->queryType = static_cast<u8>(NannyRequestType::Register);

	void *response = event::EventQueue::getInstance().pushAndWaitForResponse(reinterpret_cast<event::Event*>(nannyRequest));
	NannyResponse *nr = reinterpret_cast<NannyResponse*>(response);
	RegisterResponse *resp = reinterpret_cast<RegisterResponse*>(nr->data);
	id=resp->assignedId;
	if(resp->registerStatus == static_cast<u8>(RegisterStatus::registered) )
		nannyLogInfo("Registration complete successfully id: " + std::to_string(id));

	delete nr;
	event::EventQueue::getInstance().registerAsWaiter(id,*this);
	//waking up thread
}
void PhoneThread::sendNotifyRequest()
{
	NannyRequest *nannyRequest = reinterpret_cast<NannyRequest*>(allocateNanny<NotifyRequest,NannyRequest>());
	nannyRequest->requestType = static_cast<u32>(event::NannyQuery);
	nannyRequest->queryType = static_cast<u8>(NannyRequestType::NotifyWhenStartCrying);
	nannyRequest->senderId = id;
	NotifyRequest *notifyRequest = reinterpret_cast<NotifyRequest*>(nannyRequest->payload);
	notifyRequest->notifyType = static_cast<u8>(NotifyRequestType::registerNotify);
	event::EventQueue::getInstance().push(reinterpret_cast<event::Event*>(nannyRequest));
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
		sendNotifyRequest();
		nannyLogInfo("User " + std::to_string(id) +" received " + std::to_string(readBytes) + "bytes of data ");
	}
	event::EventQueue::getInstance().deregister(id);
	nannyLogInfo("Killing PhoneThread connection");
}

void PhoneThread::notify(void *dataToSend)
{
	NannyResponse *response = reinterpret_cast<NannyResponse*>(dataToSend);
	const u32 size = response->size;

	nannyLogError("Received data to send " + std::to_string(size) + "my id " + std::to_string(id) + " received id " + std::to_string(response->id));
	//if( write(socket,response->data,size) < size )
	//	nannyLogError("Error sending data to client");
}
void PhoneThread::kill()
{
	shutdown(socket, SHUT_RD);
}
PhoneThread::~PhoneThread()
{
	nannyLogInfo("PhoneThread destructor");
}

