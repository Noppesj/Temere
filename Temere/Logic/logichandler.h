#ifndef TEMERE_LOGIC_LOGICHANDLER_H
#define TEMERE_LOGIC_LOGICHANDLER_H

#include "..\\Utility\macro.h"

namespace Temere
{
	namespace Logic
	{
		class LogicHandler
		{
			public:
				TEMERE_DYNAMIC_LIBRARY_PREFIX LogicHandler();
				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~LogicHandler();

				TEMERE_DYNAMIC_LIBRARY_PREFIX void checkInput(float deltaTime);
				TEMERE_DYNAMIC_LIBRARY_PREFIX void updateLogic(float deltaTime);
				TEMERE_DYNAMIC_LIBRARY_PREFIX void updatePhysics(float deltaTime);
				TEMERE_DYNAMIC_LIBRARY_PREFIX void updateGraphics(float deltaTime);

				TEMERE_DYNAMIC_LIBRARY_PREFIX void updateAll(float deltaTime);
			private:
		};
	}
}
#endif