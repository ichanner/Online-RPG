#include "Logo.h"

//sf::RenderWindow* window
Logo::Logo(){
	this->logotex.loadFromFile("Resources/images/logo.png");
	this->logo.setTexture(&this->logotex);
	this->logo.setSize(sf::Vector2f(600,600));
	this->logo.setOrigin(100 / 2, 100 / 2);
	this->logo.setPosition(sf::Vector2f(700, 250.0f));
	this->color = 255;
	this->past = false;
	
	//(float)this->window.getSize().x/2,(float)this->window.getSize().y/2
}

Logo::~Logo()
{
}


void Logo::draw(sf::RenderTarget* target)
{
	
	target->draw(logo);
	
}

void Logo::update(const float& time)
{
	
}

void Logo::countDown()
{

	this->time_fade = this->fade.getElapsedTime().asSeconds();
	//std::cout << time_fade << std::endl;
}

void Logo::fadeaway()
{
	if (this->time_fade > 1 && this->color > 0) {

		this->logo.setFillColor(sf::Color(255, 255, 255, this->color));
		this->color--;
	}

}

void Logo::Setswtich()
{

	if (this->time_fade > 3) {
		this->past = true;
		
	}
}

bool Logo::Getswitch()
{
	return this->past;
}



