#include "HooverableRectShape.h"


//Constructor 
HooverableRectShape::HooverableRectShape(float x, float y, float width, float height){

	rectShape.setPosition(x,y);
	rectShape.setSize(sf::Vector2f(width, height));

}

//render method
void HooverableRectShape::render(sf::RenderWindow &window){

}

//update method
void HooverableRectShape::update(long dT){

	if(isHoovered){

		



	}


}