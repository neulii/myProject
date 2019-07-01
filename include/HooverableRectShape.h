#ifndef HOOVERABLERECTSHAPE
#define HOOVERABLERECTSHAPE

//define Debugging mode on or off
#define DEBUG 0

#include "SFML/Graphics.hpp"
#include "Library.h"

//Function Pointer for getting Hooveraction
typedef void(*HooverAction)(void);


class HooverableRectShape{
	
	private:
		bool isHoovered = false;
		sf::RectangleShape rectShape;
		sf::RenderWindow *window = nullptr;
		sf::FloatRect rect;
		
		//HooverAction hooverAction = nullptr;
		HooverAction leavingAction = nullptr;
		HooverAction enterAction = nullptr;

	public:

		HooverableRectShape(float x, float y, float width, float height);
		void render(sf::RenderWindow &window);
		void update(long dT);
		void leaving();
		void entering();

		//void addHooverAction(HooverAction action);
		void setEnterAction(HooverAction action);
		void setLeavingAction(HooverAction action);


};

#endif