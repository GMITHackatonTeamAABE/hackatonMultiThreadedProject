#ifndef GAME_H
#define GAME_H
#include "Debug.h"
#include <memory>
#include <mutex>
#include <atomic>
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

	std::unique_ptr<Player> mPlayer;

	std::mutex mMutex;
};
#endif

