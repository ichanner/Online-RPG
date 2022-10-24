#include "Text.h"

Text::Text()
{

}



Text::Text(int pos_x, int pos_y, std::string text, sf::Font* font, sf::Color text_color, int size)
{
	this->font = *font;
	this->text.setFont(*font);
	this->text.setCharacterSize(size);
	this->text.setFillColor(sf::Color(text_color));
	this->text.setPosition(sf::Vector2f(pos_x, pos_y));
	this->text.setString(text);
}

Text::~Text()
{
}

void Text::draw(sf::RenderTarget* target)
{
	target->draw(this->text);
}

void Text::update(const float& time)
{
}

void Text::hide()
{
	this->text.setString("");
}

void Text::show(std::string text)
{
	this->text.setString(text);
}

void Text::fadein(sf::Color fade_color)
{

	this->text.setFillColor(fade_color);
}

void Text::fadeout(sf::Color fadeout)
{

}
