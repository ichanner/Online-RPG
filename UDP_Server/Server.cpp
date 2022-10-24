#include "Server.h"

void Server::initValues()
{
	this->running = true;
	this->player = new PlayerSystem();
	this->chat = new Chat();


	this->enemy[1] = new EnemySpawner(0, 500, 1);
	this->enemy[2] = new EnemySpawner(1, 400, 2);
}

void Server::initEnet()
{
	this->enet = new ENetNetwork(port);
}

bool Server::recieveEnemySpawners(ENetHost* server, ENetPacket enetPacket)
{
	sf::Packet receptionPacket;
	sf::Packet typePacket;
	std::string recievingDataType;
	std::string sentDataType;

	receptionPacket.append(enetPacket.data, enetPacket.dataLength);
	typePacket.append(enetPacket.data, enetPacket.dataLength);

	typePacket >> recievingDataType;

	if (recievingDataType == "ENEMYSPAWNPOINTS") {
		std::cout << "Server got spawn points! \n";
		if (receptionPacket >> recievingDataType >> otherEnemySpawnerId << otherEnemyPlayerId) {

			std::cout << otherEnemySpawnerId << "\n";
			this->otherEnemySpawnerId++;
			this->enemy[this->otherEnemySpawnerId] = new EnemySpawner(10, 100, otherEnemySpawnerId);
		}
	}
}

Server::Server()
{
	this->initValues();
	this->initEnet();
}

Server::~Server()
{
}


void Server::update()
{

	while (running) { // Update loop

		if (enet_host_service(this->enet->getServer(), this->enet->getEvent(), 0) > 0) {

			switch (this->enet->getEvent()->type) {

			case ENET_EVENT_TYPE_CONNECT:

				connected++;
				std::cout << "A user connected!" << std::endl;
				
				break;

			case ENET_EVENT_TYPE_DISCONNECT:


				connected--;
				std::cout << "A user disconnected!" << std::endl;
				
				break;

			case ENET_EVENT_TYPE_RECEIVE:
				
				

				this->player->brodcastPlayerLocomotion(this->enet->getServer(), *this->enet->getEvent()->packet);
				this->player->brodcastDisconnectSignal(this->enet->getServer(), *this->enet->getEvent()->packet);
				
				this->chat->brodcastMessage(this->enet->getServer(), *this->enet->getEvent()->packet);
				
				//this->recieveEnemySpawners(this->enet->getServer(), *this->enet->getEvent()->packet);
				
				for (auto& it : this->enemy) {
					
					it.second->update(this->enet->getServer(), player->getActivePlayers());
				}

				enet_packet_destroy(this->enet->getEvent()->packet);

				break;

			}
		}
	}
}


void Server::run(unsigned int port)
{
	std::cout << "[NETWORK] THE SERVER HAS BEEN SUCCESSFULLY INITIZIALIZED ON PORT " << port << std::endl;

	this->port = port;

	this->initValues();
	this->initEnet();
	this->update();
}

void Server::disconnect()
{
}

