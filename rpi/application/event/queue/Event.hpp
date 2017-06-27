/*
 * Event.hpp
 *
 *  Created on: Jun 7, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_EVENT_EVENT_HPP_
#define APPLICATION_EVENT_EVENT_HPP_

#include <defines.hpp>
#include "EventType.hpp"

namespace event {

struct Event
{
	EventType type;
	u8 payload[1];
};

}



#endif /* APPLICATION_EVENT_EVENT_HPP_ */
