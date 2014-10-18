#ifndef TEMERE_SCENE_SCENEOBJECT_H
#define TEMERE_SCENE_SCENEOBJECT_H

#include "..\\Utility\macro.h"
#include "transformobject.h"
#include "scenehandler.h"
#include "hitbox.h"

namespace Temere
{
	namespace Scene
	{
		class SceneObject : public TransformObject
		{
			public:
				TEMERE_DYNAMIC_LIBRARY_PREFIX SceneObject();
				TEMERE_DYNAMIC_LIBRARY_PREFIX SceneObject(const SceneObject& ref);
				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~SceneObject();
				TEMERE_DYNAMIC_LIBRARY_PREFIX const SceneObject& operator=(const SceneObject& ref);

				TEMERE_DYNAMIC_LIBRARY_PREFIX inline unsigned int getId() const { return miId; }

				TEMERE_DYNAMIC_LIBRARY_PREFIX void update(float deltaTime);
			private:
				unsigned int miId;
			
				friend void SceneHandler::addEntity(SceneObject* entity);

				HitBox *mHitBox;
		};
	}
}
#endif