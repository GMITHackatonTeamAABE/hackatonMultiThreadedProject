#include <SDL.h>			//SDL
#include <SDL_ttf.h>
#include <string>
#include "include\GameStateController.h"
#include "include\Renderer.h"
#include "include\Sprite.h"
#include "include\KeyBoardInput.h"
#include "include\Menu.h"


//Screen dimension constants
const int SCREEN_WIDTH = 1248;			//SDL
const int SCREEN_HEIGHT = 704;			//SDL
Menu* menu; 										//gamestates

void Init();
void DrawGame();
void UpdateGame();
void Reset();
void ClearPointers();


int wmain()
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//SDL
#pragma region SDL STUFF
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
					UpdateGame();
					DrawGame();
					break;
				case GameStateController::PAUSE:
					UpdateGame();
					DrawGame();
					break;
				}//end switch

				 // Escape button
				if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_ESCAPE))
				{
					quit = true;
				}

			}//end while wuit
		}//end else
	}//end else

	ClearPointers();
	return 0;
}

void Init()
{
	menu = new Menu(SCREEN_WIDTH, SCREEN_HEIGHT);
}
void DrawGame()
{
	Renderer::GetInstance()->ClearRenderer();

	/*Call Darw on objects here*/


	Renderer::GetInstance()->RenderScreen();
}
void UpdateGame()
{

}
void Reset()
{

}
void ClearPointers()
{
	delete menu;
}