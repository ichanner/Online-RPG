
#include "dialogue.h"

dialogue::dialogue()
{
}

dialogue::dialogue(int pos_x, int pos_y, std::string text, sf::Font* font, sf::Color text_color, int size, int speed, sf::Color hide, int hide_x, int hide_y, int size_x, int size_y)
{
	this->text2 = text;
	this->font = *font;
	this->text.setFont(*font);
	this->text.setPosition(sf::Vector2f(pos_x, pos_y));
	this->text.setString(text);
	this->text.setFillColor(sf::Color(text_color));
	this->text.setCharacterSize(size);
	this->cover.setFillColor(sf::Color(hide));
	this->cover.setPosition(hide_x, hide_y);
	this->cover.setSize(sf::Vector2f(size_x,size_y));
	
}

dialogue::~dialogue()
{
}

void dialogue::draw(sf::RenderTarget* target)
{
	target->draw(this->text);
	target->draw(this->cover);
}

void dialogue::update(const float& time)
{
	
	for(int i = 0; i < 3; i++)
		this->cover.move(i,0);
}

