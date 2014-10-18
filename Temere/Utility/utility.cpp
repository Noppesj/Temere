#include "utility.h"
#include <iostream>

using namespace Temere::Utility;

Utility::Utility()
{
}

Utility::~Utility()
{
}

void Utility::print()
{
	std::cout << "DLL Test" << std::endl;
}

Utility::Utility(const Utility& ref)
{
	TEMERE_UREF(ref)
}

const Utility& Utility::operator=(const Utility& ref)
{
	TEMERE_UREF(ref)
	return *this;
}