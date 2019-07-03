#include <iostream>
#include "SFML/Graphics.hpp"

#include <vector>

#include "HooverableRectShape.h"
#include "Library.h"

void setColorBlue();
void test();

unsigned widthInFields = 10;
unsigned heightInFields = 10;

unsigned fieldWidth = 50;
unsigned fieldHeight = 50;


unsigned targetResolutionWidth = widthInFields * fieldWidth;
unsigned targetResolutionHeight = heightInFields * fieldHeight;

//fields 
std::vector<HooverableRectShape*> fields;


//Define Hoover actions for hooverable rectangles

HooverAction myHooverAction =  &test;
HooverAction setHooverBlue = &setColorBlue;


//main - method
int main(){

	//create window
	sf::RenderWindow window(sf::VideoMode(targetResolutionWidth,targetResolutionWidth),
						"Hello SFML-World",
						sf::Style::None);
	//calculate elements needed
	unsigned elements = widthInFields * heightInFields;

	//create elements and add it to field-vector
	for(unsigned i=0; i < elements; i++){

		unsigned elementInRow = i % widthInFields;
		unsigned elementInCol = i / widthInFields;

		float tempPosX = fieldWidth * elementInRow;
		float tempPosY = fieldHeight *elementInCol;

		HooverableRectShape* tempField;
		//make temporary field 
		tempField = new HooverableRectShape(tempPosX, tempPosY, static_cast<float>(fieldWidth), static_cast<float>(fieldHeight));
		tempField->setHooverColor(sf::Color::Yellow);
		//add field to vector
		fields.push_back(tempField);

	}

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

void test(){

	std::cout << "super" << std::endl;
}

void setColorBlue(){

}