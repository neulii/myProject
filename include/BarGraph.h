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

            float width;
            float height;

            float barWidth;
    

        public:
            BarGraph(float width, float height);

            void render(sf::RenderWindow& window);
            void update(long dT);

            void addBar(float value);
            

    };


}
#endif