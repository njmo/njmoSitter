/*
 * VoiceRecorderExecutor.cpp
 *
 *  Created on: Jul 26, 2017
 *      Author: njmo
 */

#include "VoiceRecorderExecutor.hpp"

namespace event {
namespace executor {

VoiceRecorderExecutor::VoiceRecorderExecutor() 
{
  microphone.initialize();
}

Response* VoiceRecorderExecutor::execute(void *data)
{
  MicrophoneData *mic_data = reinterpret_cast<MicrophoneData*>(data);

	Response* resp = reinterpret_cast<Response *>(allocate<VideoRecorderResponse>());
  resp->status = Reponse_Ok;
  resp->type = WithoutResponse;

  if(mic_data->type == 0)
  {
    microphone.startRecording();
  }
  else if(mic_data->type == 1)
  {
    microphone.stopRecording();
  }
  else if(mic_data->type == 2)
  {
    resp->status = Reponse_Ok;
    resp->type = WithReponse;
    VideoRecorderResponse *vrResp = reinterpret_cast<VideoRecorderResponse *>(resp->data);
    vrResp->state = (microphone.isCrying())?VideoRecorderState::Loud:VideoRecorderState::notLoud;
  }

	return resp;
}
VoiceRecorderExecutor::~VoiceRecorderExecutor() {
	// TODO Auto-generated destructor stub
}

} /* namespace executor */
} /* namespace event */
