#pragma once
#include "SFML/Network.hpp"
#include <iostream>
#include "Server.h"
#include "ENetNetwork.h"
class Chat
{
private:

	unsigned int userId;
	std::string message;

	std::string otherMessage;
	unsigned int otherId;

	class ENetNetwork* enet;

public:

	Chat();

	void brodcastMessage(ENetHost* server, ENetPacket enetPacket);

};

