#ifndef APPLICATION_DEVICE_MICROPHONE_HPP_
#define APPLICATION_DEVICE_MICROPHONE_HPP_

#include <utils/Logger/Logger.hpp>
#include <string>
#include <alsa/asoundlib.h>

#include <math.h>
#include <thread>

#define PCM_DEVICE_CAPTURE "hw:1"
#define BUFFER_SIZE 1024


namespace device {

enum MicrophoneState 
{
	recording,
  notRecording,
	configuredm,
  failedOnConfigurationm,
	unconfiguredm
};

class Microphone : public std::thread
{
public:
  Microphone();
  void detectCry();
  bool isCrying();
  void startRecording();
  void stopRecording();
	void initialize();
  virtual ~Microphone();

private:
  double rms(short *buffer);
  volatile  MicrophoneState state;
  volatile u64 numberOfLoudFrames;
  u64 frames;
  snd_pcm_t *pcm_handle;
};

} // namespace device

#endif /* APPLICATION_DEVICE_MICROPHONE_HPP_ */
