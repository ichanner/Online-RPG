#pragma once
#include "State.h"
#include "Keyboard.h"


class Register : public State
{

private:
	sf::RenderWindow* window;
	std::map<std::string, class Button*> buttons;
	

	

	void Keybinds();

	std::map<std::string, class Textbox*> key;
	
	sf::Font font;

	sf::Event evnt;
	

public:
	

	Register(sf::RenderWindow* window, std::map<std::string, int>* keys, std::stack<State*>* states);
	virtual ~Register();
	void update(const float& time);
	void draw(sf::RenderTarget* target = 0);
	void input(const float& time);
	void updateButtons();
	void onClosed();
	void test();
	void sendData();
};





