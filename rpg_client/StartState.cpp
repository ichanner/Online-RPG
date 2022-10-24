#include "StartState.h"

void StartState::Keybinds()
{
}

StartState::StartState(sf::RenderWindow* window, std::map<std::string, int>* keys, std::stack<State*>*states) : State(window, keys, states)
	
{ 
	
	
}

StartState::~StartState()
{

}

void StartState::draw(sf::RenderTarget* target)
{
	this->debug.draw(target);
	this->poop.draw(target);

	
}
void StartState::input(const float& time)
{
	this->UpdateMouse();
	this->poop.Setswtich();
	if(poop.Getswitch())
		this->setClosed();

}
void StartState::onClosed()
{

	std::cout << "I'm done for! Time for state(2)" << std::endl;
	
}
void StartState::update(const float& time)
{
	this->debug.update_fps();
	this->debug.getFps();
	this->debug.update_pos();
	this->debug.update(time);
	this->poop.update(time);
	this->input(time);
	//test
	this->poop.countDown();
	this->poop.fadeaway();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		std::cout << "Hello this is State(1)! Thanks for watching!" << std::endl;
}

