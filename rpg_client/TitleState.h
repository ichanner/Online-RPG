#pragma once
#include"TitleEntity.h"
#include"State.h"
class TitleState : public State
{

private:
	sf::RenderTarget* window;
	TitleEntity tit;
	void Keybinds();
public:
	TitleState(sf::RenderWindow* window, std::map<std::string, int>* keys,std::stack<State*>*states);
	virtual ~TitleState();
	virtual void draw(sf::RenderTarget* target);
	virtual void update(const float& time);
	void input(const float& time);
	void onClosed();

};

