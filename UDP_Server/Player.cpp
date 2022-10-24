#include "Player.h"

Player::Player(float pos_x, float pos_y, float velocity_x, float velocity_y, unsigned int id, unsigned int movementState) : Entity()
{
	//this->setVelocity(velocity_x, velocity_y);
	this->id = id;
	///this->setMovementState(movementState);

	pos = sf::Vector2f(pos_x, pos_y);
}

sf::Vector2f Player::getPosition()
{
	return pos;
}

sf::Vector2f Player::getVelocity()
{
	return this->getVelocity();
}

unsigned int Player::getId()
{
	return id;
}

void Player::setPosition(float pos_x, float pos_y)
{
	this->setPosition(pos_x, pos_y);
}
