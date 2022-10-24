#include "TitleState.h"

void TitleState::Keybinds()
{
	this->keybinds.emplace("Start", this->keys->at("X"));
}

TitleState::TitleState(sf::RenderWindow* window, std::map<std::string, int>* keys, std::stack<State*>*states) : State(window, keys, states)
{
	this->window = window;
	this->Keybinds();
}

TitleState::~TitleState()
{
}

void TitleState::draw(sf::RenderTarget* target)
{
	this->tit.draw(target);
}

void TitleState::update(const float& time)
{
	this->input(time);
	this->tit.update(time);
	this->tit.getTime();
	this->tit.toggle();
	this->window->clear(sf::Color::Black);

}

void TitleState::input(const float& time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("Start")))) {

		this->setClosed();
	}
}

void TitleState::onClosed()
{
}
