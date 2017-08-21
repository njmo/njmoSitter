/*
 * Messages.hpp
 *
 *  Created on: Apr 11, 2017
 *      Author: njmo
 */

#ifndef MESSAGES_HPP_
#define MESSAGES_HPP_

#include "defines.hpp"
#include "event/queue/Event.hpp"

#include <interface/message/NannyRequest.hpp>
#include <event/queue/Event.hpp>

#define NANNY_ID 101

template<typename T>
void *allocate()
{
	u32 size = sizeof(T) + sizeof(event::Event) - 1;
	return (void*)new u8[size];
}
inline void *allocate(u32 _s)
{
	u32 size = _s + sizeof(event::Event) - 1;
	return (void*)new u8[size];
}
template<typename T,typename D>
void *allocateNanny()
{
	u32 size = sizeof(T) + sizeof(D) - 1;
	return (void*)new u8[size];
}
inline void freed(void *a)
{
	delete[] (((u32*)a)-2);
}
inline void freedNannyQuery(void *a)
{
	delete[] (((u32*)a)-3);
}
#endif /* MESSAGES_HPP_ */
