#include "HooverableRectShape.h"

HooverableRectShape::HooverableRectShape(float x, float y, float width, float height){

	isHoovered = false;

	rectShape.setPosition(x,y);
	rectShape.setSize(sf::Vector2f(width, height));

}