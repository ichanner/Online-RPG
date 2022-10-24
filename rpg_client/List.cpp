#include "List.h"

UI::List::List(int pos_text_x_index, int pos_x_text)
{
	this->pos_text_x[pos_text_x_index] = pos_x_text;

}

UI::List::~List()
{
}

void UI::List::update(const float& time)
{
}

void UI::List::draw(sf::RenderTarget* target)
{
}

const bool UI::List::is_Down() const
{
	return false;
}

const bool UI::List::is_Up() const
{
	return false;
}
