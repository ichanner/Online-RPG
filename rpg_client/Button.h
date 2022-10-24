#pragma once
#include "BootupEffect.h"
enum ButtonStates { Idle = 0, Hover = 1, Clicked = 2, Disabled = 3};
class Button
{
private:
	int State;
	bool is_clicked;
	bool is_hovering;
	sf::RectangleShape button_obj;
	sf::Font button_font;
	sf::Text button_text;
	sf::Color idle;
	sf::Color hovering;
	sf::Color clicked;

public:
	Button(float pos_y, float pos_x, float width, float height, std::string text, sf::Font* font, sf::Color idle, sf::Color hovering, sf::Color clicked, int size);
	virtual ~Button();
	const bool isclicked() const;
	virtual void update(const sf::Vector2f& mousePos);
	virtual void draw(sf::RenderTarget* target);
};

