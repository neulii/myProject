#ifndef TILE_H
#define TILE_H

#include "GameObject.h"

namespace neulii{

    class Tile : public GameObject
    {
    
    private:

        float x;
        float y;

        sf::Texture texture;
        sf::IntRect rectangle;
        sf::Sprite sprite;

    public:

        Tile(sf::Texture& tex);

        void setPosition(float x, float y);
        
        void update(long dT);
        void render(sf::RenderWindow &window);
    };

} // namespace neulii

#endif // Tile.h