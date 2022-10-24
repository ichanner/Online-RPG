#pragma once
#define WIN32_LEAN_AND_MEAN
#include "SFML/Network.hpp"
#include <iostream>
#include <strstream>
#include<sstream>
#include "map.h"
#include <enet/enet.h>
#include<dos.h> 
#include<conio.h>
#include <string>
#include <sstream>
#include <tchar.h>
#include<chrono>
#include <fstream>
#include "ENetNetwork.h"
#include "PlayerSystem.h"
#include "Chat.h"
#include "EnemySpawner.h"
#include <vector>
#include <list>
#include <string>
#include <thread>
class Server
{
	
private:


	

	bool running;
	unsigned short port;
	unsigned int connected;
	unsigned int otherEnemyPlayerId;
	int enemySpawnerId;
	int otherEnemySpawnerId;


	class PlayerSystem* player;
	class Chat* chat;
	class ENetNetwork* enet;
	std::map<int, class EnemySpawner*> enemy;

	void initValues();
	void initEnet();

	bool recieveEnemySpawners(ENetHost* server, ENetPacket enetPacket);

public:

	Server();
	virtual ~Server();

	void update();

	void run(unsigned int port);
	void disconnect();

};

