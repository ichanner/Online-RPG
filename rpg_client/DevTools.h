#pragma once
#include "Button.h"
///#include "States.h"
class DevTools
{
private:
	bool enabled;
	
	sf::RectangleShape debug_obj;
	sf::Vector2i debug_pos;
	sf::Vector2f pos;
	float pos_x;
	float pos_y;
	
	sf::Text posx;
	sf::Text posy;
	sf::Font dev_font;

	sf::Text posx_num;
	sf::Text posy_num;

	sf::Text fps_lable;
	sf::Text fps;
	sf::Clock fps_clock;
	sf::Time fps_time;
	float fps_value;

	sf::Text ElapsedTime_lable;
	sf::Text ElapsedTime_value;
	int elapsed_time;
	sf::Clock SessionTime;
public:
	DevTools();
	virtual ~DevTools();
	virtual void update(const float& time);
	virtual void draw(sf::RenderTarget* target);
	virtual void input(const float& time);
	void update_pos();
	void update_fps();
	void getFps();
	void getElaspsedTime();
	void updateElaspsedTime();
	
	void setEnabled();
	void disable();
	const bool getEnabled() const;
	const bool getDisabled() const;
	
};

