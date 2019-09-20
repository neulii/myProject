#include "Button.h"
#include <iostream>

namespace neulii
{
	//Constructor
	Button::Button(float x, float y, float width, float height) : 
		ClickableHooverableRectShape(x,y,width,height) 
	{
	
		buttonPosX = x; 
		buttonPosY = y; 
	
		//set shape on right bottom position
		shadowShape.setPosition(buttonPosX + shadowOffsetX, buttonPosY + shadowOffsetY);

		shadowShape.setSize(sf::Vector2f(width, height));
		shadowShape.setFillColor(sf::Color::Green);
	
		//set text for button
		if (!buttonFont.loadFromFile("resources/fonts/arial.ttf")) 
		{
			std::cout << "Fehler beim Laden der button-Schrift";
		}	

		textColor = sf::Color::White;
		
		buttonText.setFont(buttonFont);
		buttonText.setString("hallo");
		buttonText.setCharacterSize(20);
		buttonTextPosX = buttonPosX + (getRectangleShape().getSize().x - this->buttonText.getLocalBounds().width) / 2;
		buttonTextPosY = -5+  buttonPosY + (getRectangleShape().getSize().y - this->buttonText.getLocalBounds().height) / 2;
		buttonText.setPosition(buttonTextPosX,buttonTextPosY);
		buttonText.setFillColor(textColor);
	

		setPosition(buttonPosX, buttonPosY);
	}

	void Button::update(long dT)  
	{
		ClickableHooverableRectShape::update(dT);

		if(isLeftButtonDown())
		{
			setPosition(buttonPosX + pressedOffsetX, buttonPosY + pressedOffsetY);
			buttonText.setPosition(buttonTextPosX + pressedOffsetX, buttonTextPosY + pressedOffsetY);
		}
		else
		{
			setPosition(buttonPosX, buttonPosY);
			buttonText.setPosition(buttonTextPosX, buttonTextPosY);
		}

		//setPosition(buttonPosX - offset, buttonPosY- offset);
	}

	void Button::render(sf::RenderWindow& window)
	{
		window.draw(shadowShape);
		ClickableHooverableRectShape::render(window);
		window.draw(buttonText);	
	}

}//namespace neulii
