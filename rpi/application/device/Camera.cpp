/*
 * Camera.cpp
 *
 *  Created on: Aug 21, 2017
 *      Author: njmo
 */

#include "Camera.hpp"

namespace device {

Camera::Camera()
	: cap(0)
{
	if (!cap.isOpened()) {
		 nannyLogError("OpenCV Failed to open camera");
	}
	Mat m;
	cap >> m;
}


void Camera::getFrame(CameraCaptureResponse &response)
{
	Mat frame,send;
	int jpegqual = 80;
	std::vector < uchar > encoded;
	cap >> frame;
	resize(frame, send, Size(800, 600), 0, 0, INTER_LINEAR);
	std::vector < int > compression_params;
	compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
	compression_params.push_back(jpegqual);

	imencode(".jpg", send, encoded, compression_params);
	imshow("send", send);
	int total_pack = 1 + (encoded.size() - 1) / 4096 ;

	const u32 sizeOfFrame = encoded.size();
	response.size = sizeOfFrame;
	memcpy(response.frame,&encoded,sizeOfFrame);
}

Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

} /* namespace device */
