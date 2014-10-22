#include "graphicmanager.h"

using namespace Temere::Graphic;
using namespace Temere::Utility;

std::atomic<GraphicManager*> GraphicManager::mpInstance = 0;
SingletonDestroyer<GraphicManager> GraphicManager::mDestroyer;
std::mutex GraphicManager::mThreadLock;

GraphicManager* GraphicManager::getInstance()
{
	mThreadLock.lock();
	if(!(GraphicManager*)mpInstance)
	{
		mpInstance = TEMERE_NEW GraphicManager();
		mDestroyer.setSingleton(mpInstance);
	}
	mThreadLock.unlock();
	return mpInstance;
}

Shader* GraphicManager::loadShader(const std::string &vertexShader, const std::string &fragmentShader)
{
	std::string key = vertexShader;
	key += fragmentShader;

	if(mShaderMap.count(key) == 0) 
	{
		Shader *shader = TEMERE_NEW Shader();
		shader->loadShader(CSHADER_PATH + vertexShader, CSHADER_PATH + fragmentShader);
		mShaderMap.emplace(key, shader);
		return shader;		
	}
	else
	{
		return mShaderMap[key];	
	}
}

Texture* GraphicManager::loadTexture(const std::string &textureFile)
{
	std::string key = textureFile;

	if(mTextureMap.count(key) == 0) 
	{
		Texture *texture = TEMERE_NEW Texture();
		if( texture->loadTexture(CTEXTURE_PATH + textureFile) )
			mTextureMap.emplace(key, texture);
		return texture;		
	}
	else
	{
		return mTextureMap[key];	
	}
}

BufferResource* GraphicManager::loadBufferResource(const std::vector<Vertex*> &vertices, const std::vector<GLuint> &indices, const std::string& fileName)
{
	std::string key = fileName;

	if(mBufferResourceMap.count(key) == 0) 
	{
		BufferResource *bufferResource = TEMERE_NEW BufferResource(vertices, indices, fileName);
		mBufferResourceMap.emplace(key, bufferResource);
		return bufferResource;		
	}
	else
	{
		return mBufferResourceMap[key];	
	}	
}

BufferResource* GraphicManager::loadBufferResource(const std::vector<Vertex*> &vertices, const std::string& fileName)
{
	std::string key = fileName;

	if (mBufferResourceMap.count(key) == 0)
	{
		BufferResource *bufferResource = TEMERE_NEW BufferResource(vertices, fileName);
		mBufferResourceMap.emplace(key, bufferResource);
		return bufferResource;
	}
	else
	{
		return mBufferResourceMap[key];
	}
}

BufferResource* GraphicManager::getBufferResource(const std::string& fileName)
{
	if(mBufferResourceMap.count(fileName) == 0) 
	{
		return nullptr;
	}
	else
	{
		return mBufferResourceMap[fileName];
	}
}

GraphicManager::GraphicManager()
{
	mShaderInUse = nullptr;
	mTextureInUse = nullptr;
}

GraphicManager::~GraphicManager()
{
}

void GraphicManager::ClearResources()
{
	if(!mShaderMap.empty())
	{
		for(std::unordered_map<std::string, Shader*>::iterator iter = mShaderMap.begin(); iter != mShaderMap.end(); ++iter)
		{
			TEMERE_SAFE_DELETE (iter->second)
		}
		mShaderMap.clear();
	}

	if(!mTextureMap.empty())
	{
		for(std::unordered_map<std::string, Texture*>::iterator iter = mTextureMap.begin(); iter != mTextureMap.end(); ++iter)
		{
			TEMERE_SAFE_DELETE(iter->second)
		}
		mTextureMap.clear();
	}

	if(!mBufferResourceMap.empty())
	{
		for(std::unordered_map<std::string, BufferResource*>::iterator iter = mBufferResourceMap.begin(); iter != mBufferResourceMap.end(); ++iter)
		{
			TEMERE_SAFE_DELETE(iter->second)
		}
		mBufferResourceMap.clear();
	}
}

GraphicManager::GraphicManager(const GraphicManager& ref)
{
	TEMERE_UREF(ref)
}

const GraphicManager& GraphicManager::operator=(const GraphicManager& ref)
{
	TEMERE_UREF(ref)
		return *this;
}

void GraphicManager::UseShader(Shader* shader)
{
	if(mShaderInUse == nullptr)
	{
		mShaderInUse = shader;
		mShaderInUse->bindShader();
	}
	else if(mShaderInUse != shader)
	{
		mShaderInUse->unbindShader();
		mShaderInUse = shader;
		mShaderInUse->bindShader();
	}
}

void GraphicManager::UseTexture(Texture* texture)
{
	if(mTextureInUse == nullptr)
	{
		mTextureInUse = texture;
		mTextureInUse->bindTexture();
	}
	else if(mTextureInUse != texture)
	{
		mTextureInUse->unbindTexture();
		mTextureInUse = texture;
		mTextureInUse->bindTexture();
	}
}