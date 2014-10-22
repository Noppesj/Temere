#include "graphicobject.h"

using namespace Temere::Graphic;

GraphicObject::GraphicObject() : SceneObject()
{
	mpShader = nullptr;
	mpTexture = nullptr;
}

GraphicObject::GraphicObject(const std::vector<Vertex*> &vertices,const std::vector<GLuint>& indices, const std::string& fileName) : SceneObject()
{
	mpShader = nullptr;
	mpTexture = nullptr;
	mBufferResource = GraphicManager::getInstance()->loadBufferResource(vertices, indices, fileName);
}

GraphicObject::GraphicObject(const GraphicObject& ref) : SceneObject(ref)
{
	mBufferResource = ref.mBufferResource;
	mpShader = ref.mpShader;
	mpTexture = ref.mpTexture;
}
 
GraphicObject::~GraphicObject()
{
}
const GraphicObject& GraphicObject::operator=(const GraphicObject& ref)
{
	if(this != &ref)
	{
		SceneObject::operator=(ref);
		mBufferResource = ref.mBufferResource;
		mpShader = ref.mpShader;
		mpTexture = ref.mpTexture;
	}
	return *this;
}

bool GraphicObject::loadShaders(const std::string& vertexShader_path, const std::string& fragmentShader_path)
{
	mpShader = GraphicManager::getInstance()->loadShader(vertexShader_path, fragmentShader_path);
	
	return (mpShader != nullptr) ? true : false;  
}

bool GraphicObject::loadTexture(const std::string& texturePath)
{
	mpTexture = GraphicManager::getInstance()->loadTexture(texturePath);
	
	return (mpTexture != nullptr) ? true : false;
}

void GraphicObject::Draw(const glm::mat4 &projMatrix, const glm::mat4 &viewMatrix)
{
	GraphicManager::getInstance()->UseShader(mpShader);
	int projectionMatrixLocation = glGetUniformLocation(mpShader->getShaderId(), "projectionMatrix"); // Get the location of our projection matrix in the shader
	int viewMatrixLocation = glGetUniformLocation(mpShader->getShaderId(), "viewMatrix"); // Get the location of our view matrix in the shader
	int modelMatrixLocation = glGetUniformLocation(mpShader->getShaderId(), "modelMatrix"); // Get the location of our model matrix in the shader
	
	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &projMatrix[0][0]); // Send our projection matrix to the shader
	glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]); // Send our view matrix to the shader
	glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &getModelMatrix()[0][0]); // Send our model matrix to the shader
	
	GraphicManager::getInstance()->UseTexture(mpTexture);
	glBindVertexArray(mBufferResource->getVertexArrayObject());
	glDrawElementsBaseVertex(GL_TRIANGLES, mBufferResource->getNumIndices(), GL_UNSIGNED_INT, 0, 0);
	glBindVertexArray(0);
}
