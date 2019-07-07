#include "ClickableHooverableRectShape.h"
#include <iostream>

ClickableHooverableRectShape::ClickableHooverableRectShape(float x, float y, float width, float height):HooverableRectShape(x,y,width,height){

}

//overrides update method from hoverablerectshape
void ClickableHooverableRectShape::update(long dT){

	
}

void ClickableHooverableRectShape::operateClick(sf::Mouse::Button button){

	if(button == sf::Mouse::Left){

		std::cout << "leftclick" << std::endl;
	}

	if(button == sf::Mouse::Right){
		std::cout << "right click" << std::endl;
	}
	
}