/*
 * NannyResponse.hpp
 *
 *  Created on: Jul 26, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_INTERFACE_RESPONSE_NANNYRESPONSE_HPP_
#define APPLICATION_INTERFACE_RESPONSE_NANNYRESPONSE_HPP_
#include <inc/defines.hpp>

enum NannyResponseStatus
{
	Error=0,
	NannyOk
};
struct NoResponseData
{

};
struct NannyResponse
{
	u32 size;
	u8	id;
	u8	status;
	u8	data[1];
};


#endif /* APPLICATION_INTERFACE_RESPONSE_NANNYRESPONSE_HPP_ */
