#ifndef LIBRARY_H
#define LIBRARY_H

#include "SFML/Graphics.hpp"
#include "Bar.h"
#include "BarGraph.h"

#define NL '\n'
#define TAB '\t'

namespace neulii{

	//typedefs
	typedef std::vector<Bar*> barArray;

	//log message to console
	void log(const char* message);

	// prints a FloatRect to Console
	void floatRectToConsole(sf::FloatRect rect);
	
	//prints a Vector2i to the console
	void vector2ToConsole(sf::Vector2i vector);
	void vector2ToConsole(sf::Vector2f vector);

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
	
	void bubbleSortBar(barArray& bars);
	
	void printArrayToConsole(int array[], size_t size);
	void printArrayToLineConsole(int array[], size_t size);

} //namespace neulii

#endif