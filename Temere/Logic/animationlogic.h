#ifndef TEMERE_LOGIC_ANIMATIONLOGIC_H
#define TEMERE_LOGIC_ANIMATIONLOGIC_H

#include "..\\Utility\\macro.h"

namespace Temere
{
	namespace Logic
	{
		class AnimationLogic
		{
			public:
				TEMERE_DYNAMIC_LIBRARY_PREFIX AnimationLogic();
				TEMERE_DYNAMIC_LIBRARY_PREFIX AnimationLogic(unsigned int startIndex, unsigned int endIndex);
				TEMERE_DYNAMIC_LIBRARY_PREFIX ~AnimationLogic();

				TEMERE_DYNAMIC_LIBRARY_PREFIX unsigned int getNextIndex();
				TEMERE_DYNAMIC_LIBRARY_PREFIX unsigned int getPrevIndex();
				TEMERE_DYNAMIC_LIBRARY_PREFIX void reset();

				TEMERE_DYNAMIC_LIBRARY_PREFIX unsigned int getStartIndex();
			private:
				unsigned int mStartIndex;
				unsigned int mEndIndex;
				unsigned int mCurrentIndex;
		};
	}
}
#endif