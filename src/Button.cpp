#include "Button.h"

namespace neulii
{
	//Constructor
	Button::Button(float x, float y, float width, float height) : 
		ClickableHooverableRectShape(x,y,width,height) 
	{
	
		shadowShape.setPosition(x+1, y+1);
		shadowShape.setSize(sf::Vector2f(width, height));
		shadowShape.setFillColor(sf::Color::Red);


	}

	void Button::update(long dT)  
	{

		ClickableHooverableRectShape::update(dT);
	}

	void Button::render(sf::RenderWindow& window)
	{
		ClickableHooverableRectShape::render(window);
		window.draw(shadowShape);

	}



}//namespace neulii
