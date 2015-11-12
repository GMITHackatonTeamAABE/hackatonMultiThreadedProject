#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <iostream> 
#include <SDL.h>			//SDL
#include <stdio.h>
#include "SDL_mixer.h"
#include <list>

#pragma comment(lib, "SDL2_mixer.lib")

using namespace std;

class SoundManager
{
public:
	static const int SHOOT = 0, MUSIC = 1;
	
	static SoundManager* GetInstance();
	void play(int);
	bool load_files();
	void clean_up();
	~SoundManager()
	{
		instanceFlag = false;
	}
private:
	SoundManager()
	{
		
		
		//Initialize SDL_mixer
		if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
		{
			
		}
	}
	Mix_Music* shoot = NULL;
	Mix_Chunk* scratch = NULL;
	static bool instanceFlag;
	static SoundManager* instance;
	
};
#endif
