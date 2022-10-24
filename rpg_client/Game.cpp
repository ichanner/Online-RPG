#include "Game.h"

//What needs to booted up on startup(Init). Todo:all in one function

//Create the canvas
void Game::init()
{
	this->window = new sf::RenderWindow(sf::VideoMode(600,600),"Tales from the Backyard", sf::Style::Fullscreen);
	this->window->setFramerateLimit(145);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initKeys()
{
	this->keys.emplace("X", sf::Keyboard::Key::X);//Start
	this->keys.emplace("Down", sf::Keyboard::Key::Down);
	this->keys.emplace("Up", sf::Keyboard::Key::Up);
	this->keys.emplace("Right", sf::Keyboard::Key::Right);
	this->keys.emplace("Left", sf::Keyboard::Key::Left);
	this->keys.emplace("W", sf::Keyboard::Key::W);
	this->keys.emplace("S", sf::Keyboard::Key::S);
	this->keys.emplace("D", sf::Keyboard::Key::D);
	this->keys.emplace("A", sf::Keyboard::Key::A);
	this->keys.emplace("Enter", sf::Keyboard::Key::Enter);
	
	
}

void Game::initStates()
{

	this->states.push(new Confirm(this->window, &this->keys, &this->states));
	this->states.push(new Character(this->window, &this->keys, &this->states));
	this->states.push(new Options(this->window, &this->keys, &this->states));
	this->states.push(new MainMenu(this->window, &this->keys, &this->states));
	this->states.push(new TitleState(this->window, &this->keys, &this->states));
	this->states.push(new StartState(this->window, &this->keys, &this->states));
	
	
	
	
//No input needed
	//this->states.push(new ColorBootup(this->window, &this->keys, &this->states));
	//this->states.push(new Begin(this->window, &this->keys, &this->states));



}


//What happesn when game is run (Don't forget to call the inits here)
Game::Game()
{
	this->init();
	this->initKeys();
	this->initStates();
}


//On game close. Destroy Everything >:) !!!!!
Game::~Game()
{
	//Destroy Canvas
	delete this->window;
	
	while (!states.empty()) {

		delete this->states.top();
		states.pop();
	
	}
}



void Game::fps()
{
	
	this->time = this->fpss.restart().asSeconds();
	
}
//Update display *At the time its moving per frame
void Game::update()
{

	this->Event();
	this->window->clear(sf::Color::White);
	if (!this->states.empty()) {

		this->states.top()->update(this->time);
		

		if (!this->states.top()->Getclosed()) {
		
			//this->states.top()->setClosed();
			
		}

	

		
		if (states.top()->Getclosed()) {

			this->states.top()->onClosed();
			delete this->states.top();
			states.pop();
		}

	}

		
		
	
}
//Render here
void Game::draw()
{
	
	if (!this->states.empty()) 

		this->states.top()->draw(this->window);
	
	this->window->display();
	
	
}
//Event loop
//Input?
void Game::Event()
{
	while (this->window->pollEvent(this->evnt)){

		if (this->evnt.type == sf::Event::Closed) {

			this->window->close();
		}

		
	
	}
}
//Compile those functions above to run in main
void Game::run()
{
	while (this->window->isOpen()) {

		this->fps();
		this->draw();
		this->update();
	}
}
