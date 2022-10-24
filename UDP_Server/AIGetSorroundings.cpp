#include "AIGetSorroundings.h"

float AI::AIGetSorroundings::getRawDistance(sf::Vector2f self, sf::Vector2f target)
{

    float x = target.x - self.x;
    x *= x;
    float y = target.y - self.y;
    y *= y;
    return sqrt(x+y);
	//float distance = (abs(sqrt( ((target.x - self.x) * (target.x - self.x)) + ((target.y - self.y) * (target.y - self.y)) )));
	//return distance;
}