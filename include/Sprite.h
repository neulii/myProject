#ifndef SPRITE_H
#define SPRITE_H

#include "GameObject.h"

namespace neulii{

    class Sprite : public GameObject
    {

        public:

        void update(long dT);
        void render(sf::RenderWindow &window);
        





    };

} // namespace neulii

#endif // Sprite.h