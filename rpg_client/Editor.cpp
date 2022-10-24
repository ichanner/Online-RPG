#include "Editor.h"

void Editor::Keybinds()
{

}

Editor::Editor(sf::RenderWindow* window, std::map<std::string, int>* keys, std::stack<State*>* states) : State(window,keys,states)
{

	this->window = window;
	this->Editor_font.loadFromFile("Resources/fonts/Commodore Angled v1.2.ttf");
	this->Editor_buttons["Run"] = new Button(100, 1700, 100, 50, "Run", &this->Editor_font, sf::Color(255, 0, 0), sf::Color(0, 255, 0), sf::Color(0, 0, 255), 14);
	this->Editor_buttons["Test"] = new Button(150, 1700, 200, 50, "Draw", &this->Editor_font, sf::Color(255, 0, 0), sf::Color(0, 255, 0), sf::Color(0, 0, 255), 14);
	this->Editor_buttons["Test2"] = new Button(200, 1700, 200, 50, "Eraser", &this->Editor_font, sf::Color(255, 0, 0), sf::Color(0, 255, 0), sf::Color(0, 0, 255), 14);
	this->Editor_buttons["Test3"] = new Button(250, 1700, 200, 50, "Load From File", &this->Editor_font, sf::Color(255, 0, 0), sf::Color(0, 255, 0), sf::Color(0, 0, 255), 14);
	this->Onenter_delay = 100;
	this->test.loadFromFile("Resources/images/texture.jpg");

	this->Shape_mode = 0;
}

Editor::~Editor()
{
}

void Editor::update(const float& time)
{
	this->UpdateMouse();
	this->UpdateButtons();
	

	this->Onenter_delay -= 1;
	this->window->clear(sf::Color::Black);
	std::cout << this->Shape_mode;
	system("cls");
	
}

void Editor::draw(sf::RenderTarget* target)
{
	for (auto& it : this->Editor_buttons) {

		it.second->draw(target);
	}

	for (auto& it : this->game_obj) {

		it.second->draw(target);
	}


	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->draw_delay == 0) {


		this->draw_delay = 10;

		if(rectangle_Mode)
			this->obj += 1;


			if (this->obj != 0) {
				
				this->game_obj[this->obj] = new class GameObject(MouseScreen_pos.y, MouseScreen_pos.x, 200, 200, sf::Color(255, 0, 0), sf::Color(0, 255, 0), sf::Color(0, 0, 255));
			}
			
	}
	
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->draw_delay > 0) {

		this->draw_delay--;

	}
}

void Editor::input(const float& time)
{
}

void Editor::onClosed()
{
}



void Editor::UpdateButtons()
{

	for (auto& it : this->Editor_buttons) {

		it.second->update(MouseView_pos);
	}

	for (auto& it : this->game_obj) {

		it.second->update(MouseView_pos);
	}

	if (this->Editor_buttons["Test"]->isclicked()) {

		this->rectangle_Mode = true;
	
	}


	if (this->Editor_buttons["Test2"]->isclicked()) {

		this->circle_Mode = true;

	}

	if (this->Editor_buttons["Test3"]->isclicked()) {

		///system("explorer C:\\");

			//this->rect[1]->set_Tex(&test);
	}

	if (this->Editor_buttons["Run"]->isclicked()) {

		this->states->pop();
	}
}