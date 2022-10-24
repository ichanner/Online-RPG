#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* keys, std::stack<State*>*states)
{
	this->window = window;
	this->keys = keys;
	this->states = states;
	this->quiting = false;

}

State::~State()
{
}

const bool& State::Getclosed() const
{
	return this->quiting;
}
void State::setClosed()
{
	
	this->quiting = true;
		

}

void State::UpdateMouse()
{
	this->MouseScreen_pos = sf::Mouse::getPosition();
	this->MouseWindow_pos = sf::Mouse::getPosition(*this->window);
	this->MouseView_pos = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
