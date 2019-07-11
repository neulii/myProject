#include "ClickableHooverableRectShape.h"
#include <iostream>

namespace neulii{

	//Constructor
	ClickableHooverableRectShape::ClickableHooverableRectShape(float x, float y, float width, float height):HooverableRectShape(x,y,width,height){

	}

	//overrides update method from hoverablerectshape
	void ClickableHooverableRectShape::update(long dT){

		//check if window is NULL
		if(getWindow()==nullptr){
			return;
		}

		//Coloring when hoovered
		if(checkIfHoovered()){
			rectShape.setFillColor(hooveringColor);
			//std::cout << "lsdkjf"<< std::endl;
		}
		//coloring when NOT hoovered
		else{
			rectShape.setFillColor(defaultColor);
		}

		//left button down
		if(checkIfHoovered() && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			rectShape.setFillColor(leftPressedColor);
		}
		//right button down
		else if(checkIfHoovered() && sf::Mouse::isButtonPressed(sf::Mouse::Right)){
			rectShape.setFillColor(rightPressedColor);
		}
	}

	//oparate clicking action
	void ClickableHooverableRectShape::operateClick(sf::Mouse::Button button){

		//getting window for calculate relative MousePos
		sf::Window* window = this->getWindow();
		
		//check on nullptr
		if(window==nullptr)
			return;
		
		//when mouse is clicked inside
		if(checkIfHoovered()){

			//leftclick
			if(button == sf::Mouse::Left){
				std::cout << "left at: " << sf::Mouse::getPosition(*window).x << "   " << sf::Mouse::getPosition(*window).y << std::endl;
				leftClickAction();
			}

			//rightclick
			if(button == sf::Mouse::Right){
				//std::cout << "right at: " << sf::Mouse::getPosition(*window).x << "   " << sf::Mouse::getPosition(*window).y << std::endl;
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