#ifndef HOOVERABLERECTSHAPE
#define HOOVERABLERECTSHAPE

#include "SFML/Graphics.hpp"

class HooverableRectShape{
	
	private:
	
		bool isHoovered;
		sf::RectangleShape rectShape;

	public:

		HooverableRectShape(sf::RectangleShape shape);
		


};

#endif