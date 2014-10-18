#include "vertex.h"

using namespace Temere::Graphic;

Vertex::Vertex()
{
	mPos = glm::vec3(0.0f, 0.0f, 0.0f);
	mTexCoord = glm::vec2(0.0f, 0.0f);
	mNormal = glm::vec3(0.0f, 0.0f, 0.0f);
}

Vertex::Vertex(const glm::vec3& pos, const glm::vec2& textCoord, const glm::vec3& normal)
{
	mPos = pos;
	mTexCoord = textCoord;
	mNormal = normal;
}

Vertex::~Vertex()
{
	
}

Vertex::Vertex(const Vertex& ref)
{
	TEMERE_UREF(ref)
}
const Vertex& Vertex::operator=(const Vertex& ref)
{	
	TEMERE_UREF(ref)
	return *this;
}