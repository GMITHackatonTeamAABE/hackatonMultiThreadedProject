#ifndef GAME_H
#define GAME_H
#include "Debug.h"
#include <memory>
#include <mutex>
#include <atomic>
#include <chrono>
#include <SDL.h>
#include "Player.h"

class Game
{
public:
	Game();
	~Game();
	bool Initialize(const char*, int, int, int, int, int);
	void LoadContent();
	void UnloadContent();
	void Render();
	void Update();
	void HandleEvents();
	bool IsRunning() const;
	void CleanUp();
private:
	atomic<bool> m_running;
	SDL_Window* m_p_Window;
	SDL_Renderer* m_p_Renderer;
	SDL_Texture* m_p_Texture;
	SDL_Rect m_Source;
	SDL_Rect m_Destination;
	SDL_Surface* m_p_Surface;

	unique_ptr<Player> mPlayer;

	mutex mMutex;

	chrono::milliseconds timePerUpdate;
	chrono::steady_clock updateClock;
	chrono::time_point<chrono::system_clock> timeOfLastUpdate;
};
#endif

