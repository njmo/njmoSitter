/*
 * CameraRequest.hpp
 *
 *  Created on: Jul 27, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_INTERFACE_MESSAGE_CAMERAREQUEST_HPP_
#define APPLICATION_INTERFACE_MESSAGE_CAMERAREQUEST_HPP_
#include <inc/defines.hpp>

enum CameraRequestType
{
	registerForCamera,
	deregisterForCamera,
	changeFps
};

struct CameraRequest
{
	u8 cameraType;
	u8 fps;
};


#endif /* APPLICATION_INTERFACE_MESSAGE_CAMERAREQUEST_HPP_ */
