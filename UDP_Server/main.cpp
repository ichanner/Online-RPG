#include "Server.h"

Server server;
int port;
int main() {
	
	std::cin >> port;

	server.run(port);
	return 0;
}