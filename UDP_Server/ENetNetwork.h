#pragma once
#define WIN32_LEAN_AND_MEAN
#include "SFML/Network.hpp"
#include <iostream>
#include <strstream>
#include<sstream>
#include "map.h"
#include "Player.h"
#include <enet/enet.h>
#include<dos.h> 
#include<conio.h>
#include <string>
#include <sstream>
#include <tchar.h>
#include<chrono>
#include <fstream>

class ENetNetwork
{

	private:

		ENetHost* server;
		ENetEvent enetEvent;
		ENetAddress address;
		
		void initEnet();

	public:

		ENetNetwork(unsigned int port, size_t maxPlayers = 32, size_t channels = 1, enet_uint32 incomingBandwidth = 0, enet_uint32 outgoingBandwidth = 0);
		virtual ~ENetNetwork();

		void brodcastPacket(ENetHost* server, sf::Packet packet, size_t channels, int flag);

		ENetEvent* getEvent();
		ENetHost* getServer();
};

