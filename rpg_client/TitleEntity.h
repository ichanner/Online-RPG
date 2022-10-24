#pragma once
#include "dialogue.h"
#include "Text.h"

class TitleEntity
{

private:

	sf::Font start_font;
	std::map<std::string, class Text*>start;
	sf::Clock time;
	int time_num;
	bool toggle_value;
	int delay;
	int color4;
	int num;
	int num_2;

public:
	virtual ~TitleEntity();
	TitleEntity();
	void draw(sf::RenderTarget* target);
	void update(const float& time);
	void getTime();
	void toggle();
};

