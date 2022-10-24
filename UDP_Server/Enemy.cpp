#include "Enemy.h"


Enemy::Enemy(unsigned int enemyId, int type, unsigned int enemySpawnerId, float tiggerDistance, float startPatrolDis, float endPatrolDis) : Entity()
{
	this->type = type;
	this->triggerDistance = tiggerDistance;
	this->enemyId = enemyId;
	this->enemySpawnerId = enemySpawnerId;
	this->startPatrolDis = startPatrolDis;
	this->endPatrolDis = endPatrolDis;
	state = IDLE;
}

void Enemy::brodcastLocomotion(ENetHost* server)
{
	std::string sentDataType = "ENEMIES";
	sf::Packet sendPacket;


	targetId = 27;

	switch (state) {
		
	case FOLLOW:
		
		sendPacket << sentDataType << enemyId << enemySpawnerId << type << targetId << state;
		break;

	case IDLE:

		sendPacket << sentDataType << enemyId << enemySpawnerId << type << targetId << patrol.generateMovement(500, 600, sf::Vector2f(3,6));
		break;

	}


	this->enet->brodcastPacket(server, sendPacket, 0, 8);
}

void Enemy::lookForPlayer(std::pair<const int, Player*>& player)
{


	std::cout << sorroundings.getRawDistance(this->getPosition(), player.second->getPosition()) << std::endl;


	if (((sorroundings.getRawDistance(this->getPosition(), player.second->getPosition()) < triggerDistance))) {
		
		///this->targetId = player.second->getId();
		this->state = FOLLOW;
	}
}



