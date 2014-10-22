#include "texture.h"
#include "stb_image.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "easylogging++.h"


using namespace Temere::Graphic;

Texture::Texture()
{
	mTextureID = 0;
}

Texture::Texture(const Texture& ref)
{
	mTextureID = ref.mTextureID;
}

Texture::~Texture()
{

}
const Texture& Texture::operator=(const Texture& ref)
{
	TEMERE_UREF(ref);
	return *this;
}

bool Texture::loadTexture(const std::string& textureFile)
{
	if (textureFile.find(".png") != std::string::npos)
	{
		int width, height, numComponents;
		unsigned char* data = stbi_load((textureFile).c_str(), &width, &height, &numComponents, 4);

		if (data == NULL)
		{
			LOG(ERROR) << "Could not load texture: " << textureFile << std::endl;
			return false;
		}

		glGenTextures(1, &mTextureID);
		bindTexture();

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		stbi_image_free(data);

		LOG(INFO) << "Loaded texture: " << textureFile << std::endl;
		return true;
	}
	else
	{
		return loadDDS(textureFile.c_str());
	}
}


bool Texture::loadDDS(const char* imagepath)
{
	const unsigned long FOURCC_DXT1 = 0x31545844; //(MAKEFOURCC('D','X','T','1'))
	const unsigned long FOURCC_DXT3 = 0x33545844; //(MAKEFOURCC('D','X','T','3'))
	const unsigned long FOURCC_DXT5 = 0x35545844; //(MAKEFOURCC('D','X','T','5'))
	unsigned char header[124];
	FILE *pFile = NULL;

	fopen_s(&pFile, imagepath, "rb");

	if (pFile == NULL)
	{
		return false;
	}

	char fileCode[4];
	fread(fileCode, 1, 4, pFile);

	if (strncmp(fileCode, "DDS ", 4) != 0)
	{
		fclose(pFile);
		return false;
	}

	fread(&header, 124, 1, pFile);

	unsigned int height = *(unsigned int*)&(header[8]);
	unsigned int width = *(unsigned int*)&(header[12]);
	unsigned int linearSize = *(unsigned int*)&(header[16]);
	unsigned int mipMapCount = *(unsigned int*)&(header[24]);
	unsigned int fourCC = *(unsigned int*)&(header[80]);
	unsigned char * buffer;
	unsigned int bufsize;	bufsize = mipMapCount > 1 ? linearSize * 2 : linearSize;
	buffer = (unsigned char*)malloc(bufsize * sizeof(unsigned char));
	fread(buffer, 1, bufsize, pFile);
	fclose(pFile);

	unsigned int components = (fourCC == FOURCC_DXT1) ? 3 : 4;
	unsigned int format;
	switch (fourCC)
	{
	case FOURCC_DXT1:
		format = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
		break;
	case FOURCC_DXT3:
		format = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
		break;
	case FOURCC_DXT5:
		format = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
		break;
	default:
		free(buffer);
		return 0;
	}

	glGenTextures(1, &mTextureID);

	glBindTexture(GL_TEXTURE_2D, mTextureID);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	unsigned int blockSize = (format == GL_COMPRESSED_RGBA_S3TC_DXT1_EXT) ? 8 : 16;
	unsigned int offset = 0;

	for (unsigned int level = 0; level < mipMapCount && (width || height); ++level)
	{
		unsigned int size = ((width + 3) / 4)*((height + 3) / 4)*blockSize;
		glCompressedTexImage2D(GL_TEXTURE_2D, level, format, width, height,
			0, size, buffer + offset);

		offset += size;
		width /= 2;
		height /= 2;
	}

	free(buffer);
	LOG(INFO) << "Loaded texture: " << imagepath << std::endl;
	return true;
}


void Texture::bindTexture()
{
	glBindTexture(GL_TEXTURE_2D, mTextureID);
}

void Texture::unbindTexture()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

GLuint Texture::getTextureID()
{
	return mTextureID;
}


