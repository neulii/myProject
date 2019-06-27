#include "HooverableRectShape.h"
#include <iostream>


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


	//get Absolute MousePosition
	sf::Vector2i mousePos = sf::Mouse::getPosition();
	sf::FloatRect rect = rectShape.getLocalBounds();

	std::cout << rect.left << "   " << rect.top << "    " << rect.width << "  " << rect.height <<  std::endl;

	//std::cout << dT << std::endl;
	//std::cout << mousePos.x << "   " << mousePos.y << std::endl;

	if(isHoovered){

		



	}


}