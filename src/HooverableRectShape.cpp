#include "HooverableRectShape.h"
#include <iostream>
#include "Library.h"


//Constructor 
HooverableRectShape::HooverableRectShape(float x, float y, float width, float height){

	rectShape.setPosition(x,y);
	rectShape.setSize(sf::Vector2f(width, height));

}

//render method
void HooverableRectShape::render(sf::RenderWindow &window){
	this->window = &window;
}

//update method
void HooverableRectShape::update(long dT){


	//get Absolute MousePosition
	
	//when window isn't initialized
	if(window == nullptr){
		return;
	}

	//get position of window
	sf::Vector2i windowPosition = this->window->getPosition();
	
	//get position of mouse
	sf::Vector2i mousePos = sf::Mouse::getPosition();
	
	//calculate relative MousePosition to window
	sf::Vector2i  relativeMousePos((mousePos.x-windowPosition.x), (mousePos.y-windowPosition.y));


	sf::FloatRect rect = rectShape.getLocalBounds();

	neulii::vector2iToConsole(relativeMousePos);

	//std::cout << rect.left << "   " << rect.top << "    " << rect.width << "  " << rect.height <<  std::endl;

	//std::cout << dT << std::endl;
	//std::cout << mousePos.x << "   " << mousePos.y << std::endl;

	if(isHoovered){

		



	}


}