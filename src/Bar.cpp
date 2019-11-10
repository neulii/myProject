#include "Bar.h"
#include <iostream>
#include "Library.h"

namespace neulii{

    Bar::Bar(float x,float y, float width, float height, float range):
        x(x), y(y),
        width(width), height(height),
        range(range)
    
    {
        rect.setPosition(x,y);
       

        //rect.setSize(sf::Vector2f(width,height));
        //rect.setOutlineColor(sf::Color::Red);
        //rect.setOutlineThickness(2);
        rect.setFillColor(sf::Color::Blue);
    }

    void Bar::setValue(float value){
        this->value = value;
        this->height_value = -height/range * value;

        std::cout << height_value << std::endl;
        

       // this->rect.setSize(sf::Vector2f(width,0));

        std::cout << this->rect.getSize().y << std::endl;
    }

    float Bar::getValue(){
        return this->value;
    }

    float Bar::getRange()
    {
        return this->range;
    }

    void Bar::update(long dT){
    }

    void Bar::render(sf::RenderWindow& window){
        

       

        window.draw(this->rect);
        vector2ToConsole(this->rect.getSize());

    }

    void Bar::setWidth(float width)
    {
        this->width = width;
        this->rect.setSize(sf::Vector2f(width, height_value));

        
    }

    sf::Vector2f Bar::getPosition()
    {
        return rect.getPosition();
    }

    void Bar::setPosition(sf::Vector2f pos)
    {
        rect.setPosition(pos);
    }

    sf::Vector2f Bar::getSize()
    {
        return sf::Vector2f(width,height);
    }

    void Bar::setColor(sf::Color color)
    {
        rect.setFillColor(color);
    }
}