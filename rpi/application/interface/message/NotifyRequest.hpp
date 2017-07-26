/*
 * NotifyRequest.hpp
 *
 *  Created on: Jul 26, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_INTERFACE_MESSAGE_NOTIFYREQUEST_HPP_
#define APPLICATION_INTERFACE_MESSAGE_NOTIFYREQUEST_HPP_
#include <inc/defines.hpp>

enum NotifyRequestType
{
	registerNotify=0,
	deregisterNotify
};

struct NotifyRequest
{
	u8 notifyType;
};


#endif /* APPLICATION_INTERFACE_MESSAGE_NOTIFYREQUEST_HPP_ */
