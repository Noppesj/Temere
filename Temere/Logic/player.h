#ifndef TEMERE_LOGIC_PLAYER_H
#define TEMERE_LOHIC_PLAYER_H

#include "actor.h"
#include "animationlogic.h"
#include "..\\Graphic\spriteanimation.h"
#include "..\\Graphic\camera.h"

using namespace Temere::Graphic;

namespace Temere
{
	namespace Logic
	{
		class Player : public Actor
		{
			public:
				TEMERE_DYNAMIC_LIBRARY_PREFIX Player(AnimationLogic& headLeft, AnimationLogic& headRight, AnimationLogic& bodyLeft, AnimationLogic& bodyRight, AnimationLogic& legsLeft, AnimationLogic& legsRight,
														unsigned int mTextureRows, unsigned int mTextureCols);

				TEMERE_DYNAMIC_LIBRARY_PREFIX Player(AnimationLogic& headLeft, AnimationLogic& headRight, AnimationLogic& bodyLeft, AnimationLogic& bodyRight,
														unsigned int mTextureRows, unsigned int mTextureCols);

				TEMERE_DYNAMIC_LIBRARY_PREFIX Player(AnimationLogic& headLeft, AnimationLogic& headRight, AnimationLogic& headUp, AnimationLogic& headDown, AnimationLogic& bodyLeft, AnimationLogic& bodyRight,
					 AnimationLogic& bodyUp, AnimationLogic& bodyDown, unsigned int mTextureRows, unsigned int mTextureCols);

				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~Player();
						
				TEMERE_DYNAMIC_LIBRARY_PREFIX void update(const float deltaTime);
				TEMERE_DYNAMIC_LIBRARY_PREFIX void draw(const glm::mat4& projection,const  glm::mat4& view);

				TEMERE_DYNAMIC_LIBRARY_PREFIX void loadShaders(std::string vertexShader_path, std::string fragmentShader_path);
				TEMERE_DYNAMIC_LIBRARY_PREFIX bool loadTexture(std::string texturePath);

				TEMERE_DYNAMIC_LIBRARY_PREFIX void moveLeft(const float deltaTime);
				TEMERE_DYNAMIC_LIBRARY_PREFIX void moveRight(const float deltaTime);
				TEMERE_DYNAMIC_LIBRARY_PREFIX void moveUp(const float deltaTime);
				TEMERE_DYNAMIC_LIBRARY_PREFIX void moveDown(const float deltaTime);

				TEMERE_DYNAMIC_LIBRARY_PREFIX void setPosition(const glm::vec3& position);
				TEMERE_DYNAMIC_LIBRARY_PREFIX void setScale(const glm::vec3& scale);

				TEMERE_DYNAMIC_LIBRARY_PREFIX const glm::vec3& getPosition();
			private:
				SpriteAnimation *mHead;
				SpriteAnimation *mBody;
				SpriteAnimation *mLegs;

				AnimationLogic mHeadLeft;
				AnimationLogic mHeadRight;
				AnimationLogic mHeadUp;
				AnimationLogic mHeadDown;

				AnimationLogic mBodyLeft;
				AnimationLogic mBodyRight;
				AnimationLogic mBodyUp;
				AnimationLogic mBodyDown;

				AnimationLogic mLegsLeft;
				AnimationLogic mLegsRight;

				unsigned int mCurrentHeadIndex;
				unsigned int mCurrentBodyIndex;
				unsigned int mCurrentLegsIndex;
				
				TEMERE_DYNAMIC_LIBRARY_PREFIX Player();
				TEMERE_DYNAMIC_LIBRARY_PREFIX Player(const Player& ref);
				TEMERE_DYNAMIC_LIBRARY_PREFIX const Player& operator=(const Player& ref);
			protected:
		};
	}
}
#endif