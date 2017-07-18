/*
 * MusicPlayerExecutor.hpp
 *
 *  Created on: Jul 17, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_EVENT_EXECUTORS_MUSICPLAYEREXECUTOR_HPP_
#define APPLICATION_EVENT_EXECUTORS_MUSICPLAYEREXECUTOR_HPP_
#include <inc/defines.hpp>
#include <utils/Logger/Logger.hpp>
#include <event/queue/Response.hpp>

#include <event/event_data/MusicPlayerData.hpp>
#include <device/MusicPlayer.hpp>

namespace event {
namespace executor {

class MusicPlayerExecutor {
public:
	MusicPlayerExecutor();
	Response* execute(void *);
	virtual ~MusicPlayerExecutor();
private:

	device::MusicPlayer musicPlayer;
	std::string currentlyPlayingSong;
};

} /* namespace executor */
} /* namespace event */

#endif /* APPLICATION_EVENT_EXECUTORS_MUSICPLAYEREXECUTOR_HPP_ */
