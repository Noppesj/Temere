#ifndef TEMERE_GRAPHIC_DISPLAY_H
#define TEMERE_GRAPHIC_DISPLAY_H

#include "..\\Utility\macro.h"
#include <string>
#include <SDL.h>

namespace Temere
{
	namespace Graphic
	{
		class Display
		{
			public:
				TEMERE_DYNAMIC_LIBRARY_PREFIX Display();
				TEMERE_DYNAMIC_LIBRARY_PREFIX Display(int width, int height, const std::string &title);
				TEMERE_DYNAMIC_LIBRARY_PREFIX Display(const Display& ref);
				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~Display();
				TEMERE_DYNAMIC_LIBRARY_PREFIX const Display& operator=(const Display& ref);

				TEMERE_DYNAMIC_LIBRARY_PREFIX void Clear(float r, float g, float b, float a);
				TEMERE_DYNAMIC_LIBRARY_PREFIX void SwapBuffers();
			private:
				SDL_Window* mWindow;
				SDL_GLContext mGLContext;
		};
	}
}
#endif