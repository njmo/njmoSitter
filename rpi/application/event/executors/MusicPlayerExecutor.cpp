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
			musicPlayer.stop();
			break;
		default:
			break;
	}
	return nullptr;
}

} /* namespace executor */
} /* namespace event */
