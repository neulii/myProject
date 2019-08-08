#ifndef LIBRARY_H
#define LIBRARY_H

#include "SFML/Graphics.hpp"

namespace neulii{

	// prints a FloatRect to Console
	void floatRectToConsole(sf::FloatRect rect);
	
	//prints a Vector2i to the console
	void vector2iToConsole(sf::Vector2i vector);

	//prints a string vector to the console
	void printStringVec(std::vector<std::string> &stringVector);

	//write a string vector to file
	void writeStringVecToFile(std::vector<std::string> &vector, std::string fileName);

} //namespace neulii

#endif