#include "display.h"
#include <GL\glew.h>
#include "easylogging++.h"

//_INITIALIZE_EASYLOGGINGPP
using namespace Temere::Graphic;

Display::Display()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	mWindow = SDL_CreateWindow("Unknown", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,  1024, 576, SDL_WINDOW_OPENGL);
	mGLContext = SDL_GL_CreateContext(mWindow);

	GLenum status = glewInit();

	if(status != GLEW_OK)
	{
		LOG(ERROR) << "Error could not initalize glew." << std::endl;
	}

	//glEnable (GL_BLEND);
	//glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

Display::Display(int width, int height, const std::string &title)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	mWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,  width, height, SDL_WINDOW_OPENGL);
	mGLContext = SDL_GL_CreateContext(mWindow);

	GLenum status = glewInit();

	if(status != GLEW_OK)
	{
		LOG(ERROR) << "Error could not initalize glew." << std::endl;
	} 

	glEnable (GL_BLEND);
	//glBlendFunc (GL_ONE);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_MULTISAMPLE);
	//glEnable(GL_DEPTH_TEST);
}

Display::Display(const Display& ref)
{
	TEMERE_UREF(ref)
}

Display::~Display()
{
	SDL_GL_DeleteContext(mGLContext);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

const Display& Display::operator=(const Display& ref)
{
	TEMERE_UREF(ref)
		return *this;
}

void Display::Clear(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Display::SwapBuffers()
{
	SDL_GL_SwapWindow(mWindow);
}