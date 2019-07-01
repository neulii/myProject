#include <iostream>
#include "SFML/Graphics.hpp"

#include "HooverableRectShape.h"
#include "Library.h"

int main(){
	
	//create window
	sf::RenderWindow window(sf::VideoMode(800,600),"Hello SFML-World",sf::Style::None);

	window.setFramerateLimit(60);
	
	sf::Clock clock;
	sf::Time time;

	HooverableRectShape hoover(0,0,50,50);
	HooverableRectShape haaver(0,100,50,50);

	//while window is open
	while(window.isOpen()){


		sf::Event event;

		//check events while window is open
		while(window.pollEvent(event)){

			//when close event -> close window
			if(event.type == sf::Event::Closed)
				window.close();

			//if key is pressed
			if(event.type == sf::Event::KeyPressed){

				//select pressed key
				switch(event.key.code){

					//ESCAPE Key to close game 
					case sf::Keyboard::Escape:

						window.close();
						break;

				}
			}
	

		}

		//time for Update methods
		time = clock.getElapsedTime();
		long dT = time.asMilliseconds();

		//updating logic
		hoover.update(dT); 
		haaver.update(dT);

		clock.restart();

		//clear window before drawing new frame
		window.clear();

		//rendering window		
		hoover.render(window);
		haaver.render(window);


		//show content on display
		window.display();


	}

}