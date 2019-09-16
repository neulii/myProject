#ifndef BUTTON_H
#define BUTTON_H

#include "ClickableHooverableRectShape.h"
namespace neulii
{

	class Button : public ClickableHooverableRectShape
	{

	private: 

		sf::RectangleShape shadowShape;

	public: 
		
		Button(float x, float y, float width, float height); 
		
		void update(long dT);
		void render(sf::RenderWindow& window);
	};


}








#endif
