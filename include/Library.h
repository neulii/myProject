#ifndef LIBRARY_H
#define LIBRARY_H

#include "SFML/Graphics.hpp"

#define NL '\n'
#define TAB '\t'

namespace neulii{

	// prints a FloatRect to Console
	void floatRectToConsole(sf::FloatRect rect);
	
	//prints a Vector2i to the console
	void vector2iToConsole(sf::Vector2i vector);

	//prints a string vector to the console
	void printStringVec(std::vector<std::string> &stringVector);

	//write a string vector to file
	void writeStringVecToFile(std::vector<std::string> &vector, std::string fileName);


	/*	random Generator is to be initialized before using with:

		std::srand(static_cast<unsigned long>(std::time(nullptr)))*/
	unsigned getRandomInt(unsigned min, unsigned max);
	
	unsigned findMaxAtArray(int array[], size_t size);

	void selectionSortIntegerArray(int array[], size_t size);
	void bubbleSortIntegerArray(int array[], size_t size);
	
	void printArrayToConsole(int array[], size_t size);
	void printArrayToLineConsole(int array[], size_t size);

} //namespace neulii

#endif