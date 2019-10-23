#include "ActionTile.h"
#include <iostream>


namespace neulii
{

    ActionTile::ActionTile(sf::Texture& tex, float x, float y, float width, float height)
    : ClickableHooverableRectShape(x,y,width,height)
    {
    	hooveredTile = nullptr;

        this->tile = new Tile(tex);
		tile->setPosition(x, y);

    }

	void ActionTile::setHooveredTile(Tile& tile)
	{
		this->hooveredTile = &tile;
		hooveredTile->setPosition(this->tile->getPosition().x,this->tile->getPosition().y);
		
		neulii::vector2ToConsole(hooveredTile->getPosition());
		 
	}

    void ActionTile::render(sf::RenderWindow& window)
    {

        ClickableHooverableRectShape::render(window);
		if (checkIfHoovered()) 
		{
			if(hooveredTile)
				hooveredTile->render(window);
		}
		else
		{
			tile->render(window);

		}
        
    }

	void ActionTile::entering()
	{
		HooverableRectShape::entering();
	}

	void ActionTile::blendTile()
	{

	
	}

	void ActionTile::deBlendTile() {


	}

} //namespace neulii
