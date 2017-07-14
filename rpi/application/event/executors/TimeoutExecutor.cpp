/*
 * TimeoutExecutor.cpp
 *
 *  Created on: Jul 14, 2017
 *      Author: njmo
 */

#include "TimeoutExecutor.hpp"

namespace event {
namespace executor {

TimeoutExecutor::TimeoutExecutor() {
	// TODO Auto-generated constructor stub

}

Response* TimeoutExecutor::execute(void *)
{
	nannyLogInfo("Executing timeout");

	Response * response =  new Response;
	response->status = Reponse_Ok;
	response->type = WithoutResponse;
	return response;
}

TimeoutExecutor::~TimeoutExecutor() {
	// TODO Auto-generated destructor stub
}

} // namespace executor
} // namespace event
