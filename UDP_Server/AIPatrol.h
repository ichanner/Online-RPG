#pragma once
#include "SFML/Network.hpp"

namespace AI {

	class AIPatrol
	{
	
	private:

		int counter;
		int randomnMovement;
	
	public:

		int generateMovement(float start, float end, sf::Vector2f range);

	};


}