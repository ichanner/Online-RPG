#pragma once
#include "State.h"
#include "Register.h"
class Character : public State
{

private:
	sf::RenderWindow* window;
	std::map<std::string, class Button*> buttons;
	sf::Font font;
	sf::String playerInput;
	sf::Text playerText;
	void Keybinds();

public:

	Character(sf::RenderWindow* window, std::map<std::string, int>* keys, std::stack<State*>* states);

	virtual ~Character();
	void update(const float& time);
	void draw(sf::RenderTarget* target = 0);
	void input(const float& time);
	void updateButtons();
	void onClosed();

};
