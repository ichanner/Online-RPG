#pragma once
#include "Rectangle.h"
class Text
{
private:
	sf::Color text_color;
	sf::Color*fade_color;
	sf::Font font;
	sf::Text text;
public:
	Text();
	Text(int pos_x, int pos_y,std::string text, sf::Font* font, sf::Color text_color, int size);
	virtual ~Text();
	virtual void draw(sf::RenderTarget* target);
	virtual void update(const float& time);
	void hide();
	void show(std::string text);
	void fadein(sf::Color fade_color);
	void fadeout(sf::Color fadeout);
};

