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

#include "Bar.h"
#include "BarGraph.h"
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

unsigned targetResolutionWidth = 800;
unsigned targetResolutionHeight = 600;

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
				targetResolutionHeight),
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
neulii::barArray b;

std::vector<Bar*> bars;

sf::Texture testTex;
sf::Sprite testSprite;

sf::Sprite hardSprite;

sf::Texture hardTex;

void showRGBDemo() {

	const int tex_x = 100;
	const int tex_y = 100;

	hardTex.create(tex_x, tex_y);
	hardSprite.setTexture(hardTex);

	sf::Uint8* pixels;

	pixels = new sf::Uint8[tex_x * tex_y * 4];

	for (int y = 0; y < tex_y; y++) {

		for (int x = 0; x < tex_x; x++) {
			int index = ((tex_x)*y + x) * 4;


			//std::cout << "index: " << index <<  " | " << x << "/" << y << std::endl;

			pixels[index] = 255.0 / tex_x * x;
			pixels[index + 1] = 255.0 / tex_x * x;
			pixels[index + 2] = 0;
			pixels[index + 3] = 255;

		}
	}

	hardTex.update(pixels);
	//hardSprite.setScale(10,10);


}



int main()
{

	BarGraph(10,10);

	const int MAX_RANGE = 100000;
	const int NUMBERS = 800;

	//for random 
	std::srand(static_cast<unsigned long>(std::time(nullptr)));
	
	//fill every bar with a random number;
	for(int i = 0; i < NUMBERS; i++){

		float barWidth;
		float barHeight;

		float barPosX;
		float barPosY = targetResolutionHeight;

		barWidth = static_cast<float>(targetResolutionWidth) / NUMBERS;		//for calcing in float
		barHeight = targetResolutionHeight;

		barPosX = i*barWidth;

		Bar* temp = new Bar(barPosX, barPosY,barWidth,barHeight,MAX_RANGE);

		temp->setValue(neulii::getRandomInt(0,MAX_RANGE));


		bars.push_back(temp);

	}


	//showRGBDemo(); 

	if (!testTex.loadFromFile("resources/images/moneySymbol.png"))
	{
		log("fehler test");
	}
	//testSprite.setTextureRect(sf::IntRect(0, 0, 200, 200));

	testSprite.scale(0.5f,0.5f);
	testSprite.setPosition(200, 200);

	testSprite.setTexture(testTex);


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

	sf::Texture iron_oreField;

	if (!iron_oreField.loadFromFile("resources/images/iron_oreField.png"))
	{
		log("error by loading texture");
	}

	aTile = new ActionTile(coalMineField ,10,10,50,50);
	Tile* blendTile = new Tile(iron_oreField);


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
				if(event.key.code ==sf::Keyboard::Enter){

				
				}

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
	

	std::cout << "sort" << std::endl;
}

void setColorBlue()
{

}

//rendering all elements to display
void render(sf::RenderWindow &window)
{

	//render tiles vector
	for(unsigned i=0; i<tiles.size();i++)
	{
		//tiles.at(i)->render(window);
	}

	//aTile->render(window);
	//window.draw(testSprite);
	//window.draw(hardSprite);

	for(int i= 0; i<bars.size(); i++){
		bars.at(i)->render(window);
	}


}

//updating logic
void update(long dT)
{
	//update tiles vector
	for(unsigned i=0; i<tiles.size();i++)
	{
		tiles.at(i)->update(dT);
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
