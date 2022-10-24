#pragma once
#include "Text.h"
enum text_states{Text1 = 0, Text2, Text3};//Will add more
class BootupEffect 
{

private:
	sf::Text bootup_text;
	sf::Text bootup_text_space;
	sf::Font bootup_font;
	sf::Clock tree_effect;
	sf::Clock t;
	float tree_countdown;
	class Text text;
	std::map<std::string, class Text*> text_bootup;
	
	int index, y2;
	int offset;
	std::vector<int>num;

	sf::RectangleShape buffer;
	sf::RectangleShape boundry;
	std::map<std::string, class Rectangle*> cursor;
	
	bool toggle_value;
	int delay;

	
public:
	BootupEffect();
	virtual ~BootupEffect();
	
	virtual void draw(sf::RenderTarget* target);
	virtual void update(const float& time);

	void initValues();
	void initText();
	void initFont();
	void clock();
	const bool clear() const;
	void toggle();
	void type(std::string text, std::string string, float interval, int x, int y);
};

