/*
 * Messages.hpp
 *
 *  Created on: Apr 11, 2017
 *      Author: njmo
 */

#ifndef MESSAGES_HPP_
#define MESSAGES_HPP_

#include "defines.hpp"

namespace server
{

struct Message
{
	msgID id;
}__attribute__((__packed__));

}// namespace server


#endif /* MESSAGES_HPP_ */
