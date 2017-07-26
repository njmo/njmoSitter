/*
 * User.hpp
 *
 *  Created on: Jul 25, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_NANNY_USER_HPP_
#define APPLICATION_NANNY_USER_HPP_
#include <inc/defines.hpp>

class User {
public:
	User(u32);
	void registerForVoiceRecorderNotify();
	void unRegisterForVoiceRecorderNotify();
	bool hasRequestedForVoiceRecorderNotify();
	u32 getId(){ return id; }
	virtual ~User();
private:
	u32 id;
	volatile bool requestedForVoiceRecorder;
};

#endif /* APPLICATION_NANNY_USER_HPP_ */
