#ifndef _PLAY_H_
#define _PLAY_H_

#include <iostream>
#include <stdio.h>

#include <SDL.h>
#include "include\Button.h"
#include "include\GameStateController.h"


static class Play
{
private:
	Sprite* backGroundImage;
public:

	Play(int w, int h);
	~Play()
	{
		delete backGroundImage;
	}
	void Init();
	bool Update();
	void Draw();


};
#endif
