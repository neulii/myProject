#include "ActionTile.h"


namespace neulii
{

    ActionTile::ActionTile(sf::Texture& tex, float x, float y, float width, float height)
    : ClickableHooverableRectShape(x,y,width,height)
    {
        this->tile = new Tile(tex);

        

    }

    void ActionTile::render(sf::RenderWindow& window)
    {
        ClickableHooverableRectShape::render(window);
        log("test");


    }

} //namespace neulii