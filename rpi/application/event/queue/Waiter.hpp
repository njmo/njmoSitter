/*
 * Waiter.hpp
 *
 *  Created on: Jul 13, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_EVENT_QUEUE_WAITER_HPP_
#define APPLICATION_EVENT_QUEUE_WAITER_HPP_
#include <inc/defines.hpp>
#include <utils/Logger/Logger.hpp>

namespace queue {

class Waiter {
public:
	Waiter()
		: waiting(true),
		  data(nullptr)
	{
		nannyLogInfo("Waiter is born");
	}
	u8* waitForResponse()
	{
		while( waiting )
			;
		nannyLogInfo("Waiter retrieve response data, returning value to code");
		return data;
	}
	void notify(u8 *_data)
	{
		nannyLogInfo("Waiter is being notified");
		data = _data;
		waiting = false;
	}
	virtual ~Waiter()
	{
		nannyLogInfo("Waiter is being killed");
	}
private:
	volatile bool waiting;
	u8 *data;
};

} /* namespace queue */

#endif /* APPLICATION_EVENT_QUEUE_WAITER_HPP_ */