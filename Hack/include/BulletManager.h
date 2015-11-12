#pragma once
#ifndef BULLETMANAGER_H
#define BULLETMANAGER_H

#include <list>
#include "Bullet.h"

class BulletManager {
private:
	static bool instanceFlag;
	static BulletManager* instance;
	BulletManager() { 
		
	}
	std::list<Bullet*> bullets;
public:
	static BulletManager* getInstance();
	void Update();
	void Fire(float dir);
	void add(float x, float y, b2World& world);
	void Draw();
	~BulletManager();
};

#endif