#ifndef BUTTON_H
#define BUTTON_H

#include "ClickableHooverableRectShape.h"
#include "GameObject.h"
namespace neulii
{

	class Button : public ClickableHooverableRectShape, public GameObject
	{

	private:

		unsigned buttonPosX = 0;
		unsigned buttonPosY = 0;
		
		unsigned shadowOffsetX = 3;
		unsigned shadowOffsetY = 3;

		float buttonTextPosX = 0;
		float buttonTextPosY = 0;

		sf::RectangleShape shadowShape;

		unsigned const pressedOffsetX = 2; 
		unsigned const pressedOffsetY = 2;
	
		sf::Text buttonText;
		sf::Font buttonFont;
		sf::Color textColor;

	public: 
		
		Button(float x, float y, float width, float height); 
		
		void update(long dT);
		void render(sf::RenderWindow& window);
	};
}

#endif
