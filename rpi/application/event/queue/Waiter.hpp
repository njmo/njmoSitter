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

struct IWaiter
{
	virtual void notify(void *) = 0;
	virtual ~IWaiter(){}
};

class Waiter : IWaiter{
public:
	Waiter()
		: waiting(true),
		  data(nullptr)
	{
	}
	void* waitForResponse()
	{
		while( waiting )
			;
		return data;
	}
	void notify(void *_data)
	{
		data = _data;
		waiting = false;
	}
	virtual ~Waiter()
	{
	}
private:
	volatile bool waiting;
	void *data;
};

} /* namespace queue */

#endif /* APPLICATION_EVENT_QUEUE_WAITER_HPP_ */
