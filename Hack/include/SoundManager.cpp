#include <include/SoundManager.h>


bool SoundManager::instanceFlag = false;
SoundManager* SoundManager::instance = NULL;

SoundManager* SoundManager::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new SoundManager;
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}

bool SoundManager::load_files()
{
	//Load the music
	shoot = Mix_LoadMUS("Assets/shoot.wav");

	//If there was a problem loading the music
	if (shoot == NULL)
	{
		return false;
	}

	//Load the sound effects
	scratch = Mix_LoadWAV("Assets/shoot.wav");

	//If there was a problem loading the sound effects
	if (scratch == NULL)
	{
		return false;
	}

	//If everything loaded fine
	return true;
}
void SoundManager::clean_up()
{

	//Free the sound effects
	Mix_FreeChunk(scratch);

	//Free the music
	Mix_FreeMusic(SHOOT);

	//Quit SDL_mixer
	Mix_CloseAudio();

	//Quit SDL
	SDL_Quit();
}
void SoundManager::play(int i)
{
	//If there is no music playing
	switch (i)
	{
	case SHOOT:
		Mix_PlayChannel(-1, scratch, 0);
		break;
	case MUSIC:
		if (Mix_PlayingMusic() == 0)
		{
			//Play the music
			Mix_PlayMusic(shoot, -1);
		
		}
		break;
	}
}
