#include "Game.h"
#include <iostream>
#include <thread>


using namespace std;

Game::Game() : m_running(false)
{
}

Game::~Game()
{
}

bool Game::Initialize(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	lock_guard<mutex> lock(mMutex);

	timeOfLastUpdate = updateClock.now();
	timePerUpdate = chrono::milliseconds(16);

	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		DEBUG_MSG("SDL Init success");
		m_p_Window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if(m_p_Window != 0)
		{
			DEBUG_MSG("Window creation success");
			m_p_Renderer = SDL_CreateRenderer(m_p_Window, -1, 0);
			if(m_p_Renderer != nullptr)
			{
				DEBUG_MSG("Renderer creation success");
				SDL_SetRenderDrawColor(m_p_Renderer, 255, 255, 255, 255);
			}
			else
			{
				DEBUG_MSG("Renderer init fail");
				return false;
			}
		}
		else
		{
			DEBUG_MSG("Window init fail");
			return false;
		}
	}
	else
	{
		DEBUG_MSG("SDL init fail");
		return false;
	}



	m_running = true;

	return true;
}



void Game::LoadContent()
{
	lock_guard<mutex> lock(mMutex);
	DEBUG_MSG("Loading Content");
	m_p_Surface = SDL_LoadBMP("assets/sprite.bmp");
	m_p_Texture = SDL_CreateTextureFromSurface(m_p_Renderer, m_p_Surface);
	SDL_FreeSurface(m_p_Surface);

	if(SDL_QueryTexture(m_p_Texture, NULL, NULL, &m_Source.w, &m_Destination.h)==0)
	{
		m_Destination.x = m_Source.x = 0;
		m_Destination.y = m_Source.y = 0;
		m_Destination.w = m_Source.w = 32;
		m_Destination.h = m_Source.h = 32;

		/*DEBUG_MSG("Destination X:" + m_Destination.x);
		DEBUG_MSG("Destination Y:" + m_Destination.y);
		DEBUG_MSG("Destination W:" + m_Destination.w);
		DEBUG_MSG("Destination H:" + m_Destination.h);*/

		mPlayer = std::make_unique<Player>(m_p_Texture);
	}
	else
	{
		DEBUG_MSG("Texture Query Failed");
		m_running = false;
	}
}

void Game::Render()
{
	SDL_RenderClear(m_p_Renderer);
	//DEBUG_MSG("Width Source" + m_Destination.w);
	//DEBUG_MSG("Width Destination" + m_Destination.w);

	mPlayer->Render(m_p_Renderer);

	SDL_RenderPresent(m_p_Renderer);
}

void Game::Update()
{
	if (updateClock.now() - timeOfLastUpdate >= timePerUpdate) {
		timeOfLastUpdate = updateClock.now();
		//DEBUG_MSG("Updating....");
		mPlayer->Update();
	}
}

void Game::HandleEvents()
{
	SDL_Event event;
	bool assignDirection = false;
	unsigned char direction = 0x00;	//bitflags
	while (SDL_PollEvent(&event))
	{
		switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				m_running = false;
				break;
			case SDLK_UP:
				//DEBUG_MSG("Up Key Pressed");
				//SDL_SetRenderDrawColor(m_p_Renderer, 255, 0, 0, 255);
				direction = mPlayer->UP;
				assignDirection = true;
				break;
			case SDLK_DOWN:
				//DEBUG_MSG("Down Key Pressed");
				//SDL_SetRenderDrawColor(m_p_Renderer, 0, 255, 0, 255);
				direction = mPlayer->DOWN;
				assignDirection = true;
				break;
			case SDLK_LEFT:
				//DEBUG_MSG("Left Key Pressed");
				//SDL_SetRenderDrawColor(m_p_Renderer, 0, 0, 255, 255);
				direction = mPlayer->LEFT;
				assignDirection = true;
				break;
			case SDLK_RIGHT:
				//DEBUG_MSG("Right Key Pressed");
				//SDL_SetRenderDrawColor(m_p_Renderer, 255, 255, 255, 255);
				direction = mPlayer->RIGHT;
				assignDirection = true;
				break;
			case SDLK_SPACE:
				if (mPlayer->IsAwake()) {
					mPlayer->Sleep();
					SDL_SetRenderDrawColor(m_p_Renderer, 50, 50, 50, 255);
				} else {
					mPlayer->Wake();
					SDL_SetRenderDrawColor(m_p_Renderer, 255, 255, 255, 255);
				}
			default:
				//SDL_SetRenderDrawColor(m_p_Renderer, 0, 0, 0, 255);
				break;
			}
			break;
		}

		if (assignDirection) {
			DEBUG_MSG("inst");
			mPlayer->Instruct(direction);
		}
	}
}

bool Game::IsRunning() const {
	return m_running;
}

void Game::UnloadContent()
{
	lock_guard<mutex> lock(mMutex);
	DEBUG_MSG("Unloading Content");
	//delete(m_p_Texture);
	//m_p_Texture = nullptr;
}

void Game::CleanUp()
{
	lock_guard<mutex> lock(mMutex);
	DEBUG_MSG("Cleaning Up");
	SDL_DestroyWindow(m_p_Window);
	SDL_DestroyRenderer(m_p_Renderer);
	SDL_Quit();
}
