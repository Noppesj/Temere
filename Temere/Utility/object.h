#ifndef TEMERE_UTILITY_OBJECT_H
#define TEMERE_UTILITY_OBJECT_H

#include "macro.h"

namespace Temere
{
	namespace Utility
	{
		class Object
		{
			public:
				TEMERE_DYNAMIC_LIBRARY_PREFIX Object();
				TEMERE_DYNAMIC_LIBRARY_PREFIX Object(const Object& ref);
				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~Object() = 0;
				TEMERE_DYNAMIC_LIBRARY_PREFIX const Object& operator=(const Object& ref);

				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual void update();
		};
	}
}

#endif