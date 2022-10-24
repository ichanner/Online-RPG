#include "BootupEffect.h"

void BootupEffect::initValues()
{
	
	this->num.resize(43);
}

void BootupEffect::initText()
{

	this->text_bootup["Company"] = new Text(600, 150, "***BASEMENT GAMES 1.0***", &bootup_font, sf::Color(12, 233, 249), 38);
	this->text_bootup["Bytes"] = new Text(400, 200, "64K RAM SYSTEM  20200 BASIC BYTES FREE", &bootup_font, sf::Color(12, 233, 249), 38);
	this->text_bootup["Ready"] = new Text(101, 300, "READY.", &bootup_font, sf::Color(12, 233, 249), 38);
	this->cursor["Boundry"] = new class Rectangle(100, 110, 1700, 850, sf::Color(0, 0, 255));
	this->cursor["Cursor"] = new class Rectangle(101, 350, 40, 40, sf::Color(12, 233, 249));
}

void BootupEffect::initFont()
{
	this->bootup_font.loadFromFile("Resources/fonts/Commodore Angled v1.2.ttf");
}

BootupEffect::BootupEffect()
{
	this->initValues();
	this->initText();
	this->initFont();

}

BootupEffect::~BootupEffect()
{
}


void BootupEffect::draw(sf::RenderTarget* target)
{


	for (auto& it : this->cursor) {

		it.second->draw(target);
	}

	for (auto& it : this->text_bootup) {

		it.second->draw(target);
	}
	target->draw(this->buffer);
	
	
}

void BootupEffect::update(const float& time)
{
	for (auto& it : this->text_bootup) {

		it.second->update(time);
	}
	
	this->type("Load", "L", 7, 101, 350);
	this->type("Load1", "O", 7.5, 128, 350);
	this->type("Load2", "A", 8, 155, 350);
	this->type("Load3", "D ", 8.5, 182, 350);
	this->type("qu","\"", 9, 219, 350);
	this->type("Load4", "B", 9.5, 250, 350);
	this->type("Load5", "A", 10, 278, 350);
	

	this->type("Load6", "C", 10.5, 306, 350);

	this->type("Load7", "K", 11, 334, 350);
	this->type("Load8", "Y", 11.5, 362, 350);
	this->type("Load9", "A", 12, 390, 350);
	this->type("Load10", "R", 12.5, 418, 350);
	this->type("Load11", "D", 13, 446, 350);
	this->type("Load12", "T", 14, 474, 350);
	this->type("Load13", "A", 14.5, 502, 350);
	this->type("Load14", "L", 15, 530, 350);
	this->type("Load15", "E", 15.5, 558, 350);
	this->type("Load16", "S", 16, 586, 350);
	this->type("Load17", "\"", 16.5, 620, 350);
	
	this->type("Play", "PRESS PLAY ON TAPE", 18, 101, 450);
	if (tree_countdown > 19) {

		this->buffer.setSize(sf::Vector2f(10000, 10000));
		this->buffer.setFillColor(sf::Color(12,233, 249));
		this->buffer.setOrigin(sf::Vector2f(999 / 2, 999 / 2));
		this->buffer.setPosition(300, 490);
	}

	if (tree_countdown > 21.0) {

		this->buffer.setSize(sf::Vector2f(0, 0));

	}
	this->type("Ok", "OK", 21, 101, 500);
	this->type("Search", "SEARCHING ", 22, 101, 600);
	this->type("Game", "FOUND BACKYARDTALES ", 23, 101, 650);
	this->type("Loadinf", "LOADING", 24, 101, 700);




}


void BootupEffect::clock()
{
	this->tree_countdown = this->tree_effect.getElapsedTime().asSeconds();

}





const bool BootupEffect::clear() const
{
	if (this->tree_countdown > 25) {

		return true;
	}
	return false;
}

void BootupEffect::toggle()
{
	
	this->toggle_value = true;

	if (this->toggle_value == true) {

		this->delay += 1;

		this->cursor["Cursor"]->change_Color(sf::Color(0,0,255));

		if (delay > 5) {

			this->toggle_value = false;

			if (delay > 10)
				delay = 0;
		}

	}

	if (this->toggle_value == false) {
		this->cursor["Cursor"]->change_Color(sf::Color(12, 233, 249));
	}

	if (this->tree_countdown > 7) {

		this->cursor["Cursor"]->set_Pos(9999.9f, 99999.9f);
	}
}

void BootupEffect::type(std::string text, std::string string,float interval, int x, int y)
{

	this->text_bootup[text] = new Text(x, y, "", &bootup_font, sf::Color(12, 233, 249), 38);

	if (this->tree_countdown > interval) {

		this->text_bootup[text]->show(string);

	}
}





