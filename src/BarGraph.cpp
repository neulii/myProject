#include "BarGraph.h"
#include <iostream>

namespace neulii{

    BarGraph::BarGraph(float x, float y, float width, float height,float range):
        width(width), height(height), range(range),
        barGraphPosX(x), barGraphPosY(y)

    {
        std::cout << this->width << "    " << this-> height << std::endl;

    }

    void BarGraph::addBar(float value)
    {
        barWidth = width/(bars.size()+1);


        Bar* tempBar = new Bar( barGraphPosX + width*bars.size(), 
                                -barGraphPosY, barWidth, height, range);
        
        bars.push_back(tempBar);

        for (int i = 0; i<bars.size(); i++)
        {
            bars.at(i)->setWidth(barWidth);
        }
        
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