#pragma once

#include "MenuTheme.h"
#include "MainMenu.h"
#include "State.h"
#include "dialogue.h"
class Confirm : public State
{
private:
	dialogue dial;
	sf::RenderWindow* window;
	std::map<std::string, Text*> text;
	std::map<std::string, class Rectangle*> rect;
    std::map<std::string, dialogue*> dia;
	void Keybinds();
	sf::Font font;
	std::vector<int> delay;
	int index;
	int Onenter_delay;
	sf::Texture tex;
public:
	Confirm(sf::RenderWindow* window, std::map<std::string, int>* keys, std::stack<State*>* states);
	virtual ~Confirm();
	void update(const float& time);
	void draw(sf::RenderTarget* target = 0);
	void input(const float& time);
	void Updatelist();
	void onClosed();
};

