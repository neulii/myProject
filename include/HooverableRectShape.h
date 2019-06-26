#ifndef HOOVERABLERECTSHAPE
#define HOOVERABLERECTSHAPE

#include "SFML/Graphics.hpp"

class HooverableRectShape{
	
	private:
	
		bool isHoovered;
		sf::RectangleShape rectShape;

	

	public:

		HooverableRectShape(float x, float y, float width, float height);
		


};

#endif