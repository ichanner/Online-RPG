#pragma once
#include "MenuTheme.h"
#include "State.h"
class Options : public State
{
public:
	Options(sf::RenderWindow* window, std::map<std::string, int>* keys, std::stack<State*>* states);
	virtual ~Options();
	void update(const float& time);
	void draw(sf::RenderTarget* target = 0);
	void input(const float& time);
	void onClosed();

private:
	sf::RenderWindow* window;
	void Keybinds();

	sf::Font font;

	std::map<std::string, class Rectangle*> rect;
	sf::Texture tex;
	std::map<std::string, Text*>text;

};

