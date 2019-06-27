#include "Library.h"
#include <iostream>

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

} //namespace neulii







