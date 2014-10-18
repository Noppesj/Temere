#include "scenehandler.h"
#include "sceneobject.h"

using namespace Temere::Scene;
using namespace Temere::Utility;

std::atomic<SceneHandler*> SceneHandler::mpInstance = 0;
SingletonDestroyer<SceneHandler> SceneHandler::mDestroyer;
std::mutex SceneHandler::mThreadLock;

SceneHandler* SceneHandler::getInstance()
{
	mThreadLock.lock();
	if(!(SceneHandler*)mpInstance)
	{
		mpInstance = new SceneHandler();
		mDestroyer.setSingleton(mpInstance);
	}
	mThreadLock.unlock();
	return mpInstance;
}

SceneHandler::~SceneHandler()
{
}

void SceneHandler::addEntity(SceneObject* entity)
{
	entity->miId = miIdCounter;
	if (mEntityMap.count(entity->miId) == 0)
	{
		mEntityMap.emplace(entity->miId, entity);
		++miIdCounter;
	}
}

void SceneHandler::removeEntity(unsigned int iId)
{
	if (mEntityMap.count(iId) == 1)
	{
		SceneObject* pEntity = mEntityMap[iId];
		TEMERE_SAFE_DELETE(pEntity)
		mEntityMap.erase(iId);
	}
}

void SceneHandler::removeAllEntities()
{
	for(std::unordered_map<unsigned int, SceneObject*>::iterator entityIter = mEntityMap.begin();
		entityIter != mEntityMap.end(); ++entityIter)
	{
		TEMERE_SAFE_DELETE((*entityIter).second)
	}
	mEntityMap.clear();
}

SceneObject* SceneHandler::getEntityById(unsigned int iId)
{
	if (mEntityMap.count(iId) == 1)
	{
		return mEntityMap[iId];
	}
	return nullptr;
}

SceneHandler::SceneHandler() : mEntityMap()
{
	miIdCounter = 1;
}

SceneHandler::SceneHandler(const SceneHandler& ref)
{
	TEMERE_UREF(ref)
}

const SceneHandler& SceneHandler::operator=(const SceneHandler& ref)
{
	TEMERE_UREF(ref)
	return *this;
}