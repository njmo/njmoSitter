/*
 * phoneThread.h
 *
 *  Created on: Apr 10, 2017
 *      Author: njmo
 */

#ifndef PHONETHREAD_H_
#define PHONETHREAD_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <thread>
#include <unistd.h>
#include <inc/Messages.hpp>
#include <event/queue/EventQueue.hpp>
#include <event/queue/Waiter.hpp>
#include <interface/message/RegisterUser.hpp>

class PhoneThread : public std::thread , queue::IWaiter
{
public:
	PhoneThread(int,struct sockaddr_in*);
	void test();
	void notify(void *);
	virtual ~PhoneThread();
private:
	struct sockaddr_in clientAddr;
	int socket;
};

#endif /* PHONETHREAD_H_ */
