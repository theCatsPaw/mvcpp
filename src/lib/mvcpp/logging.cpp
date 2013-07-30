/*
 * logging.cpp
 *
 *  Created on: 22.07.2013
 *      Author: pharno
 */

#include "logging.h"

namespace mvc {


string level_toString[] = {
		"TRACE   ",
		"DEBUG   ",
		"INFO    ",
		"WARN    ",
		"ERROR   ",
		"CRITICAL"
};

Logger::Logger(string loggername) {
	name = loggername;
	lvl = INFO;
}

void Logger::log(string toLog, LEVEL logLevel) {
	if (logLevel >= lvl) {
		LOGSTREAM<< level_toString[logLevel] << " ¦ " << name << " ¦ " << toLog << std::endl;
	}
}

void Logger::setLevel(LEVEL logLevel) {
	lvl = logLevel;
}

void Logger::trace(string toLog) {
	log(toLog, TRACE);
}

void Logger::debug(string toLog) {
	log(toLog, DEBUG);
}

void Logger::info(string toLog) {
	log(toLog, INFO);
}

void Logger::warn(string toLog) {
	log(toLog, WARN);
}

void Logger::error(string toLog) {
	log(toLog, ERROR);
}

void Logger::critical(string toLog) {
	log(toLog, CRITICAL);
}


} //namespace mvc

