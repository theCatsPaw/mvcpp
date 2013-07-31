/*
 * logging.cpp
 *
 *  Created on: 22.07.2013
 *      Author: pharno
 */

#include "logging.h"

namespace mvcpp {


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
	lvl = Level::INFO;
}

void Logger::log(string toLog, Level::LEVEL logLevel) {
	if (logLevel >= lvl) {
		LOGSTREAM<< level_toString[logLevel] << " ¦ " << name << " ¦ " << toLog << std::endl;
	}
}

void Logger::setLevel(Level::LEVEL logLevel) {
	lvl = logLevel;
}

void Logger::trace(string toLog) {
	log(toLog, Level::TRACE);
}

void Logger::debug(string toLog) {
	log(toLog, Level::DEBUG);
}

void Logger::info(string toLog) {
	log(toLog, Level::INFO);
}

void Logger::warn(string toLog) {
	log(toLog, Level::WARN);
}

void Logger::error(string toLog) {
	log(toLog, Level::ERROR);
}

void Logger::critical(string toLog) {
	log(toLog, Level::CRITICAL);
}


} //namespace mvc

