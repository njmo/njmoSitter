/*
 * CameraCaptureResponse.hpp
 *
 *  Created on: Aug 21, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_INTERFACE_RESPONSE_CAMERACAPTURERESPONSE_HPP_
#define APPLICATION_INTERFACE_RESPONSE_CAMERACAPTURERESPONSE_HPP_
#include <inc/defines.hpp>

#define MAX_SIZE (1920*3) * (1080*3)

struct CameraCaptureResponse
{
  u32 size;
	u8 frame[MAX_SIZE];
};



#endif /* APPLICATION_INTERFACE_RESPONSE_CAMERACAPTURERESPONSE_HPP_ */
