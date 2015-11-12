#pragma once
#ifndef BULLETMANAGER_H
#define BULLETMANAGER_H

#include <list>
#include "Bullet.h"

class BulletManager {
private:
	static bool instanceFlag;
	BulletManager() { }
	
public:
	static BulletManager* getInstance();
	void Update();
	void add(Bullet bullet) {
		//bullets.add(new Bullet(x,y, world));
	}
	~BulletManager() {
		instanceFlag = false;
	}
};

#endif