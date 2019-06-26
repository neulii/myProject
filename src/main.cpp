#include <iostream>
#include "SFML/Graphics.hpp"

#include "HooverableRectShape.h"

int main(){
	
	//create window
	sf::RenderWindow window(sf::VideoMode(800,600),"Hello SFML-World");

	sf::RectangleShape test(sf::Vector2f(10,10));

	HooverableRectShape hoover(test);


	//while window is open
	while(window.isOpen()){


		sf::Event event;

		//check events while window is open
		while(window.pollEvent(event)){

			//when close event -> close window
			if(event.type == sf::Event::Closed)
				window.close();

		}

		//clear window before drawing new frame
		window.clear();
		

		//show content on display
		window.display();
	}

}