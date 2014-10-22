#ifndef TEMERE_GRAPHIC_CAMERA_H
#define TEMERE_GRAPHIC_CAMERA_H

#include "..\\Utility\macro.h"
#include "GLM\glm.hpp"

namespace Temere
{
	namespace Graphic
	{
		class Camera
		{
		public:
			TEMERE_DYNAMIC_LIBRARY_PREFIX Camera();
			TEMERE_DYNAMIC_LIBRARY_PREFIX Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar);
			TEMERE_DYNAMIC_LIBRARY_PREFIX Camera(const Camera& ref);
			TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~Camera();
			TEMERE_DYNAMIC_LIBRARY_PREFIX const Camera& operator=(const Camera& ref);

			TEMERE_DYNAMIC_LIBRARY_PREFIX  inline  glm::mat4& GetViewProjection();
			TEMERE_DYNAMIC_LIBRARY_PREFIX  inline  glm::mat4& GetView();
			TEMERE_DYNAMIC_LIBRARY_PREFIX  inline  glm::mat4& GetProj();

			TEMERE_DYNAMIC_LIBRARY_PREFIX void updatePos(const glm::vec3 &pos);
		private:
			glm::mat4 mProjectionMatrix;
			glm::mat4 mViewMatrix;
			glm::mat4 mViewProj;
			glm::vec3 mPosition;
			glm::vec3 mForward;
			glm::vec3 mUp;

			float mFov;
			float mAspect;
			float mNear;
			float mFar;
		};
	}
}
#endif