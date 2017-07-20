/*
 * Broadcaster.hpp
 *
 *  Created on: Jul 19, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_UTILS_BROADCASTER_HPP_
#define APPLICATION_UTILS_BROADCASTER_HPP_
#include "InterfaceFinder.hpp"
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

class Broadcaster {
public:
	Broadcaster(InterfaceFinder&);

	void broadcastNannyAddress();

	virtual ~Broadcaster();
private:
	InterfaceFinder& interfaceFinder;
};

#endif /* APPLICATION_UTILS_BROADCASTER_HPP_ */
