#ifndef HOOVERABLERECTSHAPE
#define HOOVERABLERECTSHAPE

//define Debugging mode on or off
#define DEBUG 0

#include "SFML/Graphics.hpp"
#include "Library.h"




class HooverableRectShape{
	
	private:
		bool isHoovered = false;
		sf::RectangleShape rectShape;
		sf::RenderWindow *window = nullptr;
		sf::FloatRect rect;
		
		//void (*pFunc)(void) = nullptr;

		HooverAction hooverAction = nullptr;

	public:

		HooverableRectShape(float x, float y, float width, float height);
		void render(sf::RenderWindow &window);
		void update(long dT);
		void leaving();
		void entering();

		void addHooverAction(HooverAction action);

};

#endif