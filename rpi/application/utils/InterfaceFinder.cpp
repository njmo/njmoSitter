/*
 * InterfaceFinder.cpp
 *
 *  Created on: Jul 19, 2017
 *      Author: njmo
 */

#include "InterfaceFinder.hpp"

InterfaceFinder::InterfaceFinder() {
	// TODO Auto-generated constructor stub

}

InterfaceFinder::~InterfaceFinder() {
	// TODO Auto-generated destructor stub
}

bool InterfaceFinder::init(std::string interface)
{
		int sock;
	    struct ifreq ifr;
	    struct sockaddr_in *ipaddr;
	    char address[INET_ADDRSTRLEN];
	    size_t ifnamelen;
		DIR *d;
		struct dirent *de;

		d = opendir("/sys/class/net/");
		if (d == NULL) {
			nannyLogError("Error during opening dir");
		    return false;
		}
		bool isInterfaceFound = false;
		while (NULL != (de = readdir(d)))
		{
			std::string s(de->d_name);
			if(s != interface)
				continue;

			isInterfaceFound = true;

			nannyLogInfo("Found interface " + interface);

			memcpy(ifr.ifr_name, s.c_str(), s.size());
			ifr.ifr_name[s.size()] = '\0';

			sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
			if (sock < 0)
			{
				nannyLogError("Error during opening socket");
				return false;
			}

			if( !storeAddr(sock,ifr) || !storeNetmask(sock,ifr) || !storeBroadcastAddr(sock,ifr))
				return false;

			close(sock);
		}
		if(!isInterfaceFound)
		{
			nannyLogError("interface not found " + interface);
			return false;
		}
		return true;
	}

bool InterfaceFinder::storeAddr(int sock,struct ifreq& _ir)
{
	bool result = (ioctl(sock, SIOCGIFADDR, &_ir) != -1);
	addr = *((struct sockaddr_in *)&_ir.ifr_netmask);
	if(!result)
		nannyLogError("Error getting addr from interface");
	return result;

}
bool InterfaceFinder::storeNetmask(int sock,struct ifreq& _ir)
{
	bool result = (ioctl(sock, SIOCGIFNETMASK, &_ir) != -1);
	netmaskAddr = *((struct sockaddr_in *)&_ir.ifr_netmask);
	if(!result)
		nannyLogError("Error getting netmask from interface");
	return result;

}
bool InterfaceFinder::storeBroadcastAddr(int sock,struct ifreq& _ir)
{
	bool result = (ioctl(sock, SIOCGIFBRDADDR, &_ir) != -1);
	broadcastAddr = *((struct sockaddr_in *)&_ir.ifr_netmask);
	if(!result)
		nannyLogError("Error getting broadcast addr from interface");
	return result;
}

std::string InterfaceFinder::getAddr()
{
    char address[INET_ADDRSTRLEN];
	if (inet_ntop(AF_INET, &addr.sin_addr, address, sizeof(address)) != NULL)
	{
		return std::string(address);
	}
	nannyLogError("Error parsing addr sin_addr to string");
	return "error";
}
std::string InterfaceFinder::getNetmaskAddr()
{
    char address[INET_ADDRSTRLEN];
	if (inet_ntop(AF_INET, &netmaskAddr.sin_addr, address, sizeof(address)) != NULL)
	{
		return std::string(address,INET_ADDRSTRLEN);
	}
	nannyLogError("Error parsing netmask sin_addr to string");
	return "error";

}
std::string InterfaceFinder::getBroadcastAddr()
{
    char address[INET_ADDRSTRLEN];
	if (inet_ntop(AF_INET, &broadcastAddr.sin_addr, address, sizeof(address)) != NULL)
	{
		return std::string(address);
	}
	nannyLogError("Error parsing broadcast sin_addr to string");
	return "error";

}
