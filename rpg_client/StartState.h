#pragma once
#include "State.h"

class StartState : public State
{
private:
	Logo poop;
	sf::RenderWindow* window;
	DevTools debug;

	void Keybinds();
public:
	StartState(sf::RenderWindow* window, std::map<std::string, int>* keys, std::stack<State*>*states);
	virtual ~StartState();
	void draw(sf::RenderTarget* target = 0);
	void update(const float& time);
	void input(const float& time);
	void onClosed();

};

