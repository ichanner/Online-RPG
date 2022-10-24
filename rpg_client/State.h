#pragma once
#include "Logo.h"
class State
{
private:
	//Don't use

protected:
	std::stack<State*>*states;
	sf::RenderWindow* window;
	std::map<std::string, int>* keys;
	std::map<std::string, int> keybinds;
	bool quiting;
	sf::Vector2i MouseScreen_pos;
	sf::Vector2i MouseWindow_pos;
	sf::Vector2f MouseView_pos;

	virtual void Keybinds() = 0;
public:
	State(sf::RenderWindow* window, std::map<std::string, int>* keys, std::stack<State*>*states);
	virtual ~State();
	virtual void draw(sf::RenderTarget* target = 0) = 0;
	virtual void update(const float& time) = 0;
	virtual void input(const float& time) = 0;
	const bool & Getclosed() const;
	virtual void setClosed();
	virtual void onClosed() = 0;
	virtual void UpdateMouse();
};

