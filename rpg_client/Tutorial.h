#pragma once
#include "State.h"

class Tutorial : public State
{

private:
	sf::RenderWindow* window;
	
	void Keybinds();

public:

	Tutorial(sf::RenderWindow* window, std::map<std::string, int>* keys, std::stack<State*>* states);

	virtual ~Tutorial();
	void update(const float& time);
	void draw(sf::RenderTarget* target = 0);
	void input(const float& time);
	void onClosed();

};

