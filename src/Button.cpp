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

		unsigned offset = 0;

		if(checkIfHoovered())
		{
			offset = OFFSET_HOOVERED;
		}
		else
		{
			offset = OFFSET_UNHOOVERED;
			
		}

		
		shadowShape.setPosition(shadowPosX+offset, shadowPosY+offset);


	}

	void Button::render(sf::RenderWindow& window)
	{

		ClickableHooverableRectShape::render(window);
		window.draw(shadowShape);

	}



}//namespace neulii
