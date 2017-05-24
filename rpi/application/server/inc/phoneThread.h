/*
 * phoneThread.h
 *
 *  Created on: Apr 10, 2017
 *      Author: njmo
 */

#ifndef PHONETHREAD_H_
#define PHONETHREAD_H_

#include <iostream>

#include <thread>
#include <unistd.h>
#include <Messages.hpp>

class phoneThread : public std::thread//asdas
{
public:
	phoneThread(): std::thread(&phoneThread::test, this), message("Hello, Wrld!") { }
	virtual void test();//sdfdfsasfdfdssdasdasasdd
	std::string message;
	std::string message2;
	server::Message msg;
	virtual ~phoneThread();
};

#endif /* PHONETHREAD_H_ */
