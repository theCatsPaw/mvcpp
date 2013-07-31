/*
 * mvcpp.cpp
 *
 *  Created on: 15.07.2013
 *      Author: pharno
 */
#include "../mongoose/mongoose.h"

#include "mvcpp.h"
#include "Request.h"
#include "logging.h"

#include <iostream>

using namespace std;

namespace mvcpp {

Mvcpp::Mvcpp() {
	return;

}

Mvcpp::~Mvcpp() {
	return;
}

int Mvcpp::handle(struct mg_connection *conn){

	// pack request info in object
	const struct mg_request_info *request_info = mg_get_request_info(conn);


	Request r = Request(*request_info);

	log.info(r.toString());

	// route

	// call request url

	cout << request_info->request_method << " " << request_info->uri << endl;
	  char content[100];

	  // Prepare the message we're going to send
	  int content_length = snprintf(content, sizeof(content),
	                                "Hello from mongoose! Remote port: %d",
	                                request_info->remote_port);

	  // Send HTTP reply to the client
	  mg_printf(conn,
	            "HTTP/1.1 200 OK\r\n"
	            "Content-Type: text/plain\r\n"
	            "Content-Length: %d\r\n"        // Always set Content-Length
	            "\r\n"
	            "%s",
	            content_length, content);

	  // Returning non-zero tells mongoose that our function has replied to
	  // the client, and mongoose should not send client any more data.
	  return 1;
}

} //namespace mvc
