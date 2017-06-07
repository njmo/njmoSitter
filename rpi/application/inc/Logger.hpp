/*
 * Logger.hpp
 *
 *  Created on: Jun 5, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_INC_LOGGER_HPP_
#define APPLICATION_INC_LOGGER_HPP_

#include <string>

using std::string;

namespace app{

class Logger
{
public:
	void logInfo(string);
	void logError(string);
	void logWarning(string);
private:
	u32 errors;
	u32 warnings;
	u32 info;
};

} /* namespace app */



#endif /* APPLICATION_INC_LOGGER_HPP_ */
