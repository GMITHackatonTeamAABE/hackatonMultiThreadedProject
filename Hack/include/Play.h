#ifndef _PLAY_H_
#define _PLAY_H_

#include <iostream>
#include <stdio.h>

#include <SDL.h>
#include <Box2D/Box2D.h>
#include "include\Button.h"
#include "include\GameStateController.h"
#include <include\KeyBoardInput.h>
#include <include\Tower.h>
#include <include\Bullet.h>
#include <include/KeyBoardInput.h>
#include <include/Tower.h>
#include "include\Bullet.h"
#include <chrono>
#include "EnemyManager.h"
#include "include\floor.h"


class Play
{
private:
	Sprite* backGroundImage;
	Tower* tower;
	b2World* world;
	Bullet* bullet;
	Floor* floor;
	bool clockInit;

	int mouseX, mouseY;
	std::chrono::steady_clock myClock;
	chrono::time_point<chrono::steady_clock> lastTickTime;
	const chrono::milliseconds TIME_PER_TICK;
public:

	Play(b2World*,int w, int h);
	~Play()
	{
		delete backGroundImage;
		delete tower;
		delete floor;
		delete bullet;
	}
	void Init();
	
	void Update();
	void Draw() const;
	int timeSinceGameStartInMS;
	void UpdateMousePos(int x, int y);
};
#endif
