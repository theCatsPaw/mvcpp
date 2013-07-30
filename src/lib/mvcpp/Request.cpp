/*
 * Request.cpp
 *
 *  Created on: 22.07.2013
 *      Author: pharno
 */

#include "Request.h"
#include "logging.h"
#include "IP.h"


#include <sstream>
#include <string>


namespace mvc {

Request::Request(mg_request_info info): ip(info.remote_ip){
	log.info("new Request");
	std::stringstream ss;
	ip = IP(info.remote_ip);
	ss << "client: " << ip.toString() << ":" << info.remote_port;
	log.info(ss.str());
	// TODO Auto-generated constructor stub

}

Request::~Request() {
	// TODO Auto-generated destructor stub
}

std::string Request::toString(){
	std::stringstream ss;
	ss << "Request<" << ip.toString() << ">";
	return ss.str();
}

} /* namespace mvc */
