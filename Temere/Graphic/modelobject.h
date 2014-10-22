#ifndef SV11_GRAPHIC_MODELOBJECT_H
#define SV11_GRAPHIC_MODELOBJECT_H


#include "graphicobject.h"

namespace Temere
{
	namespace Graphic
	{
		class ModelObject : public GraphicObject
		{
			public:
				TEMERE_DYNAMIC_LIBRARY_PREFIX ModelObject();
				TEMERE_DYNAMIC_LIBRARY_PREFIX ModelObject(const ModelObject& ref);
				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~ModelObject();
				TEMERE_DYNAMIC_LIBRARY_PREFIX const ModelObject& operator=(const ModelObject& ref);
				
				TEMERE_DYNAMIC_LIBRARY_PREFIX bool loadObj(const std::string& path);
				TEMERE_DYNAMIC_LIBRARY_PREFIX void Draw(const glm::mat4 &projMatrix, const glm::mat4 &viewMatrix);
			private:
				
				TEMERE_DYNAMIC_LIBRARY_PREFIX glm::vec3 splitVec3(char* line);
				TEMERE_DYNAMIC_LIBRARY_PREFIX glm::vec2 splitVec2(char* line);
		};
	}
}
#endif