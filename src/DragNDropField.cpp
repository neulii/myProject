#include "DragNDropField.h"
#include <iostream>
#include "Library.h"

namespace neulii {

	DragNDropField::DragNDropField(float x, float y, float width, float height) 
		:ClickableHooverableRectShape(x,y,width,height)
	{


	}

	void DragNDropField::update(long dT)
	{
		ClickableHooverableRectShape::update(dT);

		sf::RenderWindow *window = getWindow();
		if (window)
		{
			
			mouseNew = sf::Mouse::getPosition(*window);
			
			if ((mouseOld != mouseNew) && isLeftButtonDown())
			{
				//std::cout << "mouse is moved" << std::endl;
				sf::Vector2i moved = mouseOld - mouseNew;

				setPosition(getPosition().x-moved.x, getPosition().y - moved.y);

				//neulii::vector2ToConsole(moved);

			}
			
			mouseOld = mouseNew;

		}
	}
}
