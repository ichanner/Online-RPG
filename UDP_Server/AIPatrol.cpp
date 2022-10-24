#include "AIPatrol.h"

int AI::AIPatrol::generateMovement(float start, float end, sf::Vector2f range)
{
    counter++;



    if (counter >= end) {

        counter = 0;
        randomnMovement = 0;
    }

    if (counter >= start) {

        if (counter == start) {

            this->randomnMovement = rand() % ((6 + 3) + 3);
        }


        return randomnMovement;
    }
}
