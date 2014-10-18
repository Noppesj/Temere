#ifndef TEMERE_UTILITY_TIMER_H
#define TEMERE_UTILITY_TIMER_H

#include "macro.h"

namespace Temere
{
	namespace Utility
	{
		class Timer
		{
		public:
			TEMERE_DYNAMIC_LIBRARY_PREFIX Timer();
			TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~Timer();

			TEMERE_DYNAMIC_LIBRARY_PREFIX double getElapsedTime();

		private:
			TEMERE_DYNAMIC_LIBRARY_PREFIX Timer(const Timer& ref);
			TEMERE_DYNAMIC_LIBRARY_PREFIX const Timer& operator=(const Timer& ref);

			#ifdef TEMERE_OS_WIN
			long long int mFrequency;
			long long int mStartCount;
			long long int mEndCount;
			double mTicksPerUnit;
			#endif

		};
	}
}

#endif