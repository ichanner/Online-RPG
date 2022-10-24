
#include "Game.h"
#include<iostream>
#include <mysql.h>
using namespace std;
MYSQL* connection;

int main() {
	Game game;
	game.run();
	connection = mysql_init(0);
	connection = mysql_real_connect(connection, "localhost", "root", "", "rpg", 3306, NULL, 0);

	if (connection) {

		std::cout << "connected to server!";
	}
	else {

		std::cout << "couldn't connect!";
	}
	return 0;
}