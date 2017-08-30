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
  json j(aviavableSongs);
  nannyLogInfo(j.dump());
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
	MusicPlayerData *data = reinterpret_cast<MusicPlayerData*>(_data);
	switch(data->type)
	{
		case stopMusic:
			nannyLogInfo("stoping Music");
			//musicPlayer.stop();
			break;
    case playMusic:
    {
      musicPlayer.play("/home/pi/songs/" + aviavableSongs.at(data->songId));
      break;
    }
		default:
			break;
	}
	Response * response =  new Response;
	response->status = Reponse_Ok;
	response->type = WithoutResponse;
	return response;
}

} /* namespace executor */
} /* namespace event */
