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
//	: musicPlayer(_player)
{
	// TODO Auto-generated constructor stub

}

MusicPlayerExecutor::~MusicPlayerExecutor() {
	// TODO Auto-generated destructor stub
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
