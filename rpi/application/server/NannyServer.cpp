/*
 * NannyServer.cpp
 *
 *  Created on: Jul 24, 2017
 *      Author: njmo
 */
#include "NannyServer.hpp"


NannyServer::NannyServer(i32 _portNumber)
	: sock(0),
	  status(NotInitialized),
	  portNumber(_portNumber),
	  isRunning(false),
	  std::thread(&NannyServer::start, this)
{
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portNumber);
}
bool NannyServer::init()
{
	status = Initialized;

	sock = socket(AF_INET,SOCK_STREAM,0);
	if( sock < 0 )
	{
		status = FailedOnSockCreation;
	}

	if( bind(sock,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) == -1 )
	{
		status = FailedOnBindingSocket;
	}

	return (status == Initialized);
}

ConnectionStatus NannyServer::getStatus()
{
	return status;
}
void NannyServer::run()
{
	nannyLogInfo("NannyServer runned");
	isRunning = true;
}
void NannyServer::start()
{
	nannyLogInfo("NannyServer created");
	while(!isRunning)
		;
	nannyLogInfo("NannyServer started");
	while(isRunning)
	{
		listen(sock,maxNumOfConnectionsQueue);
		sockaddr_in clientSockAddr;
		bzero((char *) &clientSockAddr, sizeof(clientSockAddr));

		socklen_t cliLen = 0;
		int newConnectionSocket = accept(sock,(struct sockaddr*)&clientSockAddr,&cliLen);
		if(newConnectionSocket < 0)
		{
			nannyLogError("Error while creating connection socket");
		}
		else
		{
			nannyLogInfo("Creating new client");
			users.push_front(new PhoneThread(newConnectionSocket,&clientSockAddr));
		}
	}
	nannyLogInfo("NannyServer is killed");
}
void NannyServer::stop()
{
	nannyLogInfo("NannyServer being killed");
	isRunning = false;
	shutdown(sock,SHUT_RD);
}
NannyServer::~NannyServer()
{
	nannyLogInfo("NannyServer Decttructor");
	while(!users.empty())
	{
		PhoneThread* th = users.front();
		th->kill();
		th->join();
		delete th;
		users.pop_front();
	}
}
