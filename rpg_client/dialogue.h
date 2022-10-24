#pragma once

#include "MenuTheme.h"

class dialogue
{
private:
	sf::Text text;
	sf::Font font;
	sf::RectangleShape cover;


	std::string text2;
public:
	dialogue();
	dialogue(int pos_x, int pos_y, std::string text, sf::Font* font, sf::Color text_color, int size, int speed, sf::Color hide, int hide_x, int hide_y, int size_x, int size_y);
	virtual ~dialogue();
	
	void draw(sf::RenderTarget* target);
	void update(const float& time);
	
	void test();
};

