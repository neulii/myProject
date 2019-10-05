#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SFML/Graphics.hpp"

namespace neulii
{
    class GameObject
    {
        public:
            virtual void update(long dT) = 0;
            virtual void render(sf::RenderWindow &window) = 0;
    };
}
#endif