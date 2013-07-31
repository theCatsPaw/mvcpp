/*
 * Request.h
 *
 *  Created on: 22.07.2013
 *      Author: pharno
 */

#ifndef REQUEST_H_
#define REQUEST_H_


#include "../mongoose/mongoose.h"

#include "logging.h"
#include "IP.h"

#include <string>

namespace mvcpp {

class Request {

private:
	Logger log = Logger("Request");
	IP ip;

public:

	Request(mg_request_info);
	virtual ~Request();
	std::string toString();
	//IP getIp();

};

} /* namespace mvcpp*/
#endif /* REQUEST_H_ */
