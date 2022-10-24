#include "Register.h"

void Register::Keybinds()
{
}

Register::Register(sf::RenderWindow* window, std::map<std::string, int>* keys, std::stack<State*>* states) : State(window, keys, states)
{
	this->window = window;
	this->font.loadFromFile("Resources/fonts/Commodore Angled v1.2.ttf");
	this->key["test"] = new Textbox(18, sf::Color(50, 50, 50), true);
	this->key["test"]->setFont(this->font);


}



Register::~Register()
{
}

void Register::update(const float& time)
{

	this->test();
}

void Register::draw(sf::RenderTarget* target)
{


	for (auto& it : this->key) {

		it.second->drawTo(target);
	}
}

void Register::input(const float& time)
{
}

void Register::updateButtons()
{
}

void Register::onClosed()
{
}

void Register::test()
{
	
	while (this->window->pollEvent(this->evnt) && this->window->isOpen()) {

		std::cout << "Event";

		if (evnt.type == sf::Event::TextEntered) {

			this->key["test"]->typedOn(this->evnt);
		}

	}
}

void Register::sendData()
{
	while (this->window->isOpen()) {

		this->test();
	}
}
