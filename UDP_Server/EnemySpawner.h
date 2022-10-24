#pragma once

#include<vector>
#include<list>
#include<algorithm>
#include<array>
#include "SFML/Network.hpp"
#include <iostream>
#include "ENetNetwork.h"
#include "Player.h"
#include "Enemy.h"




class EnemySpawner
{

private:

	std::map<int, class Enemy*> enemies;

	float frequency;
	float counter;
	int enemySpawnerId;
	int maxEnemies;
	int enemyId;
	int otherEnemyId;
	float pos_x;
	float pos_y;

	class ENetNetwork* enet;

public:



	EnemySpawner(float maxEnemies, float frequency, unsigned int id);
	void update(ENetHost* server, std::map<int, Player*>& players);
	void updateEnemies(ENetHost* server, ENetPacket enetPacket);
	void updateSpawner(ENetHost* server, std::map<int, Player*>& players);
};

