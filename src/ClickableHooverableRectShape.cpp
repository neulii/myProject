#include "ClickableHooverableRectShape.h"
#include <iostream>

ClickableHooverableRectShape::ClickableHooverableRectShape(float x, float y, float width, float height):HooverableRectShape(x,y,width,height){

}

//overrides update method from hoverablerectshape
void ClickableHooverableRectShape::update(long dT){

	
}

void ClickableHooverableRectShape::operateClick(sf::Mouse::Button button){

	//getting window for calculate relative MousePos
	sf::Window* window = this->getWindow();
	
	//check on nullptr
	if(window==nullptr)
		return;
	if(button == sf::Mouse::Left){
		
		std::cout << sf::Mouse::getPosition(*window).x << "   " << sf::Mouse::getPosition(*window).y << std::endl;
	}

	if(button == sf::Mouse::Right){
		std::cout << "right click" << std::endl;
	}
	
}