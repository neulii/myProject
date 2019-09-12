#ifndef CLICKABLEHOOVERABLERECTSHAPE_H
#define CLICKABLEHOOVERABLERECTSHAPE_H

#include "HooverableRectShape.h"

namespace neulii{

	//Function Pointer for getting Hooveraction
	typedef void(*ClickAction)(void);

	class ClickableHooverableRectShape :public HooverableRectShape{

	private:

		bool isPressed = false;

		bool leftActionExecuted = false;
		bool rightActionExecuted = false;

		bool leftButtonIsDown = false;
		bool rightButtonIsDown = false;

		sf::Color leftPressedColor = sf::Color::Red;
		sf::Color rightPressedColor = sf::Color::Blue;

		ClickAction leftClick = nullptr;
		ClickAction rightClick = nullptr;

		void leftClickAction();
		void rightClickAction();
	
	public:

		ClickableHooverableRectShape(float x, float y, float width, float height);

		void setRightPressedColor(sf::Color color);
		void setLeftPressedColor(sf::Color color);
		
		//void operateClick(sf::Mouse::Button mouseButton);	
		void update(long dT);

		void setRightclickAction(ClickAction action);
		void setLeftclickAction(ClickAction action);

		bool isRightButtonDown();
		bool isLeftButtonDown();

		sf::Color getLeftPressedColor();
	};

}//namespace neulii

#endif