#include "Library.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

namespace neulii{

	#define NL '\n'
	#define TAB '\t'

	void floatRectToConsole(sf::FloatRect rect){

		std::cout << "x:      " << rect.left <<   std::endl;
		std::cout << "y:      " << rect.top  <<   std::endl;
		std::cout << "width:  " << rect.width <<  std::endl;
		std::cout << "height: " << rect.height << std::endl; 
	}
	
	void vector2iToConsole(sf::Vector2i vector){
		std::cout << "x: " << vector.x  << "   y: " << vector.y << std::endl;
	}

	void printStringVec(std::vector<std::string> &stringVector){	
		
		for(unsigned i=0; i<stringVector.size(); i++){
			std::cout << stringVector.at(i) << std::endl;
		}

	}

	void writeStringVecToFile(std::vector<std::string> &vector, std::string fileName){

		std::ofstream output;
		output.open(fileName);

		for(unsigned i = 0; i<vector.size();i++){
			output << vector.at(i) << std::endl;
		}
		output.close();
	}

	//returns a random integer
	unsigned getRandomInt(unsigned min, unsigned max){

	/*
		random Generator is to be initialized before using with:

		std::srand(static_cast<unsigned long>(std::time(nullptr)));

	*/
		int randNumber = std::rand();
		int randomNumber =  randNumber % (max - min + 1) + min;

		return randomNumber;
	}

	//sorts the array 
	void sortIntegerArray(int array[], size_t size){
		unsigned maxValue;
		for(int j = 0; j<size; j++){

			maxValue = findMaxAtArray(array, size-j);
			
			int swap = array[maxValue];
			array[maxValue] = array[size-j-1];
			array[size-j-1] = swap;
		}
	}

	//returns the position of the biggest value
	unsigned findMaxAtArray(int array[], size_t size){

		unsigned maxValuePos = 0;
		for(unsigned i = 0; i<size; i++){
			
			if(array[maxValuePos]<array[i]){
				maxValuePos = i;
			}
		}
		return maxValuePos;
	}

	//print the array to the console
	void printArrayToConsole(int array[], size_t size){
		std::cout << "=================" << NL;
		for (unsigned i = 0; i<size; i++){
			std::cout << array[i]<< NL;
		}
		std::cout << "=================" << NL;
	}

} //namespace neulii







