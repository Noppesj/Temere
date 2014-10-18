#ifndef TEMERE_SCENE_TRANSFORMOBJECT_H
#define TEMERE_SCENE_TRANSFORMOBJECT_H

#include "..\\utility\\macro.h"
#include "..\\Utility\object.h"
#include <GLM\glm.hpp>

namespace Temere
{
	namespace Scene
	{
		class TransformObject : public Temere::Utility::Object
		{
			public:
				TEMERE_DYNAMIC_LIBRARY_PREFIX TransformObject();
				TEMERE_DYNAMIC_LIBRARY_PREFIX TransformObject(const TransformObject& ref);
				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~TransformObject() = 0;
				TEMERE_DYNAMIC_LIBRARY_PREFIX const TransformObject& operator=(const TransformObject& ref);

				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual void update();

				TEMERE_DYNAMIC_LIBRARY_PREFIX inline void setPosition(const glm::vec3& vector) { mPosition = vector; mbCalculateTranslationRequired = true; }
				TEMERE_DYNAMIC_LIBRARY_PREFIX inline void setPosition(float fX, float fY, float fZ) { mPosition = glm::vec3(fX, fY, fZ); mbCalculateTranslationRequired = true; }
				TEMERE_DYNAMIC_LIBRARY_PREFIX inline void setRotate(const glm::vec3& vector) { mRotate = vector; mbCalculateRotationRequired = true; }
				TEMERE_DYNAMIC_LIBRARY_PREFIX inline void setRotate(float fX, float fY, float fZ) { mRotate = glm::vec3(fX, fY, fZ); mbCalculateRotationRequired = true; }
				TEMERE_DYNAMIC_LIBRARY_PREFIX inline void setScale(const glm::vec3& vector) { mScale = vector; mbCalculateScaleRequired = true; }
				TEMERE_DYNAMIC_LIBRARY_PREFIX inline void setScale(float fX, float fY, float fZ) { mScale = glm::vec3(fX, fY, fZ); mbCalculateScaleRequired = true; }

				TEMERE_DYNAMIC_LIBRARY_PREFIX inline void increasePosition(const glm::vec3& vector) { mPosition += vector; mbCalculateTranslationRequired = true; }
				TEMERE_DYNAMIC_LIBRARY_PREFIX inline void increasePosition(float fX, float fY, float fZ) { mPosition += glm::vec3(fX, fY, fZ); mbCalculateTranslationRequired = true; }
				TEMERE_DYNAMIC_LIBRARY_PREFIX inline void increaseRotate(const glm::vec3& vector) { mRotate += vector; mbCalculateRotationRequired = true; }
				TEMERE_DYNAMIC_LIBRARY_PREFIX inline void increaseRotate(float fX, float fY, float fZ) { mRotate += glm::vec3(fX, fY, fZ); mbCalculateRotationRequired = true; }
				TEMERE_DYNAMIC_LIBRARY_PREFIX inline void increaseScale(const glm::vec3& vector) { mScale += vector; mbCalculateScaleRequired = true; }
				TEMERE_DYNAMIC_LIBRARY_PREFIX inline void increaseScale(float fX, float fY, float fZ) { mScale += glm::vec3(fX, fY, fZ); mbCalculateScaleRequired = true; }

				TEMERE_DYNAMIC_LIBRARY_PREFIX inline const glm::vec3& getPosition() const { return mPosition; }
				TEMERE_DYNAMIC_LIBRARY_PREFIX inline const glm::vec3& getRotate() const { return mRotate; }
				TEMERE_DYNAMIC_LIBRARY_PREFIX inline const glm::vec3& getScale() const { return mScale; }
				TEMERE_DYNAMIC_LIBRARY_PREFIX inline const glm::mat4& getTranslateMatrix() const { return mTranslateMatrix; }
				TEMERE_DYNAMIC_LIBRARY_PREFIX inline const glm::mat4& getRotateMatrix() const { return mRotateMatrix; }
				TEMERE_DYNAMIC_LIBRARY_PREFIX inline const glm::mat4& getScaleMatrix() const { return mScaleMatrix; }
				TEMERE_DYNAMIC_LIBRARY_PREFIX inline const glm::mat4& getTransformMatrix() const { return mTransformMatrix; }

				TEMERE_DYNAMIC_LIBRARY_PREFIX inline glm::mat4& getModelMatrix();
				TEMERE_DYNAMIC_LIBRARY_PREFIX inline glm::mat4& getMVP() const;
		//private:
		protected:
				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual void calculateTranslateMatrix();
				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual void calculateRotateMatrix();
				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual void calculateScaleMatrix();
				TEMERE_DYNAMIC_LIBRARY_PREFIX virtual void calculateTransformMatrix();

				glm::vec3 mPosition;
				glm::vec3 mRotate;
				glm::vec3 mScale;
				glm::mat4 mTranslateMatrix;
				glm::mat4 mModelMatrix;
				glm::mat4 mRotateMatrix;
				glm::mat4 mScaleMatrix;
				glm::mat4 mTransformMatrix;
				bool mbCalculateTranslationRequired;
				bool mbCalculateRotationRequired;
				bool mbCalculateScaleRequired;
				bool mbCalculateTransformRequired;	   
		};
	}
}
#endif