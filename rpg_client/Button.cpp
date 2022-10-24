#include "Button.h"



Button::~Button()
{
}

const bool Button::isclicked() const
{
if (this->State == Clicked) {

		return true;
	}
		

	return false;
	
	
}

Button::Button(float pos_y, float pos_x, float width, float height, std::string text, sf::Font* font, sf::Color idle, sf::Color hovering, sf::Color clicked, int size)
{
	this->button_obj.setPosition(sf::Vector2f(pos_x, pos_y));
	this->button_obj.setSize(sf::Vector2f(width, height));
	this->button_text.setString(text);
	this->button_font = *font;
	this->button_text.setFont(*font);
	this->button_text.setCharacterSize(size);
	this->idle = idle;
	this->clicked = clicked;
	this->hovering = hovering;
	this->button_text.setFillColor(sf::Color::Black);//Lazy
	this->button_obj.setFillColor(this->idle);
	this->State = Idle;
	this->button_text.setPosition((this->button_obj.getPosition().x + (this->button_obj.getGlobalBounds().width / 2.f) - this->button_text.getGlobalBounds().width / 2.f) - 0, this->button_obj.getPosition().y + ((this->button_obj.getGlobalBounds().height / 2.f) - this->button_text.getGlobalBounds().height / 2.f) -3); //Offset param?
	//this->button_obj.setOrigin(sf::Vector2f(width / 2.0f, height / 2.0f));
}



void Button::update(const sf::Vector2f& mousePos)
{


	if (!this->button_obj.getGlobalBounds().contains(mousePos)) {
		this->button_obj.setFillColor(this->idle);
		this->State = Idle;
	
	}
	if (this->button_obj.getGlobalBounds().contains(mousePos)) {
		this->button_obj.setFillColor(this->hovering);
		this->State = Hover;	
		
	}
	if (this->button_obj.getGlobalBounds().contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		this->button_obj.setFillColor(this->clicked);
		this->State = Clicked;
		
	}
}

void Button::draw(sf::RenderTarget* target)
{
	target->draw(this->button_obj);
	target->draw(this->button_text);
}
