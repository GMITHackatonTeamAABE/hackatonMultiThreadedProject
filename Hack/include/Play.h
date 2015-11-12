#ifndef _PLAY_H_
#define _PLAY_H_

#include <iostream>
#include <stdio.h>

#include <SDL.h>
#include <Box2D/Box2D.h>
#include "include\Button.h"
#include "include\GameStateController.h"
#include <include/Tower.h>
#include "EnemyManager.h"


static class Play
{
private:
	Sprite* backGroundImage;
	Tower* tower;
	b2World* world;
public:

	Play(b2World*,int w, int h);
	~Play()
	{
		delete backGroundImage;
		delete tower;
	}
	void Init();
	
	void Update();
	void Draw();


};
#endif
