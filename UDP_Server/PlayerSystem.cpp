#include "PlayerSystem.h"


PlayerSystem::PlayerSystem() 
{
}

void PlayerSystem::brodcastPlayerLocomotion(ENetHost* server, ENetPacket enetPacket)
{

	sf::Packet receptionPacket;
	sf::Packet typePacket;
	std::string recievingDataType;
	std::string sentDataType;

	receptionPacket.append(enetPacket.data, enetPacket.dataLength);
	typePacket.append(enetPacket.data, enetPacket.dataLength);

	typePacket >> recievingDataType;
	
	if (recievingDataType == "PLAYERS") {
	
		if (receptionPacket >> recievingDataType >> otherCounter >> otherId >> otherMov >> Other_Pos_x >> Other_Pos_y >> other_Velocity_X >> other_Velocity_Y) {

			receptionPacket << sentDataType << counter << userId << mov << Local_Pos_x << Local_Pos_y << velocity_X << velocity_Y;

			counterMap[otherId] = otherCounter;

			if (counterMap[otherId] > prevCounter[otherId]) {

				this->enet->brodcastPacket(server, receptionPacket, 0, 1);

				this->activePlayers[otherId] = new Player(Other_Pos_x, Other_Pos_y, velocity_X, velocity_Y, otherId, mov);
			
				this->prevCounter[otherId] = counter;
			}

		}
	}
}

void PlayerSystem::brodcastDisconnectSignal(ENetHost* server, ENetPacket enetPacket)
{


	sf::Packet receptionPacket;
	sf::Packet typePacket;
	std::string sentDataType;
	std::string recievingDataType;

	receptionPacket.append(enetPacket.data, enetPacket.dataLength);
	typePacket.append(enetPacket.data, enetPacket.dataLength);

	typePacket >> recievingDataType;
	
	if (recievingDataType == "DISCONNECT") {

		if (receptionPacket >> recievingDataType >> otherId) {

			receptionPacket << sentDataType << userId;

			this->enet->brodcastPacket(server, receptionPacket, 0, 1);
		}

	}
}

std::map<int, Player*>&  PlayerSystem::getActivePlayers()
{
	return activePlayers;
}

