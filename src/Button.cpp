#include "Button.h"
#include <iostream>

namespace neulii
{
	//Constructor
	Button::Button(float x, float y, float width, float height) : 
		ClickableHooverableRectShape(x,y,width,height) 
	{
		shadowPosX = x + OFFSET_UNHOOVERED;
		shadowPosY = y + OFFSET_UNHOOVERED;
		
		shadowShape.setPosition(shadowPosX , shadowPosY);

		shadowShape.setSize(sf::Vector2f(width, height));
		shadowShape.setFillColor(sf::Color::Red);


	}

	void Button::update(long dT)  
	{
		ClickableHooverableRectShape::update(dT);

		unsigned offset;
		if(checkIfHoovered())
		{
			
			offset = OFFSET_HOOVERED;
			std::cout << offset << std::endl;

		}
		else
		{
			offset = OFFSET_UNHOOVERED;
			std::cout << "not hovered" << std::endl;
		}

		
		std::cout << offset << std::endl;

	}

	void Button::render(sf::RenderWindow& window)
	{

		window.draw(shadowShape);
		ClickableHooverableRectShape::render(window);

	}



}//namespace neulii
