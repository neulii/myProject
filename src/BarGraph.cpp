#include "BarGraph.h"
#include <iostream>

namespace neulii{

    BarGraph::BarGraph(float x, float y, float width, float height,float range):
       barGraphPosX(x), barGraphPosY(y), 
       width(width), height(height),
       range(range)
    {
        
    }

    void BarGraph::addBar(float value, sf::Color color)
    {
        barWidth = width/(bars.size()+1);

        Bar* tempBar = new Bar( barGraphPosX + (barWidth*bars.size()), 
                                barGraphPosY, barWidth, height, range);
        
        tempBar->setValue(value);
        tempBar->setColor(color);
        
        bars.push_back(tempBar);

        for (int i = 0; i<bars.size(); i++)
        {
            bars.at(i)->setWidth(barWidth);
            bars.at(i)->setPosition(sf::Vector2f(barGraphPosX+barWidth * i, barGraphPosY));
            
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

    void BarGraph::showBarGraphConsole()
    {
        for(int i = 0; i<bars.size(); i++)
        {
            std::cout << "========" << i << "=======" << std::endl;
            std::cout << "x: " << bars.at(i)->getPosition().x << "  y: " << bars.at(i)->getPosition().y << std::endl;
            std::cout << "range: " << bars.at(i)->getRange() << "   " << "value: " << bars.at(i)->getRange() << std::endl;
        }
    }


    void BarGraph::printAllValuesToConsole()
    {
        for(int i =0; i < bars.size(); i++)
        {
            std::cout << bars.at(i)->getValue() << "/";
        }
    }

    void BarGraph::swap(int first, int second)
    {
        std::cout << bars.at(first)->getValue() << std::endl;
        std::cout << bars.at(second)->getValue() << std::endl;



        Bar* temp = bars.at(first);
        bars.at(first) = bars.at(second);
        bars.at(second) = temp;
        std::cout << "swapped" << std::endl;

         std::cout << bars.at(first)->getValue() << std::endl;
        std::cout << bars.at(second)->getValue() << std::endl;
    }
}