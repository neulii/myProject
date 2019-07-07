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

		sf::Color hooveringColor = sf::Color::Red;
		sf::Color defaultColor = sf::Color::White;
		
		HooverAction leavingAction = nullptr;
		HooverAction enterAction = nullptr;

	private:
		void leaving();
		void entering();
		bool checkIfHoovered();

	public:

		HooverableRectShape(float x, float y, float width, float height);
		
		void render(sf::RenderWindow &window);
		void update(long dT);
		
		//void addHooverAction(HooverAction action);
		void setEnterAction(HooverAction action);
		void setLeavingAction(HooverAction action);

		//set Color for Default and Hoovering
		void setHooverColor(sf::Color color);
		void setDefaultColor(sf::Color color);

		sf::RenderWindow* getWindow();
	
};

#endif