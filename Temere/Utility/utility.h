#ifndef TEMERE_UTILITY_UTILITY_H
#define TEMERE_UTILITY_UTILITY_H

#include "macro.h"

namespace Temere
{
	namespace Utility
	{
		class Utility
		{
		public:
			TEMERE_DYNAMIC_LIBRARY_PREFIX Utility();
			TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~Utility();
			TEMERE_DYNAMIC_LIBRARY_PREFIX void print();

		private:
			TEMERE_DYNAMIC_LIBRARY_PREFIX Utility(const Utility& ref);
			TEMERE_DYNAMIC_LIBRARY_PREFIX const Utility& operator=(const Utility& ref);
		};
	}
}

#endif