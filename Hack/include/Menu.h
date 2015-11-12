#ifndef _MENU_H_
#define _MENU_H_

#include <iostream>
#include <stdio.h>

#include <SDL.h>
#include "include\Button.h"
#include "Sprite.h"
#include "include\GameStateController.h"


static class Menu
{
private:
	Button playButton;
	Button exitButton;
	Sprite* backGroundImage;
public:

	Menu(int w,int h);
	~Menu()
	{
		delete backGroundImage;
	}
	void Init();
	bool Update(SDL_Event e);
	void Draw();


};
#endif
