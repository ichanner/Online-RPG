#include "DevTools.h"

DevTools::DevTools()
{
	this->enabled = false;
	
	/*
	this->debug_obj.setFillColor(sf::Color::Red);
	this->debug_obj.setPosition(sf::Vector2f(1856.0, 2.0));
	this->debug_obj.setSize(sf::Vector2f(45.0, 34.0));
	*/
	this->dev_font.loadFromFile("Resources/fonts/sansation.ttf");
	this->posx.setFont(this->dev_font);
	this->posy.setFont(this->dev_font);
	
	this->posy.setFillColor(sf::Color::Red);
	this->posx.setFillColor(sf::Color::Red);
	
	this->posx.setCharacterSize(12);
	this->posy.setCharacterSize(12);
	
	this->posy.setString("Position Y:");
	this->posx.setString("Position X:");
	
	//this->posx.setPosition(1700, 0);
	//this->posy.setPosition(1700, 25);


	this->posx_num.setFont(this->dev_font);
	this->posy_num.setFont(this->dev_font);

	this->posx_num.setFillColor(sf::Color::Green);
	this->posy_num.setFillColor(sf::Color::Green);

	this->posx_num.setCharacterSize(12);
	this->posy_num.setCharacterSize(12);

	this->posx_num.setString("0");
	this->posy_num.setString("0");

	//this->posy_num.setPosition(1760, 25);
	//this->posx_num.setPosition(1760, 0);

	this->fps_lable.setCharacterSize(12);
	this->fps_lable.setFont(this->dev_font);
	this->fps_lable.setFillColor(sf::Color::Red);
	this->fps_lable.setString("Fps:");
	//this->fps_lable.setPosition(1700, 50);

	this->fps.setCharacterSize(12);
	this->fps.setFont(this->dev_font);
	this->fps.setFillColor(sf::Color::Green);
	this->fps.setString("0");
	//this->fps.setPosition(1760, 50);

	this->ElapsedTime_lable.setCharacterSize(12);
	this->ElapsedTime_lable.setFont(this->dev_font);
	this->ElapsedTime_lable.setFillColor(sf::Color::Red);
	this->ElapsedTime_lable.setString("Elapsed Time:");
	//this->ElapsedTime_lable.setPosition(1700, 75);


	this->ElapsedTime_value.setCharacterSize(12);
	this->ElapsedTime_value.setFont(this->dev_font);
	this->ElapsedTime_value.setFillColor(sf::Color::Green);
	this->ElapsedTime_value.setString("0");
	//this->ElapsedTime_value.setPosition(1780, 75);

	this->posx.setPosition(99999, 0);
	this->posy.setPosition(99999, 25);

	this->posy_num.setPosition(99999, 25);
	this->posx_num.setPosition(99999, 0);

	this->fps_lable.setPosition(99999, 50);

	this->fps.setPosition(99999, 50);

	this->ElapsedTime_lable.setPosition(99999, 75);

	this->ElapsedTime_value.setPosition(99999, 75);

}

DevTools::~DevTools()
{
	
}

void DevTools::update(const float& time)
{
	
	this->input(time);
	
}

void DevTools::draw(sf::RenderTarget* target)
{
	//target->draw(debug_obj);
	target->draw(posy);
	target->draw(posx);
	target->draw(posx_num);
	target->draw(posy_num);
	target->draw(fps_lable);
	target->draw(fps);
	target->draw(ElapsedTime_lable);
	target->draw(ElapsedTime_value);

}

void DevTools::input(const float& time)
{
	this->pos = debug_obj.getPosition();
	this->pos_x = pos.x;
	this->pos_y = pos.y;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		this->debug_pos = sf::Mouse::getPosition();
		this->debug_obj.setPosition((float)this->debug_pos.x, (float)this->debug_pos.y);

	}
}

void DevTools::update_pos()
{
	posx_num.setString(std::to_string(this->pos_x));
	posy_num.setString(std::to_string(this->pos_y));
}
void DevTools::update_fps()
{
	fps.setString(std::to_string(this->fps_value));
}
void DevTools::getFps()
{
	this->fps_time = this->fps_clock.getElapsedTime();
	this->fps_value = 1.0f / this->fps_time.asSeconds();
	this->fps_clock.restart().asSeconds();

}
void DevTools::getElaspsedTime()
{
	this->elapsed_time = this->SessionTime.getElapsedTime().asSeconds();
}

void DevTools::updateElaspsedTime()
{
	this->ElapsedTime_value.setString(std::to_string(this->elapsed_time));
}

void DevTools::setEnabled()
{
	
	
		

		this->posx.setPosition(1700, 0);
		this->posy.setPosition(1700, 25);

		this->posy_num.setPosition(1760, 25);
		this->posx_num.setPosition(1760, 0);

		this->fps_lable.setPosition(1700, 50);

		this->fps.setPosition(1760, 50);

		this->ElapsedTime_lable.setPosition(1700, 75);

		this->ElapsedTime_value.setPosition(1780, 75);

	}


	


void DevTools::disable()
{
	
		

		this->posx.setPosition(9999, 0);
		this->posy.setPosition(9999, 25);

		this->posy_num.setPosition(9999, 25);
		this->posx_num.setPosition(99999, 0);

		this->fps_lable.setPosition(99999, 50);

		this->fps.setPosition(9999, 50);

		this->ElapsedTime_lable.setPosition(99999, 75);

		this->ElapsedTime_value.setPosition(99999, 75);

	}




const bool DevTools::getEnabled() const
{
	if (this->enabled == false) 
		return true;
}

const bool DevTools::getDisabled() const
{
	if(this->enabled == true)
		return true;
}


