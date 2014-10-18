#include "inputhandler.h"
#include "SDL.h"

using namespace Temere::Logic; 

InputHandler::InputHandler()
{
	mMoveLeft = SDLK_LEFT;
	mMoveRight = SDLK_RIGHT;
	mMoveUp = SDLK_UP;
	mMoveDown = SDLK_DOWN;

	mHotBar1 = SDLK_1;
	mHotBar2 = SDLK_2;
	mHotBar3 = SDLK_3;
	mHotBar4 = SDLK_4;
	mHotBar5 = SDLK_5;
	mHotBar6 = SDLK_6;
}

InputHandler::~InputHandler()
{

}

void InputHandler::pollEvents()
{
	
}