#include "object.h"

using namespace Temere::Utility;

Object::Object()
{
}

Object::Object(const Object& ref)
{
	TEMERE_UREF(ref)
}

Object::~Object()
{
}

const Object& Object::operator=(const Object& ref)
{
	TEMERE_UREF(ref)
	return *this;
}

void Object::update()
{
}