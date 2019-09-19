#include "Button.h"
#include <iostream>

namespace neulii
{

//TODO Button Text must be inserted		
		
		
	//Constructor
	Button::Button(float x, float y, float width, float height) : 
		ClickableHooverableRectShape(x,y,width,height) 
	{
		buttonPosX = x + OFFSET_UNHOOVERED;
		buttonPosY = y + OFFSET_UNHOOVERED;
	
		//set shape on right bottom position
		shadowShape.setPosition(buttonPosX+2 , buttonPosY+2);

		shadowShape.setSize(sf::Vector2f(width, height));
		shadowShape.setFillColor(sf::Color::Green);

		setPosition(buttonPosX, buttonPosY);
	}

	void Button::update(long dT)  
	{
		ClickableHooverableRectShape::update(dT);

		unsigned offset = 0;

		if(isLeftButtonDown())
		{
			offset = OFFSET_HOOVERED;
		}
		else
		{
			offset = OFFSET_UNHOOVERED;
			
		}

		setPosition(buttonPosX- offset, buttonPosY- offset);
	}

	void Button::render(sf::RenderWindow& window)
	{

		window.draw(shadowShape);
		ClickableHooverableRectShape::render(window);
	}

}//namespace neulii
