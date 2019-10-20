#ifndef TILE_H
#define TILE_H

#include "GameObject.h"

namespace neulii{

    class Tile : public GameObject
    {

        public:

        void update(long dT);
        void render(sf::RenderWindow &window);






    };

} // namespace neulii

#endif // Tile.h