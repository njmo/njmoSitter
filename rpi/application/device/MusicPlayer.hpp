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

class MusicPlayer{
public:
	MusicPlayer();
	MusicPlayer(std::string);
	void initialize();

	void stop();
	//resume
	//pause
	void play(std::string);

	void changeDirectory(std::string);
	std::list<std::string> getSongs();

	PlayerState getMusicPlayerState();

	virtual ~MusicPlayer();
private:
	std::string directory;
	PlayerState state;
};

} /* namespace device */

#endif /* APPLICATION_DEVICE_MUSICPLAYER_HPP_ */
