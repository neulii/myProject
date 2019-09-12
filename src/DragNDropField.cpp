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
			sf::Vector2i moved = mouseOld - mouseNew;
			
			if ((mouseOld != mouseNew) && isLeftButtonDown() && !draggingActive)
			{
				//std::cout << "mouse is moved" << std::endl;
				draggingActive = true;

				//neulii::vector2ToConsole(moved);

			}

			if (draggingActive)
			{
				if (!isLeftButtonDown()) {
					draggingActive = false;
				}
				else {
					setPosition(getPosition().x-moved.x, getPosition().y - moved.y);
					rectShape.setFillColor(getLeftPressedColor());
				}
			}

			mouseOld = mouseNew;

		}
	}
}
