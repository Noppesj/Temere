#include "hitbox.h"

using namespace Temere::Scene;

HitBox::HitBox() : TransformObject()
{

}

HitBox::HitBox(const HitBox& ref) : TransformObject(ref)
{
	TEMERE_UREF(ref)
}

HitBox::~HitBox()
{
}

const HitBox& HitBox::operator=(const HitBox& ref)
{
	if(this != &ref)
	{
		TransformObject::operator=(ref);
	}
	return *this;
}