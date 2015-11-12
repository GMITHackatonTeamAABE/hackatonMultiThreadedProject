#pragma once
#ifndef BULLET_H
#define BULLET_H

#include <Box2D/Box2D.h>
#include <list>
#include <vector>
#include "include\Renderer.h"
#include "include\Sprite.h"

class Bullet {
private:
	b2Vec2 m_position;
	//b2Vec2 m_velocity;
	float SCALE = 0.3f;
	b2Body* bulletBody;
	Sprite* sprite;

	float initX = 0;
	float initY = 0;
	
	//bool fire = false;

	SDL_Rect spriteRect;
public:
	Bullet(float x, float y, b2World* World, float dir, float power);
	void Update(); 
	//void CreateBody();
	//bool CheckLife();
	//void Fire(float dir, float power);
	Bullet(float x, float y, b2World& World);
	void CreateBody();
	void Fire(float dir);
	void setPosition(float x, float y);
	bool CheckCollision(SDL_Rect* rect);
	void Draw() const;

	~Bullet(); 
};

#endif