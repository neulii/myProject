#include "Tile.h"

namespace neulii
{
    Tile::Tile(sf::Texture& tex)
    {
        texture = tex;
        rectangle.height = tex.getSize().y;
        rectangle.width = tex.getSize().x;

        sprite.setTexture(tex);
    }

    void Tile::setPosition(float x, float y)
    {
        sprite.setPosition(x,y);

    }

	sf::Vector2f Tile::getPosition()
	{
		return sprite.getPosition();
	}

    void Tile::update(long dT)
    {
        
    }

    void Tile::render(sf::RenderWindow &window)
    {
        window.draw(sprite);
    }
}