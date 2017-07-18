/*
 * WaitingRoom.hpp
 *
 *  Created on: Jul 13, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_EVENT_QUEUE_WAITINGROOM_HPP_
#define APPLICATION_EVENT_QUEUE_WAITINGROOM_HPP_
#include <map>
#include "Waiter.hpp"
#include <mutex>
#include <inc/defines.hpp>
#include <utils/Logger/Logger.hpp>

namespace queue {

class WaitingRoom {
public:
	WaitingRoom();
	void registerWaiter(u32,Waiter &);
	void notifyWaiter(u32,void*);
	virtual ~WaitingRoom();
private:
	std::map<u32,Waiter*> waiters;
	std::mutex mutex;
};

} /* namespace app */

#endif /* APPLICATION_EVENT_QUEUE_WAITINGROOM_HPP_ */
