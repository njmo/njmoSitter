/*
 * MotorRequest.hpp
 *
 *  Created on: Jul 17, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_INTERFACE_MOTORREQUEST_HPP_
#define APPLICATION_INTERFACE_MOTORREQUEST_HPP_
#include <inc/defines.hpp>

enum MotorRequestType
{
  startMotor = 0,
  stopMotor
};

struct MotorRequest
{
	MotorRequestType type;
  u8 motorSpeed;
};

#endif /* APPLICATION_INTERFACE_MOTORREQUEST_HPP_ */
