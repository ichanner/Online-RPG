#include "Begin.h"


void Begin::Keybinds()
{
}

Begin::Begin(sf::RenderWindow* window, std::map<std::string, int>* keys, std::stack<State*>*states) : State(window, keys, states)
{
	this->window = window;
	this->InitButtons();
	this->InitFonts();
}




Begin::~Begin()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it) {

		delete it->second;
	}
}

void Begin::update(const float& time)
{
	this->time = clock.getElapsedTime().asSeconds();
	this->UpdateButtons();
	this->UpdateMouse();
	this->debug.update(time);
	this->debug.getElaspsedTime();
	this->debug.updateElaspsedTime();
	this->debug.update_pos();
	this->debug.update_fps();
	this->debug.getFps();
	this->effect.update(time);
	this->effect.clock();
	this->effect.toggle();
	this->input(time);
	this->window->clear(sf::Color(12,233,249));
	if (this->effect.clear()) {	
		this->setClosed();
	}
		

}

void Begin::draw(sf::RenderTarget* target)
{
	this->debug.draw(target);
	this->effect.draw(target);
	this->DrawButtons(target);
	
}

void Begin::input(const float& time)
{
	this->UpdateMouse();
	this->debug.getEnabled();

}

void Begin::onClosed()
{
	std::cout << "I'm done for! Time for state(3)" << std::endl;
}

void Begin::InitFonts()
{
	this->font.loadFromFile("Resources/fonts/sansation.ttf");
}

void Begin::InitButtons()
{
	this->buttons["DevTools"] = new Button(115, 1755, 100, 50, "Debug Tools", &this->font, sf::Color(255, 0, 0), sf::Color(0, 255, 0), sf::Color(0, 0, 255), 16);

	this->buttons["Back"] = new Button(115, 1655, 100, 50, "Back", &this->font, sf::Color(255, 0, 0), sf::Color(0, 255, 0), sf::Color(0, 0, 255), 16);

}

void Begin::UpdateButtons()
{
	for (auto& it : this->buttons) {

		it.second->update(this->MouseView_pos);
	}

	if (this->buttons["DevTools"]->isclicked()) {

		this->debug.setEnabled();
		
	}

	if (this->buttons["Back"]->isclicked()) {

		this->debug.disable();

	}


	

	
}

void Begin::DrawButtons(sf::RenderTarget* target)
{

	
}
