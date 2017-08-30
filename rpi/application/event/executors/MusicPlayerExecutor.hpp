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
#include "EventExecutor.hpp"
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <inc/Messages.hpp>

#include <event/event_data/MusicPlayerData.hpp>
#include <interface/response/MusicPlayerResponse.hpp>
#include <device/MusicPlayer.hpp>

// downloaded from https://github.com/nlohmann/json
#include <utils/json.hpp>
using nlohmann::json;

namespace event {
namespace executor {

class MusicPlayerExecutor : public EventExecutor {
public:
	MusicPlayerExecutor();
	Response* execute(void *);
	virtual ~MusicPlayerExecutor();
private:
  void readSongs();
  std::string getFileExtension(const std::string& FileName)
  {
      if(FileName.find_last_of(".") != std::string::npos)
          return FileName.substr(FileName.find_last_of(".")+1);
      return "";
  }

	device::MusicPlayer musicPlayer;

	std::string currentlyPlayingSong;
  std::vector<std::string> aviavableSongs;
};

} /* namespace executor */
} /* namespace event */

#endif /* APPLICATION_EVENT_EXECUTORS_MUSICPLAYEREXECUTOR_HPP_ */
