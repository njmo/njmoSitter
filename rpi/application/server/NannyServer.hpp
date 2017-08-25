/*
 * NannyServer.hpp
 *
 *  Created on: Jul 24, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_SERVER_INC_NANNYSERVER_HPP_
#define APPLICATION_SERVER_INC_NANNYSERVER_HPP_
#include <inc/defines.hpp>
#include <utils/Logger/Logger.hpp>
#include "PhoneThread.hpp"
#include <list>

// downloaded from https://github.com/nlohmann/json
#include <utils/json.hpp>
using nlohmann::json;

enum ConnectionStatus
{
	NotInitialized,
	FailedOnSockCreation,
	FailedOnBindingSocket,
	Initialized
};

class NannyServer : public std::thread
{
public:
	NannyServer(i32);
	bool init();
	void start();
	void run();
	void stop();
	ConnectionStatus getStatus();
	virtual ~NannyServer();
private:
	i32 sock;
	i32 portNumber;
	std::list<PhoneThread*> users;
	struct sockaddr_in serv_addr;
	static const i32 maxNumOfConnectionsQueue = 1;
	volatile bool isRunning;
	ConnectionStatus status;
};


#endif /* APPLICATION_SERVER_INC_NANNYSERVER_HPP_ */
