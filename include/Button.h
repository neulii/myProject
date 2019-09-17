#ifndef BUTTON_H
#define BUTTON_H

#include "ClickableHooverableRectShape.h"
namespace neulii
{

	class Button : public ClickableHooverableRectShape
	{

	private:

		unsigned shadowPosX = 0;
		unsigned shadowPosY = 0;

		sf::RectangleShape shadowShape;
		unsigned const OFFSET_HOOVERED= 1;
		unsigned const OFFSET_UNHOOVERED= 3;

	public: 
		
		Button(float x, float y, float width, float height); 
		
		void update(long dT);
		void render(sf::RenderWindow& window);
	};


}








#endif
