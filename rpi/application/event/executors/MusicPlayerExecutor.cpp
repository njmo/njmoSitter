/*
 * MusicPlayerExecutor.cpp
 *
 *  Created on: Jul 17, 2017
 *      Author: njmo
 */

#include "MusicPlayerExecutor.hpp"

namespace event {
namespace executor {

MusicPlayerExecutor::MusicPlayerExecutor()
{
  musicPlayer.initialize();
  readSongs();
}

MusicPlayerExecutor::~MusicPlayerExecutor() 
{

}

void MusicPlayerExecutor::readSongs()
{
  DIR* FD;
  struct dirent* in_file;

  if (NULL == (FD = opendir ("/home/pi/songs"))) 
  {
      fprintf(stderr, "Error : Failed to open input directory - %s\n", strerror(errno));
      //return 1;
  }

  while ((in_file = readdir(FD))) 
  {
      if (!strcmp (in_file->d_name, "."))
          continue;
      if (!strcmp (in_file->d_name, ".."))    
          continue;

      const std::string fileName = in_file->d_name;
      if( getFileExtension(fileName) == "wav" )
      {
        aviavableSongs.push_back(fileName); 
        nannyLogInfo("Found file " + fileName);
      }
  }
}

Response* MusicPlayerExecutor::execute(void *_data)
{
	Response* response = reinterpret_cast<Response *>(allocate<MusicPlayerResponse>());
	response->status = Reponse_Ok;
	response->type = WithoutResponse;

	MusicPlayerData *data = reinterpret_cast<MusicPlayerData*>(_data);

	switch(data->type)
	{
		case stopMusic:
    {
			nannyLogInfo("stoping Music");
			musicPlayer.stop();
			break;
    }
    case changeVolume:
    {
      nannyLogInfo("Changing volume");
      musicPlayer.changeVolume(data->songId);
      break;
    }
		case pauseMusic:
    {
			nannyLogInfo("pause Music");
			musicPlayer.pause();
			break;
    }
    case playMusic:
    {
      musicPlayer.play("/home/pi/songs/" + aviavableSongs.at(data->songId));
      break;
    }
    case getSongList:
    {
      MusicPlayerResponse *resp = reinterpret_cast<MusicPlayerResponse*>(response->data);
      response->status = Reponse_Ok;
      response->type = WithReponse;
      json j(aviavableSongs);
      nannyLogInfo(j.dump());
      memcpy(resp->songList,j.dump().c_str(),j.dump().size());
    }
		default:
			break;
	}
	return response;
}

} /* namespace executor */
} /* namespace event */
