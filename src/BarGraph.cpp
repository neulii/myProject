#include "BarGraph.h"
#include <iostream>

namespace neulii{

    BarGraph::BarGraph(float width, float height):
        width(width),
        height(height)
    {
        std::cout << this->width << "    " << this-> height << std::endl;

    }

    void BarGraph::addBar(float value)
    {
        barWidth = width/bars.size();

        






    }

    void BarGraph::render(sf::RenderWindow& window)
    {
        for(int i = 0; i<bars.size(); i++)
        {
            bars.at(i)->render(window);
        }        
    }

    void BarGraph::update(long dT)
    {
        for(int i = 0; i<bars.size(); i++)
        {
            bars.at(i)->update(dT);
        }        
    }

}