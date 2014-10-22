#ifndef TEMERE_GRAPHIC_GRAPHICMANGER_H
#define TEMERE_GRAPHIC_GRAPHICMANGER_H

#include "..\\Utility\macro.h"
#include "..\\Utility\\singletondestroyer.h"
#include "shader.h"
#include "texture.h"
#include "bufferresource.h"
#include <atomic>
#include <mutex>
#include <unordered_map>
#include <string>

namespace Temere
{
	namespace Graphic
	{
		static std::string CSHADER_PATH = "..\\..\\Resources\\Shaders\\";
		static std::string CTEXTURE_PATH = "..\\..\\Resources\\Textures\\";
		class GraphicManager
		{
			public:
				TEMERE_DYNAMIC_LIBRARY_PREFIX static GraphicManager* getInstance();
				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~GraphicManager();

				TEMERE_DYNAMIC_LIBRARY_PREFIX Shader* loadShader(const std::string &vertexShader, const std::string &fragmentShader);
				TEMERE_DYNAMIC_LIBRARY_PREFIX Texture* loadTexture(const std::string &textureFile);
				TEMERE_DYNAMIC_LIBRARY_PREFIX BufferResource* loadBufferResource(const std::vector<Vertex*> &vertices, const std::vector<GLuint> &indices, const std::string& fileName);
				TEMERE_DYNAMIC_LIBRARY_PREFIX BufferResource* loadBufferResource(const std::vector<Vertex*> &vertices, const std::string& fileName);
				TEMERE_DYNAMIC_LIBRARY_PREFIX BufferResource* getBufferResource(const std::string& fileName);

				TEMERE_DYNAMIC_LIBRARY_PREFIX void ClearResources();
				TEMERE_DYNAMIC_LIBRARY_PREFIX void UseShader(Shader* shader);
				TEMERE_DYNAMIC_LIBRARY_PREFIX void UseTexture(Texture* texture);
			private:
				TEMERE_DYNAMIC_LIBRARY_PREFIX GraphicManager();
				TEMERE_DYNAMIC_LIBRARY_PREFIX GraphicManager(const GraphicManager& ref);
				TEMERE_DYNAMIC_LIBRARY_PREFIX const GraphicManager& operator=(const GraphicManager& ref);

				static std::atomic<GraphicManager*> mpInstance;
				static Temere::Utility::SingletonDestroyer<GraphicManager> mDestroyer;
				static std::mutex mThreadLock;

				std::unordered_map<std::string, Shader*> mShaderMap;
				std::unordered_map<std::string, Texture*> mTextureMap;
				std::unordered_map<std::string, BufferResource*> mBufferResourceMap;

				Shader * mShaderInUse;
				Texture * mTextureInUse;
		};
	}
}
#endif;