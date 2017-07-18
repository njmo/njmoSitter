/*
 * MusicPlayer.cpp
 *
 *  Created on: Jul 17, 2017
 *      Author: njmo
 */

#include "MusicPlayer.hpp"

namespace device {

MusicPlayer::MusicPlayer()
	: state(unconfigured)
{
	// TODO Auto-generated constructor stub

}

MusicPlayer::MusicPlayer(std::string)
: state(unconfigured)
{

}
void MusicPlayer::initialize()
{

}

void MusicPlayer::stop()
{

}

void MusicPlayer::play(std::string)
{

}

void MusicPlayer::changeDirectory(std::string)
{

}
std::list<std::string> MusicPlayer::getSongs()
{
	return std::list<std::string>();
}

PlayerState MusicPlayer::getMusicPlayerState()
{
	return playing;
}

MusicPlayer::~MusicPlayer() {
	// TODO Auto-generated destructor stub
}

} /* namespace device */
