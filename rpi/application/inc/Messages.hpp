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
#endif /* MESSAGES_HPP_ */
