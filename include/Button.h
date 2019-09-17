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
		unsigned const OFFSET_HOOVERED= 4;
		unsigned const OFFSET_UNHOOVERED= 1;

	public: 
		
		Button(float x, float y, float width, float height); 
		
		void update(long dT);
		void render(sf::RenderWindow& window);
	};


}








#endif
