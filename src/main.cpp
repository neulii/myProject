#include <iostream>
#include "SFML/Graphics.hpp"

#include <vector>

#include "HooverableRectShape.h"
#include "ClickableHooverableRectShape.h"
#include "DragNDropField.h"
#include "Library.h"
#include "Button.h"
#include "MenuButton.h"
#include "Tile.h"
#include "ActionTile.h"

using namespace neulii;

void exitProg();
void setColorBlue();
void test();
void buttonClickedText();

void render(sf::RenderWindow& window);
void update(long dT);

unsigned widthInFields = 10;
unsigned heightInFields = 10;

unsigned fieldWidth = 50;
unsigned fieldHeight = 50;

unsigned targetResolutionWidth = widthInFields * fieldWidth;
unsigned targetResolutionHeight = heightInFields * fieldHeight;

//fields 
std::vector<ClickableHooverableRectShape*> fields;

//tiles

std::vector<Tile*> tiles;

//Define Hoover actions for hooverable rectangles

HooverAction myHooverAction =  &test;
HooverAction setHooverBlue = &setColorBlue;

ClickAction click = &buttonClickedText;

//create window
sf::RenderWindow window(sf::VideoMode(
				targetResolutionWidth,
				targetResolutionWidth),
				"Hello SFML-World"
				,sf::Style::Default
				/*,
				sf::Style::None*/);



sf::Vector2i pixelPos;

// convert it to world coordinates
sf::Vector2f worldPos;

//test.setDefaultColor(sf::Color::Green);

//main - method

ActionTile* aTile;

int main()
{
	sf::Texture grassFieldTexture;

	if(!grassFieldTexture.loadFromFile("resources/images/grassField.png"))
	{
		log("error by loading texture");
	}

	sf::Texture coalMineField;

	if(!coalMineField.loadFromFile("resources/images/coalMineField.png"))
	{
		log("error by loading texture");
	}

	sf::Texture ironOreMineField;

	if (!ironOreMineField.loadFromFile("resources/images/ironOreMineField.png"))
	{
		log("error by loading texture");
	}


	
	aTile = new ActionTile(coalMineField ,10,10,50,50);
	Tile* blendTile = new Tile(ironOreMineField);


	aTile->setHooveredTile(*blendTile);




	//calculate elements needed
	unsigned elements = widthInFields * heightInFields;

	//create elements and add it to field-vector
	for(unsigned i=0; i < elements; i++){

		unsigned elementInRow = i % widthInFields;
		unsigned elementInCol = i / widthInFields;

		float tempPosX = static_cast<float>(fieldWidth  *elementInRow);
		float tempPosY = static_cast<float>(fieldHeight *elementInCol);

		Tile* tile;
		tile = new Tile(grassFieldTexture);
		tile->setPosition(tempPosX,tempPosY);

		tiles.push_back(tile);

		
		ClickableHooverableRectShape* tempField;
		
		//make temporary field 
		// tempField = new ClickableHooverableRectShape(
		// 		tempPosX, 
		// 		tempPosY, 
		// 		static_cast<float>(fieldWidth), 
		// 		static_cast<float>(fieldHeight));



		// tempField->setDefaultColor(sf::Color::Blue);
		// tempField->setLeftPressedColor(sf::Color::Yellow);

		//add field to vector
		fields.push_back(tempField);
	}

	//set Framerate to 60 FPS -> deactivated macos performance 
	window.setFramerateLimit(60);
	
	sf::Clock clock;
	sf::Time time;

	//while window is open
	while(window.isOpen())
	{

		sf::Event event;

		//check events while window is open
		while(window.pollEvent(event))
		{
			//when close event -> close window
			if(event.type == sf::Event::Closed)
				window.close();

			//if key is pressed
			if(event.type == sf::Event::KeyPressed)
			{

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
		
		update(dT);
		
		clock.restart();
	//=====================================================

		//clear window before drawing new frame
		window.clear();

		//render all elements
		render(window);

		

		//show content on display
		window.display();
	//========================================================
	}
}

void test()
{

	std::cout << "super" << std::endl;
}

void setColorBlue()
{

}

//rendering all elements to display
void render(sf::RenderWindow &window)
{

	//render field vector
	for(unsigned i=0; i<fields.size();i++)
	{


		tiles.at(i)->render(window);
	}

	aTile->render(window);

}

//updating logic
void update(long dT)
{
	//update field vector
	for(unsigned i=0; i<fields.size();i++)
	{
		//fields.at(i)->update(dT);

	}

	aTile->update(dT);
}

void exitProg()
{
	exit(0);
}

void buttonClickedText()
{
	std::cout << "button clicked" << std::endl;
}
