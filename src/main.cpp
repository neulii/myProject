#include <iostream>
#include "SFML/Graphics.hpp"

#include "HooverableRectShape.h"

int main(){
	
	//create window
	sf::RenderWindow window(sf::VideoMode(800,600),"Hello SFML-World");

	

	HooverableRectShape hoover(0,0,50,50);


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