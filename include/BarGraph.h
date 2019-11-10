#ifndef BARGRAPH_H
#define BARGRAPH_H

#include "GameObject.h"
#include "Bar.h"
#include "Library.h"

namespace neulii{

    class BarGraph : public GameObject 
    
    {
        private: 

            barArray bars;

            float barGraphPosX;
            float barGraphPosY;

            float width;
            float height;

            float range; 

            float barWidth;

        public:
            BarGraph(float x, float y, float width, float height, float range);

            void render(sf::RenderWindow& window);
            void update(long dT);

            void addBar(float value, sf::Color color);
            void showBarGraphConsole();

            void printAllValuesToConsole();

            void swap(int first, int second);
            
    };
}
#endif