#pragma once
#include "State.h"
#include "BootupEffect.h"
class Begin : public State
{
private:
	sf::RenderWindow* window;
	BootupEffect effect;
	DevTools debug;
	std::map<std::string, Button*> buttons;
	sf::Font font;
	void Keybinds();
	sf::Clock clock;
	int time;
public:
	Begin(sf::RenderWindow* window, std::map<std::string, int>* keys, std::stack<State*>*states);
	virtual ~Begin();
	void update(const float& time);
	void draw(sf::RenderTarget* target = 0);
	void input(const float& time);
	void onClosed();
	void InitFonts();
	void InitButtons();
	void UpdateButtons();
	void DrawButtons(sf::RenderTarget* target);
};

