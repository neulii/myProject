#ifndef HOOVERABLERECTSHAPE
#define HOOVERABLERECTSHAPE
#include "GameObject.h"
#include "SFML/Graphics.hpp"
#include "Library.h"

namespace neulii{

	//Function Pointer for getting Hooveraction
	typedef void(*HooverAction)(void);

	class HooverableRectShape : public GameObject{
		
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

		protected:
			void leaving();
			virtual void entering();

		public:

			HooverableRectShape(float x, float y, float width, float height);
			
			virtual void render(sf::RenderWindow &window);
			virtual void update(long dT);

			sf::Vector2f getPosition();
			sf::RectangleShape getRectangleShape();

			bool checkIfHoovered();
			virtual void setEnterAction(HooverAction action);
			void setLeavingAction(HooverAction action);

			//set Color for Default and Hoovering
			void setHooverColor(sf::Color color);
			void setDefaultColor(sf::Color color);

			void setPosition(float x, float y);
			void setSize(sf::Vector2f size);
			sf::RenderWindow* getWindow();

			sf::Color getDefaultColor();
	};

}//namespace neulii

#endif
