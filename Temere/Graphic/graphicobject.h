#ifndef TEMERE_GRAPHIC_GRAPHICOBJECT_H
#define TEMERE_GRAPHIC_GRAPHICOBJECT_H

#include "..\\utility\\macro.h"
#include "..\\Scene\\sceneobject.h"
#include "graphicmanager.h"
#include "bufferresource.h"

using namespace Temere::Scene;

namespace Temere
{
	namespace Graphic
	{
		class GraphicObject : public SceneObject 
		{
			public:
				TEMERE_DYNAMIC_LIBRARY_PREFIX GraphicObject(std::vector<Vertex*> vertices, std::vector<GLuint> indices, std::string fileName);
				TEMERE_DYNAMIC_LIBRARY_PREFIX GraphicObject(const GraphicObject& ref);
				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~GraphicObject();
				TEMERE_DYNAMIC_LIBRARY_PREFIX const GraphicObject& operator=(const GraphicObject& ref);

				TEMERE_DYNAMIC_LIBRARY_PREFIX bool loadShaders(std::string vertexShader_path, std::string fragmentShader_path);
				TEMERE_DYNAMIC_LIBRARY_PREFIX bool loadTexture(std::string texturePath);

				TEMERE_DYNAMIC_LIBRARY_PREFIX void Draw(const glm::mat4 &projMatrix, const glm::mat4 &viewMatrix);

			protected:
				Shader *mpShader;
				Texture *mpTexture;
				BufferResource *mBufferResource;
				TEMERE_DYNAMIC_LIBRARY_PREFIX GraphicObject();
		};
	}
}
#endif