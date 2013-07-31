#include <stdio.h>
#include <string>
#include <sstream>


using namespace std;


#include "lib/mongoose/mongoose.h"
#include "lib/mvcpp/logging.h"
#include "lib/mvcpp/mvcpp.h"

#include "app/gensrc/Config.hpp"

Config conf;
using namespace mvcpp;
Mvcpp framework;

/**
* This function will be called by mongoose on every new request. Mvcpp::handle(struct mg_connection *conn)
*/
static int begin_request_handler(struct mg_connection *conn) {

	return framework.handle(conn);

}


int main(void) {
	Logger log = Logger("main");
	log.setLevel(mvcpp::Level::TRACE);
	log.trace("main()");

	struct mg_context *ctx;
	struct mg_callbacks callbacks;

	// List of options. Last element must be NULL.
	const char *options[] = { "listening_ports", conf.getPort().c_str(), NULL };

	log.trace("setting callbacks");
	// Prepare callbacks structure. We have only one callback, the rest are NULL.
	memset(&callbacks, 0, sizeof(callbacks));
	callbacks.begin_request = begin_request_handler;

	// Start the web server.
	stringstream ss;

	ss << "starting server " << mg_version() << " on port :" << options[1];

	log.info(ss.str());
	ctx = mg_start(&callbacks, NULL, options);

	// Wait until user hits "enter". Server is running in separate thread.
	// Navigating to http://localhost:8080 will invoke begin_request_handler().
	getchar();

	// Stop the server.
	mg_stop(ctx);

	log.info("shutting down");
	return 0;
}
