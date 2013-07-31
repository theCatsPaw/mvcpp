/*
 * logging.h
 *
 *  Created on: 17.07.2013
 *      Author: pharno
 */

#ifndef LOGGING_H_
#define LOGGING_H_


#include <iostream>
#include <time.h>
#include <vector>
#include <string.h>


using namespace std;


namespace mvcpp {


#ifndef LOGSTREAM
	#define LOGSTREAM std::cout
#endif

namespace Level {

enum LEVEL{
		TRACE = 0,
		DEBUG,
		INFO,
		WARN,
		ERROR,
		CRITICAL
	};

} // namespace Level


class Logger {
public:
	string name;

	Level::LEVEL lvl;


	Logger(string loggername);

	void log(string toLog, Level::LEVEL logLevel);

	void setLevel(Level::LEVEL logLevel);

	void trace(string toLog);

	void debug(string toLog);

	void info(string toLog);

	void warn(string toLog);

	void error(string toLog);

	void critical(string toLog);
};

#define LOG(name) LOGSTREAM <<__FILE__ <<"["<<__LINE__<<"] " << #name << " -> " << name << std::endl;
#define LOGSTR(str) LOGSTREAM <<__FILE__ <<"["<<__LINE__<<"] " <<  str << std::endl;


} // namespace mvc

#endif /* LOGGING_H_ */
