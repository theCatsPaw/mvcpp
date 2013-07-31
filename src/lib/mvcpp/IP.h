/*
 * IP.h
 *
 *  Created on: 23.07.2013
 *      Author: pharno
 */

#ifndef IP_H_
#define IP_H_

#include <string>
using namespace std;

namespace mvcpp {

class IP {

public:
	char octets[4] = {0,0,0,0};

	IP(long);
	virtual ~IP();
	string toString();
};


} /* namespace mvcpp*/
#endif /* IP_H_ */
