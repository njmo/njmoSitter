#include "Microphone.hpp"

namespace device {

Microphone::Microphone()
  : isBabyCrying(false),
		std::thread(&Microphone::detectCry, this),
    numberOfLoudFrames(0)
{

}

void Microphone::initialize()
{
  snd_pcm_hw_params_t *params;
  u32 pcm;
  u32 rate = 44100;

  const i32 channels = 2;
  if (pcm = snd_pcm_open(&pcm_handle, PCM_DEVICE_CAPTURE,
            SND_PCM_STREAM_CAPTURE, 0) < 0) 
  {
    nannyLogError("ERROR: Can't open " + std::string(PCM_DEVICE_CAPTURE) + " PCM device. " + snd_strerror(pcm));
    state = failedOnConfigurationm; 
    return ;
  }

  snd_pcm_hw_params_alloca(&params);
  snd_pcm_hw_params_any(pcm_handle, params);
  if (pcm = snd_pcm_hw_params_set_access(pcm_handle, params,
            SND_PCM_ACCESS_RW_INTERLEAVED) < 0) 
  {
    nannyLogError("ERROR: Can't set interleaved mode." + snd_strerror(pcm));
    state = failedOnConfigurationm; 
    return ;
  }

  if (pcm = snd_pcm_hw_params_set_format(pcm_handle, params,
            SND_PCM_FORMAT_S16_LE) < 0) 
  {
    nannyLogError("ERROR: Can't set format." + snd_strerror(pcm));
    state = failedOnConfigurationm; 
    return ;
  }

  if (pcm = snd_pcm_hw_params_set_channels(pcm_handle, params, channels) < 0) 
  {
    nannyLogError("ERROR: Can't set channels number. " + snd_strerror(pcm));
    state = failedOnConfigurationm; 
    return ;
  }

  if (pcm = snd_pcm_hw_params_set_rate(pcm_handle, params, rate, 0) < 0) 
  {
    nannyLogError("ERROR: Can't set rate." + snd_strerror(pcm));
    state = failedOnConfigurationm; 
    return ;
  }

  /* Write parameters */
  if (pcm = snd_pcm_hw_params(pcm_handle, params) < 0)
  {
    nannyLogError("ERROR: Can't set harware parameters." + snd_strerror(pcm));
    state = failedOnConfigurationm; 
    return ;
  }
  snd_pcm_hw_params_get_period_size(params, &frames, 0);

  state = configuredm;
}
void Microphone::detectCry()
{
  state = unconfiguredm;
  while(state!=configuredm)
    ;
  snd_pcm_prepare (pcm_handle);

  float result = 0.0f;
  int size = 512;
  short buffer[size];
  numberOfLoudFrames = 0;
  while(1){
    while(state != recording)
      ;
    if (snd_pcm_readi (pcm_handle, buffer, size/2) == size/2)
    {
        // Compute the maximum peak value
        for (int i = 0; i < size; ++i)
        {
            // Substitute better algorithm here if needed
            float s = buffer[i] / 32768.0f;
            if (s < 0) s *= -1;
            if (result < s) result = s;
        }
    } 
    if(result > 0.005)
      numberOfLoudFrames++;
    result = 0;
  }
}
void Microphone::startRecording()
{
  state = recording;
}
void Microphone::stopRecording()
{
  state = notRecording;
}
bool Microphone::isCrying()
{
  bool isCryin = numberOfLoudFrames > 50;
  numberOfLoudFrames = 0;
  return isCryin;
}

Microphone::~Microphone()
{

}

} // namespace device
