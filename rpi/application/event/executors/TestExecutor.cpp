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
	void *msg = allocate<TestResponse>();
	Response* resp = reinterpret_cast<Response *>(msg);
	resp->status = Reponse_Ok;
	resp->type = WithReponse;
	TestResponse *tr = reinterpret_cast<TestResponse *>(resp->data);
	tr->a = 2;
	tr->b = 5;
	return resp;
}

} // namespace executor
} /* namespace event */
