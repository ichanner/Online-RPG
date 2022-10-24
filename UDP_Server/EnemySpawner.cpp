#include "EnemySpawner.h"


EnemySpawner::EnemySpawner(float maxEnemies, float frequency, unsigned int id)
{
	this->maxEnemies = maxEnemies;
	this->frequency = frequency;
	this->enemySpawnerId = id;

}

void EnemySpawner::update(ENetHost* server, std::map<int, Player*>& players)
{
	sf::Packet sendPacket;
	std::string sendType = "ENEMYSPAWN";

	if (maxEnemies > this->enemies.size()) {

		counter++;

		if (counter > frequency) {

			enemyId = rand() % INT_MAX;
			int type = 0;

			sendPacket << sendType << enemyId << enemySpawnerId << type;

			this->enemies[enemyId] = new Enemy(enemyId, type, enemySpawnerId);

			this->enet->brodcastPacket(server, sendPacket, 0, 8);
			
			counter = 0;
		}
	}

	for (auto& jt : players) {

		for (auto& it : this->enemies) {

			it.second->lookForPlayer(jt);
		}
	}

	for (auto& it : this->enemies) {

		it.second->brodcastLocomotion(server);
	}
			
}

void EnemySpawner::updateEnemies(ENetHost* server, ENetPacket enetPacket)
{
	sf::Packet receptionPacket;
	sf::Packet typePacket;

	std::string recievingDataType;
	std::string sentDataType;

	receptionPacket.append(enetPacket.data, enetPacket.dataLength);
	typePacket.append(enetPacket.data, enetPacket.dataLength);

	typePacket >> recievingDataType;

	if (recievingDataType == "ENEMYUPDATE") {

		if (receptionPacket >> recievingDataType >> otherEnemyId >> pos_x >> pos_y) {

			this->enemies[otherEnemyId]->setPositon(pos_x, pos_y);
		}
	}
}
