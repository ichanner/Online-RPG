#include "ENetNetwork.h"

void ENetNetwork::initEnet()
{
	if (enet_initialize() != 0)
	{
		fprintf(stderr, "An error occurred while initializing ENet.\n");
	}

	atexit(enet_deinitialize);
}

ENetNetwork::ENetNetwork(unsigned int port, size_t maxPlayers, size_t channels, enet_uint32 incomingBandwidth, enet_uint32 outgoingBandwidth)
{
	//Initizialize Enet
	
	this->initEnet();

	//Create host

	this->address.host = ENET_HOST_ANY;
	this->address.port = port;

	this->server = enet_host_create(&address, maxPlayers, channels, incomingBandwidth, outgoingBandwidth);

	if (server == NULL) {

		std::cout << "[NETWORK ERROR] UNABLE TO CREATE HOST" << std::endl;
	}
}

ENetNetwork::~ENetNetwork()
{
	enet_host_destroy(server);
}

void ENetNetwork::brodcastPacket(ENetHost* server, sf::Packet packet, size_t channels, int flag)
{
	ENetPacket* enetPacket = enet_packet_create(packet.getData(), packet.getDataSize(), flag);

	enet_host_broadcast(server, channels, enetPacket);
}

ENetEvent* ENetNetwork::getEvent()
{
	return &this->enetEvent;
}

ENetHost* ENetNetwork::getServer()
{
	return this->server;
}
