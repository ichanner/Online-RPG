#include "Options.h"

Options::Options(sf::RenderWindow* window, std::map<std::string, int>* keys, std::stack<State*>* states) : State(window,keys,states)
{
	this->window = window;
	this->font.loadFromFile("Resources/fonts/Commodore Angled v1.2.ttf");
	this->tex.loadFromFile("Resources/images/pointer.png");
	this->text["Options"] = new Text(850.0f, 300.0f, "Options", &font, sf::Color(255, 255, 255), 48);
	this->rect["Cursor"] = new class Rectangle(550, 350, 300, 300, sf::Color(255, 255, 255));
	this->rect["Cursor"]->set_Tex(&tex);
}

Options::~Options()
{
}

void Options::update(const float& time)
{
	this->input(time);
	this->window->clear(sf::Color::Black);
}

void Options::draw(sf::RenderTarget* target)
{
	for (auto& it : this->text) {
		it.second->draw(target);
	}

	for (auto& it : this->rect) {
		it.second->draw(target);
	}
}

void Options::input(const float& time)
{
}

void Options::onClosed()
{
}

void Options::Keybinds()
{
}
