#ifndef TEMERE_GRAPHIC_BUFFERRESOURCE_H
#define TEMERE_GRAPHIC_BUFFERRESOURCE_H

#include "..\\Utility\macro.h"
#include "GL\glew.h"
#include "vertex.h"
#include <vector>
#include <string>

namespace Temere
{
	namespace Graphic
	{
		
		enum BufferPositions
		{
			POSITION_VB,
			TEXCOORD_VB,
			NORMAL_VB,
			INDEX_VB
		};
		
		class BufferResource
		{
			public:
				TEMERE_DYNAMIC_LIBRARY_PREFIX BufferResource();
				TEMERE_DYNAMIC_LIBRARY_PREFIX BufferResource(const std::vector<Vertex*> &vertices, const std::vector<GLuint> &indices, const std::string &fileName);
				TEMERE_DYNAMIC_LIBRARY_PREFIX BufferResource(const std::vector<Vertex*> &vertices, const std::string &fileName);
				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~BufferResource();
				TEMERE_DYNAMIC_LIBRARY_PREFIX BufferResource(const BufferResource& ref);
				TEMERE_DYNAMIC_LIBRARY_PREFIX const BufferResource& operator=(const BufferResource& ref);

				TEMERE_DYNAMIC_LIBRARY_PREFIX const GLuint getVertexArrayObject(){return mVertexArrayObject;}
				TEMERE_DYNAMIC_LIBRARY_PREFIX const GLuint getNumIndices(){return mNumIndices;}
				TEMERE_DYNAMIC_LIBRARY_PREFIX const std::string getFileName(){return mFileName;}
			private:
				static const unsigned int NUM_BUFFERS = 3;
				GLuint mVertexArrayObject;
				GLuint mVertexBufferObject[NUM_BUFFERS];
				GLuint mNumIndices;
				std::string mFileName;

				TEMERE_DYNAMIC_LIBRARY_PREFIX void init(const std::vector<Vertex*> &vertices, const std::vector<GLuint> &indices);
				TEMERE_DYNAMIC_LIBRARY_PREFIX void init(const std::vector<Vertex*> &vertices);
		};
	}
}
#endif