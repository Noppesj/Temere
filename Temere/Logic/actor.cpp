#include "actor.h"

using namespace Temere::Logic;

Actor::Actor()
{

}

Actor::Actor(const Actor& ref)
{
	TEMERE_UREF(ref)
}

Actor::~Actor()
{
}

const Actor& Actor::operator=(const Actor& ref)
{
	TEMERE_UREF(ref)
	return *this;
}