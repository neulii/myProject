#ifndef HOOVERABLERECTSHAPE
#define HOOVERABLERECTSHAPE

#include "SFML/Graphics.hpp"

class HooverableRectShape{
	
	private:
		bool isHoovered = false;
		sf::RectangleShape rectShape;
		sf::RenderWindow *window = nullptr;

	

	public:

		HooverableRectShape(float x, float y, float width, float height);
		void render(sf::RenderWindow &window);
		void update(long dT);

};

#endif