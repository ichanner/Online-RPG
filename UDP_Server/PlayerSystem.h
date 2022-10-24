#pragma once

#include "SFML/Network.hpp"
#include <iostream>
#include "map.h"
#include "Server.h"
#include "ENetNetwork.h"
#include "Player.h"

class PlayerSystem
{

private:

	int mov;
	int otherMov;

	float Local_Pos_x;
	float Local_Pos_y;
	float Other_Pos_x;
	float Other_Pos_y;

	int counter;
	int otherCounter;

	int userId;
	int otherId;

	float velocity_X;
	float velocity_Y;
	float other_Velocity_X;
	float other_Velocity_Y;

	std::string message;
	std::string otherMessage;
	
	std::map<int, int> counterMap;
	std::map<int, int> prevCounter;
	std::map<int, Player*> activePlayers;

	class ENetNetwork* enet;

public:

	PlayerSystem();

	void brodcastPlayerLocomotion(ENetHost* server, ENetPacket enetPacket);
	void brodcastDisconnectSignal(ENetHost* server, ENetPacket enetPacket);

	std::map<int, Player*>& getActivePlayers();

};

