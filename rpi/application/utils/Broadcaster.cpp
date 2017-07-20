/*
 * Broadcaster.cpp
 *
 *  Created on: Jul 19, 2017
 *      Author: njmo
 */

#include "Broadcaster.hpp"

Broadcaster::Broadcaster(InterfaceFinder &_finder)
	: interfaceFinder(_finder)
{
	sock = socket (PF_INET, SOCK_DGRAM, IPPROTO_UDP);
}

void Broadcaster::broadcastNannyAddress()
{
	  char buffer[1024];
	  int status, yes=1;
	  struct sockaddr_in sock_in;

	  NannyBroadcasMessage *msg = reinterpret_cast<NannyBroadcasMessage *>(buffer);
	  memcpy(msg->addr,interfaceFinder.getAddrString().c_str(),interfaceFinder.getAddrString().size());
	  msg->port = 1234;

	  memset(&sock_in, 0, sizeof(struct sockaddr_in));

	  if( setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &yes, sizeof(int)) != 0)
		  nannyLogError("Failed setting broadcast option on socket");

	  sock_in.sin_addr = interfaceFinder.getBroadcastAddr().sin_addr;
	  sock_in.sin_port = htons(12345); /* port number */
	  sock_in.sin_family = PF_INET;

	  const i32 messageLength = sizeof(NannyBroadcasMessage);
	  if( sendto(sock, buffer, messageLength, 0, (struct sockaddr *)&sock_in, sizeof(struct sockaddr_in)) < messageLength)
		  nannyLogError("Failed when sending broadcast data");
	  else
		  nannyLogInfo("Broadcast to address " + interfaceFinder.getBroadcastAddrString() + " send successfully");
}

Broadcaster::~Broadcaster() {
	  close(sock);
}

