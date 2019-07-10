#ifndef CLICKABLEHOOVERABLERECTSHAPE_H
#define CLICKABLEHOOVERABLERECTSHAPE_H

#include "HooverableRectShape.h"

namespace neulii{

	//Function Pointer for getting Hooveraction
	typedef void(*ClickAction)(void);

	class ClickableHooverableRectShape :public HooverableRectShape{

	private:

		bool isPressed = false;
		sf::Color pressedColor = sf::Color::Red;

		ClickAction leftClick = nullptr;
		ClickAction rightClick = nullptr;

		void leftClickAction();
		void rightClickAction();
	
	public:

		ClickableHooverableRectShape(float x, float y, float width, float height);

		void setPressedColor(sf::Color color);
		void operateClick(sf::Mouse::Button mouseButton);	
		void update(long dT);

		void setRightclickAction(ClickAction action);
		void setLeftclickAction(ClickAction action);

	};

}//namespace neulii

#endif