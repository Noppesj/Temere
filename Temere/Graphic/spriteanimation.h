#ifndef TEMERE_GRAPHIC_SPRITEANIMATION_H
#define TEMERE_GRAPHIC_SPRITEANIMATION_H

#include "spriteobject.h"
#include "..\\Utility\macro.h"

namespace Temere
{
	namespace Graphic
	{
		class SpriteAnimation : public SpriteObject
		{
			public:
				//TEMERE_DYNAMIC_LIBRARY_PREFIX SpriteAnimation();
				TEMERE_DYNAMIC_LIBRARY_PREFIX SpriteAnimation(int rowNum, int colNum);
				TEMERE_DYNAMIC_LIBRARY_PREFIX SpriteAnimation(const SpriteAnimation& ref);
				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~SpriteAnimation();
				TEMERE_DYNAMIC_LIBRARY_PREFIX const SpriteAnimation& operator=(const SpriteAnimation& ref);

				TEMERE_DYNAMIC_LIBRARY_PREFIX void Draw(const glm::mat4 &projMatrix, const glm::mat4 &viewMatrix, const int spriteIndex);
			private:
				int mRowNum;
				int mColNum;
				
				TEMERE_DYNAMIC_LIBRARY_PREFIX void changeSprite(const int spriteIndex);		
		};
	}
}
#endif