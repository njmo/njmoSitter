/*
 * MotorExecutor.cpp
 *
 *  Created on: Aug 21, 2017
 *      Author: njmo
 */

#include "MotorExecutor.hpp"

namespace event {
namespace executor {

MotorExecutor::MotorExecutor() 
{

}


Response* MotorExecutor::execute(void *req)
{
  MotorRequest *motorRequest = reinterpret_cast<MotorRequest*>(req);

  switch(motorRequest->type)
  {
    case MotorRequestType::startMotor:
    {
      motor.start(motorRequest->motorSpeed);
      break;
    }
    case MotorRequestType::stopMotor:
    {
      motor.stop();
      break;
    }
    default:
      break;
  }
	Response *resp = new Response;
	resp->status = Reponse_Ok;
	resp->type = WithoutResponse;
	
	return resp;
}

MotorExecutor::~MotorExecutor() {
	// TODO Auto-generated destructor stub
}

} /* namespace executor */
} /* namespace event */
