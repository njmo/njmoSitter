#include "Microphone.hpp"

namespace device {

Microphone::Microphone()
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

  snd_pcm_prepare (pcm_handle);

/*
  short* buf = NULL;
  float result = 0.0f;
  buf = (short*)malloc(BUFFER_SIZE*2);
  while(1)
  {
    short buffer[512];
    if (snd_pcm_readi (pcm_handle, buffer, 256) == 256)
    {
        // Compute the maximum peak value
        for (int i = 0; i < 512; ++i)
        {
            // Substitute better algorithm here if needed
            float s = buffer[i] / 32768.0f;
            if (s < 0) s *= -1;
            if (result < s) result = s;
        }
    } 
    if(result > 0.005)
      nannyLogInfo("dB " + std::to_string(result));
    result = 0;
  }*/
}

double Microphone::rms(short *buffer)
{
  int i;
  long int square_sum = 0.0;
  for(i=0; i<BUFFER_SIZE/2; i++) {
    square_sum += (buffer[i] * buffer[i]);
  }

  double result = sqrt(square_sum/BUFFER_SIZE/2);
  return result;
}
Microphone::~Microphone()
{

}

} // namespace device
