/*
 * MusicPlayer.hpp
 *
 *  Created on: Jul 17, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_DEVICE_MUSICPLAYER_HPP_
#define APPLICATION_DEVICE_MUSICPLAYER_HPP_
#include <string>
#include <list>
#include <utils/Logger/Logger.hpp>

#include <alsa/asoundlib.h>
#include <alsa/mixer.h>

#include <sndfile.h>
#include <thread>

namespace device {
#define PCM_DEVICE "hw:2"

enum PlayerState
{
	playing=0,
  paused,
	stopped,
	configured,
  failedOnConfiguration,
	unconfigured,
  changingMusic
};

class MusicPlayer : public std::thread
{
public:
	MusicPlayer();
	void initialize();

	void stop();
	void play(std::string);
  void changeVolume(u8);

  void mainLoop();

  void pause();
  void resume(){}

	PlayerState getState();

	virtual ~MusicPlayer();
private:
  u32 buff_size;
  snd_pcm_t *pcm_handle;
  volatile PlayerState state;
  SNDFILE *activeFile;
  u64 frames;

  snd_mixer_t *mix_handle;
  snd_mixer_selem_id_t *mix_sid;
  snd_mixer_elem_t *mix_elem;
};

} /* namespace device */

#endif /* APPLICATION_DEVICE_MUSICPLAYER_HPP_ */
