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

//action when entering area
void HooverableRectShape::entering(){
	

}

//action when leaving area
void HooverableRectShape::leaving(){
	
	if(hooverAction!=nullptr)
		hooverAction();
	//when hooveraction is defined
	// if(pFunc!=nullptr)
	// 	pFunc();
		
}

void HooverableRectShape::addHooverAction(HooverAction action){
	hooverAction = action;
	// pFunc = func;
}

