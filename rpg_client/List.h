#pragma once
#include "MenuTheme.h"
#include"Rectangle.h"
namespace UI {

	class List
	{
	private:
		std::map<std::string, Text*> text_list;
		class Rectangle cursor;
		std::vector<int> pos_text_x;
		
	public:
		List(int pos_text_x_index, int pos_x_text);
		
		
		virtual ~List();
		void update(const float& time);
		void draw(sf::RenderTarget* target);
		
		
		
		const bool is_Down() const;
		const bool is_Up() const;

	
	
	};


}

