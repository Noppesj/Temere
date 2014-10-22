#include "transformobject.h"
#include "GLM\gtx\transform.hpp"

using namespace Temere::Scene;
using namespace Temere::Utility;

TransformObject::TransformObject() : Object(),
	mPosition(0.0f, 0.0f, 0.0f), mRotate(0.0f, 0.0f, 0.0f), mScale(0.0f, 0.0f, 0.0f),
	mTranslateMatrix(), mRotateMatrix(), mScaleMatrix(), mTransformMatrix()
{
	mTransformMatrix = glm::mat4();
}

TransformObject::TransformObject(const TransformObject& ref) : Object(ref),
	mPosition(ref.mPosition), mRotate(ref.mRotate), mScale(ref.mScale),
	mTranslateMatrix(ref.mTranslateMatrix), mRotateMatrix(ref.mRotateMatrix), mScaleMatrix(ref.mScaleMatrix), mTransformMatrix(ref.mTransformMatrix)
{
}

TransformObject::~TransformObject()
{
}

const TransformObject& TransformObject::operator=(const TransformObject& ref)
{
	if (this != &ref)
	{
		Object::operator=(ref);
		mPosition = ref.mPosition;
		mRotate = ref.mRotate;
		mScale = ref.mScale;
		mTranslateMatrix = ref.mTranslateMatrix;
		mRotateMatrix = ref.mRotateMatrix;
		mScaleMatrix = ref.mScaleMatrix;
		mTransformMatrix = ref.mTransformMatrix;
	}
	return *this;
}

void TransformObject::update()
{
	calculateTranslateMatrix();
	calculateRotateMatrix();
	calculateScaleMatrix();
	calculateTransformMatrix();
}

void TransformObject::calculateTranslateMatrix()
{
	if (mbCalculateTranslationRequired)
	{
		mbCalculateTransformRequired = true;
	}
}

void TransformObject::calculateRotateMatrix()
{
	if (mbCalculateRotationRequired)
	{
		mbCalculateTransformRequired = true;
	}
}

void TransformObject::calculateScaleMatrix()
{
	if (mbCalculateScaleRequired)
	{
		mbCalculateTransformRequired = true;
	}
}

void TransformObject::calculateTransformMatrix()
{
	if (mbCalculateTransformRequired)
	{
		mTransformMatrix = mScaleMatrix * mRotateMatrix * mTranslateMatrix;
	}
}

glm::mat4& TransformObject::getModelMatrix()
{
	glm::mat4 posMat = glm::translate(mPosition);
	glm::mat4 scaleMat = glm::scale(mScale);
	glm::mat4 rotX = glm::rotate(mRotate.x, glm::vec3(1.0, 0.0, 0.0));
	glm::mat4 rotY = glm::rotate(mRotate.y, glm::vec3(0.0, 1.0, 0.0));
	glm::mat4 rotZ = glm::rotate(mRotate.z, glm::vec3(0.0, 0.0, 1.0));
	glm::mat4 rotMat = rotX * rotY * rotZ;
	mModelMatrix = (posMat * rotMat * scaleMat);
	return mModelMatrix;
}
