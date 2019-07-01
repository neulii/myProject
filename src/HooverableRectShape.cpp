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
	window.draw(rectShape);
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

	//check if mouse is in rect
	if(rect.contains(relativeMousePos.x, relativeMousePos.y)){
		isHoovered = true;
	}
	else{
		isHoovered = false;
	}
	
	//when rect is hoovered
	if(isHoovered){

		rectShape.setFillColor(sf::Color::Green);


		//Debugging iformation for console

		#if DEBUG == 1
			neulii::vector2iToConsole(relativeMousePos);
		#endif

	}
	//when field is not hoovered
	else{

		rectShape.setFillColor(sf::Color::Red);

	}





}