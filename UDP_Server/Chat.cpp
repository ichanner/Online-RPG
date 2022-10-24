#include "Chat.h"

Chat::Chat()
{
}

void Chat::brodcastMessage(ENetHost* server, ENetPacket enetPacket)
{


	sf::Packet receptionPacket;
	sf::Packet typePacket;

	std::string recievingDataType;
	std::string sentDataType;

	receptionPacket.append(enetPacket.data, enetPacket.dataLength);
	typePacket.append(enetPacket.data, enetPacket.dataLength);

	typePacket >> recievingDataType;

	if (recievingDataType == "CHAT") {

		if (receptionPacket >> recievingDataType >> otherMessage >> otherId) {

			receptionPacket << sentDataType << message << userId;

			this->enet->brodcastPacket(server, receptionPacket, 0, ENET_PACKET_FLAG_RELIABLE);
		}
	}
}
