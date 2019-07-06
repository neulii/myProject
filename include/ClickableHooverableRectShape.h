#ifndef CLICKABLEHOOVERABLERECTSHAPE_H
#define CLICKABLEHOOVERABLERECTSHAPE_H

#include "HooverableRectShape.h"


//Function Pointer for getting Hooveraction
typedef void(*ClickAction)(void);

class ClickableHooverableRectShape :public HooverableRectShape{

private:

	bool isPressed = false;
	sf::Color pressedColor = sf::Color::Red;

public:

	ClickableHooverableRectShape(float x, float y, float width, float height);

	void setPressedColor(sf::Color color);
	bool checkClickAt(sf::Vector2f mousePos);	
	void update(long dT);
};



#endif