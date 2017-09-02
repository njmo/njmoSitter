/*
 * Camera.hpp
 *
 *  Created on: Aug 21, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_DEVICE_MOTOR_HPP_
#define APPLICATION_DEVICE_MOTOR_HPP_
#include <inc/defines.hpp>
#include <utils/Logger/Logger.hpp>

#include <pigpio.h>
#include <signal.h>

namespace device {

class Motor{
public:
	Motor();
  void start(u8);
  void stop();
	virtual ~Motor();
private:

};

} /* namespace device */

#endif /* APPLICATION_DEVICE_MOTOR_HPP_ */
