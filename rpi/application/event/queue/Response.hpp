/*
 * Response.hpp
 *
 *  Created on: Jul 13, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_EVENT_QUEUE_RESPONSE_HPP_
#define APPLICATION_EVENT_QUEUE_RESPONSE_HPP_

enum ResponseStatus
{
	Reponse_Ok,
	Reponse_Error
};
enum ReponseType
{
	WithReponse,
	WithoutResponse
};
struct Response
{
	ResponseStatus status;
	ReponseType type;
	u8 data[1];
};

#endif /* APPLICATION_EVENT_QUEUE_RESPONSE_HPP_ */
