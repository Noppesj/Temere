#ifndef TEMERE_GRAPHIC_VERTEX_H
#define TEMERE_GRAPHIC_VERTEX_H

#include "..\\Utility\macro.h"
#include "GLM\glm.hpp"

namespace Temere
{
	namespace Graphic
	{
		class Vertex
		{
			public:
				TEMERE_DYNAMIC_LIBRARY_PREFIX Vertex();
				TEMERE_DYNAMIC_LIBRARY_PREFIX Vertex(const glm::vec3& pos, const glm::vec2& textCoord, const glm::vec3& normal);
				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~Vertex();
				TEMERE_DYNAMIC_LIBRARY_PREFIX Vertex(const Vertex& ref);
				TEMERE_DYNAMIC_LIBRARY_PREFIX const Vertex& operator=(const Vertex& ref);
				
				TEMERE_DYNAMIC_LIBRARY_PREFIX inline const glm::vec3& GetPos() { return mPos; }
				TEMERE_DYNAMIC_LIBRARY_PREFIX inline const glm::vec2& GetTexCoord() { return mTexCoord; }
				TEMERE_DYNAMIC_LIBRARY_PREFIX inline const glm::vec3& GetNormal() { return mNormal; }
			private:
				glm::vec3 mPos;
				glm::vec2 mTexCoord;
				glm::vec3 mNormal;
		};
	}
}
#endif