#pragma once
#include "DevTools.h"
class Logo 
{
private:
	sf::RenderWindow window;
	sf::RectangleShape logo;
	sf::Texture logotex;
	sf::Clock fade;
	float time_fade;
	int color;
	bool past;
	sf::FloatRect bounds;
	sf::RectangleShape obj;
	sf::Vector2i devtool_pos;
public:

	virtual ~Logo();
	Logo();
	virtual void draw(sf::RenderTarget* target);
	virtual void update(const float& time);
	virtual void countDown();
	virtual void fadeaway();
	void Setswtich();
	bool Getswitch();
};

