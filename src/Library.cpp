#include "Library.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

namespace neulii{

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

} //namespace neulii







