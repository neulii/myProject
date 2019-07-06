#include "ClickableHooverableRectShape.h"
#include <iostream>

ClickableHooverableRectShape::ClickableHooverableRectShape(float x, float y, float width, float height):HooverableRectShape(x,y,width,height){

}

void ClickableHooverableRectShape::update(long dT){

	std::cout << "test" << std::endl;


}