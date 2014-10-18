#include "texture.h"
#include "stb_image.h"
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

bool Texture::loadTexture(const std::string textureFile)
{
	int width, height, numComponents;
	unsigned char* data = stbi_load((textureFile).c_str(), &width, &height, &numComponents, 4);
	
	if(data == NULL)
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


