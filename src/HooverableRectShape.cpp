#include "HooverableRectShape.h"
#include <iostream>
#include "Library.h"

namespace neulii{

	//Constructor 
	HooverableRectShape::HooverableRectShape(float x, float y, float width, float height)
	{
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

	//checks if shape is hoovered
	bool HooverableRectShape::checkIfHoovered(){

		//if window isnt initialized
		if(getWindow()==nullptr)
			return false;
		//get position of window
		sf::Vector2i windowPosition = this->window->getPosition();
		
		//get position of mouse
		sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

		sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
		sf::Vector2f worldPos = window->mapPixelToCoords(pixelPos);
		
		

		//calculate relative MousePosition to window
		sf::Vector2i  relativeMousePos((static_cast<int>(worldPos.x)), static_cast<int>((worldPos.y)));

		//check if mouse is in rect
		if(this->rect.contains(static_cast<float>(relativeMousePos.x), static_cast<float>(relativeMousePos.y))){
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

	//returns window
	sf::RenderWindow* HooverableRectShape::getWindow(){
		return window;

	}

	sf::Color HooverableRectShape::getDefaultColor()
	{
		return defaultColor;
	}

	void HooverableRectShape::setPosition(float x, float y){
		rectShape.setPosition(x,y);
		rect.left = rectShape.getPosition().x;
		rect.top = rectShape.getPosition().y;
	}

	void HooverableRectShape::setSize(sf::Vector2f size){
		rectShape.setSize(size);
	}

	sf::Vector2f HooverableRectShape::getPosition()
	{
		return rectShape.getPosition();
	}

}//namespace neulii