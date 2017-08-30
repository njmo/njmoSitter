/*
 * CameraData.hpp
 *
 *  Created on: Jul 27, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_INTERFACE_RESPONSE_MICROPHONEDATA_HPP_
#define APPLICATION_INTERFACE_RESPONSE_MICROPHONEDATA_HPP_

#define CAMERA_DATA_SIZE (800*3)*(600*3)

enum MicrophoneDataType
{
  startRecording=0,
  stopRecording,
  getInformation
};
struct MicrophoneData
{
	u8 type;
};



#endif /* APPLICATION_INTERFACE_RESPONSE_MICROPHONEDATA_HPP_ */
