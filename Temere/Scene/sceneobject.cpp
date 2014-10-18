#include "sceneobject.h"

using namespace Temere::Scene;

SceneObject::SceneObject() : TransformObject()
{
	miId = 0;
}

SceneObject::SceneObject(const SceneObject& ref) : TransformObject(ref)
{
	TEMERE_UREF(ref)
}

SceneObject::~SceneObject()
{
}

const SceneObject& SceneObject::operator=(const SceneObject& ref)
{
	if(this != &ref)
	{
		TransformObject::operator=(ref);
	}
	return *this;
}

void SceneObject::update(float deltaTime)
{
	if( mbCalculateTranslationRequired ||
		mbCalculateRotationRequired ||
		mbCalculateScaleRequired ||
		mbCalculateTransformRequired)
	{
		mHitBox->setPosition(mPosition);	
	}

	(void)deltaTime;
}