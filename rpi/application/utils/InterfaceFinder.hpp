/*
 * Broadcaster.hpp
 *
 *  Created on: Jul 19, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_UTILS_INTERFACEFINDER_HPP_
#define APPLICATION_UTILS_INTERFACEFINDER_HPP_
#include <stdio.h>
#include <string.h>
#include <net/if.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <dirent.h>
#include <string>

#include <utils/Logger/Logger.hpp>

class InterfaceFinder {
public:
	InterfaceFinder();
	virtual ~InterfaceFinder();
	bool init(std::string);

	struct sockaddr_in& getAddrStr();
	struct sockaddr_in& getNetmaskAddr();
	struct sockaddr_in& getBroadcastAddr();

	std::string getAddrString();
	std::string getNetmaskAddrString();
	std::string getBroadcastAddrString();
private:

	bool storeAddr(int,struct ifreq&);
	bool storeNetmask(int,struct ifreq&);
	bool storeBroadcastAddr(int,struct ifreq&);

    struct sockaddr_in addr;
    struct sockaddr_in broadcastAddr;
    struct sockaddr_in netmaskAddr;
};

#endif /* APPLICATION_UTILS_INTERFACEFINDER_HPP_ */

