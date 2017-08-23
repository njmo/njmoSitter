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

void MusicPlayer::initialize()
{
  state = configured;

}

void MusicPlayer::stop()
{

}

void MusicPlayer::play(std::string)
{

}

PlayerState MusicPlayer::getState()
{
	return state;
}

MusicPlayer::~MusicPlayer() {
	// TODO Auto-generated destructor stub
}

} /* namespace device */
