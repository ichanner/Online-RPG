#pragma once
#include "State.h"
#include "MenuTheme.h"
#include "Rectangle.h"
#include "GameObject.h"
class Editor : public State
{
private:
	int Shape_mode;
	int obj;
	int x;
	sf::Texture test;
	sf::Font Editor_font;
	bool rectangle_Mode;
	bool circle_Mode;
	std::map<std::string, Button*> Editor_buttons;
	std::map<int,class GameObject*> game_obj;
	//class GameObject gameobject;
	class Rectangle rect2;
	sf::RenderWindow* window;
	int Onenter_delay;
	void Keybinds();
	int draw_delay;
public:
	Editor(sf::RenderWindow* window, std::map<std::string, int>* keys, std::stack<State*>* states);
	virtual ~Editor();
	void update(const float& time);
	void draw(sf::RenderTarget* target = 0);
	void input(const float& time);
	void onClosed();
	void UpdateButtons();

};

