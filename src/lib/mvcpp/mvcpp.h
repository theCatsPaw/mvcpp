/*
 * mvcpp.h
 *
 *  Created on: 15.07.2013
 *      Author: pharno
 */

#ifndef MVCPP_H_
#define MVCPP_H_

#include "logging.h"
namespace mvc {
class mvcpp {

private:
	Logger log = Logger("Request");

public:
	mvcpp();
	virtual ~mvcpp();

	int handle(struct mg_connection *conn);
};
} // namespace mvc
#endif /* MVCPP_H_ */
