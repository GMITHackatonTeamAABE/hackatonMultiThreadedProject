// Hack.cpp : Defines the entry point for the console application.
//

#pragma comment(lib, "Box2D.lib")

#include <SDL.h>
#include <Box2D/Box2D.h>

#include <include/Renderer.h>
#include <include/Tower.h>

int wmain()
{
	srand(time_t(0U));
	Renderer::GetInstance()->Init(SDL_CreateWindow("Hackathon", 100, 100, 600, 400, 0), 600, 400);

	b2World myWorld = b2World(b2Vec2_zero);
	Tower myTower = Tower(myWorld, 100, 100);
	while(true)
	{
		myTower.update(1, 1, 0);
		myTower.draw();
		Renderer::GetInstance()->RenderScreen();
	}

    return 0;
}

