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
	static u32 f = 4;
	nannyLogInfo("Creating response");
	void *msg = allocate<TestResponse>();
	Response* resp = reinterpret_cast<Response *>(msg);
	resp->status = Reponse_Ok;
	resp->type = WithReponse;
	TestResponse *tr = reinterpret_cast<TestResponse *>(resp->data);
	tr->a = f++;
	tr->b = f++  + 2;
	return resp;
}

} // namespace executor
} /* namespace event */
