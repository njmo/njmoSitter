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
	u32 getFps() { return fps; }
	void setFps(u32 _f){ fps = _f; }
	bool hasRequestedForCamera() { return requestedForCamera; }
	void registerForCamera() { requestedForCamera = true; }
	void unRegisterForCamera() { requestedForCamera = false; }
	u32 getId(){ return id; }
	virtual ~User();
private:
	u32  id;
	bool requestedForVoiceRecorder;
	bool requestedForCamera;
	u32  fps;
};

#endif /* APPLICATION_NANNY_USER_HPP_ */
