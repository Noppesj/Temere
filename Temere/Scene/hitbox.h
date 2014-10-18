#ifndef TEMERE_SCENE_HITBOX_H
#define TEMERE_SCENE_HITBOX_H

#include "..\\Utility\macro.h"
#include "transformobject.h"

namespace Temere
{
	namespace Scene
	{
		class HitBox : public TransformObject
		{
			public:
				TEMERE_DYNAMIC_LIBRARY_PREFIX HitBox();
				TEMERE_DYNAMIC_LIBRARY_PREFIX HitBox(const HitBox& ref);
				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~HitBox();
				TEMERE_DYNAMIC_LIBRARY_PREFIX const HitBox& operator=(const HitBox& ref);
			private:

		};
	}
}
#endif