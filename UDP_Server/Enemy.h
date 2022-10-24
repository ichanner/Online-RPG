#pragma once

#include<vector>
#include<list>
#include<algorithm>
#include<array>
#include "SFML/Network.hpp"
#include <iostream>
#include "ENetNetwork.h"
#include "Player.h"
#include "AIGetSorroundings.h"
#include "Entity.h"
#include "AIPatrol.h"

enum EnemyType {

	PROVOKED,
	AGGRESSIVE
};

enum EnemyStates {

	IDLE,
	FOLLOW,
	ATTACK,
	ENEMY_UP,
	ENEMY_DOWN,
	ENEMY_RIGHT,
	ENEMY_LEFT,
	DAMAGE,
	RETREAT,
	DEAD,
	SPAWN
};


class Enemy : Entity
{
private:

	int type;
	int state;
	int targetId;
	int enemyId;
	float triggerDistance;
	unsigned int enemySpawnerId;
	float startPatrolDis;  
	float endPatrolDis;

	class AI::AIPatrol patrol;
	class ENetNetwork* enet;
	class AI::AIGetSorroundings sorroundings;

public:

	Enemy(unsigned int enemyId, int type, unsigned int enemySpawnerId, float tiggerDistance = 200.f, float startPatrolDis = 100, float endPatrolDis = 500);


	void brodcastLocomotion(ENetHost* server);
	void lookForPlayer(std::pair<const int, Player*>& player);


	sf::Vector2f getPosition() {

		return getPosition();
	}

	void setPositon(float x, float y) {

		setPosition(x, y);
	}

	int getTarget() {
		
		return this->targetId;
	}
	int getId() {

		return enemyId;
	}
};
