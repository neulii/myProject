#include "ClickableHooverableRectShape.h"
#include <iostream>

namespace neulii{

	//Constructor
	ClickableHooverableRectShape::ClickableHooverableRectShape(	float x, 
																float y, 
																float width, 
																float height)
		:HooverableRectShape(x,y,width,height)
	{
	}

	//overrides update method from hoverable rectshape
	void ClickableHooverableRectShape::update(long dT)
	{
		//constructor from parent class
		HooverableRectShape::update(dT);

		//when mouse is clicked inside
		if(checkIfHoovered()){

			//leftclick
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				rectShape.setFillColor(leftPressedColor);

				leftButtonIsDown = true;

				//for action is just executed  one time
				if(!leftActionExecuted){
					leftClickAction();
					leftActionExecuted = true;
				}
			}
			else 
				leftButtonIsDown = false;

			//rightclick
			if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
				rectShape.setFillColor(rightPressedColor);

				rightButtonIsDown = true;

				//for action is just executed  one time
				if(!rightActionExecuted){
					rightClickAction();
					rightActionExecuted = true;
				}
			}
			else
				rightButtonIsDown = false;

			//reset flag when mousebutton is released and action is executed
			if(leftActionExecuted && !sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				leftActionExecuted = false;
			}

			if(rightActionExecuted && !sf::Mouse::isButtonPressed(sf::Mouse::Right)){
				rightActionExecuted = false;
			}
		}	
		//when shape isnt hoovered button is more clicked
		/*else{
			leftButtonIsDown = false;
			rightButtonIsDown =false;
		}*/
	}

	//left-click Action;
	void ClickableHooverableRectShape::leftClickAction(){
		if(leftClick!=nullptr){
			leftClick();
		}
	}

	//right-click action
	void ClickableHooverableRectShape::rightClickAction(){
		if(rightClick!=nullptr){
			rightClick();
		}
	}

	void ClickableHooverableRectShape::setRightPressedColor(sf::Color color){
		this->rightPressedColor = color;
	}

	void ClickableHooverableRectShape::setLeftPressedColor(sf::Color color){
		this->leftPressedColor = color;
	}

	void ClickableHooverableRectShape::setLeftclickAction(ClickAction action){
		
		leftClick = action;
	}

	void ClickableHooverableRectShape::setRightclickAction(ClickAction action){
		rightClick = action;
	}

	bool ClickableHooverableRectShape::isLeftButtonDown(){
		return leftButtonIsDown;
	}

	bool ClickableHooverableRectShape::isRightButtonDown(){
		return rightButtonIsDown;
	}

	sf::Color ClickableHooverableRectShape::getLeftPressedColor()
	{
		return leftPressedColor;
	}
}//namespace neulii