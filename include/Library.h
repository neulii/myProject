#ifndef LIBRARY_H
#define LIBRARY_H

#include "SFML/Graphics.hpp"


//Function Pointer for getting Hooveraction
typedef void(*HooverAction)(void);



namespace neulii{

	// prints a FloatRect to Console
	void floatRectToConsole(sf::FloatRect rect);
	
	//prints a Vector2i to the console
	void vector2iToConsole(sf::Vector2i vector);




} //namespace neulii

#endif