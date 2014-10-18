#ifndef TEMERE_LOGIC_ACTOR_H
#define TEMERE_LOGIC_ACTOR_H

#include "..\\Utility\macro.h"

namespace Temere
{
	namespace Logic
	{
		class Actor
		{
			public:
				TEMERE_DYNAMIC_LIBRARY_PREFIX Actor();
				TEMERE_DYNAMIC_LIBRARY_PREFIX Actor(const Actor& ref);
				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~Actor();
				TEMERE_DYNAMIC_LIBRARY_PREFIX const Actor& operator=(const Actor& ref);
			private:
			protected:
		};
	}
}
#endif