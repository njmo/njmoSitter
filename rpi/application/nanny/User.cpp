/*
 * User.cpp
 *
 *  Created on: Jul 25, 2017
 *      Author: njmo
 */

#include "User.hpp"

User::User(u32 _id)
	:	id(_id),
		requestedForVoiceRecorder(false)
{
	// TODO Auto-generated constructor stub

}

void User::registerForVoiceRecorderNotify()
{
	requestedForVoiceRecorder = true;
}
void User::unRegisterForVoiceRecorderNotify()
{
	requestedForVoiceRecorder = false;
}
bool User::hasRequestedForVoiceRecorderNotify()
{
	return requestedForVoiceRecorder;
}
User::~User() {
	// TODO Auto-generated destructor stub
}

