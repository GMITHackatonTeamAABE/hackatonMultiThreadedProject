#pragma comment(lib, "Box2D.lib")

#include <SDL.h>			//SDL
#include <SDL_ttf.h>
#include <string>
#include <chrono>
#include "include\GameStateController.h"
#include "include\Renderer.h"
#include "include\Sprite.h"
#include "include\KeyBoardInput.h"
#include "include\Menu.h"
#include "include\Play.h"
#include <Box2D/Box2D.h>
#include "include\SoundManager.h"


//Screen dimension constants
const int SCREEN_WIDTH = 1248;			//SDL
const int SCREEN_HEIGHT = 704;			//SDL

Menu* menu;
Play* play;
bool quit;

b2World world(b2Vec2(0,30));

void Init();
void Reset();
void ClearPointers();


int wmain(){
#pragma region SDL Mixer
	int audio_rate, audio_channels;
	Uint16 audio_format;
	Uint32 t;
	Mix_Music *music;
	int volume = SDL_MIX_MAXVOLUME;

	/* initialize SDL for audio and video */
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		return 1;
	}
	atexit(SDL_Quit);

	/* initialize sdl mixer, open up the audio device */
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) < 0)
	{
		return 1;
	}

	/* load the song */
	if (!(music = Mix_LoadMUS("./assets/bgmus.mp3")))
	{
		return 1;
	}

	if (Mix_PlayMusic(music, 1) == -1)
	{
		return 1;
	}
#pragma endregion


	//The window we'll be rendering to
	SDL_Window* window = nullptr;

	//SDL
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("Spooky Scary Skeletons", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == nullptr)
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
						play->UpdateMousePos(e.motion.x, e.motion.y);
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
				world.DrawDebugData();
			}//end while wait
		}//end else
	}//end else

	ClearPointers();
	return 0;
}

void Init(){
	quit = false;
	menu = new Menu(SCREEN_WIDTH, SCREEN_HEIGHT);
	play = new Play(&world,SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!SoundManager::GetInstance()->load_files())
	{
		printf("Sounds Did not load ");
	}
}

void Reset(){
}

void ClearPointers(){
	delete menu;
	delete play;
	SoundManager::GetInstance()->clean_up();
}