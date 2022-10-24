
#include "GameObject.h"



GameObject::GameObject()
{
}

GameObject::GameObject(float pos_y, float pos_x, float width, float height, sf::Color idle, sf::Color hovering, sf::Color editing)
{
	this->game_obj.setPosition(sf::Vector2f(pos_x, pos_y));
	this->game_obj.setSize(sf::Vector2f(width, height));
	this->idle = idle;
	this->editing = editing;
	this->hovering = hovering;
	this->is_edtiting = false;
	this->State = IsIdle;

}	

GameObject::~GameObject()
{
}



void GameObject::update(const sf::Vector2f& mousePos)
{
	if (!this->game_obj.getGlobalBounds().contains(mousePos) && this->State != Editing) {
		this->State = IsIdle;


	}
	if (this->game_obj.getGlobalBounds().contains(mousePos) && this->State != Editing) {
		this->State = IsHover;


	}
	if (this->game_obj.getGlobalBounds().contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		this->State = Editing;
		

	}

	this->UpdateStates();

}


const bool GameObject::isEditing() const
{
	if (this->State == Editing) {

		return true;
	}
	return false;
}



void GameObject::draw(sf::RenderTarget* target)
{
	target->draw(this->game_obj);
}

void GameObject::UpdateStates()
{
	
	switch (State) {

	case IsIdle:
		this->game_obj.setFillColor(this->idle);
		break;
	case IsHover:
		this->game_obj.setFillColor(this->hovering);
		break;
	case Editing:
		this->game_obj.setFillColor(this->editing);
		break;
	}

}
