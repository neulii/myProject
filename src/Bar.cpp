#include "Bar.h"

namespace neulii{

    Bar::Bar(float x,float y, float width, float height, float range){

        rect.setPosition(x,y);
        this->width = width;
        this->height = height;

        rect.setSize(sf::Vector2f(width,height));
        //rect.setOutlineColor(sf::Color::Red);
        //rect.setOutlineThickness(2);
        rect.setFillColor(sf::Color::Blue);

        this->range = range;
    }

    void Bar::setValue(int value){
        this->value = value;
        this->height_value = height/range * value;

        rect.setSize(sf::Vector2f(width,-height_value));
    }

    int Bar::getValue(){
        return this->value;
    }

    void Bar::update(long dT){
    }

    void Bar::render(sf::RenderWindow& window){
        window.draw(rect);
    }
}