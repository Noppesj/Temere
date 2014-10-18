#ifndef TEMERE_SCENE_SCENEHANDLER_H
#define TEMERE_SCENE_SCENEHANDLER_H

#include "..\\utility/macro.h"
#include "..\\utility/singletondestroyer.h"
#include <atomic>
#include <mutex>
#include <unordered_map>

namespace Temere
{
	namespace Scene
	{
		class SceneObject;

		class SceneHandler
		{
		public:
			TEMERE_DYNAMIC_LIBRARY_PREFIX static SceneHandler* getInstance();
			TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~SceneHandler();

			TEMERE_DYNAMIC_LIBRARY_PREFIX void addEntity(SceneObject* entity);
			TEMERE_DYNAMIC_LIBRARY_PREFIX void removeEntity(unsigned int iId);
			TEMERE_DYNAMIC_LIBRARY_PREFIX void removeAllEntities();

			TEMERE_DYNAMIC_LIBRARY_PREFIX SceneObject* getEntityById(unsigned int iId);

		private:
			TEMERE_DYNAMIC_LIBRARY_PREFIX SceneHandler();
			TEMERE_DYNAMIC_LIBRARY_PREFIX SceneHandler(const SceneHandler& ref);
			TEMERE_DYNAMIC_LIBRARY_PREFIX const SceneHandler& operator=(const SceneHandler& ref);

			static std::atomic<SceneHandler*> mpInstance;
			static Temere::Utility::SingletonDestroyer<SceneHandler> mDestroyer;
			static std::mutex mThreadLock;
			std::unordered_map<unsigned int, SceneObject*> mEntityMap;
			unsigned int miIdCounter;
		};
	}
}

#endif