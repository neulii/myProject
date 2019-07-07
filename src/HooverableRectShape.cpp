#include "HooverableRectShape.h"
#include <iostream>
#include "Library.h"

//Constructor 
HooverableRectShape::HooverableRectShape(float x, float y, float width, float height){
	//set Position of rectShape
	rectShape.setPosition(x,y);

	//set Size of rectShape
	rectShape.setSize(sf::Vector2f(width, height));

	//get dimensions for floatRect -> contains
	rect = rectShape.getGlobalBounds();
	
	//set defaultColors
	defaultColor = sf::Color::White;
	hooveringColor = sf::Color::Green;

}

//render method
void HooverableRectShape::render(sf::RenderWindow &window){
	this->window = &window;
	window.draw(rectShape);
}

bool HooverableRectShape::checkIfHoovered(){

	//get position of window
	sf::Vector2i windowPosition = this->window->getPosition();
	
	//get position of mouse
	sf::Vector2i mousePos = sf::Mouse::getPosition();
	
	//calculate relative MousePosition to window
	sf::Vector2i  relativeMousePos((mousePos.x-windowPosition.x), (mousePos.y-windowPosition.y));

	//check if mouse is in rect
	if(this->rect.contains(relativeMousePos.x, relativeMousePos.y)){
		//when mouse is coming in
		if(isHoovered==false){
			entering();
		}
		isHoovered = true;
	}
	else{
		//when mouse is going out
		if(isHoovered==true){
			leaving();
		}
		isHoovered = false;
	}

	return isHoovered;

}


//update method
void HooverableRectShape::update(long dT){

	//get Absolute MousePosition
	
	//when window isn't initialized
	if(window == nullptr){
		return;
	}

	//when rect is hoovered
	if(checkIfHoovered()){
		rectShape.setFillColor(hooveringColor);
	}

	//when field is not hoovered
	else{
		rectShape.setFillColor(defaultColor);
	}
}

//action when entering area
void HooverableRectShape::entering(){
	
	//check if enterAction is set
	if(enterAction!=nullptr)
		enterAction();

}

//action when leaving area
void HooverableRectShape::leaving(){
	
	//check if leavingaction is set
	if(leavingAction != nullptr)
		leavingAction();

}

//set action for entering
void HooverableRectShape::setEnterAction(HooverAction action){
	enterAction = action;
}

//set action for leaving
void HooverableRectShape::setLeavingAction(HooverAction action){
	leavingAction = action;
}

//set Color for Hoovering
void HooverableRectShape::setHooverColor(sf::Color color){
	hooveringColor = color;
}

//set default Color
void HooverableRectShape::setDefaultColor(sf::Color color){
	defaultColor=color;
	rectShape.setFillColor(defaultColor);

}

sf::RenderWindow* HooverableRectShape::getWindow(){
	return window;

}

