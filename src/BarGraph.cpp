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

    void BarGraph::sortBarGraph()
    {

        

        
       
        for(unsigned j=0; j<bars.size()-1; j++){

            for (unsigned i=0; i<bars.size()-j-1; i++){

              
                    bars.at(i)->setColor(sf::Color::Red);
              
                if(bars.at(i)->getValue()> bars.at(i+1)->getValue())
                {
                    float temp;

                    temp = bars.at(i)->getValue();
                    bars.at(i)->setValue(bars.at(i+1)->getValue());
                    bars.at(i+1)->setValue(temp);	
                    
                    bars.at(i)->setColor(sf::Color::Blue);
                    
                    break;
                   

                }	
                			
            }
                
            return;
        }
        
        std::cout << "sorted" << std::endl;
    }

    void BarGraph::printAllValuesToConsole()
    {
        for(int i =0; i < bars.size(); i++)
        {
            std::cout << bars.at(i)->getValue() << "/";
        }
    }
}