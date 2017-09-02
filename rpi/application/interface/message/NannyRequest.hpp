/*
 * NannyQuery.hpp
 *
 *  Created on: Jul 26, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_INTERFACE_MESSAGE_NANNYREQUEST_HPP_
#define APPLICATION_INTERFACE_MESSAGE_NANNYREQUEST_HPP_
#include <inc/defines.hpp>

enum NannyRequestType
{
	Register=0,
	Deregister,
	NotifyWhenStartCrying,
	CaptureCamera,
	CaptureVoice,
  MusicPlayer,
	ControllMotor
};

struct NannyRequest
{
	u32 requestType;
	u32 senderId;
	u8 queryType;
	u8 payload[1];
};


#endif /* APPLICATION_INTERFACE_MESSAGE_NANNYREQUEST_HPP_ */
