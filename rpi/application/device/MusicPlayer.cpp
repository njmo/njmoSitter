/*
 * MusicPlayer.cpp
 *
 *  Created on: Jul 17, 2017
 *      Author: njmo
 */

#include "MusicPlayer.hpp"

namespace device {

MusicPlayer::MusicPlayer()
	: state(unconfigured),
    buff_size(0)
{
	// TODO Auto-generated constructor stub

}

void MusicPlayer::initialize()
{
  u32 pcm;
  snd_pcm_hw_params_t *params;
  u32 rate = 44100;
  const i32 channels = 2;
  if (pcm = snd_pcm_open(&pcm_handle, PCM_DEVICE,
            SND_PCM_STREAM_PLAYBACK, 0) < 0) 
  {
    nannyLogError("ERROR: Can't open " + std::string(PCM_DEVICE) + " PCM device. " + snd_strerror(pcm));
    state = failedOnConfiguration; 
    return ;
  }

  snd_pcm_hw_params_alloca(&params);
  snd_pcm_hw_params_any(pcm_handle, params);
  if (pcm = snd_pcm_hw_params_set_access(pcm_handle, params,
            SND_PCM_ACCESS_RW_INTERLEAVED) < 0) 
  {
    nannyLogError("ERROR: Can't set interleaved mode." + snd_strerror(pcm));
    state = failedOnConfiguration; 
    return ;
  }

  if (pcm = snd_pcm_hw_params_set_format(pcm_handle, params,
            SND_PCM_FORMAT_S16_LE) < 0) 
  {
    nannyLogError("ERROR: Can't set format." + snd_strerror(pcm));
    state = failedOnConfiguration; 
    return ;
  }

  if (pcm = snd_pcm_hw_params_set_channels(pcm_handle, params, channels) < 0) 
  {
    nannyLogError("ERROR: Can't set channels number. " + snd_strerror(pcm));
    state = failedOnConfiguration; 
    return ;
  }

  if (pcm = snd_pcm_hw_params_set_rate(pcm_handle, params, rate, 0) < 0) 
  {
    nannyLogError("ERROR: Can't set rate." + snd_strerror(pcm));
    state = failedOnConfiguration; 
    return ;
  }

  /* Write parameters */
  if (pcm = snd_pcm_hw_params(pcm_handle, params) < 0)
  {
    nannyLogError("ERROR: Can't set harware parameters." + snd_strerror(pcm));
    state = failedOnConfiguration; 
    return ;
  }
  snd_pcm_hw_params_get_period_size(params, &frames, 0);

  buff_size = frames * channels * 2 /* 2 -> sample size */;

  //snd_pcm_hw_params_free (params);
  state = configured;
//  play("/home/pi/songs/wogrodku.wav");
}

void MusicPlayer::stop()
{

}

void MusicPlayer::play(std::string songName)
{
  SF_INFO sfinfo;
  SNDFILE *infile = NULL;
  int pcmrc,readcount;
  short* buf = NULL;
  infile = sf_open(songName.c_str(), SFM_READ, &sfinfo);

  nannyLogInfo("Starting to play : " + songName); 

  buf = (short*)malloc(buff_size);
  while ((readcount = sf_readf_short(infile, buf, frames))>0) {
      pcmrc = snd_pcm_writei(pcm_handle, buf, readcount);
      if (pcmrc == -EPIPE) {
          fprintf(stderr, "Underrun!\n");
          snd_pcm_prepare(pcm_handle);
      }
      else if (pcmrc < 0) {
          fprintf(stderr, "Error writing to PCM device: %s\n", snd_strerror(pcmrc));
      }
      else if (pcmrc != readcount) {
          fprintf(stderr,"PCM write difffers from PCM read.\n");
      }

  }
  snd_pcm_drain(pcm_handle);
  free(buf);
}

PlayerState MusicPlayer::getState()
{
	return state;
}

MusicPlayer::~MusicPlayer() {
  snd_pcm_close(pcm_handle);
	// TODO Auto-generated destructor stub
}

} /* namespace device */
