#include "TitleEntity.h"



TitleEntity::~TitleEntity()
{
	
}

TitleEntity::TitleEntity()
{

	this->color4 = 51;
	
	this->start_font.loadFromFile("Resources/fonts/Commodore Angled v1.2.ttf");
	this->start["start"] = new Text(710.0f, 700.0f, "Press X to Start", &start_font, sf::Color(255, 255, 255), 42);
	this->start["company"] = new Text(800.0f, 1000.0f, "©Basement Games 2019,2020", &start_font, sf::Color(255, 255, 255), 18);
	
}

void TitleEntity::draw(sf::RenderTarget* target)
{
	for (auto& it : this->start) {

		it.second->draw(target);
	}
}

void TitleEntity::update(const float& time)
{
	
	
	
	for (auto& it : this->start) {

		it.second->update(time);
	}
	
}

void TitleEntity::getTime()
{
	this->time_num = this->time.getElapsedTime().asSeconds();
}

void TitleEntity::toggle()
{
	this->toggle_value = true;

	if (this->toggle_value == true){

		
		this->delay += 1;
	
		this->start["start"]->fadein(sf::Color(0, 0, 255));
		
		if (delay > 100) {

			this->toggle_value = false;

			if(delay > 200)
				delay = 0;
		}
		
	}

	if (this->toggle_value == false) {
		this->start["start"]->fadein(sf::Color(255, 255, 255));
	}
	
	
}



