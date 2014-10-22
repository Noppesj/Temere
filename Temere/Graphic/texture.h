#ifndef TEMERE_GRAPHIC_TEXTURE_H
#define TEMERE_GRAPHIC_TEXTURE_H

#include "..\\Utility\\macro.h"
#include <string>
#include <GL\glew.h>

namespace Temere
{
	namespace Graphic
	{
		class Texture
		{
			public:
				TEMERE_DYNAMIC_LIBRARY_PREFIX Texture();
				TEMERE_DYNAMIC_LIBRARY_PREFIX Texture(const Texture& ref);
				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~Texture();
				TEMERE_DYNAMIC_LIBRARY_PREFIX const Texture& operator=(const Texture& ref);

				TEMERE_DYNAMIC_LIBRARY_PREFIX void bindTexture();
				TEMERE_DYNAMIC_LIBRARY_PREFIX void unbindTexture();

				TEMERE_DYNAMIC_LIBRARY_PREFIX bool loadTexture(const std::string& textureFile);
				TEMERE_DYNAMIC_LIBRARY_PREFIX bool loadDDS(const char* imagepath);
				TEMERE_DYNAMIC_LIBRARY_PREFIX GLuint getTextureID();
			private:
				GLuint mTextureID;
		};
	}
}
#endif