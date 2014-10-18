#ifndef TEMERE_GRAPHIC_SPRITEOBJECT_H
#define TEMERE_GRAPHIC_SPRITEOBJECT_H

#include "graphicobject.h"

namespace Temere
{
	namespace Graphic
	{
		class SpriteObject : public GraphicObject
		{
			public:
				TEMERE_DYNAMIC_LIBRARY_PREFIX SpriteObject();
				TEMERE_DYNAMIC_LIBRARY_PREFIX SpriteObject(const SpriteObject& ref);
				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~SpriteObject();
				TEMERE_DYNAMIC_LIBRARY_PREFIX const SpriteObject& operator=(const SpriteObject& ref);
			private:		

		};
	}
}

#endif