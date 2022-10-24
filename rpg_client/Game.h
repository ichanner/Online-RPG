#pragma once
#include "State.h"
#include "StartState.h"
#include"Begin.h"
#include "ColorBootup.h"
#include"TitleState.h"
#include "MainMenu.h"
#include "Confirm.h"
#include "Options.h"
#include "Character.h"
#include "Register.h"
class Game
{
private:

	sf::RenderWindow* window;
	sf::Event evnt;
	sf::Clock fpss;
	float time;
	std::stack<State*> states;
	std::map<std::string, int> keys;
	MainMenu main;
	void init();
	void initKeys();
	void initStates();
public:
	Game();
	virtual ~Game();
	void fps();
	void update();
	void draw();
	void Event();
	
	void run();

};

