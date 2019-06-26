#include <iostream>
#include "SFML/Graphics.hpp"

int main(){
	
	//create window
	sf::RenderWindow window(sf::VideoMode(800,600),"super fenster");

	sf::RectangleShape shape;
	shape.setPosition(10,10);
	shape.setSize(sf::Vector2f(10,10));
	shape.setOutlineColor(sf::Color::Blue);
	shape.setOutlineThickness(2);

	shape.setFillColor(sf::Color::Red);

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
		window.draw(shape);

		//show content on display
		window.display();
	}

}