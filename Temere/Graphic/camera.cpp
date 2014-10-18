#include "camera.h"
#include "GLM\gtx\transform.hpp"

using namespace Temere::Graphic;

Camera::Camera()
{
	mPosition = glm::vec3(0.0f, 0.0f, 0.0f);
	mForward = glm::vec3(0.0f, 0.0f, 1.0f);
	mUp = glm::vec3(0.0f, 1.0f, 0.0f);
	mProjectionMatrix = glm::perspective(90.0f, 1.77777778f, 0.01f, 1000.0f);
}

Camera::Camera(const glm::vec3 &pos, float fov, float aspect, float zNear, float zFar)
{
	mPosition = pos;
	mForward = glm::vec3(0.0f, 0.0f, 1.0f);
	mUp = glm::vec3(0.0f, 1.0f, 0.0f);
	mProjectionMatrix = glm::perspective(fov, aspect, zNear, zFar);
}

Camera::Camera(const Camera& ref)
{
	TEMERE_UREF(ref)
}

Camera::~Camera()
{

}
const Camera& Camera::operator=(const Camera& ref)
{
	TEMERE_UREF(ref)
		return *this;
}

glm::mat4& Camera::GetViewProjection()
{
	mViewProj = mProjectionMatrix * (glm::lookAt(mPosition, mPosition + mForward, mUp));
	return mViewProj;
}

glm::mat4& Camera::GetView()
{
	glm::mat4 temp = (glm::lookAt(mPosition, mPosition + mForward, mUp));
	mViewMatrix = temp;
	return mViewMatrix;
}	

glm::mat4& Camera::GetProj()
{
	return mProjectionMatrix;
}

void Camera::updatePos(const glm::vec3 &pos)
{
	mPosition.x = pos.x;
	mPosition.y = pos.y;
}