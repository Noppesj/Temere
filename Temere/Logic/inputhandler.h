#ifndef TEMERE_LOGIC_INPUTHANDLER_H
#define TEMERE_LOGIC_INPUTHANDLER_H

#include "..\\Utility\macro.h"

namespace Temere
{
	namespace Logic
	{
		class InputHandler
		{
			public:
				TEMERE_DYNAMIC_LIBRARY_PREFIX InputHandler();
				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~InputHandler();

				TEMERE_DYNAMIC_LIBRARY_PREFIX void pollEvents();
			private:
				int mMoveLeft;
				int mMoveRight;
				int mMoveUp;
				int mMoveDown;

				int mHotBar1;
				int mHotBar2;
				int mHotBar3;
				int mHotBar4;
				int mHotBar5;
				int mHotBar6;
		};
	}
}
#endif