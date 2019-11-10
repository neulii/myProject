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

        // std::cout << "======newBAr======" << std::endl;
    
        // std::cout << "width:     " << width << std::endl;
        // std::cout << "bar width: " << barWidth << std::endl;


        // std::cout << "=================" << std::endl;

        Bar* tempBar = new Bar( barGraphPosX + (barWidth*bars.size()), 
                                barGraphPosY, barWidth, height, range);
        
        tempBar->setValue(value);
        tempBar->setColor(color);
        
        bars.push_back(tempBar);

        for (int i = 0; i<bars.size(); i++)
        {
            bars.at(i)->setWidth(barWidth);
            bars.at(i)->setPosition(sf::Vector2f(barGraphPosX+barWidth * i, barGraphPosY));
            
            // std::cout << std::endl;
            // std::cout << std::endl;

            // std::cout << "=======      " << i+1 << "     ========" << std::endl;

            
            // vector2ToConsole(bars.at(i)->getPosition());
            // vector2ToConsole(bars.at(i)->getSize());
           // std::cout << "================================" << std::endl;
        }
        //std::cout << "anzahl: " << bars.size() << std::endl;
        
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

}