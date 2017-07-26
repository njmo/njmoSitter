/*
 * VoiceRecorderExecutor.cpp
 *
 *  Created on: Jul 26, 2017
 *      Author: njmo
 */

#include "VoiceRecorderExecutor.hpp"

namespace event {
namespace executor {

VoiceRecorderExecutor::VoiceRecorderExecutor() {
	// TODO Auto-generated constructor stub

}

Response* VoiceRecorderExecutor::execute(void *)
{
	Response* resp = reinterpret_cast<Response *>(allocate<VideoRecorderResponse>());
	resp->status = Reponse_Ok;
	resp->type = WithReponse;
	VideoRecorderResponse *vrResp = reinterpret_cast<VideoRecorderResponse *>(resp->data);
	vrResp->state = VideoRecorderState::Loud;

	return resp;
}
VoiceRecorderExecutor::~VoiceRecorderExecutor() {
	// TODO Auto-generated destructor stub
}

} /* namespace executor */
} /* namespace event */
