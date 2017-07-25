/*
 * RegisterResponse.hpp
 *
 *  Created on: Jul 25, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_INTERFACE_RESPONSE_REGISTERRESPONSE_HPP_
#define APPLICATION_INTERFACE_RESPONSE_REGISTERRESPONSE_HPP_

#include <inc/defines.hpp>
enum RegisterStatus
{
	registered,
	error
};

struct RegisterResponse
{
	u8 registerStatus;
	u32 assignedId;
};


#endif /* APPLICATION_INTERFACE_RESPONSE_REGISTERRESPONSE_HPP_ */
