#include "spriteanimation.h"

using namespace Temere::Graphic;


SpriteAnimation::SpriteAnimation(int rowNum, int colNum) : SpriteObject()
{
	mRowNum = rowNum;
	mColNum = colNum;
	glBindVertexArray(mBufferResource->getVertexArrayObject());
}
// SpriteAnimation();
SpriteAnimation::SpriteAnimation(const SpriteAnimation& ref) : SpriteObject(ref)
{

}

SpriteAnimation::~SpriteAnimation()
{

}

const SpriteAnimation& SpriteAnimation::operator=(const SpriteAnimation& ref)
{
	if(this != &ref)
	{
		SpriteObject::operator=(ref);
	}
	return *this;
}

void SpriteAnimation::changeSprite(const int spriteIndex)
{
	float s = (float)(spriteIndex % mColNum) / (float)mColNum;
	float t = (float)1-(spriteIndex / mRowNum) / (float)mRowNum;
	int st_offsetLocation = glGetUniformLocation(mpShader->getShaderId(), "st_offset");
	int rowsLocation = glGetUniformLocation(mpShader->getShaderId(), "rowNums");
	int colsLocation = glGetUniformLocation(mpShader->getShaderId(), "colNums");
	mpShader->setSpriteUV(s, t, st_offsetLocation, (float)mRowNum, (float)mColNum, rowsLocation, colsLocation);
}

void SpriteAnimation::Draw(const glm::mat4 &projMatrix, const glm::mat4 &viewMatrix, const int spriteIndex)
{
	GraphicManager::getInstance()->UseShader(mpShader);
	int projectionMatrixLocation = glGetUniformLocation(mpShader->getShaderId(), "projectionMatrix"); // Get the location of our projection matrix in the shader
	int viewMatrixLocation = glGetUniformLocation(mpShader->getShaderId(), "viewMatrix"); // Get the location of our view matrix in the shader
	int modelMatrixLocation = glGetUniformLocation(mpShader->getShaderId(), "modelMatrix"); // Get the location of our model matrix in the shader

	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &projMatrix[0][0]); // Send our projection matrix to the shader
	glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]); // Send our view matrix to the shader
	glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &getModelMatrix()[0][0]); // Send our model matrix to the shader

	GraphicManager::getInstance()->UseTexture(mpTexture);
	changeSprite(spriteIndex);
	glBindVertexArray(mBufferResource->getVertexArrayObject());
	glDrawElementsBaseVertex(GL_TRIANGLES, mBufferResource->getNumIndices(), GL_UNSIGNED_INT, 0, 0);
	glBindVertexArray(0);
}
