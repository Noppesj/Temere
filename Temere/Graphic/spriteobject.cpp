#include "spriteobject.h"

using namespace Temere::Graphic;

SpriteObject::SpriteObject() : GraphicObject()
{
	mBufferResource = GraphicManager::getInstance()->getBufferResource("SpriteObject");
	if(mBufferResource == nullptr)
	{
		std::vector<Vertex*> mVertex;
		/*mVertex.push_back(new Vertex(glm::vec3(0, 0, 0), glm::vec2(1, 1), glm::vec3(0, 0, 0)));
		mVertex.push_back(new Vertex(glm::vec3(1.0, 0, 0), glm::vec2(0, 1), glm::vec3(0, 0, 0)));
		mVertex.push_back(new Vertex(glm::vec3(0, 1.0, 0), glm::vec2(1, 0), glm::vec3(0, 0, 0)));
		mVertex.push_back(new Vertex(glm::vec3(1.0, 1.0, 0), glm::vec2(0, 0), glm::vec3(0, 0, 0)));*/

		mVertex.push_back(TEMERE_NEW Vertex(glm::vec3(1, 1, 0), glm::vec2(0, 0), glm::vec3(0, 0, 0)));
		mVertex.push_back(TEMERE_NEW Vertex(glm::vec3(-1, 1, 0), glm::vec2(1, 0), glm::vec3(0, 0, 0)));
		mVertex.push_back(TEMERE_NEW Vertex(glm::vec3(1, -1, 0), glm::vec2(0, 1), glm::vec3(0, 0, 0)));
		mVertex.push_back(TEMERE_NEW Vertex(glm::vec3(-1, -1, 0), glm::vec2(1, 1), glm::vec3(0, 0, 0)));

		std::vector<GLuint> mIndices;
		mIndices.push_back(0);
		mIndices.push_back(1);
		mIndices.push_back(2);
		mIndices.push_back(2);
		mIndices.push_back(1);
		mIndices.push_back(3);

		mBufferResource = GraphicManager::getInstance()->loadBufferResource(mVertex, mIndices, "SpriteObject");

		for(unsigned int i = 0; i < mVertex.size(); i++)
		{
			TEMERE_SAFE_DELETE(mVertex[i])
		}
		mVertex.clear();
	}
}

SpriteObject::SpriteObject(const SpriteObject& ref) :  GraphicObject(ref)
{

}

SpriteObject::~SpriteObject()
{

}

const SpriteObject& SpriteObject::operator=(const SpriteObject& ref)
{
	if(this != &ref)
	{
		GraphicObject::operator=(ref);
	}
	return *this;
}
