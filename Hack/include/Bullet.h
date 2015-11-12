#pragma once
#ifndef BULLET_H
#define BULLET_H

#include <list>
#include <vector>
#include "include\Renderer.h"
#include "include\Sprite.h"

class Bullet {
private:
	//b2Vec2 m_position;
	// m_velocity;

	//b2World* world;
	//b2Body* bulletBody;
	Sprite* sprite;

	float initX = 0;
	float initY = 0;

	SDL_Rect* spriteRect;
public:
	//Bullet(float x, float y, b2World& World);
	void Update(float dir); // b2Vec2 dir
	void CreateBody();
	bool CheckLife();
	bool CheckCollision(SDL_Rect* rect);
	void Draw(); // sprite.Draw();

	~Bullet(); 
};


class BulletManager {
private:
	static bool instanceFlag;
	BulletManager() { }
public:
	static BulletManager* getInstance();
	void Update();

	~BulletManager() {
		instanceFlag = false;
	}
};


#endif