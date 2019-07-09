#include "ClickableHooverableRectShape.h"
#include <iostream>

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
		rectShape.setFillColor(sf::Color::Red);
	}
	//right button down
	else if(checkIfHoovered() && sf::Mouse::isButtonPressed(sf::Mouse::Right)){
		rectShape.setFillColor(sf::Color::Blue);
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
			std::cout << "right at: " << sf::Mouse::getPosition(*window).x << "   " << sf::Mouse::getPosition(*window).y << std::endl;
			rightClickAction();
		}
	}
}

//left-click Action;
void ClickableHooverableRectShape::leftClickAction(){


}

//right-click action
void ClickableHooverableRectShape::rightClickAction(){


}