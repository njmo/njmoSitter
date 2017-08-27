/*
 * Broadcaster.cpp
 *
 *  Created on: Jul 19, 2017
 *      Author: njmo
 */

#include "Broadcaster.hpp"

Broadcaster::Broadcaster()
{
	sock = socket (PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	interfaceFinder.init("eth0");
  int status, yes=1;

  memset(&sock_in, 0, sizeof(struct sockaddr_in));

  if( setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &yes, sizeof(int)) != 0)
    nannyLogError("Failed setting broadcast option on socket");

  sock_in.sin_addr = interfaceFinder.getBroadcastAddr().sin_addr;
  sock_in.sin_port = htons(12345); /* port number */
  sock_in.sin_family = PF_INET;

  response["port"] = 1234;
  response["ip"] = interfaceFinder.getAddrString();
}

void Broadcaster::broadcastNannyAddress()
{

    nannyLogInfo("Sending response " + response.dump());
	  const i32 messageLength = response.dump().length()+1;
	  if( sendto(sock, response.dump().c_str(), messageLength, 0, (struct sockaddr *)&sock_in, sizeof(struct sockaddr_in)) < messageLength)
		  nannyLogError("Failed when sending broadcast data");
	  else
		  nannyLogInfo("Broadcast to address " + interfaceFinder.getBroadcastAddrString() + " send successfully");
}

Broadcaster::~Broadcaster() {
	  close(sock);
}

