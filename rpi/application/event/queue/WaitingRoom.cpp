/*
 * WaitingRoom.cpp
 *
 *  Created on: Jul 13, 2017
 *      Author: njmo
 */

#include "WaitingRoom.hpp"

namespace queue {

WaitingRoom::WaitingRoom() {
	// TODO Auto-generated constructor stub

}

WaitingRoom::~WaitingRoom() {
	// TODO Auto-generated destructor stub
}

void WaitingRoom::registerWaiter(u32 sender,IWaiter *_waiter)
{
	std::lock_guard<std::mutex> lock(mutex);
	nannyLogInfo("Registering waiter in WaitingRoom");
	waiters.insert(std::pair<u32,IWaiter*>(sender,_waiter));
}

void WaitingRoom::notifyWaiter(u32 sender,void* data)
{
	std::lock_guard<std::mutex> lock(mutex);
	auto waiter = waiters.find(sender);
	if(waiter != waiters.end())
	{
		nannyLogInfo("NotifyWaiter in WaitingRoom");
		waiter->second->notify(data);
		waiters.erase(sender);
	}
	else
	{
		nannyLogError("Trying to notify waiter which doesn't exist! sender ");
	}
}

void WaitingRoom::deregisterWaiter(u32 id)
{
	nannyLogInfo("Removing waiter from WaitingRoom");
	std::lock_guard<std::mutex> lock(mutex);
	waiters.erase(id);
}

} /* namespace app */
