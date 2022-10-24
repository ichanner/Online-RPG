#pragma once
#include "SFML/Network.hpp"
#include "Entity.h"

class Player : public Entity
{

private:

	int quadrant;
	int id;
	sf::Vector2f pos;

public:

	Player(float pos_x, float pos_y, float velocity_x, float velocity_y, unsigned int id, unsigned int movementState);

	sf::Vector2f getPosition();
	sf::Vector2f getVelocity();
	unsigned int getId();

	void setPosition(float pos_x, float pos_y);
};

