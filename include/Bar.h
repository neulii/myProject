#ifndef BAR_H
#define BAR_H

#include "GameObject.h"

namespace neulii{


    class Bar : public GameObject {

    private:

        float x;
        float y;

        float width; 
        float height;

        float value;
        float range;

        float height_value;

        sf::RectangleShape rect;

    public:

        Bar(float x,float y, float width, float height, float range);
        
        void setValue(int value);
        int getValue();

        void update(long dT);
        void render(sf::RenderWindow& window);

        sf::Vector2f getPosition();
        
        void setWidth(float width);
        ~Bar(){}
    };
    

}
#endif