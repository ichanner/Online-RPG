#include "Confirm.h"

void Confirm::Keybinds()
{
	this->keybinds.emplace("Down", this->keys->at("Down"));
	this->keybinds.emplace("Up", this->keys->at("Up"));
	this->keybinds.emplace("Enter", this->keys->at("Enter"));

}

Confirm::Confirm(sf::RenderWindow* window, std::map<std::string, int>* keys, std::stack<State*>* states) : State(window, keys, states)
{
	this->window = window;
	this->Onenter_delay = 100;
	this->Keybinds();
	this->index = 2;
	this->font.loadFromFile("Resources/fonts/Commodore Angled v1.2.ttf");
	this->tex.loadFromFile("Resources/images/pointer.png");
	this->text["company"] = new Text(800.0f, 1000.0f, "©Basement Games 2019,2020", &font, sf::Color(255, 255, 255), 18);
	this->text["Yes"] = new Text(925.0f, 800.0f, "Yes", &font, sf::Color(255, 255, 255), 38);
	this->text["No"] = new Text(925.0f, 850.f, "No", &font, sf::Color(255, 255, 255), 38);
	this->rect["Test"] = new class Rectangle(101, 350, 300, 300, sf::Color(255, 255, 255));
	this->rect["Test"]->set_Tex(&tex);//Lazy could be faster
	//int pos_x, int pos_y, std::string text, sf::Font* font, sf::Color text_color, int size, int speed, sf::Color hide, int hide_x, int hide_y, int size_x, int size_y
	this->dia["Are you sure?"] = new dialogue(550,600,"Are you sure you want to Exit?", &font, sf::Color(255,255,255),38,2,sf::Color(0,0,0),550,600,10000,50);
}

Confirm::~Confirm()
{
}

void Confirm::update(const float& time)
{


	this->input(time);

	this->window->clear(sf::Color::Black);
	for (auto& it : this->dia) {

		it.second->update(time);
		
	}

	this->Updatelist();

}

void Confirm::draw(sf::RenderTarget* target)
{
	for (auto& it : this->text) {

		it.second->draw(target);
	}


	for (auto& it : this->rect) {

		it.second->draw(target);
	}

	for (auto& it : this->dia) {

		it.second->draw(target);
	}

}

void Confirm::input(const float& time)
{


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("Up")))) {
	
		this->index = 2;
	
		
		///this->asset["Pointer"]->setPos(1, 2);
		//Dev Note: Asset Class is prone to crash the program

	}



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("Down")))) {
		
		this->index = 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("Enter"))) && this->index == 2 && Onenter_delay == 0) {

		this->window->close();

	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("Enter"))) && Onenter_delay > 0) {

		this->Onenter_delay -= 1;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("Enter"))) && this->index == 1) {

		this->states->push(new MainMenu(this->window, this->keys, this->states));

	}

	

}

void Confirm::Updatelist()
{
	if (this->index == 2) {
		std::cout << "2";
		this->rect["Test"]->set_Pos(775, 700);
	}
	if(this->index == 1) {
		std::cout << "1";
		this->rect["Test"]->set_Pos(775, 750);
	}


	
}

void Confirm::onClosed()
{
}
