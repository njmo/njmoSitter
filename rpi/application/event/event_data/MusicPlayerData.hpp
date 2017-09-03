/*
 * MusicPlayerData.hpp
 *
 *  Created on: Jul 17, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_EVENT_EVENT_DATA_MUSICPLAYERDATA_HPP_
#define APPLICATION_EVENT_EVENT_DATA_MUSICPLAYERDATA_HPP_
#include <inc/defines.hpp>

enum MusicPlayerRequestType
{
	playMusic=0,
	stopMusic,
  getSongList,
	changeMusic,
	reloadMusic,
	pauseMusic,
	unPauseMusic,
  changeVolume
};

struct MusicPlayerData
{
	MusicPlayerRequestType type;
	u8 songId;
};

#endif /* APPLICATION_EVENT_EVENT_DATA_MUSICPLAYERDATA_HPP_ */
