#include "..\\Graphic\display.h"
#include "..\Graphic\camera.h"
#include "..\\Logic\player.h"
#include "..\\Utility\timer.h"
#include "easylogging++.h"

_INITIALIZE_EASYLOGGINGPP

using namespace Temere::Graphic;
using namespace Temere::Utility;
using namespace Temere::Logic;

int DISPLAY_WIDTH = 1600;
int DISPLAY_HEIGHT = 10001;

const std::string TITLE = "Temere V1.0";
/* Our program's entry point */
int main(int argc, char *argv[])
{
	TEMERE_UREF(argc)
	TEMERE_UREF(argv)
	// Load configuration from file
    el::Configurations conf("C:\\Development\\Temere\\Resources\\Conf\\conf.conf");
    // Reconfigure single logger
    el::Loggers::reconfigureLogger("GLOBAL", conf);
    // Actually reconfigure all loggers instead
    el::Loggers::reconfigureAllLoggers(conf);

	Display display(DISPLAY_WIDTH, DISPLAY_HEIGHT, TITLE);
	

	Camera camera(glm::vec3(0.0f, 0.0f, -3.0f), 70.0f, (float)DISPLAY_WIDTH/(float)DISPLAY_HEIGHT, 0.1f, 100.0f);
	
	//Player player(AnimationLogic(0, 5), AnimationLogic(6, 11), AnimationLogic(12, 17), AnimationLogic(18, 23), AnimationLogic(24, 29), AnimationLogic(30, 35), 6, 6);
	//Player player(AnimationLogic(0, 3), AnimationLogic(4, 7), AnimationLogic(8, 11), AnimationLogic(12, 15), 4, 8);
	/*Player(AnimationLogic headLeft, AnimationLogic headRight, AnimationLogic headUp, AnimationLogic headDown, AnimationLogic bodyLeft, AnimationLogic bodyRight,
														AnimationLogic bodyUp, AnimationLogic bodyDown, unsigned int mTextureRows, unsigned int mTextureCols);*/
	AnimationLogic a1 = AnimationLogic(0, 3);
	AnimationLogic a2 = AnimationLogic(8, 11);
	AnimationLogic a3 = AnimationLogic(16, 19);
	AnimationLogic a4 = AnimationLogic(24, 27);
	AnimationLogic a5 = AnimationLogic(56, 60);
	AnimationLogic a6 = AnimationLogic(48, 52);
	AnimationLogic a7 = AnimationLogic(32, 35);
	AnimationLogic a8 = AnimationLogic(40, 43);
	//Player player(AnimationLogic(0, 3), AnimationLogic(8, 11), AnimationLogic(16, 19), AnimationLogic(24, 27), AnimationLogic(56, 60), AnimationLogic(48, 52), AnimationLogic(32, 35), AnimationLogic(40, 43),  8, 8);
	Player player(a1, a2, a3, a4, a5, a6, a7, a8, 8, 8);
	player.loadShaders("animationVertex.glsl", "textureFragment.glsl");
	player.loadTexture("Pninja2.png");
	player.setScale(glm::vec3(1.0f, 1.0f, 1.0f));
	player.setPosition(glm::vec3(0.0f, 0.5f, 0.0f));
	
	SpriteObject test;
	test.loadShaders("textureVertex.glsl", "textureFragment.glsl");
	test.loadTexture("Pninja2.png");
	SDL_Event e;
	//int spriteIndex = 0;
	bool isRunning = true;
	
	 int startTicks = SDL_GetTicks();
	 int frame = 0;
	//"Main loop"
		while(isRunning)
		{
			startTicks = SDL_GetTicks();
			while(SDL_PollEvent(&e))
			{
				switch( e.type )
				{
					case SDL_QUIT:
						isRunning = false;
					break;
					case SDL_KEYDOWN:
						/* Check the SDLKey values and move change the coords */
						switch( e.key.keysym.sym )
						{
							case SDLK_LEFT:
								player.moveLeft(1.0f);
							break;
							case SDLK_RIGHT:
								player.moveRight(1.0f);
							break;
							case SDLK_UP:
								player.moveUp(1.0f);
							break;
							case SDLK_DOWN:
								player.moveDown(1.0f);
							break;
							default:
								break;
						}
					break;
				}
			}
			
			camera.updatePos(player.getPosition());
			display.Clear(0.0f, 0.0f, 0.0f, 1.0f);
			player.draw(camera.GetProj(), camera.GetView());
			test.Draw(camera.GetProj(), camera.GetView());
			//player.draw(camera.GetViewProjection(), glm::mat4());
			display.SwapBuffers();
			frame++;
			if( (SDL_GetTicks() - startTicks) < 1000 / 150 )
			{
				//Sleep the remaining frame time
				SDL_Delay( ( 1000 / 150 ) - (SDL_GetTicks() - startTicks) );
				//LOG(INFO) << "FPS: " << frame % 150 << std::endl;
				//std::cout << "FPS: " << frame % 150 << std::endl;
			}
		}
	
	GraphicManager::getInstance()->ClearResources();

    return 0;
}