/*
 * Motor.cpp
 *
 *  Created on: Aug 21, 2017
 *      Author: njmo
 */

#include "Motor.hpp"

namespace device {

Motor::Motor()
{
  if (gpioInitialise() < 0)
    nannyLogError("Error during gpioInitialization");
  else
    nannyLogInfo("Gpio initialized successfully!");

//  gpioSetSignalFunc(SIGINT, stop);
}
void Motor::start(u8 speed)
{
  gpioPWM(12,speed);
  nannyLogInfo("Starting motor with speed " + std::to_string(speed));
}
void Motor::stop()
{
  nannyLogInfo("Stopping motor");

}
Motor::~Motor() {
  gpioTerminate();
	// TODO Auto-generated destructor stub
}

} /* namespace device */
