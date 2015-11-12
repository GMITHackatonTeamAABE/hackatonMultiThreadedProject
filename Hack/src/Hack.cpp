#pragma comment(lib, "Box2D.lib")

#include <SDL.h>			//SDL
#include <SDL_ttf.h>
#include <string>
#include "include\GameStateController.h"
#include "include\Renderer.h"
#include "include\Sprite.h"
#include "include\KeyBoardInput.h"
#include "include\Menu.h"
#include "include\Play.h"
#include <Box2D/Box2D.h>


//Screen dimension constants
const int SCREEN_WIDTH = 1248;			//SDL
const int SCREEN_HEIGHT = 704;			//SDL

Menu* menu;
Play* play;
b2World world(b2Vec2(0,9.81));

int mouseX, mouseY;

void Init();
void Reset();
void ClearPointers();

int wmain(){
	//The window we'll be rendering to
	SDL_Window* window = NULL;
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Create Renderer for the Window
			if (!Renderer::GetInstance()->Init(window, SCREEN_WIDTH, SCREEN_HEIGHT))
			{
				return 0;
			}

			bool quit = false;
			Init();

			SDL_Event e;
			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0) {
					KeyBoardInput::GetInstance()->updateKeyboard(e);
					switch (e.type)
					{
					case SDL_QUIT:
						quit = true;
						break;
					case SDL_MOUSEMOTION:
						mouseX = e.motion.x;
						mouseY = e.motion.y;
						break;
					}
				}

				//controls gameState added in game menu feature
				switch (GameStateController::GetInstance()->getGameState())
				{
				case GameStateController::MENU:
					//updateMenu
					quit = menu->Update(e);
					//draw menu
					menu->Draw();

					break;
				case GameStateController::PLAY:
					
					play->Update();
					play->Draw();
					break;
				case GameStateController::PAUSE:
					
					break;
				}//end switch

				 // Escape button
				if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_ESCAPE)){
					quit = true;
				}

			}//end while wait
		}//end else
	}//end else

	ClearPointers();
	return 0;
}

void Init(){
	menu = new Menu(SCREEN_WIDTH, SCREEN_HEIGHT);
	play = new Play(&world,SCREEN_WIDTH, SCREEN_HEIGHT);
}

void Reset(){
}

void ClearPointers(){
	delete menu;
	delete play;
}