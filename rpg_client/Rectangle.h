#pragma once
#include "TitleEntity.h"
class Rectangle
{
private:
	sf::RectangleShape rect;
	sf::Color color;
	sf::Texture tex;
public:
	Rectangle(int posx, int posy,int height, int width, sf::Color color);
	Rectangle();
	virtual ~Rectangle();
	void draw(sf::RenderTarget* targtet);
	void update(const float& time);
	void change_Color(sf::Color color);
	void set_Pos(int x, int y);
	void set_Tex(sf::Texture* tex);
	sf::FloatRect Bounds();
	bool Contains(sf::Vector2f& mouse);
	//Other animations will be handled in parent class
};

