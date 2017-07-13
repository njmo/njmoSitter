/*
 * TestExecutor.cpp
 *
 *  Created on: Jun 27, 2017
 *      Author: njmo
 */

#include "TestExecutor.hpp"

namespace event {
namespace executor{

TestExecutor::TestExecutor() {
	// TODO Auto-generated constructor stub

}

TestExecutor::~TestExecutor() {
	// TODO Auto-generated destructor stub
}

Response* TestExecutor::execute(void *)
{
	nannyLogInfo("Creating response");
	Response* resp = new Response();
	resp->status = Reponse_Ok;
	resp->type = WithReponse;
	TestResponse *tr = new TestResponse;
	tr->a = 2;
	tr->b = 5;
	resp->data = reinterpret_cast<u8 *>(tr);
	return resp;
}

} // namespace executor
} /* namespace event */
