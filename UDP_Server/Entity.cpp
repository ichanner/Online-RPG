#include "Entity.h"

Entity::Entity()
{
}

sf::Vector2f Entity::getDirection()
{
    return direction;
}

sf::Vector2f Entity::getVelocity()
{   
    return velocity;
}

unsigned int Entity::getId()
{
    return id;
}

sf::Vector2f Entity::getPosition()
{
    return this->entity.getPosition();
}

int Entity::getMovementState()
{
    return movementState;
}

void Entity::setPosition(float pos_x, float pos_y)
{
    this->entity.setPosition(pos_x, pos_y);
}

void Entity::setVelocity(float velocity_x, float velocity_y)
{
    this->velocity = sf::Vector2f(velocity_x, velocity_y);
}

void Entity::setDirection(float dir_x, float dir_y)
{
    this->direction = sf::Vector2f(dir_x, dir_y);
}

void Entity::setId(unsigned int id)
{
    this->id = id;
}

void Entity::setMovementState(int state)
{
    this->movementState = state;
}

void Entity::move(float dir_x, float dir_y)
{
    this->entity.move(dir_x, dir_y);
}
