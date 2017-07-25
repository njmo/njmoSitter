/*
 * Logger.hpp
 *
 *  Created on: Jun 28, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_UTILS_LOGGER_LOGGER_HPP_
#define APPLICATION_UTILS_LOGGER_LOGGER_HPP_
#include <string>
#include <list>
#include <iostream>
#include <inc/defines.hpp>
#include <ctime>

#define nannyLogInfo(x) utils::Logger::getLogger().logInfo("INF/" + std::string(__FILE__).substr(std::string(__FILE__).find_last_of("//") + 1) + "/" + std::string(__FUNCTION__) + ": " + x)
#define nannyLogError(x) utils::Logger::getLogger().logError("ERR/" + std::string(__FILE__).substr(std::string(__FILE__).find_last_of("//") + 1) + "/" + std::string(__FUNCTION__) + ": " + x)
#define nannyLogWarning(x) utils::Logger::getLogger().logWarning("WRN/" + std::string(__FILE__).substr(std::string(__FILE__).find_last_of("//") + 1) + "/" + std::string(__FUNCTION__) + ": " + x)

namespace utils{

enum LogLevel
{
	WithoutRestriction=0,
};

struct LogLevelGuard
{
	void activateLogLevel(LogLevel);
	void deactivateLogLevel(LogLevel);

	bool canBePrinted(LogLevel);

	u64 flags;
};

struct Source
{
	u32 sourceId;

	virtual void flush() = 0;
	virtual void push() = 0;
	virtual void init() = 0;
	virtual void close() = 0;

	virtual ~Source() {}
};

class Logger {
public:
	static Logger& getLogger()
	{
		static Logger log;
		return log;
	}
	void logInfo(std::string);
	void logError(std::string);
	void logWarning(std::string);
	/*void logFunctionalityInfo(LogLevel,std::string);
	void logFunctionalityError(LogLevel,std::string);
	void logFunctionalityWarning(LogLevel,std::string);

	void registerNewLoggerSource(Source *);
	void unregisterLoggerSource(u32);
	*/
	virtual ~Logger();
private:
	Logger()
		: errors(0),
		  warnings(0),
		  infos(0)
	{

	}
	void log(std::string);

	u64 errors;
	u64 warnings;
	u64 infos;

	//std::list<Source*> sources;
	//LogLevelGuard logLevelGuard;
};

}// namespace utils
#endif /* APPLICATION_UTILS_LOGGER_LOGGER_HPP_ */
