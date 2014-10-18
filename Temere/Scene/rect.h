#ifndef TEMERE_SCENE_RECT_H
#define TEMERE_SCENE_RECT_H

#include "..\\Utility\macro.h"
#include "hitbox.h"

#include "GLM\glm.hpp"

namespace Temere
{
	namespace Scene
	{
		class Rect : public HitBox
		{
			public:
				TEMERE_DYNAMIC_LIBRARY_PREFIX Rect(glm::vec3& position, glm::vec3& bottomRight);
				TEMERE_DYNAMIC_LIBRARY_PREFIX Rect(float x, float y, float bottom, float right);
				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~Rect();
				TEMERE_DYNAMIC_LIBRARY_PREFIX const Rect& operator=(const Rect& ref);

				TEMERE_DYNAMIC_LIBRARY_PREFIX glm::vec3 getTopRight();
				TEMERE_DYNAMIC_LIBRARY_PREFIX glm::vec3 getBottomLeft();
				TEMERE_DYNAMIC_LIBRARY_PREFIX glm::vec3 getBottomRight();

				TEMERE_DYNAMIC_LIBRARY_PREFIX float getWidth();
				TEMERE_DYNAMIC_LIBRARY_PREFIX float getHeight();

				TEMERE_DYNAMIC_LIBRARY_PREFIX bool contains(glm::vec2 point);
				TEMERE_DYNAMIC_LIBRARY_PREFIX bool intersect(Rect rect);

			private:
				glm::vec3 mBottomRight;

				TEMERE_DYNAMIC_LIBRARY_PREFIX Rect();
				TEMERE_DYNAMIC_LIBRARY_PREFIX Rect(const Rect& ref);
		};
	}
}
#endif