#ifndef TEMERE_GRAPHIC_SHADER_H
#define TEMERE_GRAPHIC_SHADER_H

#include "..\\utility\\macro.h"
#include "GL\glew.h"
#include <iostream>

namespace Temere
{
	namespace Graphic
	{
		class Shader
		{
			public:
				TEMERE_DYNAMIC_LIBRARY_PREFIX Shader();
				TEMERE_DYNAMIC_LIBRARY_PREFIX Shader(const Shader& ref);
				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~Shader();
				TEMERE_DYNAMIC_LIBRARY_PREFIX const Shader& operator=(const Shader& ref);

				TEMERE_DYNAMIC_LIBRARY_PREFIX bool loadShader(std::string vertexShader_path, std::string fragmentShader_path);
				TEMERE_DYNAMIC_LIBRARY_PREFIX void bindShader();
				TEMERE_DYNAMIC_LIBRARY_PREFIX void unbindShader();

				TEMERE_DYNAMIC_LIBRARY_PREFIX inline int const getShaderId() const { return mShaderId; }

				TEMERE_DYNAMIC_LIBRARY_PREFIX void setSpriteUV(const GLfloat s, const GLfloat t, const GLint uvLocation, const GLfloat rowNums, const GLfloat colNums, const GLint rowLoc, const GLint colLoc);

				TEMERE_DYNAMIC_LIBRARY_PREFIX bool getInUse();

			private:
				GLint mShaderId;
				GLint mVertexShaderId;
				GLint mFragmentShaderId;
				bool  mInUse;
				bool mInit;
		};
	}
}
#endif