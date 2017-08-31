/*
 * phoneThread.cpp
 *
 *  Created on: Apr 10, 2017
 *      Author: njmo
 */

#include "PhoneThread.hpp"

PhoneThread::PhoneThread(int _socket,struct sockaddr_in* _saddr)
	: std::thread(&PhoneThread::test, this),
    isRunning(true),
	  socket(_socket),
    nannyId(0)
{
//	std::lock_guard<std::mutex> lock(mutex);

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
  nannyId = resp->nannyId;
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
void PhoneThread::sendNotifyCapture(u8 value)
{
	NannyRequest *nannyRequest = reinterpret_cast<NannyRequest*>(allocateNanny<CameraRequest,NannyRequest>());
	nannyRequest->requestType = static_cast<u32>(event::NannyQuery);
	nannyRequest->queryType = static_cast<u8>(NannyRequestType::CaptureCamera);
	nannyRequest->senderId = id;
	CameraRequest *notifyRequest = reinterpret_cast<CameraRequest*>(nannyRequest->payload);
	notifyRequest->cameraType = value;
	notifyRequest->fps = 5;
	event::EventQueue::getInstance().push(reinterpret_cast<event::Event*>(nannyRequest));
}
void PhoneThread::test()
{
	usleep(50); // use mutex before construction of PhoneThread object
  isRunning=true;
	int i = 0;
	nannyLogInfo("Starting PhoneThread connection");
	u32 fps=0;

	while(isRunning)
	{
		if(fps == 5)
		{
			nannyLogInfo("Sended 5 frames");
			fps=0;
		}
		int count;
		ioctl(socket, FIONREAD, &count);
		if( count > 0 )
		{
			i8 buffer[1024] = {};
			int readBytes;
			readBytes = read(socket,buffer,1024);
			if(readBytes <= 0 )
			{
				nannyLogError("Connection lost");
				break;
			}
      
      try
      {
        json *j = new json(json::parse(std::string(buffer)));
        j->operator[]("id") = id;
	      event::EventQueue::getInstance().sendResponse(nannyId,j);
      }catch(...){}

			nannyLogInfo("User " + std::to_string(id) +" received " + std::to_string(readBytes) + "bytes of data ");
		}
		if(!requestList.empty()){
	    std::lock_guard<std::mutex> lock(mutex);
			NannyResponse *response = requestList.front();
			requestList.pop_front();
			const u32 size = response->size;
			if( write(socket,response->data,size) < size )
				nannyLogError("Error sending data to client");
			fps++;
      delete response;
		}
	}
	nannyLogInfo("Killing PhoneThread connection");
}

void PhoneThread::notify(void *dataToSend)
{
	std::lock_guard<std::mutex> lock(mutex);
	requestList.push_back(reinterpret_cast<NannyResponse*>(dataToSend));
}
void PhoneThread::kill()
{
	event::EventQueue::getInstance().deregister(id);
  isRunning=false;
	shutdown(socket, SHUT_RD);
}
PhoneThread::~PhoneThread()
{
	nannyLogInfo("PhoneThread destructor");
}

