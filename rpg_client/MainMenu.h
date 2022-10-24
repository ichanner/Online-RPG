#pragma once
#include "State.h"
#include "dialogue.h"
#include "Confirm.h"
#include  "Options.h"
#include "Editor.h"
#include "Character.h"
class MainMenu : public State
{

private:
	dialogue dial;
	std::map<std::string, dialogue*> dia;

	std::map<std::string, Text*>test;
	int index;
	sf::Font font;
	std::map<std::string, class Button*> buttons;
	std::vector<int>delay;
	
	void Keybinds();
public:
	MainMenu();
	MainMenu(sf::RenderWindow* window, std::map<std::string, int>* keys, std::stack<State*>*states);
	virtual ~MainMenu();
	void update(const float& time);
	void draw(sf::RenderTarget* target = 0);
	void input(const float& time);
	void UpdateText();
	void UpdateBounds();
	void Updatebuttons(); //Will make parent class sooon
	void onClosed();

	

};

