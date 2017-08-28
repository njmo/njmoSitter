#ifndef APPLICATION_DEVICE_MICROPHONE_HPP_
#define APPLICATION_DEVICE_MICROPHONE_HPP_

#include <utils/Logger/Logger.hpp>
#include <string>
#include <alsa/asoundlib.h>

#include <math.h>

#define PCM_DEVICE_CAPTURE "plughw:CARD=II,DEV=0"
#define BUFFER_SIZE 1024


namespace device {

enum MicrophoneState 
{
	recording,
	configuredm,
  failedOnConfigurationm,
	unconfiguredm
};

class Microphone
{
public:
  Microphone();
	void initialize();
  virtual ~Microphone();

private:
  double rms(short *buffer);
  MicrophoneState state;
  u64 frames;
  snd_pcm_t *pcm_handle;
};

} // namespace device

#endif /* APPLICATION_DEVICE_MICROPHONE_HPP_ */
