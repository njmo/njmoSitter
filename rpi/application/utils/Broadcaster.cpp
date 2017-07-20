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
	int sock, status, buflen, sinlen;
	  char buffer[1024];
	  struct sockaddr_in sock_in;
	  int yes = 1;

	  sinlen = sizeof(struct sockaddr_in);
	  memset(&sock_in, 0, sinlen);
	  buflen = 1024;

	  sock = socket (PF_INET, SOCK_DGRAM, IPPROTO_UDP);

	  status = setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &yes, sizeof(int) );
	  printf("Setsockopt Status = %d\n", status);

	  struct sockaddr_in &a = interfaceFinder.getBroadcastAddr(); 
	  memcpy(&sock_in,&a,sizeof(struct sockaddr_in));
	  sock_in.sin_port = htons(12345); /* port number */
	  sock_in.sin_family = PF_INET;

	  sprintf(buffer, "Ciao");
	  buflen = strlen(buffer);
	  status = sendto(sock, buffer, buflen, 0, (struct sockaddr *)&sock_in, sinlen);
	  printf("sendto Status = %d\n", status);

	  close(sock);
}

Broadcaster::~Broadcaster() {
	// TODO Auto-generated destructor stub
}

