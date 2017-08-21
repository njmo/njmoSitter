/*
 * Camera.hpp
 *
 *  Created on: Aug 21, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_DEVICE_CAMERA_HPP_
#define APPLICATION_DEVICE_CAMERA_HPP_
#include <interface/response/CameraCaptureResponse.hpp>
#include <inc/defines.hpp>
#include "opencv2/opencv.hpp"
#include <cstring>
#include <utils/Logger/Logger.hpp>
#include <vector>

using namespace cv;

namespace device {

class Camera {
public:
	Camera();
	void getFrame(CameraCaptureResponse &);
	virtual ~Camera();
private:

	VideoCapture cap;
};

} /* namespace device */

#endif /* APPLICATION_DEVICE_CAMERA_HPP_ */
