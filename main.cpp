#include <iostream>
#include <thread>
#include <string>

#include "TinyXML2.h"

#include <SDL.h>
#include <SDL_image.h>

#include "Game.h"
#include "Player.h"

using namespace std;
using namespace tinyxml2;

#define THREADING_ENABLED

int main(int argc, char** argv){

	DEBUG_MSG("Game Object Created");

	Game* game = new Game();

	/*XMLDocument doc;
	doc.LoadFile("Levels.xml");

	const char* temp = doc.FirstChildElement("root")->FirstChildElement("level1")->FirstChildElement("player")->FirstChildElement("health")->GetText();*/

	//DEBUG_MSG(temp);

	//Adjust screen positions as needed
	DEBUG_MSG("Game Initialising");
	game->Initialize("Hackathon Threading Assignment - C00165681",300,100,800,600, SDL_WINDOW_INPUT_FOCUS);
	
	DEBUG_MSG("Loading Content");
	game->LoadContent();


	DEBUG_MSG("Game Loop Starting......");

#ifdef THREADING_ENABLED
	thread updateThread = thread([game]()
	{
		while (game->IsRunning())
		{
			game->Update();
		}
	});

	thread renderThread = thread([game]()
	{
		while (game->IsRunning())
		{
			game->Render();
		}
	});

	while (game->IsRunning())
	{
		game->HandleEvents();
	}

	updateThread.join();
	renderThread.join();
#else
	//Non-threaded game loop
	while (game->IsRunning())
	{
		game->HandleEvents();
		game->Update();
		game->Render();
	}
#endif

	DEBUG_MSG("Calling Cleanup");
	game->CleanUp();
	game->UnloadContent();
	
	return 0;
}


