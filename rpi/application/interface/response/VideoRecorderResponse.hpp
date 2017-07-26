/*
 * VideoRecorderResponse.hpp
 *
 *  Created on: Jul 26, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_INTERFACE_RESPONSE_VIDEORECORDERRESPONSE_HPP_
#define APPLICATION_INTERFACE_RESPONSE_VIDEORECORDERRESPONSE_HPP_
#include <inc/defines.hpp>

enum VideoRecorderState
{
	Loud=0,
	notLoud
};

struct VideoRecorderResponse
{
	VideoRecorderState state;
};


#endif /* APPLICATION_INTERFACE_RESPONSE_VIDEORECORDERRESPONSE_HPP_ */
