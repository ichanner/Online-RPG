#include "MainMenu.h"

void MainMenu::Keybinds()
{
	this->index = 1;
	this->delay.resize(2);
	this->keybinds.emplace("Down", this->keys->at("Down"));
	this->keybinds.emplace("Up", this->keys->at("Up"));
	this->keybinds.emplace("Enter", this->keys->at("Enter"));
}

MainMenu::MainMenu() : State(window, keys, states)
{

}

MainMenu::MainMenu(sf::RenderWindow* window, std::map<std::string, int>* keys, std::stack<State*>*states) : State(window, keys, states)
{
	this->window = window;
	this->Keybinds();
	this->font.loadFromFile("Resources/fonts/Commodore Angled v1.2.ttf");
	

	this->buttons["Play"] = new Button(500, 750, 500, 60, "Play", &this->font, sf::Color(255, 0, 0), sf::Color(0, 255, 0), sf::Color(0, 0, 255), 18);
	this->buttons["Options"] = new Button(600, 750, 500, 60, "Options", &this->font, sf::Color(255, 0, 0), sf::Color(0, 255, 0), sf::Color(0, 0, 255), 18);
	this->buttons["Tutorial"] = new Button(700, 750, 500, 60, "Tutorial", &this->font, sf::Color(255, 0, 0), sf::Color(0, 255, 0), sf::Color(0, 0, 255), 18);
	this->buttons["Exit"] = new Button(800, 750, 500, 60, "Exit", &this->font, sf::Color(255, 0, 0), sf::Color(0, 255, 0), sf::Color(0, 0, 255), 18);
	
	
	/*
	this->test["Play"] = new Text(850.0f, 700.0f, "Play", &font, sf::Color(255, 255, 255), 48);

	this->test["Options"] = new Text(850.0f, 750.0f, "Options", &font, sf::Color(255, 255, 255), 48);
	
	this->test["Exit"] = new Text(850.0f, 800.0f, "Exit", &font, sf::Color(255, 255, 255), 48);

	this->test["company"] = new Text(800.0f, 1000.0f, "©Basement Games 2019,2020", &font, sf::Color(255, 255, 255), 18);
	*/
	
	this->buttons["DevTools"] = new Button(115, 1755, 100, 50, "Editor", &this->font, sf::Color(255, 0, 0), sf::Color(0, 255, 0), sf::Color(0, 0, 255), 14);
	
}

MainMenu::~MainMenu()
{
}

void MainMenu::update(const float& time)
{
	
	this->input(time);
	this->UpdateText();
	this->Updatebuttons();
	this->UpdateBounds();
	system("cls");
	this->window->clear(sf::Color(0, 213, 255));
	std::cout << index;
	//std::cout << delay;
}

void MainMenu::draw(sf::RenderTarget* target)
{
	

	for (auto& it : this->test) {

		it.second->draw(target);
	}


	for (auto& it : this->buttons) {

		it.second->draw(target);
	}


}



void MainMenu::input(const float& time)
{
	
			this->UpdateMouse();

			if (this->buttons["DevTools"]->isclicked()) {

				this->states->push(new Editor(this->window, this->keys, this->states));
			}


			if (this->buttons["Play"]->isclicked()) {

				this->states->push(new Character(this->window, this->keys, this->states));
			}

			if (this->buttons["Options"]->isclicked()) {

				this->states->push(new Options(this->window, this->keys, this->states));
			}

			if (this->buttons["Exit"]->isclicked()) {

				//this->states->push(new Options(this->window, this->keys, this->states));
			}










			/*
		
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("Up"))) && delay[0] == 0) {
				this->delay[0] = 2;
				this->index -= 1;	
			}
			
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("Up"))) && delay[0] > 0) {
				this->delay[0] -= 1;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("Down"))) && delay[1] == 0) {
				this->delay[1] = 2;
				this->index += 1;
			}

			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("Down"))) && delay[1] > 0) {
				this->delay[1] -= 1;
			}

			*/
		

			
}

void MainMenu::UpdateText()
{

	/*
	if (this->index == 1) {

		this->test["Play"]->fadein(sf::Color(0, 0, 255));
	}

	else {

		this->test["Play"]->fadein(sf::Color(255, 255, 255));
	}

	if (this->index == 2) {

		this->test["Options"]->fadein(sf::Color(0, 0, 255));
	}
	else {

		this->test["Options"]->fadein(sf::Color(255, 255, 255));
	}



	if (this->index == 3) {

		this->test["Exit"]->fadein(sf::Color(0, 0, 255));
	
		
	}

	else {

		this->test["Exit"]->fadein(sf::Color(255, 255, 255));

	}


	if (this->index == 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("Enter")))) {



		this->states->push(new Character(this->window, this->keys, this->states));
	}



	if (this->index == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("Enter")))) {



		this->states->push(new Options(this->window, this->keys, this->states));
	}

	if (this->index == 3 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("Enter")))) {

		

		this->states->push(new Confirm(this->window, this->keys, this->states));
	}
	*/
	
}

void MainMenu::UpdateBounds()
{
	/*
	if (this->index < 1) {

		this->index = 3;
	}

	if (this->index > 3) {

		this->index = 1;
	}
	*/
}

void MainMenu::Updatebuttons()
{
	for (auto& it : this->buttons) {

		it.second->update(this->MouseView_pos);
	}
}


void MainMenu::onClosed()
{
}

