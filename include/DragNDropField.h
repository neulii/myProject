#ifndef DRAGNDROPFIELD_H
#define DRAGNDROPFIELD_H

#include "ClickableHooverableRectShape.h"

namespace neulii {

	class DragNDropField :
		public neulii::ClickableHooverableRectShape
	{

	private:

		sf::Vector2i mouseOld = sf::Vector2i(0, 0);
		sf::Vector2i mouseNew = sf::Vector2i(0, 0);


	public:
		
		DragNDropField(float x, float y, float width, float height);
		void update(long dT);



	};



}




#endif
