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
	// TODO Auto-generated constructor stub

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

	  sock_in.sin_addr.s_addr = htonl(INADDR_ANY);
	  sock_in.sin_port = htons(0);
	  sock_in.sin_family = PF_INET;

	  status = bind(sock, (struct sockaddr *)&sock_in, sinlen);
	  printf("Bind Status = %d\n", status);

	  status = setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &yes, sizeof(int) );
	  printf("Setsockopt Status = %d\n", status);

	  /* -1 = 255.255.255.255 this is a BROADCAST address,
	     a local broadcast address could also be used.
	     you can comput the local broadcat using NIC address and its NETMASK
	  */

	  struct sockaddr_in &a = interfaceFinder.getBroadcastAddr(); 
	  memcpy(&sock_in,&a,sizeof(struct sockaddr_in));
	  sock_in.sin_port = htons(12345); /* port number */
	  sock_in.sin_family = PF_INET;

	  sprintf(buffer, "Ciao");
	  buflen = strlen(buffer);
	  status = sendto(sock, buffer, buflen, 0, (struct sockaddr *)&sock_in, sinlen);
	  printf("sendto Status = %d\n", status);

	  shutdown(sock, 2);
	  close(sock);
}

Broadcaster::~Broadcaster() {
	// TODO Auto-generated destructor stub
}

