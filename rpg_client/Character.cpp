#include "Character.h"

void Character::Keybinds()
{
	this->keybinds.emplace("Down", this->keys->at("Down"));
	this->keybinds.emplace("Up", this->keys->at("Up"));
	this->keybinds.emplace("Enter", this->keys->at("Enter"));
}

Character::Character(sf::RenderWindow* window, std::map<std::string, int>* keys, std::stack<State*>* states) : State(window, keys, states)
{
	this->window = window;

	this->font.loadFromFile("Resources/fonts/Commodore Angled v1.2.ttf");
	this->buttons["NewCharacter"] = new Button(215, 400, 500, 60, "Create Account", &this->font, sf::Color(255, 0, 0), sf::Color(0, 255, 0), sf::Color(0, 0, 255), 18);
	this->buttons["Login"] = new Button(215, 1000, 500, 60, "Login", &this->font, sf::Color(255, 0, 0), sf::Color(0, 255, 0), sf::Color(0, 0, 255), 18);
}

Character::~Character()
{
}

void Character::update(const float& time)
{
	this->input(time);
	this->window->clear(sf::Color(0, 213, 255));
	this->updateButtons();

	



}

void Character::draw(sf::RenderTarget* target)
{
	for (auto& it : this->buttons) {

		it.second->draw(target);
	}


}

void Character::input(const float& time)
{


	if (this->buttons["NewCharacter"]->isclicked()) {

		this->states->push(new Register(this->window, this->keys, this->states));
	}

	this->UpdateMouse();
}

void Character::updateButtons()
{
	for (auto& it : this->buttons) {

		it.second->update(this->MouseView_pos);
	}
}

void Character::onClosed()
{
}
