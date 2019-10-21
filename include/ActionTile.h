#ifndef ACTIONTILE_H
#define ACTIONTILE_H

#include "Tile.h"
#include "ClickableHooverableRectShape.h"

namespace neulii{

    class ActionTile : public ClickableHooverableRectShape 
    {
    private:
        Tile* tile;
		Tile* hooveredTile;

    public:

        ActionTile(sf::Texture& tex, float x, float y, float width, float height);
        void render(sf::RenderWindow& window) override;
    
		void setHooveredTile(Tile& tile);

		void entering() override;
		void blendTile();
		void deBlendTile();	
	};
    
} // namespace neulii
#endif