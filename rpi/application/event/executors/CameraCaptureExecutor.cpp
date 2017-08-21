/*
 * CameraCaptureExecutor.cpp
 *
 *  Created on: Aug 21, 2017
 *      Author: njmo
 */

#include "CameraCaptureExecutor.hpp"

namespace event {
namespace executor {

CameraCaptureExecutor::CameraCaptureExecutor() {
	// TODO Auto-generated constructor stub

}


Response* CameraCaptureExecutor::execute(void *)
{
	CameraCaptureResponse response;
	camera.getFrame(response);

	Response *resp = reinterpret_cast<Response *>(allocate(response.size + 4));
	resp->status = Reponse_Ok;
	resp->type = WithReponse;
	memcpy(resp->data,&response,response.size + 4);
	return resp;
}

CameraCaptureExecutor::~CameraCaptureExecutor() {
	// TODO Auto-generated destructor stub
}

} /* namespace executor */
} /* namespace event */
