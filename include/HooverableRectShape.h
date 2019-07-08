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
		sf::RenderWindow *window = nullptr;
	
		HooverAction leavingAction = nullptr;
		HooverAction enterAction = nullptr;

	protected:
		sf::FloatRect rect;
		sf::RectangleShape rectShape;
		sf::Color defaultColor = sf::Color::White;
		sf::Color hooveringColor = sf::Color::Magenta;

	private:
		void leaving();
		void entering();

	public:

		HooverableRectShape(float x, float y, float width, float height);
		
		void render(sf::RenderWindow &window);
		void update(long dT);
		
		bool checkIfHoovered();
		void setEnterAction(HooverAction action);
		void setLeavingAction(HooverAction action);

		//set Color for Default and Hoovering
		void setHooverColor(sf::Color color);
		void setDefaultColor(sf::Color color);

		sf::RenderWindow* getWindow();
	
};

#endif