#include "Rectangle.h"

Rectangle::Rectangle(int posx, int posy, int height, int width, sf::Color color)
{

	this->color = color;
	this->rect.setSize(sf::Vector2f(height,width));
	this->rect.setFillColor(color);
	this->rect.setPosition(sf::Vector2f(posx, posy));
	///this->rect.setOrigin(posx / 2, posy / 2);
}

Rectangle::Rectangle()
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::draw(sf::RenderTarget* targtet)
{
	targtet->draw(this->rect);
}

void Rectangle::update(const float& time){
}

void Rectangle::change_Color(sf::Color color)
{
	this->rect.setFillColor(color);
}

void Rectangle::set_Pos(int x, int y)
{
	this->rect.setPosition(sf::Vector2f(x, y));
}

void Rectangle::set_Tex(sf::Texture* tex)
{
	this->tex = *tex;
	this->rect.setTexture(tex);
}

sf::FloatRect Rectangle::Bounds()
{
	return this->rect.getGlobalBounds();
}

bool Rectangle::Contains(sf::Vector2f& mouse)
{

	if (Bounds().contains(mouse)) {

		return true;
	}
	return false;
}

