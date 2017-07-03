/*
 * Logger.cpp
 *
 *  Created on: Jun 28, 2017
 *      Author: njmo
 */

#include "Logger.hpp"
namespace utils{

Logger::~Logger() {
	// TODO Auto-generated destructor stub
}

void Logger::log(std::string msg)
{
	time_t tm =time(NULL );
	std::string timeInString(ctime(&tm));
	timeInString.pop_back();

	std::cout << timeInString << "\t" << msg << std::endl;
}

void Logger::logInfo(std::string msg)
{
	infos++;
	log(msg);
}
void Logger::logError(std::string msg)
{
	errors++;
	log(msg);
}
void Logger::logWarning(std::string msg)
{
	warnings++;
	log(msg);
}
}//namespace utils
