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
	void ClickableHooverableRectShape::update(long dT){

		//check if window is NULL
		if(getWindow()==nullptr){
			return;
		}

		//Coloring when hoovered
		if(checkIfHoovered()){
			rectShape.setFillColor(hooveringColor);
		}
		//coloring when NOT hoovered
		else{
			rectShape.setFillColor(defaultColor);
		}

		//when mouse is clicked inside
		if(checkIfHoovered()){

			//leftclick
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				rectShape.setFillColor(leftPressedColor);
				leftClickAction();
			}

			//rightclick
			if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
				rectShape.setFillColor(rightPressedColor);
				rightClickAction();
			}
		}
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

}//namespace neulii