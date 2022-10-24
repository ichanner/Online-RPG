
#pragma once
#include "MenuTheme.h"

enum GameObjectStates { IsIdle = 0, IsHover = 1, Editing = 2, IsDisabled = 3 };

class GameObject
{	
public:
	GameObject();
	GameObject(float pos_y, float pos_x, float width, float height, sf::Color idle, sf::Color hovering, sf::Color editing);
	virtual ~GameObject();
	const bool isEditing() const;
	virtual void update(const sf::Vector2f& mousePos);
	virtual void draw(sf::RenderTarget* target);
	void UpdateStates();

private:
	int State;
	sf::RectangleShape game_obj;
	bool is_edtiting;
	sf::Color idle;
	sf::Color hovering;
	sf::Color editing;
};
