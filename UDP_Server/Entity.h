#pragma once
#include "SFML/Network.hpp"
#include "SFML/Graphics.hpp"




class Entity
{

protected:

	sf::Sprite entity;

public:

	Entity();

	sf::Vector2f getDirection();
	sf::Vector2f getVelocity();
	sf::Vector2f getPosition();
	int getMovementState();
	unsigned int getId();

	void setPosition(float pos_x, float pos_y);
	void setVelocity(float velocity_x, float velocity_y);
	void setDirection(float dir_x, float dir_y);
	void setId(unsigned int id);
	void setMovementState(int state);

	void move(float dir_x, float dir_y);


private:

	sf::Vector2f velocity;
	sf::Vector2f direction;
	sf::Vector2f position;

	int movementState;

	unsigned int id;
};

