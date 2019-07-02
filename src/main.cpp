#include <iostream>
#include "SFML/Graphics.hpp"

#include <vector>

#include "HooverableRectShape.h"
#include "Library.h"


std::vector<HooverableRectShape*> fields;

//create window
sf::RenderWindow window(sf::VideoMode(800,600),"Hello SFML-World",sf::Style::None);



void test(){

	std::cout << "super" << std::endl;
}

void closeWindow(){
	window.close();
}

void setColorBlue(){

}

//Define Hoover actions for hooverable rectangles

HooverAction myHooverAction =  &test;
HooverAction myHooverCloseWindow = &closeWindow;
HooverAction setHooverBlue = &setColorBlue;




int main(){

	fields.push_back(new HooverableRectShape(100,0,50,50));
	fields.push_back(new HooverableRectShape(100,50,50,50));

	//set Framerate to 60 FPS
	window.setFramerateLimit(60);
	
	sf::Clock clock;
	sf::Time time;

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
				
				if(event.key.code == sf::Keyboard::Escape){
					window.close();
				}
			}
		}

		//time for Update methods
		time = clock.getElapsedTime();
		long dT = time.asMilliseconds();

	//===================================================
		//updating logic
		

		//update field vector
		for(unsigned i=0; i<fields.size();i++){
			fields.at(i)->update(dT);

		}

		clock.restart();
	//=====================================================
		//rendering all

		//clear window before drawing new frame
		window.clear();

		//render field vector
		for(unsigned i=0; i<fields.size();i++){
			fields.at(i)->render(window);

		}

		//show content on display
		window.display();
	//========================================================
	}

}