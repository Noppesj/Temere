#include "rect.h"

using namespace Temere::Scene;

Rect::Rect(glm::vec3& position, glm::vec3& bottomRight) : HitBox(), mBottomRight(bottomRight)
{
	mPosition = position;
}

Rect::Rect(float x, float y, float bottom, float right) : HitBox()
{
	mPosition.x = x;
	mPosition.y = y;
	mPosition.z = 0.0f;

	mBottomRight.y = bottom;
	mBottomRight.x = right;
	mBottomRight.z = 0.0f;
}

Rect::Rect() : HitBox()
{

}

Rect::Rect(const Rect& ref) : HitBox(ref)
{
	TEMERE_UREF(ref)
}

Rect::~Rect()
{
}

const Rect& Rect::operator=(const Rect& ref)
{
	if(this != &ref)
	{
		HitBox::operator=(ref);
	}
	return *this;
}

glm::vec3 Rect::getTopRight()
{
	return glm::vec3(mBottomRight.x, mPosition.y, 0.0f);
}

glm::vec3 Rect::getBottomLeft()
{
	return glm::vec3(mPosition.x, mBottomRight.y, 0.0f);
}

glm::vec3 Rect::getBottomRight()
{
	return mBottomRight;
}

float Rect::getWidth()
{
	return (mBottomRight.x - mPosition.x);
}

float Rect::getHeight()
{
	return (mBottomRight.y - mPosition.y);
}

bool Rect::contains(glm::vec2 point)
{
	return (mPosition.x <= point.x && mBottomRight.x >= point.x &&
            mPosition.y <= point.y && mBottomRight.y >= point.y);
}

bool Rect::intersect(Rect rect)
{
	return (!( mBottomRight.y < rect.getPosition().y||
		mPosition.y > rect.getBottomRight().y ||
		mBottomRight.x < rect.getPosition().x ||
		mPosition.x > rect.getBottomRight().x ));
}