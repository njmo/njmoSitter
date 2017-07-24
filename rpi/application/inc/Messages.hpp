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


template<typename T>
void *allocate()
{
	u32 size = sizeof(T) + ( 2*sizeof(u32));
	return (void*)new u8[size];
}
template<typename T>
void *allocateNannyQuery()
{
	u32 size = sizeof(T) + ( 3*sizeof(u32));
	return (void*)new u8[size];
}
inline void freed(void *a)
{
	delete[] (((u32*)a)-2);
}
#endif /* MESSAGES_HPP_ */
