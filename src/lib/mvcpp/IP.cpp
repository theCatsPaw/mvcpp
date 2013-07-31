/*
 * IP.cpp
 *
 *  Created on: 23.07.2013
 *      Author: pharno
 */

#include "IP.h"

#include <stdio.h>
#include <sstream>
#include <string>
using namespace std;


namespace mvcpp {

IP::IP(long ip) {
	octets[3] = ip & 0xFF;
	octets[2] = (ip >> 8) & 0xFF;
	octets[1] = (ip >> 16) & 0xFF;
	octets[0] = (ip >> 24) & 0xFF;
}

IP::~IP() {
	// TODO Auto-generated destructor stub
}

string IP::toString(){
	stringstream ss;
	ss 	<< "IP<"
		<< int(octets[0]) << "."
		<< int(octets[1]) << "."
		<< int(octets[2]) << "."
		<< int(octets[3]) << ">";

	return ss.str();
}



} /* namespace mvcpp*/
