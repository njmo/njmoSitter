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

namespace device {

enum PlayerState
{
	playing,
	stopped,
	configured,
	unconfigured
};

class MusicPlayer
{
public:
	MusicPlayer();
	void initialize();

	void stop();
	void play(std::string);

  void pause(){}
  void resume(){}

	PlayerState getState();

	virtual ~MusicPlayer();
private:
	PlayerState state;
};

} /* namespace device */

#endif /* APPLICATION_DEVICE_MUSICPLAYER_HPP_ */
